#ifndef VOC_H
#define VOC_H

#include <QString>
#include <QStringList>
#include <QCryptographicHash>
#include <vector>
#include <exception>
#include "Globals.h"
#include "IHashable.h"

/**
 * @brief Speichert alle Informationen zu einer Vokabel ab<BR>
 * Darunter Definitionen, Synonyme, das Wort selbst, das Lernstadium und den Worttype @see Global::LearningState @see Global::VocType
 */
class Voc : IHashable
{

protected:
    /**
     * @brief Liste der Definitionen einer Vokabel
     */
    std::vector<QString> m_mpqstDefinition;

    /**
     * @brief Liste der Synonyme einer Vokabel
     */
    std::vector<QString> m_mpqstSynonym;

    /**
     * @brief Das Wort
     */
    QString m_qstWord;

    /**
     * @brief Der Vokabeltyp @see Global::VocType
     */
    Global::VocType m_ctCurVoc;

    /**
     * @brief Das Lernstadium @see Global::LearningState
     */
    Global::LearningState m_lsCurVoc;

public:
    /**
     * @brief Fügt eine Definition hinzu @see m_mpqstDefinition
     * @param p_qstDefinition Hinzuzufügende Definition
     */
    void addDefinition(QString p_qstDefinition);

    /**
     * @brief Fügt ein Synonym hinzu @see m_mpqstSynonym
     * @param p_qstSynonym Hinzuzufügende Synonym
     */
    void addSynonym(QString p_qstSynonym);

    /**
     * @brief Gibt eine Definition an einem bestimmten Index zurück<BR>
     * Existiert dieses Index nicht, wird eine Exception geworfen
     * @param p_stIndex Index an dem sich die Definition befindet
     * @return Definiton
     * @throws std::exception
     */
    QString getDefinition(size_t p_stIndex);

    /**
     * @brief Gibt die Anzahl der Definition zurück @see m_mpqstDefinition
     * @return Anzahl der Definitionen
     */
    size_t getDefinitionListSize();

    /**
     * @brief Gibt ein Synonym an einer bestimmten Stelle zurück<BR>
     * Existiert dieses Index nicht, wird eine Exception geworfen @see m_mpqstSynonym
     * @param p_stIndex Index an dem sich das Synonym befindet
     * @return Synonym
     * @throws std::exception
     */
    QString getSynonym(size_t p_stIndex);

    /**
     * @brief Gibt die Anzahl der Synonyme zurück @see m_mpqstSynonym
     * @return Anzahl der Synonyme
     */
    size_t getSynonymListSize();

    /**
     * @brief Gibt das Wort zurück
     * @return Wort
     */
    QString getWord();

    /**
     * @brief Legt das Wort fest
     * @param p_qstValue Wort
     */
    void setWord(QString p_qstValue);

    /**
     * @brief Gibt den aktuellen Vokabeltyp zurück @see Global::VocType
     * @return Vokabeltyp @see Global::VocType
     */
    Global::VocType getVocType();

    /**
     * @brief Legt den aktuellen Vokabeltyp fest @see Global::VocType
     * @param p_ctValue Vokabeltyp @see Global::VocType
     */
    void setVocType(Global::VocType p_ctValue);

    /**
     * @brief Gibt den aktuellen Lernstatus zurück @see Global::LearningState
     * @return Lernstatus
     */
    Global::LearningState getLearningState();

    /**
     * @brief Legt den aktuellen Lernstatus fest @see Global::LearningState
     * @param p_lsValue Lernstatus @see Global::LearningState
     */
    void setLearningState(Global::LearningState p_lsValue);

    /**
     * @brief Standard-Konstruktor, um eine Voc-Instanz zu erzeugen @see Voc
     */
    Voc();

    /**
     * @brief Destruktor, um eine Voc-Instanz vollständig zu zerstören<BR>
     * Virtual aus Polymorphie Gründen
     */
    virtual ~Voc();


    // IHashable interface
public:
    /**
     * @brief Generiert einen Hashcode zum Identifizieren der aktuellen Voc-Instanz @see IHashable
     * @return Hashcode der Voc-Instanz
     */
    QString getHashCode();
};

#endif // VOC_H
