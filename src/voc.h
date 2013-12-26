#ifndef VOC_H
#define VOC_H

#include <QString>
#include <QCryptographicHash>
#include <vector>
#include <exception>
#include "Globals.h"
#include "IHashable.h"

class Voc : IHashable
{

protected:
    std::vector<QString> m_mpqstDefinition;
    std::vector<QString> m_mpqstSynonym;
    QString m_qstWord;
    Global::VocType m_ctCurVoc;
    Global::LearningState m_lsCurVoc;

public:
    void addDefinition(QString p_qstDefinition);
    void addSynonym(QString p_qstSynonym);
    QString getDefinition(size_t p_stIndex);
    QString getSynonym(size_t p_stIndex);
    QString getWord();
    void setWord(QString p_qstValue);
    Global::VocType getVocType();
    void setVocType(Global::VocType p_ctValue);
    Global::LearningState getLearningState();
    void setLearningState(Global::LearningState p_lsValue);
    Voc();
    virtual ~Voc();


    // IHashable interface
public:
    QString getHashCode();
};

#endif // VOC_H
