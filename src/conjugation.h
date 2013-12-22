#ifndef CONJUGATION_H
#define CONJUGATION_H

#include <QString>
#include <tuple>
#include <vector>
#include <exception>
#include "conjugator.h"

class Conjugation
{
    friend class Conjugator;

private:
    QString m_qstPostFix;
    std::vector<std::tuple<QString, QString, bool>> m_mpPersonList;
    Conjugation();
    QString getPostFix() const;
    void setPostFix(const QString &p_qstValue);
    void addPerson(QString p_qstPronoun, QString p_qstConjugation, bool p_bIsSingular);
    void removePerson(size_t p_stIndex);
    QString getPronoun(size_t p_stIndex);
    QString getConjugation(size_t p_stIndex);
    QString getConjugation(QString p_qstPronoun);
    size_t getPersonListSize();
};

#else

class Conjugation;

#endif // CONJUGATION_H
