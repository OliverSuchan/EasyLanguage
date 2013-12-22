#include "parser.h"

Parser* Parser::m_pInstance = new Parser;

Parser *Parser::instance()
{
    if(!m_pInstance) m_pInstance = new Parser;
    assert(m_pInstance != NULL);
    return m_pInstance;
}

void Parser::parseLanguageDatabases()
{
    QDir qdCurrentDirectory(QDir::current());
    if(qdCurrentDirectory.exists("languages"))
    {
        qdCurrentDirectory.cd("languages");
        QDirIterator dirIterator(qdCurrentDirectory);
        while(dirIterator.hasNext())
        {
            QString qstCurrentFileName = dirIterator.next();
            if(qstCurrentFileName.endsWith(".xml"))
            {
                Language langCur = parseLanguageDataBase(qstCurrentFileName);
                if(QFile::exists(qstCurrentFileName.replace(".xml", ".cjt")))
                {
                    Conjugator cjCur = parseConjugationDataBase(qstCurrentFileName.replace(".xml", ".cjt"));
                    langCur.setLanguageConjugator(cjCur);
                }
                LanguageManager::INSTANCE()->addLanguage(langCur);
            }
        }
    }
    emit onParserFinished();
}

Conjugator Parser::parseConjugationDataBase(QString p_qstFileName)
{
    Conjugator cjCur;
    ptree pt;
    try
    {
        read_xml(p_qstFileName.toStdString().c_str(), pt);
        BOOST_FOREACH(const ptree::value_type& postFix, pt.get_child("Conjugation"))
        {
            if(postFix.first == "Postfix")
            {
                QString qstPostFix = QString::fromStdString(postFix.second.get<std::string>("<xmlattr>.value"));
                BOOST_FOREACH(const ptree::value_type& person, postFix.second.get_child(""))
                {
                    if(person.first == "Singular" || person.first == "Plural")
                    {
                        bool bSingular = (person.first == "Singular");
                        BOOST_FOREACH(const ptree::value_type& information, person.second.get_child(""))
                        {
                            if(information.first == "First" || information.first == "Second" || information.first == "Third")
                            {
                                QString qstPronoun = QString::fromStdString(information.second.get<std::string>("<xmlattr>.value"));
                                QString qstConjugation = QString::fromStdString(information.second.get<std::string>("<xmlattr>.conjugation"));
                                cjCur.addConjugation(qstPostFix, qstPronoun, qstConjugation, bSingular);
                            }
                        }
                    }
                }
            }
        }
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return cjCur;
}

Language Parser::parseLanguageDataBase(QString p_qstFileName)
{
    ptree pt;
    Language langCur;
    try
    {
        read_xml(p_qstFileName.toStdString().c_str(), pt);
        QString qstLanguageName = QString::fromStdString(pt.get_child("Language").get<std::string>("<xmlattr>.name"));
        langCur.setLanguageName(qstLanguageName);
        BOOST_FOREACH(const ptree::value_type& lection, pt.get_child("Language"))
        {
            if(lection.first == "Lection")
            {
                qint8 lectionNumber = lection.second.get<int>("<xmlattr>.number");
                Lection lectCur;
                lectCur.setLectionNumber(lectionNumber);
                BOOST_FOREACH(const ptree::value_type& voc, lection.second.get_child(""))
                {
                    if(voc.first == "Voc")
                    {
                        Global::VocType vtCur = static_cast<Global::VocType>(voc.second.get<int>("<xmlattr>.type"));
                        Global::LearningState lsCur = static_cast<Global::LearningState>(voc.second.get<int>("<xmlattr>.state"));
                        Voc *pvocCur = new Verb;
                        pvocCur->setWord(QString::fromStdString(voc.second.get<std::string>("<xmlattr>.value")));
                        pvocCur->setVocType(vtCur);
                        pvocCur->setLearningState(lsCur);
                        BOOST_FOREACH(const ptree::value_type& informations, voc.second.get_child(""))
                        {
                            if(informations.first == "Definition" || informations.first == "Synonym")
                            {
                                QStringList mpqstInfos = QString::fromStdString(informations.second.get<std::string>("")).split(";");
                                for(int iIndex = 0; iIndex < mpqstInfos.size(); iIndex++)
                                {
                                    QString qstCurInfo = mpqstInfos.at(iIndex);
                                    if(qstCurInfo != "")
                                    {
                                        if(informations.first == "Definition")
                                            pvocCur->addDefinition(qstCurInfo);
                                        else if(informations.first == "Synonym")
                                            pvocCur->addSynonym(qstCurInfo);
                                    }
                                }
                            }
                        }
                        if(vtCur == Global::VERB)
                        {
                            Verb *pverbCur = dynamic_cast<Verb*>(pvocCur);
                            QStringList mpqst =  pverbCur->getWord().split(";");
                            pverbCur->setWordRoot(mpqst.at(0));
                            pverbCur->setWordPostFix(mpqst.at(1));
                            lectCur.addVoc(pverbCur);
                        }
                        else
                            lectCur.addVoc(pvocCur);
                    }
                }
                langCur.addLection(lectCur);
            }
        }
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return langCur;
}

Parser::Parser(QObject *p_pqoParent) : QObject(p_pqoParent)
{

}

Parser::~Parser()
{

}

Parser::Parser(const Parser &)
{

}

Parser &Parser::operator=(const Parser &)
{
    return *m_pInstance;
}
