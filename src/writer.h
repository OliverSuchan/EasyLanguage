#ifndef WRITER_H
#define WRITER_H

#ifndef Q_MOC_RUN
#include "../include/boost/foreach.hpp"
#include "../include/boost/property_tree/ptree.hpp"
#include "../include/boost/property_tree/xml_parser.hpp"
#endif //Q_MOC_RUN

#include <assert.h>
#include <exception>
#include <vector>
#include <tuple>
#include "languagemanager.h"
#include "language.h"

using boost::property_tree::ptree;

/**
 * @brief Schreibt alle bearbeiteten Sprachdatenbanken neu<BR>
 * Benutzt das Singleton-Design
 */
class Writer
{
private:
    /**
     * @brief Konsturktor<BR>
     * private da es ein Singleton ist
     */
    explicit Writer();

    /**
     * @brief Desuktor<BR>
     * private da es ein Singleton ist
     */
    ~Writer();

    /**
     * @brief Kopierkonstruktor<BR>
     * private da es ein Singleton ist
     */
    Writer(Writer const&);

    /**
     * @brief Überladener Zuweisungsoperator<BR>
     * private da es ein Singleton ist
     * @return Zugewiesene Instanz
     */
    Writer& operator=(Writer const&);

    /**
     * @brief Writer-Singleton-Instanz @see Writer
     */
    static Writer* s_pWriterInstance;

    /**
     * @brief Schreibt eine bestimmte Sprachdatenbank anhand einer Language-Instanz und deren Dateiname neu @see Language
     * @param p_langValue Language-Instanz aus der die Informationen genommen werden sollen @see Language
     * @param p_qstFileName Dateiname unter der die neue Sprachdatenbank gespeichert werden soll
     */
    void rewriteModifiedLanguageDatabase(Language *p_langValue, QString p_qstFileName);

public:
    /**
     * @brief Gibt die Writer-Singleton-Instanz zurück
     * @return Writer-Singleton-Instanz @see Writer
     */
    static Writer* INSTANCE();

    /**
     * @brief Schreibt alle Sprachdatenbanken neu<BR>
     * Ruft automatisch rewriteModifiedLanguageDatabases auf @see rewriteModifiedLanguageDatabase @see LanguageManager::INSTANCE()->getModifiedLanguageDatabases
     */
    void rewriteModifiedLanguageDatabases();

};

#endif // WRITER_H
