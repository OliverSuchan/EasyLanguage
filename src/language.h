#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <QString>
#include <vector>
#include <exception>
#include "conjugator.h"
#include "lection.h"

class Language
{
private:
    QString m_qstLangName;
    std::vector<Lection> m_mpLection;
    Conjugator m_cjLanguage;

public:
    Language();
    void addLection(Lection p_lectionValue);
    void removeLection(size_t p_stIndex);
    Lection getLection(size_t p_stIndex);
    size_t getLectionListSize();
    QString getLanguageName() const;
    void setLanguageName(const QString &p_qstLangName);
    Conjugator getLanguageConjugator() const;
    void setLanguageConjugator(const Conjugator &p_cjValue);
};

#endif // LANGUAGE_H
