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

class Translator
{
private:
    explicit Translator();
    ~Translator();
    Translator(Translator const&);
    Translator& operator=(Translator const&);
    static Translator* s_pTranslatorInstance;

public:
    static Translator* INSTANCE();
    std::tuple<std::vector<QString>, std::vector<QString>> translate(Language p_langValue, QString p_qstWord);
    std::vector<QString> translate(Language p_langValueFrom, Language p_langValueInto, QString p_qstWord);
    QString getDefinition(std::tuple<std::vector<QString>, std::vector<QString>> p_tplmpqstWordInformations, size_t p_stIndex);
    size_t getDefinitionListSize(std::tuple<std::vector<QString>, std::vector<QString>> p_tplmpqstWordInformations);
    QString getSynonym(std::tuple<std::vector<QString>, std::vector<QString>> p_tplmpqstWordInformations, size_t p_stIndex);
    size_t getSynonymListSize(std::tuple<std::vector<QString>, std::vector<QString>> p_tplmpqstWordInformations);

};

#endif // TRANSLATOR_H
