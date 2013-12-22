#include "language.h"


QString Language::getLanguageName() const
{
    return m_qstLangName;
}

void Language::setLanguageName(const QString &p_qstLangName)
{
    m_qstLangName = p_qstLangName;
}


Conjugator Language::getLanguageConjugator() const
{
    return m_cjLanguage;
}

void Language::setLanguageConjugator(const Conjugator &p_cjValue)
{
    m_cjLanguage = p_cjValue;
}
Language::Language()
{
    
}

void Language::addLection(Lection p_lectionValue)
{
    if(&p_lectionValue)
        m_mpLection.push_back(p_lectionValue);
}

void Language::removeLection(size_t p_stIndex)
{
    if(p_stIndex < m_mpLection.size())
        m_mpLection.erase(m_mpLection.begin() + p_stIndex);
    else
        throw std::exception();
}

Lection Language::getLection(size_t p_stIndex)
{
    if(p_stIndex < m_mpLection.size())
        return m_mpLection.at(p_stIndex);
    else
        throw std::exception();
}

size_t Language::getLectionListSize()
{
    return m_mpLection.size();
}
