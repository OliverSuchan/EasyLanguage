#include "conjugator.h"

void Conjugator::addPronoun(QString p_qstPronoun, bool p_bIsSingular)
{
    for(size_t stIndex = 0; stIndex < m_mpPronoun.size(); stIndex++)
    {
        if(std::get<0>(m_mpPronoun.at(stIndex)) == p_qstPronoun && std::get<1>(m_mpPronoun.at(stIndex)) == p_bIsSingular)
            return;
    }
    m_mpPronoun.push_back(std::make_tuple(p_qstPronoun, p_bIsSingular));
}

void Conjugator::addConjugation(QString p_qstPostFix, QString p_qstPronoun, QString p_qstConjugation, bool p_bIsSingular)
{
    addPronoun(p_qstPronoun, p_bIsSingular);
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

bool Conjugator::getIsSingular(size_t p_stIndex)
{
    return std::get<1>(m_mpPronoun.at(p_stIndex));
}

QString Conjugator::conjugate(QString p_qstPronoun, Verb p_vrbVerb, bool p_bIsSingular)
{
    for(size_t stIndex = 0; stIndex < m_mpConjugation.size(); stIndex++)
    {
        Conjugation cjCurrent = m_mpConjugation.at(stIndex);
        if(cjCurrent.getPostFix() == p_vrbVerb.getWordPostFix())
        {
            if(p_vrbVerb.getVerbType() == Global::IRREGULAR)
            {
                try
                {
                    return p_vrbVerb.getIrregularConjugationByPronoun(p_qstPronoun, p_bIsSingular);
                }
                catch(std::exception &e)
                {
                    return cjCurrent.getConjugation(p_qstPronoun, p_bIsSingular).replace("[rw]", p_vrbVerb.getWordRoot());
                }
            }
            else if(p_vrbVerb.getVerbType() == Global::REGULAR)
                return cjCurrent.getConjugation(p_qstPronoun, p_bIsSingular).replace("[rw]", p_vrbVerb.getWordRoot());
        }
    }
    throw std::exception();
}

QString Conjugator::getPronoun(size_t p_stIndex)
{
    return std::get<0>(m_mpPronoun.at(p_stIndex));
}

size_t Conjugator::getPronounListSize()
{
    return m_mpPronoun.size();
}

Conjugator::Conjugator()
{
}
