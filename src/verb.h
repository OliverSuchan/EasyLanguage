#ifndef VERB_H
#define VERB_H

#include <QString>
#include <iostream>
#include <vector>
#include <tuple>
#include "Globals.h"
#include "IHashable.h"
#include "voc.h"

/**
 * @copydoc Voc
 * @brief Beinhaltet Informationen zu einem Verb<BR>
 * Unter anderem auch unregelmäßige Konjugationen, Wortstamm und Wortendung
 */
class Verb : public Voc, IHashable
{

private:
    /**
     * @brief Vektor der Informationen zu einer unregelmäßigen Person des Verbs speichert<BR>
     * Zu diesen Informationen zählt das Pronomen, die Konjugation und ein Boolean<BR>
     * das aussagt ob die Person Singular oder Plural ist
     */
    std::vector<std::tuple<QString, QString, bool>> m_mpqstIrregularPerson;

    /**
     * @brief Wortstamm des Verbs
     */
    QString m_qstWordRoot;

    /**
     * @brief Wortendung des Verbs
     */
    QString m_qstWordPostFix;

    /**
     * @brief Verbtyp: regelmäßig oder unregelmäßig @see Global::VerbType @see m_mpqstIrregularPerson
     */
    Global::VerbType m_vtCurVerb;

public:
    /**
     * @brief Fügt unregelmäßige Personen zum Vektor mit den unregelmäßigen Personen hinzu @see m_mpqstIrregularPerson
     * @param p_mptuplePersons Vektor mit den Informationen einer unregelmäßigen Person des Verbs<BR>
     * Zu diesen Informationen zählt das Pronomen, die Konjugation und ein Boolean<BR>
     * das aussagt ob die Person Singular oder Plural ist
     */
    void addIrregularPersons(std::vector<std::tuple<QString, QString, bool>> p_mptuplePersons);

    /**
     * @brief Fügt eine einzelne unregelmäßige Person zum Vektor mit den unregelmäßigen Personen hinzu @see m_mpqstIrregularPerson
     * @param p_qstPronoun Das Pronomen mit der unregelmäßigen Konjugation
     * @param p_qstConjugation Die unregelmäßige Konjugation
     * @param p_bIsSingular Boolean das aussagt ob die unregelmäßige Person Singular oder Plural ist
     */
    void addIrregularPerson(QString p_qstPronoun, QString p_qstConjugation, bool p_bIsSingular);

    /**
     * @brief Löscht eine unregelmäßige Person an einer gegebenen Stelle<BR>
     * Existiert der Index nicht, wird eine Exception geworfen @see m_mpqstIrregularPerson
     * @param p_stIndex Index der zu löschenden unregelmäßigen Person
     * @throws std::exception
     */
    void removeIrregularPerson(size_t p_stIndex);

    /**
     * @brief Gibt alle unregelmäßigen Personen des Verbs die Singular sind als Vektor mit den Informationen: Pronomen und Konjugation zurück<BR>
     * Es wird eine Exception geworfen, wenn es keine unregelmäßigen Personen Singular gibt @see m_mpqstIrregularPerson
     * @return Vektor bestehend aus den Informationen unregelmäßiger Personen Singular<BR>
     * Zu diesen Informationen zählt Pronomen und Konjugation
     * @throws std::exception
     */
    std::vector<std::tuple<QString, QString>> getIrregularPersonsSingular();

    /**
     * @brief Gibt alle unregelmäßigen Personen des Verbs die Plural sind als Vektor mit den Informationen: Pronomen und Konjugation zurück<BR>
     * Es wird eine Exception geworfen, wenn es keine unregelmäßigen Personen Plural gibt @see m_mpqstIrregularPerson
     * @return Vektor bestehend aus den Informationen unregelmäßiger Personen Plural<BR>
     * Zu diesen Informationen zählt Pronomen und Konjugation
     * @throws std.:exception
     */
    std::vector<std::tuple<QString, QString>> getIrregularPersonsPlural();

    /**
     * @brief Gibt eine unregelmäßige Konjugation anhand eines Pronomen und deren Eigenschaft(Singular/Plural) zurück<BR>
     * Wenn keine Konjugation gefunden werden konnte, wird eine Exception geworfen @see m_mpqstIrregularPerson
     * @param p_qstPronoun Das Pronomen nach dem für die Konjugation gesucht werden soll
     * @param p_bIsSingular Boolean das aussagt ob das Pronomen Singular oder Plural ist
     * @return Unregelmäßige Konjugation
     * @throws std::exception
     */
    QString getIrregularConjugationByPronoun(QString p_qstPronoun, bool p_bIsSingular);

    /**
     * @brief Gibt ein Pronomen an einer bestimmten Stelle zurück<BR>
     * Existiert dieses Index nicht, wird eine Exception geworfen @see m_mpqstIrregularPerson
     * @param p_stIndex Index an dem sich das Pronomen befindet
     * @return Pronomen
     * @throws std::exception
     */
    QString getPronoun(size_t p_stIndex);

    /**
     * @brief Gibt eine unregelmäßige Konjugation an einer bestimmten Stelle zurück<BR>
     * Existiert dieser Index nicht, wird eine Exception geworfen @see m_mpqstIrregularPerson
     * @param p_stIndex Index an dem sich die Konjugation befindet
     * @return Unregelmäßige Konjugation
     * @throws std::exception
     */
    QString getIrregularConjugation(size_t p_stIndex);

    /**
     * @brief Gibt nur das Verb im Ininitiv zurück<BR>
     * Sprich Seperatoren werden rausgeschnitten @see getWord @see getWordRoot @see getWordPostFix
     * @return Verb
     */
    QString getOnlyVerb();

    /**
     * @brief Legt den Wortstamm des Verbs fest @see m_qstWordRoot
     * @param p_qstValue Wortstamm des Verbs
     */
    void setWordRoot(QString p_qstValue);

    /**
     * @brief Legt die Wortendung des Verbs fest @see m_qstWordPostFix
     * @param p_qstValue Wortendung des Verbs
     */
    void setWordPostFix(QString p_qstValue);

    /**
     * @brief Gibt den Wortstamm des Verbs zurück
     * @return Wortstamm @see m_qstWordRoot
     */
    QString getWordRoot();

    /**
     * @brief Gibt die Wortendung des Verbs zurück
     * @return Wortendung @see m_qstWordPostFix
     */
    QString getWordPostFix();

    /**
     * @brief Gibt den Verbtyp zurück, regelmäßig oder unregelmäßig
     * @return Verbtyp @see Global::VerbType
     */
    Global::VerbType getVerbType();

    /**
     * @brief Legt den Verbtyp fest
     * @param p_vtValue Verbtyp @see Global::VerbType
     */
    void setVerbType(Global::VerbType p_vtValue);

    /**
     * @brief Standard-Konstruktor, um eine Verb-Instanz zu erzeugen
     */
    Verb();

    /**
      * @brief Standard-Destruktor, um eine Verb-Instanz vollständig zu zerstören
      */
    ~Verb();

    // IHashable interface
public:
    /**
     * @brief Generiert einen Hashcode zum Identifizieren der aktuellen Verb-Instanz @see IHashable
     * @return Hashcode der Verb-Instanz
     */
    QString getHashCode();
};

#endif // VERB_H
