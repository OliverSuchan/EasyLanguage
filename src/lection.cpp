#include "lection.h"


qint8 Lection::getLectionNumber() const
{
    return m_qi8LectionNumber;
}

void Lection::setLectionNumber(const qint8 &p_qi8Value)
{
    m_qi8LectionNumber = p_qi8Value;
}
void Lection::addVoc(Voc* p_vocCur)
{
    m_mpVocabulary.push_back(p_vocCur);
}

void Lection::removeVoc(size_t p_stIndex)
{
    if(p_stIndex < m_mpVocabulary.size())
        m_mpVocabulary.erase(m_mpVocabulary.begin() + p_stIndex);
}

Voc *Lection::getVoc(size_t p_stIndex)
{
    if(p_stIndex < m_mpVocabulary.size())
        return m_mpVocabulary.at(p_stIndex);
    else
        throw std::exception();
}

size_t Lection::getVocListSize()
{
    return m_mpVocabulary.size();
}

Lection::Lection()
{
}
