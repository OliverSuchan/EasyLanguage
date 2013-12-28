#ifndef LANGUAGEMANAGER_H
#define LANGUAGEMANAGER_H

#include <QString>
#include <QObject>
#include <assert.h>
#include <iostream>
#include <vector>
#include <tuple>
#include <exception>
#include "language.h"

class LanguageManager
{
private:
    static LanguageManager *m_pInstance;
    std::vector<std::tuple<Language, QString>> m_mpLanguage;
    LanguageManager();
    ~LanguageManager();
    LanguageManager(const LanguageManager& p_lm);
    LanguageManager& operator=(LanguageManager const& p_assignLanguageManager);
    QString getHashCodeByLanguageName(QString p_qstLangName);

public:
    size_t getLanguageListSize();
    Language getLanguage(size_t p_stIndex);
    Language getLanguage(QString p_qstLangName);
    bool languageGotEdited(size_t p_stIndex);
    bool languageGotEdited(QString p_qstLangName);
    void addLanguage(Language p_langValue);
    void removeLanguage(size_t p_stIndex);
    static LanguageManager* INSTANCE();

};

#endif // LANGUAGEMANAGER_H
