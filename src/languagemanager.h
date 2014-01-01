#ifndef LANGUAGEMANAGER_H
#define LANGUAGEMANAGER_H

#include <QString>
#include <QObject>
#include <assert.h>
#include <iostream>
#include <vector>
#include <tuple>
#include <exception>
#include "Writer.h"
#include "language.h"

class LanguageManager
{

private:
    static LanguageManager *m_pInstance;
    std::vector<std::tuple<Language*, QString, QString>> m_mptpllangqstLanguage;
    LanguageManager();
    ~LanguageManager();
    LanguageManager(const LanguageManager& p_lm);
    LanguageManager& operator=(LanguageManager const& p_assignLanguageManager);
    QString getHashCodeByLanguageName(QString p_qstLangName);

public:
    size_t getLanguageListSize();
    Language *getLanguage(size_t p_stIndex);
    Language *getLanguage(QString p_qstLangName);
    bool languageGotEdited(size_t p_stIndex);
    bool languageGotEdited(QString p_qstLangName);
    bool languagesGotModified();
    void addLanguage(Language *p_langValue, QString p_qstLanguageDatabaseFilename);
    std::vector<std::tuple<Language*, QString>> getModifiedLanguageDatabases();
    void removeLanguage(size_t p_stIndex);
    static LanguageManager* INSTANCE();

};

#endif // LANGUAGEMANAGER_H
