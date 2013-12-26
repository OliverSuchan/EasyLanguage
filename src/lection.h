#ifndef LECTION_H
#define LECTION_H

#include <QString>
#include <vector>
#include "IHashable.h"
#include "voc.h"

class Lection : IHashable
{
private:
    std::vector<Voc*> m_mpVocabulary;
    qint8 m_qi8LectionNumber;

public:
    void addVoc(Voc* p_vocCur);
    void removeVoc(size_t p_stIndex);
    Voc *getVoc(size_t p_stIndex);
    size_t getVocListSize();
    Lection();
    qint8 getLectionNumber() const;
    void setLectionNumber(const qint8 &p_qi8Value);

    // IHashable interface
public:
    QString getHashCode();
};

#endif // LECTION_H
