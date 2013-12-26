#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <QString>
#include <QCryptographicHash>
#include <vector>
#include <exception>
#include "IHashable.h"
#include "conjugator.h"
#include "lection.h"

class Language : IHashable
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

    // IHashable interface
public:
    QString getHashCode();
};

#endif // LANGUAGE_H
