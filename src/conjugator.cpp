#include "conjugator.h"

void Conjugator::addPronoun(QString p_qstPronoun)
{
    for(size_t stIndex = 0; stIndex < m_mpPronoun.size(); stIndex++)
    {
        if(m_mpPronoun.at(stIndex) == p_qstPronoun)
            return;
    }
    m_mpPronoun.push_back(p_qstPronoun);
}

void Conjugator::addConjugation(QString p_qstPostFix, QString p_qstPronoun, QString p_qstConjugation, bool p_bIsSingular)
{
    addPronoun(p_qstPronoun);
    for(size_t stIndex = 0; stIndex < m_mpConjugation.size(); stIndex++)
    {
        Conjugation &cjCurrent = m_mpConjugation.at(stIndex);
        if(cjCurrent.getPostFix() == p_qstPostFix)
        {
            cjCurrent.addPerson(p_qstPronoun, p_qstConjugation, p_bIsSingular);
            return;
        }
    }
    Conjugation cjCur;
    cjCur.setPostFix(p_qstPostFix);
    cjCur.addPerson(p_qstPronoun, p_qstConjugation, p_bIsSingular);
    m_mpConjugation.push_back(cjCur);
}

void Conjugator::removeConjugation(QString p_qstPostFix)
{
    for(size_t stIndex = 0; stIndex < m_mpConjugation.size(); stIndex++)
    {
        if(m_mpConjugation.at(stIndex).getPostFix() == p_qstPostFix)
        {
            m_mpConjugation.erase(m_mpConjugation.begin() + stIndex);
            return;
        }
    }
}

QString Conjugator::conjugate(QString p_qstPostFix, QString p_qstPronoun, QString p_qstRootWord)
{
    for(size_t stIndex = 0; stIndex < m_mpConjugation.size(); stIndex++)
    {
        Conjugation cjCurrent = m_mpConjugation.at(stIndex);
        if(cjCurrent.getPostFix() == p_qstPostFix)
        {
            return cjCurrent.getConjugation(p_qstPronoun).replace("[rw]", p_qstRootWord);
        }
    }
    throw std::exception();
}

QString Conjugator::getPronoun(size_t p_stIndex)
{
    return m_mpPronoun.at(p_stIndex);
}

size_t Conjugator::getPronounListSize()
{
    return m_mpPronoun.size();
}

Conjugator::Conjugator()
{
}
