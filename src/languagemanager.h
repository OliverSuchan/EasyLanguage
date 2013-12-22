#ifndef LANGUAGEMANAGER_H
#define LANGUAGEMANAGER_H

#include <assert.h>
#include <iostream>
#include <vector>
#include <exception>
#include "language.h"

class LanguageManager
{
private:
    static LanguageManager *m_pInstance;
    std::vector<Language> m_mpLanguage;
    LanguageManager();
    ~LanguageManager();
    LanguageManager(const LanguageManager& p_lm);
    LanguageManager& operator=(LanguageManager const& p_assignLanguageManager);

public:
    size_t getLanguageListSize();
    Language getLanguage(size_t p_stIndex);
    void addLanguage(Language p_langValue);
    void removeLanguage(size_t p_stIndex);
    static LanguageManager* INSTANCE();

};

#endif // LANGUAGEMANAGER_H
