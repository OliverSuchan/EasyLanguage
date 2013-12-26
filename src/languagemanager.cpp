#include "languagemanager.h"

LanguageManager* LanguageManager::m_pInstance = new LanguageManager;

LanguageManager::LanguageManager()
{
}

LanguageManager::~LanguageManager()
{
}

LanguageManager::LanguageManager(const LanguageManager &p_lm)
{

}

LanguageManager &LanguageManager::operator=(const LanguageManager &p_assignLanguageManager)
{
    return *m_pInstance;
}

size_t LanguageManager::getLanguageListSize()
{
    return m_mpLanguage.size();
}

Language LanguageManager::getLanguage(size_t p_stIndex)
{
    if(p_stIndex < m_mpLanguage.size())
        return std::get<0>(m_mpLanguage.at(p_stIndex));
    else
        throw std::exception();
}

void LanguageManager::addLanguage(Language p_langValue)
{
    if(&p_langValue)
    {
        m_mpLanguage.push_back(std::make_tuple(p_langValue, p_langValue.getHashCode()));
    }
}

void LanguageManager::removeLanguage(size_t p_stIndex)
{
    if(p_stIndex < m_mpLanguage.size())
        m_mpLanguage.erase(m_mpLanguage.begin() + p_stIndex);
}

LanguageManager *LanguageManager::INSTANCE()
{
    if(!m_pInstance)
        m_pInstance = new LanguageManager;
    assert(m_pInstance != NULL);
    return m_pInstance;
}
