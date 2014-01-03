#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <QString>
#include <QCryptographicHash>
#include <vector>
#include <exception>
#include "IHashable.h"
#include "conjugator.h"
#include "lection.h"

/**
 * @brief
 * Speichert alle Informationen für eine geparste Sprache
 */
class Language : IHashable
{
private:
    /**
     * @brief Der Name der Sprache
     */
    QString m_qstLangName;

    /**
     * @brief Vektor bestehend aus allen Lektionen der Sprache @Lection
     */
    std::vector<Lection*> m_mpplectLection;

    /**
     * @brief Konjugierer für die aktuelle Sprache @see Conjugator
     */
    Conjugator m_cjLanguage;

public:
    /**
     * @brief Standard-Konstruktor, um eine Language-Instanz zu erzeugen
     */
    Language();

    /**
      * @brief Standard-Destruktor, um eine Language-Instanz vollständig zu zerstören
      */
    ~Language();

    /**
     * @brief Fügt eine Lektion zur aktuellen Sprache hinzu @see m_mpplectLection
     * @param p_plectionValue Lektion die hinzugefügt werden soll @see Lection
     */
    void addLection(Lection* p_plectionValue);

    /**
     * @brief Löscht eine Lektion der Sprache an einem bestimmten Index
     * @param p_stIndex Index der Lektion die gelöscht werden soll @see m_mpplectLection
     * @throws std:.exception
     */
    void removeLection(size_t p_stIndex);

    /**
     * @brief Gibt die Lektion an einer bestimmten Stelle zurück
     * @param p_stIndex Stelle der Lektion im Vektor @see m_mpLection
     * @return Lektion @see Lection
     * @throws std::exception
     */
    Lection *getLection(size_t p_stIndex);

    /**
     * @brief Gibt die Anzahl der Lektionen im Lektionen-Vektor zurück
     * @return Anzahl der Lektionen @see m_mpplectLection
     */
    size_t getLectionListSize();

    /**
     * @brief Gibt den Namen der aktuellen Sprache zurück
     * @return @see m_qstLangName
     */
    QString getLanguageName() const;

    /**
     * @brief Legt den Namen der aktuellen Sprache fest @see m_qstLangName
     * @param p_qstLangName Name der Sprache
     */
    void setLanguageName(const QString &p_qstLangName);

    /**
     * @brief Gibt die Conjugator-Instanz für die aktuelle Sprache zurück @see m_cjLanguage
     * @return Konjugierer @see Conjugator
     */
    Conjugator getLanguageConjugator() const;

    /**
     * @brief Legt den Konjugierer für die aktuelle Sprache fest @see m_cjLanguage
     * @param p_cjValue Conjugator-Instanz @see Conjugator
     */
    void setLanguageConjugator(const Conjugator &p_cjValue);

    // IHashable interface
public:
    /**
     * @brief Generiert einen Hashcode zum Identifizieren der aktuellen Language-Instanz @see IHashable
     * @return Hashcode der Language-Instanz
     */
    QString getHashCode();
};

#endif // LANGUAGE_H
