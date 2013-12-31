#include "trainer.h"

void Trainer::increaseLearningState(Voc *p_pvocCurrent)
{
    if(static_cast<int>(p_pvocCurrent->getLearningState()) > static_cast<int>(Global::PERFECT))
    {
       p_pvocCurrent->setLearningState(static_cast<Global::LearningState>(static_cast<int>(p_pvocCurrent->getLearningState()) - 1));
    }
}

void Trainer::decreaseLearningState(Voc *p_pvocCurrent)
{
    if(static_cast<int>(p_pvocCurrent->getLearningState()) < static_cast<int>(Global::BAD))
    {
        p_pvocCurrent->setLearningState(static_cast<Global::LearningState>(static_cast<int>(p_pvocCurrent->getLearningState()) + 1));
    }
}

Trainer::Trainer()
{
}

void Trainer::startTraining(Language p_langValue, int p_iSizeOfVocsToLearn)
{
    m_stCurrentIndex = 0;
    std::vector<Voc*> mppvocAllVocs;
    for(size_t stLectionIndex = 0; stLectionIndex < p_langValue.getLectionListSize(); stLectionIndex++)
    {
        for(size_t stVocIndex = 0; stVocIndex < p_langValue.getLection(stLectionIndex).getVocListSize(); stVocIndex++)
        {
            mppvocAllVocs.push_back(p_langValue.getLection(stLectionIndex).getVoc(stVocIndex));
        }
    }

    for(int iCounter = 0; iCounter < p_iSizeOfVocsToLearn; iCounter++)
    {
        size_t stRandomIndex = qrand() % (mppvocAllVocs.size());
        m_mppvocVocToTrain.push_back(mppvocAllVocs.at(stRandomIndex));
    }
}

bool Trainer::isCorrect(Voc *p_pvocCurrent, QString p_qstTry)
{
    for(size_t stDefinitionIndex = 0; stDefinitionIndex < p_pvocCurrent->getDefinitionListSize(); stDefinitionIndex++)
    {
        if(p_pvocCurrent->getDefinition(stDefinitionIndex) == p_qstTry)
        {
            increaseLearningState(p_pvocCurrent);
            return true;
        }
    }
    decreaseLearningState(p_pvocCurrent);
    return false;
}

bool Trainer::hasNext()
{
    if(m_stCurrentIndex < m_mppvocVocToTrain.size() && m_stCurrentIndex >= 0)
    {
        return true;
    }
    return false;
}

Voc *Trainer::next()
{
    try
    {
        return m_mppvocVocToTrain.at(m_stCurrentIndex++);
    }
    catch(std::exception &e)
    {
        throw e;
    }
}

void Trainer::stopTraining()
{
    m_mppvocVocToTrain.clear();
    m_stCurrentIndex = -1;
}
