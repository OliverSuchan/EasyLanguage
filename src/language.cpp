#include "language.h"


QString Language::getLanguageName() const
{
    return m_qstLangName;
}

void Language::setLanguageName(const QString &p_qstLangName)
{
    m_qstLangName = p_qstLangName;
}


Conjugator Language::getLanguageConjugator() const
{
    return m_cjLanguage;
}

void Language::setLanguageConjugator(const Conjugator &p_cjValue)
{
    m_cjLanguage = p_cjValue;
}

QString Language::getHashCode()
{
    QString qstPlainHash = m_qstLangName;
    for(size_t stIndex = 0; stIndex < getLectionListSize(); stIndex++)
    {
        qstPlainHash += getLection(stIndex)->getHashCode();
    }
    QCryptographicHash qcrypthshClassHash(QCryptographicHash::Sha1);
    qcrypthshClassHash.addData(qstPlainHash.toStdString().c_str(), qstPlainHash.size());
    return QString::fromLatin1(qcrypthshClassHash.result().toHex().toUpper());
}

Language::Language() : IHashable()
{
    
}

void Language::addLection(Lection *p_plectionValue)
{
    m_mpplectLection.push_back(p_plectionValue);
}

void Language::removeLection(size_t p_stIndex)
{
    if(p_stIndex < m_mpplectLection.size())
        m_mpplectLection.erase(m_mpplectLection.begin() + p_stIndex);
    else
        throw std::exception();
}

Lection *Language::getLection(size_t p_stIndex)
{
    if(p_stIndex < m_mpplectLection.size())
        return m_mpplectLection.at(p_stIndex);
    else
        throw std::exception();
}

size_t Language::getLectionListSize()
{
    return m_mpplectLection.size();
}
