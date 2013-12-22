#include "conjugation.h"


QString Conjugation::getPostFix() const
{
    return m_qstPostFix;
}

void Conjugation::setPostFix(const QString &qstPostFix)
{
    m_qstPostFix = qstPostFix;
}

void Conjugation::addPerson(QString p_qstPronoun, QString p_qstConjugation, bool p_bIsSingular)
{
    if(p_qstPronoun != "" && p_qstConjugation != "")
    {
        m_mpPersonList.push_back(std::make_tuple(p_qstPronoun, p_qstConjugation, p_bIsSingular));
    }
}

void Conjugation::removePerson(size_t p_stIndex)
{
    if(p_stIndex < m_mpPersonList.size())
        m_mpPersonList.erase(m_mpPersonList.begin() + p_stIndex);
    else
        throw std::exception();
}

QString Conjugation::getPronoun(size_t p_stIndex)
{
    if(p_stIndex < m_mpPersonList.size())
        return std::get<0>(m_mpPersonList.at(p_stIndex));
    else
        throw std::exception();
}

QString Conjugation::getConjugation(size_t p_stIndex)
{
    if(p_stIndex < m_mpPersonList.size())
        return std::get<1>(m_mpPersonList.at(p_stIndex));
    else
        throw std::exception();
}

QString Conjugation::getConjugation(QString p_qstPronoun)
{
    for(size_t stIndex = 0; stIndex < m_mpPersonList.size(); stIndex++)
    {
        if(std::get<0>(m_mpPersonList.at(stIndex)) == p_qstPronoun)
            return std::get<1>(m_mpPersonList.at(stIndex));
    }
    return "";
}

size_t Conjugation::getPersonListSize()
{
    return m_mpPersonList.size();
}

Conjugation::Conjugation()
{
}
