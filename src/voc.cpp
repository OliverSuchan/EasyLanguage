#include "voc.h"

Global::VocType Voc::getVocType()
{
    return m_ctCurVoc;
}

void Voc::setVocType(Global::VocType p_ctValue)
{
    try
    {
        m_ctCurVoc = p_ctValue;
    }
    catch(std::exception &e) {};
}

Global::LearningState Voc::getLearningState()
{
    return m_lsCurVoc;
}

void Voc::setLearningState(Global::LearningState p_lsValue)
{
    try
    {
        m_lsCurVoc = p_lsValue;
    }
    catch(std::exception &e) {}
}

void Voc::addDefinition(QString p_qstDefinition)
{
    this->m_mpqstDefinition.push_back(p_qstDefinition);
}

void Voc::addSynonym(QString p_qstSynonym)
{
    this->m_mpqstSynonym.push_back(p_qstSynonym);
}

QString Voc::getDefinition(size_t p_stIndex)
{
    if(p_stIndex < m_mpqstDefinition.size())
        return m_mpqstDefinition.at(p_stIndex);
    else
        throw std::exception();
}

QString Voc::getWord()
{
    return m_qstWord;
}

void Voc::setWord(QString p_qstValue)
{
    if(p_qstValue != "")
        m_qstWord = p_qstValue;
}

Voc::Voc()
{
}

Voc::~Voc()
{

}
