#include "translator.h"

Translator *Translator::s_pTranslatorInstance = new Translator;

Translator::Translator()
{
}

Translator::~Translator()
{

}

Translator::Translator(const Translator &)
{

}

Translator &Translator::operator=(const Translator &)
{
    return *s_pTranslatorInstance;
}

Translator *Translator::INSTANCE()
{
    if(!s_pTranslatorInstance) s_pTranslatorInstance = new Translator;
    assert(s_pTranslatorInstance != NULL);
    return s_pTranslatorInstance;
}

std::tuple<std::vector<QString>, std::vector<QString> > Translator::translate(Language *p_langValue, QString p_qstWord)
{
    std::tuple<std::vector<QString>, std::vector<QString>> tplmpqstWordInformations = std::make_tuple(std::vector<QString>(), std::vector<QString>());
    for(size_t stIndexLection = 0; stIndexLection < p_langValue->getLectionListSize(); stIndexLection++)
    {
        Lection *lectCurrent = new Lection;
        lectCurrent = p_langValue->getLection(stIndexLection);
        for(size_t stIndexVoc = 0; stIndexVoc < lectCurrent->getVocListSize(); stIndexVoc++)
        {
            Voc *vocCurrent = lectCurrent->getVoc(stIndexVoc);
            if(vocCurrent->getWord().toUpper() == p_qstWord.toUpper())
            {
                for(size_t stIndexDefinition = 0; stIndexDefinition < vocCurrent->getDefinitionListSize(); stIndexDefinition++)
                {
                    std::get<0>(tplmpqstWordInformations).push_back(vocCurrent->getDefinition(stIndexDefinition));
                }
                for(size_t stIndexSynonym = 0; stIndexSynonym < vocCurrent->getSynonymListSize(); stIndexSynonym++)
                {
                    std::get<1>(tplmpqstWordInformations).push_back(vocCurrent->getSynonym(stIndexSynonym));
                }
                return tplmpqstWordInformations;
            }
        }
    }
    throw std::exception();
}

std::vector<QString> Translator::translate(Language *p_langValueFrom, Language *p_langValueInto, QString p_qstWord)
{
    std::tuple<std::vector<QString>, std::vector<QString>> tplmpqstFirstLanguage = translate(p_langValueFrom, p_qstWord);
    std::vector<QString> mpqstTranslation;
    for(size_t stIndexLection = 0; stIndexLection < p_langValueInto->getLectionListSize(); stIndexLection++)
    {
        Lection *lectCurrent = new Lection;
        lectCurrent = p_langValueInto->getLection(stIndexLection);
        for(size_t stIndexVoc = 0; stIndexVoc < lectCurrent->getVocListSize(); stIndexVoc++)
        {
            Voc *vocCurrent = lectCurrent->getVoc(stIndexVoc);
            for(size_t stIndexDefinition = 0; stIndexDefinition < vocCurrent->getDefinitionListSize(); stIndexDefinition++)
            {
                for(size_t stIndexDefinition_1 = 0; stIndexDefinition_1 < getDefinitionListSize(tplmpqstFirstLanguage); stIndexDefinition_1++)
                {
                    if(getDefinition(tplmpqstFirstLanguage, stIndexDefinition_1).toUpper() == vocCurrent->getDefinition(stIndexDefinition).toUpper())
                    {
                        mpqstTranslation.push_back(vocCurrent->getWord());
                    }
                }
            }
            if(mpqstTranslation.size() != 0)
                return mpqstTranslation;
        }
    }
    throw std::exception();
}

QString Translator::getDefinition(std::tuple<std::vector<QString>, std::vector<QString> > p_tplmpqstWordInformations, size_t p_stIndex)
{
    if(p_stIndex < std::get<0>(p_tplmpqstWordInformations).size())
        return std::get<0>(p_tplmpqstWordInformations).at(p_stIndex);
    throw std::exception();
}

size_t Translator::getDefinitionListSize(std::tuple<std::vector<QString>, std::vector<QString> > p_tplmpqstWordInformations)
{
    return std::get<0>(p_tplmpqstWordInformations).size();
}

QString Translator::getSynonym(std::tuple<std::vector<QString>, std::vector<QString> > p_tplmpqstWordInformations, size_t p_stIndex)
{
    if(p_stIndex < std::get<1>(p_tplmpqstWordInformations).size())
        return std::get<1>(p_tplmpqstWordInformations).at(p_stIndex);
    throw std::exception();
}

size_t Translator::getSynonymListSize(std::tuple<std::vector<QString>, std::vector<QString> > p_tplmpqstWordInformations)
{
    return std::get<1>(p_tplmpqstWordInformations).size();
}
