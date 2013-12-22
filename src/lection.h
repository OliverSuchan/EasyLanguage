#ifndef LECTION_H
#define LECTION_H

#include <QString>
#include <vector>
#include "voc.h"

class Lection
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
};

#endif // LECTION_H
