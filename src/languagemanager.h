#ifndef LANGUAGEMANAGER_H
#define LANGUAGEMANAGER_H

#include <QString>
#include <QObject>
#include <assert.h>
#include <iostream>
#include <vector>
#include <tuple>
#include <exception>
#include "Writer.h"
#include "language.h"

/**
 * @brief
 * Speichert alle verfügbaren Sprachen<BR>
 * Besitzt das Singleton-Design
 */
class LanguageManager
{

private:
    /**
     * @brief Singleton-Instanz
     */
    static LanguageManager *m_pInstance;

    /**
     * @brief Alle Sprachen<BR>
     * Zusätzlich wird noch der Hashcode der Start-Instanz gespeichert,<BR>
     * um später zu sehen ob Ändeurngen an jener Sprache vorgenommen wurden<BR>
     * und der Pfad der Sprachdatenbank
     */
    std::vector<std::tuple<Language*, QString, QString>> m_mptplplangqstLanguage;

    /**
     * @brief Standard-Konstruktor<BR>
     * private da es ein Singleton ist
     */
    LanguageManager();

    /**
      * Standard-Destruktor<BR>
      * private da es ein Singleton ist
      */
    ~LanguageManager();

    /**
     * @brief Standard-Kopierkonstruktor<BR>
     * private da es ein Singleton ist
     * @param p_lm Kopier-Instanz
     */
    LanguageManager(const LanguageManager& p_lm);

    /**
     * @brief Überladener Zuweisungs-Operator<BR>
     * private da es ein Singleton ist
     * @param p_assignLanguageManager Zuweisungs-Instanz
     * @return Zugewiesene-Instanz
     */
    LanguageManager& operator=(LanguageManager const& p_assignLanguageManager);

    /**
     * @brief Gibt den Hashcode einer Language-Instanz zurück, entsprechend des Namens einer Sprache
     * @param p_qstLangName Name der Sprache
     * @return Hashcode der Language-Instanz @see IHashable
     * @throws std::exception
     */
    QString getHashCodeByLanguageName(QString p_qstLangName);

public:
    /**
     * @brief Gibt die Anzahl der Language-Elemente im Language-Vektor zurück
     * @return Anzahl der Elemente
     */
    size_t getLanguageListSize();

    /**
     * @brief Gibt eine Language-Instanz anhand eines bestimmten Index im Vektor zurück
     * @param p_stIndex Index der Language-Instanz im Vektor @see m_mptplplangqstLanguage
     * @return Language-Instanz @see Language
     * @throws std::exception
     */
    Language *getLanguage(size_t p_stIndex);

    /**
     * @brief Gibt eine Language-Instanz anhand des Namens einer Sprache zurück @see m_mptplplangqstLanguage
     * @param p_qstLangName Name der Sprache
     * @return Language-Instanz @see Language
     * @throws std::exception
     */
    Language *getLanguage(QString p_qstLangName);

    /**
     * @brief Überprüft ob eine Sprache an einem bestimmten Index bearbeitet wurde<BR>
     * anhand des Start-Hashcodes und einem weiteren Hashcode @see IHashable @see Language
     * @param p_stIndex Index an der sich die Language-Instanz im Vektor befindet @see m_mptplplangqstLanguage
     * @return Boolean das angibt ob die Language-Instanz zur Laufzeit bearbeitet wurde
     * @throws std::exception
     */
    bool languageGotEdited(size_t p_stIndex);

    /**
     * @brief Überprüft ob eine Sprache mit einem bestimmten Namen bearbeitet wurde<BR>
     * anhand deren Start-Hashcodes und einem weiteren Hashcode @see IHashable @see Language @see m_mptplplangqstLanguage
     * @param p_qstLangName Name der Sprache
     * @return Boolean das angibt ob die Language-Instanz zur Laufzeit bearbeitet wurde
     * @throws std:.exception
     */
    bool languageGotEdited(QString p_qstLangName);

    /**
     * @brief Überprüft ob irgendeine Language-Instanz zur Laufzeit bearbeitet wurde @see IHashable @see m_mptplplangqstLanguage @see Language
     * @return Boolean das angibt ob eine Language-Instanz bearbeitet wurde
     */
    bool languagesGotModified();

    /**
     * @brief Fügt eine Sprache zu Language-Vektor hinzu @see m_mptpllangqstLanguage
     * @param p_plangValue Language-Instanz @see Language
     * @param p_qstLanguageDatabaseFilename Dateiname der Sprach-Datenbank
     */
    void addLanguage(Language *p_plangValue, QString p_qstLanguageDatabaseFilename);

    /**
     * @brief Überprüft alle gespeicherten Sprache auf Modifikationen @see IHashable @see languageGotEdited  @see m_mptplplangqstLanguage @see Language
     * @return Ein Vektor bestehend aus den zur Laufzeit modifizierte Sprachen und deren Dateinamen @see Language @see m_mptplplangqstLanguage
     * @throws std::exception
     */
    std::vector<std::tuple<Language*, QString>> getModifiedLanguageDatabases();

    /**
     * @brief Löscht eine Sprache an einem bestimmten Index im Language-Vektor
     * @param p_stIndex Index der zu löschenden Language-Instanz @see m_mptplplangqstLanguage
     */
    void removeLanguage(size_t p_stIndex);

    /**
     * @brief Gibt die aktuelle Language-Singleton-Instanz zurück
     * @return Language-Singleton-Instanz
     */
    static LanguageManager* INSTANCE();

};

#endif // LANGUAGEMANAGER_H
