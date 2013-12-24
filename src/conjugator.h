#ifndef CONJUGATOR_H
#define CONJUGATOR_H

#include <QString>
#include <iostream>
#include <vector>
#include <tuple>
#include "verb.h"
#include "conjugation.h"

class Conjugator
{
private:
    std::vector<Conjugation> m_mpConjugation;
    std::vector<std::tuple<QString, bool>> m_mpPronoun;
    void addPronoun(QString p_qstPronoun, bool p_bIsSingular);

public:
    void addConjugation(QString p_qstPostFix, QString p_qstPronoun, QString p_qstConjugation, bool p_bIsSingular);
    void removeConjugation(QString p_qstPostFix);
    bool getIsSingular(size_t p_stIndex);
    QString conjugate(QString p_qstPronoun, Verb p_vrbVerb, bool p_bIsSingular);
    QString getPronoun(size_t p_stIndex);
    size_t getPronounListSize();
    Conjugator();
};

#endif // CONJUGATOR_H
