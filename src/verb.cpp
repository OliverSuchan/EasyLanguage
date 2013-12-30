#include "verb.h"

void Verb::addIrregularPersons(std::vector<std::tuple<QString, QString, bool>> p_mptuplePersons)
{
    for(size_t stIndex = 0; stIndex < p_mptuplePersons.size(); stIndex++)
    {
        addIrregularPerson(std::get<0>(p_mptuplePersons.at(stIndex)), std::get<1>(p_mptuplePersons.at(stIndex)), std::get<2>(p_mptuplePersons.at(stIndex)));
    }
}

void Verb::addIrregularPerson(QString p_qstPronoun, QString p_qstConjugation, bool p_bIsSingular)
{
    if(p_qstPronoun != "" && p_qstConjugation != "")
    {
        m_mpqstIrregularPerson.push_back(std::make_tuple(p_qstPronoun, p_qstConjugation, p_bIsSingular));
    }
}

void Verb::removeIrregularPerson(size_t p_stIndex)
{
    if(p_stIndex < m_mpqstIrregularPerson.size())
        m_mpqstIrregularPerson.erase(m_mpqstIrregularPerson.begin() + p_stIndex);
}

std::vector<std::tuple<QString, QString> > Verb::getIrregularPersonsSingular()
{
    std::vector<std::tuple<QString, QString>> mptplqstIrregPersonsSing;
    for(size_t stIndex = 0; stIndex < m_mpqstIrregularPerson.size(); stIndex++)
    {
        if(std::get<2>(m_mpqstIrregularPerson.at(stIndex)) == true)
            mptplqstIrregPersonsSing.push_back(std::make_tuple(std::get<0>(m_mpqstIrregularPerson.at(stIndex)), std::get<1>(m_mpqstIrregularPerson.at(stIndex))));
    }
    if(mptplqstIrregPersonsSing.size() != 0)
        return mptplqstIrregPersonsSing;
    throw std::exception();
}

std::vector<std::tuple<QString, QString> > Verb::getIrregularPersonsPlural()
{
    std::vector<std::tuple<QString, QString>> mptplqstIrregPersonsPlur;
    for(size_t stIndex = 0; stIndex < m_mpqstIrregularPerson.size(); stIndex++)
    {
        if(std::get<2>(m_mpqstIrregularPerson.at(stIndex)) == false)
            mptplqstIrregPersonsPlur.push_back(std::make_tuple(std::get<0>(m_mpqstIrregularPerson.at(stIndex)), std::get<1>(m_mpqstIrregularPerson.at(stIndex))));
    }
    if(mptplqstIrregPersonsPlur.size() != 0)
        return mptplqstIrregPersonsPlur;
    throw std::exception();
}

QString Verb::getIrregularConjugationByPronoun(QString p_qstPronoun, bool p_bIsSingular)
{
    for(size_t stIndex = 0; stIndex < m_mpqstIrregularPerson.size(); stIndex++)
    {
        if(std::get<0>(m_mpqstIrregularPerson.at(stIndex)) == p_qstPronoun && std::get<2>(m_mpqstIrregularPerson.at(stIndex)) == p_bIsSingular)
                return std::get<1>(m_mpqstIrregularPerson.at(stIndex));
    }
    throw std::exception();
}

QString Verb::getPronoun(size_t p_stIndex)
{
    if(p_stIndex  < m_mpqstIrregularPerson.size())
        return std::get<0>(m_mpqstIrregularPerson.at(p_stIndex));
    else
        throw std::exception();
}

QString Verb::getIrregularConjugation(size_t p_stIndex)
{
    if(p_stIndex  < m_mpqstIrregularPerson.size())
        return std::get<1>(m_mpqstIrregularPerson.at(p_stIndex));
    else
        throw std::exception();
}

void Verb::setWordRoot(QString p_qstValue)
{
    m_qstWordRoot = p_qstValue;
}

void Verb::setWordPostFix(QString p_qstValue)
{
    m_qstWordPostFix = p_qstValue;
}

QString Verb::getWordRoot()
{
    return m_qstWordRoot;
}

QString Verb::getWordPostFix()
{
    return m_qstWordPostFix;
}

Global::VerbType Verb::getVerbType()
{
    return m_vtCurVerb;
}

void Verb::setVerbType(Global::VerbType p_vtValue)
{
    m_vtCurVerb = p_vtValue;
}

Verb::Verb() : Voc(), IHashable()
{
}

Verb::~Verb()
{

}

QString Verb::getHashCode()
{
    QString qstPlainHash = Voc::getHashCode() + m_qstWordRoot + m_qstWordPostFix + QString::number(m_vtCurVerb);
    for(size_t stIndex = 0; stIndex < m_mpqstIrregularPerson.size(); stIndex++)
    {
        std::tuple<QString, QString, bool> mpCurTuple = m_mpqstIrregularPerson.at(stIndex);
        qstPlainHash += std::get<0>(mpCurTuple) + std::get<1>(mpCurTuple) + QString::number(std::get<2>(mpCurTuple));
    }
    QCryptographicHash qcrypthshClassHash(QCryptographicHash::Sha1);
    qcrypthshClassHash.addData(qstPlainHash.toStdString().c_str(), qstPlainHash.size());
    return QString::fromLatin1(qcrypthshClassHash.result().toHex().toUpper());
}
