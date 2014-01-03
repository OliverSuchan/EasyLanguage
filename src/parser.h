#ifndef PARSER_H
#define PARSER_H

#include <QObject>
#include <QDirIterator>
#include <QDir>
#include <QString>
#include <QStringList>
#include <vector>
#include <exception>
#include <iostream>
#include <tuple>

#ifndef Q_MOC_RUN
#include "../include/boost/foreach.hpp"
#include "../include/boost/property_tree/ptree.hpp"
#include "../include/boost/property_tree/xml_parser.hpp"
#endif //Q_MOC_RUN

#include "Globals.h"
#include "conjugator.h"
#include "language.h"
#include "lection.h"
#include "voc.h"
#include "verb.h"
#include "languagemanager.h"

using boost::property_tree::ptree;

/**
 * @brief Parst alle Sprachdatenbanken und deren dazu gehörige Konjugationstabelle<BR>
 * Benutzt das Singleton-Design
 */
class Parser : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Liefert die Singleton-Instanz
     * @return Parser-Singleton-Instanz @see Parser
     */
    static Parser* INSTANCE();

    /**
     * @brief Parst alle Sprachdatenbanken in {aktuelles Verzeichnis}/languages<BR>
     * Sprachdatenbanken brauchen die Endung ".xml"<BR>
     * Sobald eine Sprachdatenbank gefunden wurde, wird nach einer Konjugationtabelle<BR>
     * mit dem Namen der Sprachdatenbank ausschau gehalten<BR>
     * Konjugationstabellen benötigen die Endung ".cjt"
     */
    void parseLanguageDatabases();

private:
    /**
     * @brief Parst eine Konjugationstabelle<BR>
     * Wird automatisch aufgerufen @see parseConjugationDataBases()
     * @param p_qstFileName Dateiname der zu parsenden Konjugationstabelle
     * @return Konjugierer der den geparsten Eigenschaften entspricht @see Conjugator
     */
    Conjugator parseConjugationDataBase(QString p_qstFileName);

    /**
     * @brief Parst eine Sprach-Datenbank<BR>
     * Wird automatischa aufgerufen @see parseConjugationDataBases()
     * @param p_qstFileName Dateiname der zu parsenden Sprach-Datenbank
     * @return Sprache die den geparsten Eigenschaften entspricht @see Language
     */
    Language *parseLanguageDataBase(QString p_qstFileName);

    /**
     * @brief Konstruktor<BR>
     * private da es ein Singleton ist
     * @param p_pqoParent Default-Parameter
     */
    explicit Parser(QObject *p_pqoParent = 0);

    /**
      * @brief Destruktor<BR>
      * private da es ein Singleton ist
      */
    ~Parser();

    /**
     * @brief Standard-Kopierkonstruktor<BR>
     * private da es ein Singleton ist
     */
    Parser(Parser const&);

    /**
     * @brief Überladener Zuweisungsoperator<BR>
     * private da es ein Singleton ist
     * @return Zugewiesene Parser-Instanz
     */
    Parser& operator=(Parser const&);

    /**
     * @brief Parser-Singleton-Instanz @see Parser
     */
    static Parser* m_pInstance;

signals:
    /**
     * @brief Signal das emittiert wird, sobald der Parser mit dem Parsen fertig ist
     */
    void onParserFinished();

};

#else

class Parser;

#endif // PARSER_H
