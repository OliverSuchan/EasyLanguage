#ifndef TRAINER_H
#define TRAINER_H

#include <iostream>
#include <vector>
#include <tuple>
#include "Globals.h"
#include "language.h"
#include "lection.h"
#include "voc.h"

class Trainer
{
private:
    std::vector<Voc*> m_mppvocVocToTrain;
    size_t m_stCurrentIndex;
    void increaseLearningState(Voc *p_pvocCurrent);
    void decreaseLearningState(Voc *p_pvocCurrent);
    Voc *m_pvocCurrentVoc;

public:
    Trainer();
    void startTraining(Language *p_langValue, int p_iSizeOfVocsToLearn);
    void startTraining(Lection *p_lectLectionToTrain, int p_iSizeOfVocsToLearn);
    bool isCorrect(Voc *p_pvocCurrent, QString p_qstTry);
    bool hasNext();
    Voc* next();
    void stopTraining();
    Voc *getCurrentVoc() const;
};

#endif // TRAINER_H
