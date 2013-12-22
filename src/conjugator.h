#ifndef CONJUGATOR_H
#define CONJUGATOR_H

#include <QString>
#include <iostream>
#include <vector>
#include "conjugation.h"

class Conjugator
{
private:
    std::vector<Conjugation> m_mpConjugation;
    std::vector<QString> m_mpPronoun;
    void addPronoun(QString p_qstPronoun);

public:
    void addConjugation(QString p_qstPostFix, QString p_qstPronoun, QString p_qstConjugation, bool p_bIsSingular);
    void removeConjugation(QString p_qstPostFix);
    QString conjugate(QString p_qstPostFix, QString p_qstPronoun, QString p_qstRootWord);
    QString getPronoun(size_t p_stIndex);
    size_t getPronounListSize();
    Conjugator();
};

#endif // CONJUGATOR_H
