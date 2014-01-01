#ifndef VERB_H
#define VERB_H

#include <QString>
#include <iostream>
#include <vector>
#include <tuple>
#include "Globals.h"
#include "IHashable.h"
#include "voc.h"

class Verb : public Voc, IHashable
{

private:
    std::vector<std::tuple<QString, QString, bool>> m_mpqstIrregularPerson;
    QString m_qstWordRoot;
    QString m_qstWordPostFix;
    Global::VerbType m_vtCurVerb;

public:
    void addIrregularPersons(std::vector<std::tuple<QString, QString, bool>> p_mptuplePersons);
    void addIrregularPerson(QString p_qstPronoun, QString p_qstConjugation, bool p_bIsSingular);
    void removeIrregularPerson(size_t p_stIndex);
    std::vector<std::tuple<QString, QString>> getIrregularPersonsSingular();
    std::vector<std::tuple<QString, QString>> getIrregularPersonsPlural();
    QString getIrregularConjugationByPronoun(QString p_qstPronoun, bool p_bIsSingular);
    QString getPronoun(size_t p_stIndex);
    QString getIrregularConjugation(size_t p_stIndex);
    QString getOnlyVerb();
    void setWordRoot(QString p_qstValue);
    void setWordPostFix(QString p_qstValue);
    QString getWordRoot();
    QString getWordPostFix();
    Global::VerbType getVerbType();
    void setVerbType(Global::VerbType p_vtValue);
    Verb();
    ~Verb();

    // IHashable interface
public:
    QString getHashCode();
};

#endif // VERB_H
