#include "lection.h"


qint8 Lection::getLectionNumber() const
{
    return m_qi8LectionNumber;
}

void Lection::setLectionNumber(const qint8 &p_qi8Value)
{
    m_qi8LectionNumber = p_qi8Value;
}

QString Lection::getHashCode()
{
    QString qstPlainHash = QString::number(m_qi8LectionNumber);
    for(size_t stIndex = 0; stIndex < m_mppvocVocabulary.size(); stIndex++)
    {
        qstPlainHash += m_mppvocVocabulary.at(stIndex)->getHashCode();
    }
    QCryptographicHash qcrypthshClassHash(QCryptographicHash::Sha1);
    qcrypthshClassHash.addData(qstPlainHash.toStdString().c_str(), qstPlainHash.size());
    return QString::fromLatin1(qcrypthshClassHash.result().toHex().toUpper());
}

void Lection::addVoc(Voc* p_pvocCur)
{
    m_mppvocVocabulary.push_back(p_pvocCur);
}

void Lection::removeVoc(size_t p_stIndex)
{
    if(p_stIndex < m_mppvocVocabulary.size())
        m_mppvocVocabulary.erase(m_mppvocVocabulary.begin() + p_stIndex);
    else
        throw std::exception();
}

Voc *Lection::getVoc(size_t p_stIndex)
{
    if(p_stIndex < m_mppvocVocabulary.size())
        return m_mppvocVocabulary.at(p_stIndex);
    throw std::exception();
}

size_t Lection::getVocListSize()
{
    return m_mppvocVocabulary.size();
}

Lection::Lection() : IHashable()
{
}
