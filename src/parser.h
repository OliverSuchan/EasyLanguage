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

class Parser : public QObject
{
    Q_OBJECT

public:
    static Parser* INSTANCE();
    void parseLanguageDatabases();

private:
    Conjugator parseConjugationDataBase(QString p_qstFileName);
    Language *parseLanguageDataBase(QString p_qstFileName);
    explicit Parser(QObject *p_pqoParent = 0);
    ~Parser();
    Parser(Parser const&);
    Parser& operator=(Parser const&);
    static Parser* m_pInstance;

signals:
    void onParserFinished();

};

#else

class Parser;

#endif // PARSER_H
