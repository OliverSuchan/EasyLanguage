#ifndef CONJUGATION_H
#define CONJUGATION_H

#include <QString>
#include <tuple>
#include <vector>
#include <exception>
#include "conjugator.h"

/**
 * @brief
 * Speichert Konjugationen für eine bestimmte Wortendung<BR>
 * Nur für die Klasse Conjugator verfügbar<BR>
 * @see Conjugator
 */
class Conjugation
{
    friend class Conjugator;

private:

    /**
     * @brief
     * Standard-Konstruktor, um eine Conjugation-Instanz zu erzeugen
     */
    Conjugation();

    /**
     * @brief
     * Der Postfix für die aktuelle Conjugation-Instanz
     */
    QString m_qstPostFix;

    /**
     * @brief
     * Ein Vektor bestehend aus den Personen für den jeweiligen Postfix mit dem Pronomen,<BR>
     * der Konjugation und einem Boolean was darstellt ob jene Person Singular<BR>
     * oder Plural ist<BR>
     */
    std::vector<std::tuple<QString, QString, bool>> m_mptplqstPersonList;

    /**
     * @brief Gibt den Postfix der aktuellen Conjugation-Instanz zurück
     * @return @see m_qstPostFix
     */
    QString getPostFix() const;

    /**
     * @brief Legt den Postfix der aktuellen Conjugation-Instanz zurück
     * @param p_qstValue Neuer Postfix-Wert @see m_qstPostFix
     */
    void setPostFix(const QString &p_qstValue);

    /**
     * @brief Fügt eine neue Person mit spezifischen Eigenschaften zum Personen-Vektor hinzu @see m_mptplqstPersonList
     * @param p_qstPronoun Das Pronomen der Person die hinzugefügt werden soll
     * @param p_qstConjugation Die regelmäßige Konjugation für diese Person
     * @param p_bIsSingular Boolean ob die aktuelle Person Singular oder Plural ist
     */
    void addPerson(QString p_qstPronoun, QString p_qstConjugation, bool p_bIsSingular);

    /**
     * @brief Löscht eine Person aus dem Vektor der Personen @see m_mptplqstPersonList
     * @param p_stIndex Index für die Stelle im Vektor @see m_mptplqstPersonList
     * @throws std::exception
     */
    void removePerson(size_t p_stIndex);

    /**
     * @brief Gibt das Pronomen an einem spezifischen Index zurück
     * @param p_stIndex Index im Vektor der Personen, von wo das Pronomen hergeholt werden soll
     * @return Pronomen
     * @throws std::exception
     */
    QString getPronoun(size_t p_stIndex);

    /**
     * @brief Gibt die Konjugation an einem spezifischen Index zurück
     * @param p_stIndex Index im Vektor der Personen, von wo die Konjugation hergeholt werden soll
     * @return Konjugation
     * @throws std::exception
     */
    QString getConjugation(size_t p_stIndex);

    /**
     * @brief Gibt die Konjugation für ein Pronomen zurück. Es wird zwischen Singular und Plural differenziert
     * @param p_qstPronoun Das Pronomen von wo die Konjugation hergeholt werden soll
     * @param p_bIsSingular Boolean ob die Person mit dem Pronomen Sigular oder Plural ist
     * @return Konjugation
     * @throws std::exception
     */
    QString getConjugation(QString p_qstPronoun, bool p_bIsSingular);

    /**
     * @brief Gibt die Anzahl der eingetragenen Personen im Personen-Vektor an @see m_mptplqstPersonList
     * @return Anzahl der Personen
     */
    size_t getPersonListSize();

public:
    /**
      * @brief Stanard-Destruktor, um eine Conjugation-Instanz vollständig zu zerstören
      */
    ~Conjugation();
};

#else

class Conjugation;

#endif // CONJUGATION_H
