#include "conjugator.h"

void Conjugator::addPronoun(QString p_qstPronoun, bool p_bIsSingular)
{
    for(size_t stIndex = 0; stIndex < m_mptplqstbPronoun.size(); stIndex++)
    {
        if(std::get<0>(m_mptplqstbPronoun.at(stIndex)) == p_qstPronoun && std::get<1>(m_mptplqstbPronoun.at(stIndex)) == p_bIsSingular)
            return;
    }
    m_mptplqstbPronoun.push_back(std::make_tuple(p_qstPronoun, p_bIsSingular));
}

void Conjugator::addConjugation(QString p_qstPostFix, QString p_qstPronoun, QString p_qstConjugation, bool p_bIsSingular)
{
    addPronoun(p_qstPronoun, p_bIsSingular);
    for(size_t stIndex = 0; stIndex < m_mpcnConjugation.size(); stIndex++)
    {
        Conjugation &cjCurrent = m_mpcnConjugation.at(stIndex);
        if(cjCurrent.getPostFix() == p_qstPostFix)
        {
            cjCurrent.addPerson(p_qstPronoun, p_qstConjugation, p_bIsSingular);
            return;
        }
    }
    Conjugation cjCur;
    cjCur.setPostFix(p_qstPostFix);
    cjCur.addPerson(p_qstPronoun, p_qstConjugation, p_bIsSingular);
    m_mpcnConjugation.push_back(cjCur);
}

void Conjugator::removeConjugation(QString p_qstPostFix)
{
    for(size_t stIndex = 0; stIndex < m_mpcnConjugation.size(); stIndex++)
    {
        if(m_mpcnConjugation.at(stIndex).getPostFix() == p_qstPostFix)
        {
            m_mpcnConjugation.erase(m_mpcnConjugation.begin() + stIndex);
            return;
        }
    }
}

bool Conjugator::getIsSingular(size_t p_stIndex)
{
    return std::get<1>(m_mptplqstbPronoun.at(p_stIndex));
}

QString Conjugator::conjugate(QString p_qstPronoun, Verb p_verbVerb, bool p_bIsSingular)
{
    for(size_t stIndex = 0; stIndex < m_mpcnConjugation.size(); stIndex++)
    {
        Conjugation cjCurrent = m_mpcnConjugation.at(stIndex);
        if(cjCurrent.getPostFix() == p_verbVerb.getWordPostFix())
        {
            if(p_verbVerb.getVerbType() == Global::IRREGULAR)
            {
                try
                {
                    return p_verbVerb.getIrregularConjugationByPronoun(p_qstPronoun, p_bIsSingular);
                }
                catch(std::exception &e)
                {
                    return cjCurrent.getConjugation(p_qstPronoun, p_bIsSingular).replace("[rw]", p_verbVerb.getWordRoot());
                }
            }
            else if(p_verbVerb.getVerbType() == Global::REGULAR)
                return cjCurrent.getConjugation(p_qstPronoun, p_bIsSingular).replace("[rw]", p_verbVerb.getWordRoot());
        }
    }
    throw std::exception();
}

QString Conjugator::getPronoun(size_t p_stIndex)
{
    if(p_stIndex < m_mptplqstbPronoun.size())
        return std::get<0>(m_mptplqstbPronoun.at(p_stIndex));
    else
        throw std::exception();
}

size_t Conjugator::getPronounListSize()
{
    return m_mptplqstbPronoun.size();
}

Conjugator::Conjugator()
{
}

Conjugator::~Conjugator()
{

}
