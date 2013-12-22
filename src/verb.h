#ifndef VERB_H
#define VERB_H

#include <QString>
#include <vector>
#include "voc.h"

class Verb : public Voc
{

private:
    std::vector<QString*> m_mpqstIrregularPerson;
    QString m_qstWordRoot;
    QString m_qstWordPostFix;

public:
    void addIrregularPerson(QString p_qstPronoun, QString p_qstConjugation);
    void removeIrregularPerson(size_t p_stIndex);
    QString getPronoun(size_t p_stIndex);
    QString getConjugation(size_t p_stIndex);
    void setWordRoot(QString p_qstValue);
    void setWordPostFix(QString p_qstValue);
    QString getWordRoot();
    QString getWordPostFix();
    Verb();
    ~Verb();
};

#endif // VERB_H
