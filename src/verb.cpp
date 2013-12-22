#include "verb.h"

void Verb::addIrregularPerson(QString p_qstPronoun, QString p_qstConjugation)
{
    if(p_qstPronoun != "" && p_qstConjugation != "")
    {
        QString *mpqstPerson = new QString[2];
        mpqstPerson[0] = p_qstPronoun;
        mpqstPerson[1] = p_qstConjugation;
        m_mpqstIrregularPerson.push_back(mpqstPerson);
    }
}

void Verb::removeIrregularPerson(size_t p_stIndex)
{
    if(p_stIndex < m_mpqstIrregularPerson.size())
        m_mpqstIrregularPerson.erase(m_mpqstIrregularPerson.begin() + p_stIndex);
}

QString Verb::getPronoun(size_t p_stIndex)
{
    if(p_stIndex  < m_mpqstIrregularPerson.size())
        return m_mpqstIrregularPerson.at(p_stIndex)[0];
    else
        throw std::exception();
}

QString Verb::getConjugation(size_t p_stIndex)
{
    if(p_stIndex  < m_mpqstIrregularPerson.size())
        return m_mpqstIrregularPerson.at(p_stIndex)[1];
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

Verb::Verb() : Voc()
{
}

Verb::~Verb()
{

}
