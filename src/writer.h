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

class Writer
{
private:
    explicit Writer();
    ~Writer();
    Writer(Writer const&);
    Writer& operator=(Writer const&);
    static Writer* s_pWriterInstance;
    void rewriteModifiedLanguageDatabase(Language p_langValue, QString p_qstFileName);

public:
    static Writer* INSTANCE();
    void rewriteModifiedLanguageDatabases();

};

#endif // WRITER_H
