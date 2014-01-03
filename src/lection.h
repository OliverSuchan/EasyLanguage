#ifndef LECTION_H
#define LECTION_H

#include <QString>
#include <vector>
#include "IHashable.h"
#include "voc.h"

/**
 * @brief Speichert alle Vokabeln einer Lektion und deren Lektionsnummer
 */
class Lection : IHashable
{
private:
    /**
     * @brief Vektor bestehend aus allen Vokabeln der Lektion @see Voc
     */
    std::vector<Voc*> m_mppvocVocabulary;

    /**
     * @brief Die Lektionsnummer der aktuellen Lection-Instanz
     */
    qint8 m_qi8LectionNumber;

public:
    /**
     * @brief Fügt eine Vokabel zum Voc-Vektor hinzu @see m_mppvocVocabulary
     * @param p_pvocCur Hinzuzufügende Vokabel @see Voc
     */
    void addVoc(Voc* p_pvocCur);

    /**
     * @brief Löscht eine Vokabel an einem bestimmten Index aus dem Voc-Vektor @see m_mppvocVocabulary
     * @param p_stIndex Index der Vokabel die gelöscht werden soll
     * @throws std::exception
     */
    void removeVoc(size_t p_stIndex);

    /**
     * @brief Gibt eine Vokabel an einem bestimmten Index im Voc-Vektor zurück
     * @param p_stIndex Index der Vokabel im Voc-Vektor @see m_mppvocVocabulary
     * @return Voc-Instanz @see Voc
     * @throws std::exception
     */
    Voc *getVoc(size_t p_stIndex);

    /**
     * @brief Gibt die Anzahl der Elemente im Voc-Vektor zurück @see m_mppvocVocabulary
     * @return Anzahl der Elemente
     */
    size_t getVocListSize();

    /**
     * @brief Standard-Konstruktur, um eine Lection-Instanz zu erzeugen
     */
    Lection();

    /**
      * Standard-Destruktor, um eine Lection-Instanz vollständig zu zerstören
      */
    ~Lection();

    /**
     * @brief Gibt die aktuelle Lektionsnummer zurück @see m_qi8LectionNumber
     * @return Lektionsnummer @see m_qi8LectionNumber
     */
    qint8 getLectionNumber() const;

    /**
     * @brief Legt die aktuelle Lektionsnnummer fest
     * @param p_qi8Value @see m_qi8LectionNumber
     */
    void setLectionNumber(const qint8 &p_qi8Value);

    // IHashable interface
public:
    /**
     * @brief Generiert einen Hashcode zum Identifizieren der aktuellen Lection-Instanz @see IHashable
     * @return Hashcode der Lection-Instanz
     */
    QString getHashCode();
};

#endif // LECTION_H
