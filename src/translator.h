#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QString>
#include <assert.h>
#include <exception>
#include <iostream>
#include <vector>
#include <tuple>
#include "Language.h"
#include "lection.h"

/**
 * @brief Übersetzt ein Wort einer gegebenen Sprache in eine andere Sprache<BR>
 * Benutzt das Singleton-Design
 */
class Translator
{
private:
    /**
     * @brief Konstruktor<BR>
     * private da es ein Singleton ist
     */
    explicit Translator();

    /**
      * @brief Destruktor<BR>
      * private da es ein Singleton ist
      */
    ~Translator();

    /**
     * @brief Standard-Kopierkonstruktor<BR>
     * private da es Singleton ist
     */
    Translator(Translator const&);

    /**
     * @brief Überladener Zuweisungsoperator<BR>
     * private da es ein Singleton ist
     * @return Zugwiesene Instanz
     */
    Translator& operator=(Translator const&);

    /**
     * @brief Translator-Singleton-Instanz @see Translator
     */
    static Translator* s_pTranslatorInstance;

public:
    /**
     * @brief Gibt die aktuelle Translator-Singleton-Instanz zurück
     * @return Translator-Singleton-Instanz @see Translator
     */
    static Translator* INSTANCE();

    /**
     * @brief Gibt die Definitionen und Synonyme jener Sprache als Tuple für ein bestimmtes Wort zurück<BR>
     * Existiert dieses Wort nicht, wird eine Exception geworfen
     * @param p_plangValue Sprache dessen Definitionen und Synonyme zurückgegeben werden sollen @see Language
     * @param p_qstWord Wort dessen Definitionen und Synonyme zurückgegeben werden sollen
     * @return Ein Tuple bestehend aus einem Vektor für die Definitionen und einem Vektor für die Synonyme
     * @throws std::exception
     */
    std::tuple<std::vector<QString>, std::vector<QString>> translate(Language *p_plangValue, QString p_qstWord);

    /**
     * @brief Übersetzt ein Wort einer Sprache in eine andere Sprache<BR>
     * Existiert dieses Wort nicht, wird eine Exception geworfen
     * @param p_plangValueFrom Sprache aus der das Wort stammt @see Language
     * @param p_plangValueInto Sprache in die das Wort übersetzt werden soll @see Language
     * @param p_qstWord Das Wort das in die andere Sprache übersetzt werden soll
     * @return Ein Vektor bestehend aus den Definitionen des Wort in der anderen Sprache
     * @throws std:exception
     */
    std::vector<QString> translate(Language *p_plangValueFrom, Language *p_plangValueInto, QString p_qstWord);

    /**
     * @brief Gibt die Definition eines an einem bestimmten Index zurück<BR>
     * Existiert dieses Index nicht, wird eine Exception geworfen
     * @param p_tplmpqstWordInformations Das Tuple aus dem die Informationen genommen werden sollen
     * @param p_stIndex Der Index an dem sich die gewünschte Definition befindet
     * @return Definition
     * @throws std::exception
     */
    QString getDefinition(std::tuple<std::vector<QString>, std::vector<QString>> p_tplmpqstWordInformations, size_t p_stIndex);

    /**
     * @brief Gibt die Anzahl der Definitionen zurück
     * @param p_tplmpqstWordInformations Das Tuple aus dem die Informationen genommen werden sollen
     * @return Anzahl der Definitionen
     */
    size_t getDefinitionListSize(std::tuple<std::vector<QString>, std::vector<QString>> p_tplmpqstWordInformations);

    /**
     * @brief Gibt das Synonym eines an einem bestimmten Index zurück<BR>
     * Existiert dieses Index nicht, wird eine Exception geworfen
     * @param p_tplmpqstWordInformations Das Tuple aus dem die Informationen genommen werden sollen
     * @param p_stIndex Der Index an dem sich das gewünschte Synonym befindet
     * @return Synonym
     * @throws std::exception
     */
    QString getSynonym(std::tuple<std::vector<QString>, std::vector<QString>> p_tplmpqstWordInformations, size_t p_stIndex);

    /**
     * @brief Gibt die Anzahl der Synonyme zurück
     * @param p_tplmpqstWordInformations Das Tuple aus dem die Informationen genommen werden sollen
     * @return Anzahl der Synonyme
     */
    size_t getSynonymListSize(std::tuple<std::vector<QString>, std::vector<QString>> p_tplmpqstWordInformations);

};

#endif // TRANSLATOR_H
