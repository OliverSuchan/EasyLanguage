#include "conjugation.h"


Conjugation::Conjugation()
{

}

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
        m_mptplqstPersonList.push_back(std::make_tuple(p_qstPronoun, p_qstConjugation, p_bIsSingular));
    }
}

void Conjugation::removePerson(size_t p_stIndex)
{
    if(p_stIndex < m_mptplqstPersonList.size())
        m_mptplqstPersonList.erase(m_mptplqstPersonList.begin() + p_stIndex);
    else
        throw std::exception();
}

QString Conjugation::getPronoun(size_t p_stIndex)
{
    if(p_stIndex < m_mptplqstPersonList.size())
        return std::get<0>(m_mptplqstPersonList.at(p_stIndex));
    else
        throw std::exception();
}

QString Conjugation::getConjugation(size_t p_stIndex)
{
    if(p_stIndex < m_mptplqstPersonList.size())
        return std::get<1>(m_mptplqstPersonList.at(p_stIndex));
    else
        throw std::exception();
}

QString Conjugation::getConjugation(QString p_qstPronoun, bool p_bIsSingular)
{
    for(size_t stIndex = 0; stIndex < m_mptplqstPersonList.size(); stIndex++)
    {
        if(std::get<0>(m_mptplqstPersonList.at(stIndex)) == p_qstPronoun && std::get<2>(m_mptplqstPersonList.at(stIndex)) == p_bIsSingular)
            return std::get<1>(m_mptplqstPersonList.at(stIndex));
    }
    throw std::exception();
}

size_t Conjugation::getPersonListSize()
{
    return m_mptplqstPersonList.size();
}

Conjugation::~Conjugation()
{

}
