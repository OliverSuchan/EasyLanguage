#include "writer.h"

Writer* Writer::s_pWriterInstance = new Writer;

Writer::Writer()
{
}

Writer::~Writer()
{

}

Writer::Writer(const Writer &)
{

}

Writer &Writer::operator=(const Writer &)
{

}

void Writer::rewriteModifiedLanguageDatabase(Language *p_langValue, QString p_qstFileName)
{
    ptree pt;
    try
    {
        pt.add_child("Language", pt);
        pt.get_child("Language").add("<xmlattr>.name", p_langValue->getLanguageName().toStdString());
        for(size_t stLectionIndex = 0; stLectionIndex < p_langValue->getLectionListSize(); stLectionIndex++)
        {
            ptree ptLection;
            Lection *lectCurrent = new Lection;
            lectCurrent = p_langValue->getLection(stLectionIndex);
            ptLection.add("<xmlattr>.number", QString::number(lectCurrent->getLectionNumber()).toStdString());
            for(size_t stVocIndex = 0; stVocIndex < lectCurrent->getVocListSize(); stVocIndex++)
            {
                ptree ptVoc;
                Voc *vocCurrent = lectCurrent->getVoc(stVocIndex);
                ptVoc.add("<xmlattr>.type", static_cast<int>(vocCurrent->getVocType()));
                ptVoc.add("<xmlattr>.state", static_cast<int>(vocCurrent->getLearningState()));
                ptVoc.add("<xmlattr>.value", vocCurrent->getWord().toStdString());
                ptree ptDefinition;
                QString qstDefinition = "";
                for(size_t stDefinitionIndex = 0; stDefinitionIndex < vocCurrent->getDefinitionListSize(); stDefinitionIndex++)
                {
                    qstDefinition += vocCurrent->getDefinition(stDefinitionIndex) + ";";
                }
                ptDefinition.add("<xmlattr>.value", qstDefinition.toStdString());
                ptVoc.add_child("Definition", ptDefinition);
                ptree ptSynonym;
                QString qstSynonym = "";
                for(size_t stSynoynmIndex = 0; stSynoynmIndex < vocCurrent->getSynonymListSize(); stSynoynmIndex++)
                {
                    qstSynonym += vocCurrent->getSynonym(stSynoynmIndex) + ";";
                }
                ptSynonym.add("<xmlattr>.value", qstSynonym.toStdString());
                ptVoc.add_child("Synonym", ptSynonym);
                Verb *verbCurrent = dynamic_cast<Verb*>(vocCurrent);
                if(verbCurrent->getVocType() == Global::VERB)
                {
                    ptVoc.add("<xmlattr>.regular", QString::number(verbCurrent->getVerbType()).toStdString());
                    if(verbCurrent->getVerbType() == Global::IRREGULAR)
                    {
                        ptree ptPersons;
                        ptree ptSingular;
                        try
                        {
                            std::vector<std::tuple<QString, QString>> mptplqstIrregularPersonSingular = verbCurrent->getIrregularPersonsSingular();
                            for(size_t stSingularPersonIndex = 0; stSingularPersonIndex < mptplqstIrregularPersonSingular.size(); stSingularPersonIndex++)
                            {
                                ptree ptPerson;
                                ptPerson.add("<xmlattr>.value", std::get<0>(mptplqstIrregularPersonSingular.at(stSingularPersonIndex)).toStdString());
                                ptPerson.add("<xmlattr>.conjugation", std::get<1>(mptplqstIrregularPersonSingular.at(stSingularPersonIndex)).toStdString());
                                ptSingular.add_child("Person", ptPerson);
                            }
                            ptPersons.add_child("Singular", ptSingular);
                        }
                        catch(std::exception &e) {}
                        ptree ptPlural;
                        try
                        {
                            std::vector<std::tuple<QString, QString>> mptplqstIrregularPersonPlural = verbCurrent->getIrregularPersonsPlural();
                            for(size_t stPluralPersonIndex = 0; stPluralPersonIndex < mptplqstIrregularPersonPlural.size(); stPluralPersonIndex++)
                            {
                                ptree ptPerson;
                                ptPerson.add("<xmlattr>.value", std::get<0>(mptplqstIrregularPersonPlural.at(stPluralPersonIndex)).toStdString());
                                ptPerson.add("<xmlattr>.conjugation", std::get<1>(mptplqstIrregularPersonPlural.at(stPluralPersonIndex)).toStdString());
                                ptPlural.add_child("Person", ptPerson);
                            }
                            ptPersons.add_child("Plural", ptPlural);
                        }
                        catch(std::exception &e) {}
                        ptVoc.add_child("Persons", ptPersons);
                    }
                }
                ptLection.add_child("Voc", ptVoc);
            }
            pt.get_child("Language").add_child("Lection", ptLection);
        }
        boost::property_tree::xml_writer_settings<char> settings('\t', 1);
        write_xml(p_qstFileName.toStdString(), pt, std::locale(), settings);
    }
    catch(std::exception &e)
    {
        printf("Error: %s\n", e.what());
    }
}

Writer *Writer::INSTANCE()
{
    if(!s_pWriterInstance)
        s_pWriterInstance = new Writer;
    assert(s_pWriterInstance != NULL);
    return s_pWriterInstance;
}

void Writer::rewriteModifiedLanguageDatabases()
{
    try
    {
        std::vector<std::tuple<Language*, QString>> mptpllangqstModifiedLanguages = LanguageManager::INSTANCE()->getModifiedLanguageDatabases();
        for(size_t stIndex = 0; stIndex < mptpllangqstModifiedLanguages.size(); stIndex++)
        {
            rewriteModifiedLanguageDatabase(std::get<0>(mptpllangqstModifiedLanguages.at(stIndex)), std::get<1>(mptpllangqstModifiedLanguages.at(stIndex)));
        }
    }
    catch(std::exception &e) { }
}
