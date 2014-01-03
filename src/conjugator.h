#ifndef CONJUGATOR_H
#define CONJUGATOR_H

#include <QString>
#include <iostream>
#include <vector>
#include <tuple>
#include "verb.h"
#include "conjugation.h"

/**
 * @brief
 * Konjugiert Verben, bei zur Hilfenahme von Conjugation @see Conjugation
 */
class Conjugator
{

private:
    /**
     * @brief Ein Vektor mit allen Konjugationen für eine bestimmte Sprache @see Conjugation
     */
    std::vector<Conjugation> m_mpcnConjugation;

    /**
     * @brief Ein Vektor aus Pronomen und einem Boolean der angibt ob das jeweilige Pronomen Singular oder Plural ist<BR>
     * Diese Liste wird beim Hinzufügen eines Pronomens automatisch erweitert @see addPronoun @see addConjugation
     */
    std::vector<std::tuple<QString, bool>> m_mptplqstbPronoun;

    /**
     * @brief Fügt ein Pronomen mit einer Singular oder Plural Eigenschaft zum Pronomen-Vektor hinzu @see m_mptplqstbPronoun<BR>
     * Wird automatisch beim Hinzufügen einer Konjugation aufgerufen @see addConjugation
     * @param p_qstPronoun Das hinzuzufügende Pronomen
     * @param p_bIsSingular Boolean der darstellt ob das Pronomen Singular oder Plural ist
     */
    void addPronoun(QString p_qstPronoun, bool p_bIsSingular);

public:
    /**
     * @brief Fügt eine Konjugation zum Conjugation-Vektor hinzu @see m_mpcnConjugation
     * @param p_qstPostFix Postfix für die jeweilige Konjugation
     * @param p_qstPronoun Pronomen das hinzugefügt werden
     * @param p_qstConjugation Konjugation, der Person entsprechend, die hinzugefügt werden soll
     * @param p_bIsSingular Differenzierung zwischen Singular und Plural für die jeweilige Person
     */
    void addConjugation(QString p_qstPostFix, QString p_qstPronoun, QString p_qstConjugation, bool p_bIsSingular);

    /**
     * @brief Löscht eine Konjugation aus dem Conjugation-Vektor @see m_mpcnConjugation
     * @param p_qstPostFix Postfix der Conjugation-Instanz die gelöscht werden soll
     */
    void removeConjugation(QString p_qstPostFix);

    /**
     * @brief Gibt zurück ob die Person an einem spezifischen Index Singular oder Plural ist @see m_mptplqstbPronoun
     * @param p_stIndex Index der Person, die überprüft werden soll
     * @return Wenn gewählte Person Singular ist: true; anderenfalls: false
     */
    bool getIsSingular(size_t p_stIndex);

    /**
     * @brief Konjugiert ein Verb
     * @param p_qstPronoun Die Person, die zum Konjugieren verwendet werden soll
     * @param p_verbVerb Das Verb, dass konjugiert werden soll
     * @param p_bIsSingular Ist die Person Singular oder Plural
     * @return Konjugation
     * @throws std::exception
     */
    QString conjugate(QString p_qstPronoun, Verb p_verbVerb, bool p_bIsSingular);

    /**
     * @brief Gibt das Pronomen an einer bestimmten Stelle zurück @see m_mptplqstbPronoun
     * @param p_stIndex Die Stelle, an der sich das Pronomen befindet
     * @return Pronomen
     * @see std::exception
     */
    QString getPronoun(size_t p_stIndex);

    /**
     * @brief Gibt die Größe der Pronomen-Liste zurück @see m_mptplqstbPronoun
     * @return Größe der Liste
     */
    size_t getPronounListSize();

    /**
     * @brief Standard-Konstruktor, um eine Conjugator-Instanz zu erzeugen
     */
    Conjugator();

    /**
     * @brief Standard-Destruktor, um eine Conjugator-Instanz vollständig zu zerstören
     */
    ~Conjugator();
};

#endif // CONJUGATOR_H
