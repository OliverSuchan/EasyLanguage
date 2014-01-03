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

QString LanguageManager::getHashCodeByLanguageName(QString p_qstLangName)
{
    for(size_t stIndex = 0; stIndex < m_mptplplangqstLanguage.size(); stIndex++)
    {
        if(std::get<0>(m_mptplplangqstLanguage.at(stIndex))->getLanguageName().toUpper() == p_qstLangName.toUpper())
            return std::get<1>(m_mptplplangqstLanguage.at(stIndex));
    }
    throw std::exception();
}


std::vector<std::tuple<Language*, QString>> LanguageManager::getModifiedLanguageDatabases()
{
    std::vector<std::tuple<Language*, QString>> mptpllangqstModifiedLanguagedDatabases;
    for(size_t stIndex = 0; stIndex < m_mptplplangqstLanguage.size(); stIndex++)
    {
        Language *langCur = new Language;
        langCur = std::get<0>(m_mptplplangqstLanguage.at(stIndex));
        if(langCur->getHashCode() != getHashCodeByLanguageName(langCur->getLanguageName()))
            mptpllangqstModifiedLanguagedDatabases.push_back(std::make_tuple(langCur, std::get<2>(m_mptplplangqstLanguage.at(stIndex))));
    }
    if(mptpllangqstModifiedLanguagedDatabases.size() != 0)
        return mptpllangqstModifiedLanguagedDatabases;
    throw std::exception();
}

size_t LanguageManager::getLanguageListSize()
{
    return m_mptplplangqstLanguage.size();
}

Language *LanguageManager::getLanguage(size_t p_stIndex)
{
    if(p_stIndex < m_mptplplangqstLanguage.size())
        return std::get<0>(m_mptplplangqstLanguage.at(p_stIndex));
    else
        throw std::exception();
}

Language *LanguageManager::getLanguage(QString p_qstLangName)
{
    for(size_t stIndex = 0; stIndex < m_mptplplangqstLanguage.size(); stIndex++)
    {
        Language *langCur = new Language;
        langCur = std::get<0>(m_mptplplangqstLanguage.at(stIndex));
        if(langCur->getLanguageName().toUpper() == p_qstLangName.toUpper())
            return langCur;
    }
    throw std::exception();
}

bool LanguageManager::languagesGotModified()
{
    for(size_t stIndex = 0; stIndex < m_mptplplangqstLanguage.size(); stIndex++)
    {
        if(languageGotEdited(stIndex))
            return true;
    }
    return false;
}

bool LanguageManager::languageGotEdited(size_t p_stIndex)
{
    try
    {
        if(getLanguage(p_stIndex)->getHashCode() == std::get<1>(m_mptplplangqstLanguage.at(p_stIndex)))
            return false;
    }
    catch(std::exception &e) { throw e; }
    return true;
}

bool LanguageManager::languageGotEdited(QString p_qstLangName)
{
    try
    {
        if(getLanguage(p_qstLangName)->getHashCode() == getHashCodeByLanguageName(p_qstLangName))
            return false;

    }
    catch(std::exception& e) { throw e; }
    return true;
}

void LanguageManager::addLanguage(Language *p_plangValue, QString p_qstLanguageDatabaseFilename)
{
    m_mptplplangqstLanguage.push_back(std::make_tuple(p_plangValue, p_plangValue->getHashCode(), p_qstLanguageDatabaseFilename));
}

void LanguageManager::removeLanguage(size_t p_stIndex)
{
    if(p_stIndex < m_mptplplangqstLanguage.size())
        m_mptplplangqstLanguage.erase(m_mptplplangqstLanguage.begin() + p_stIndex);
}

LanguageManager *LanguageManager::INSTANCE()
{
    if(!m_pInstance)
        m_pInstance = new LanguageManager;
    assert(m_pInstance != NULL);
    return m_pInstance;
}
