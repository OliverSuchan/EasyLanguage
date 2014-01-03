#ifndef TRAINER_H
#define TRAINER_H

#include <iostream>
#include <vector>
#include <tuple>
#include "Globals.h"
#include "language.h"
#include "lection.h"
#include "voc.h"

/**
 * @brief Trainiert die Vokabeln
 */
class Trainer
{
private:
    /**
     * @brief Vektor bestehend aus Vokabeln die trainiert werden sollen<BR>
     * Wird random generiert @see Voc
     */
    std::vector<Voc*> m_mppvocVocToTrain;

    /**
     * @brief Das Index an dem sich das Trainier aktuell befinden @see hasNext @see next
     */
    size_t m_stCurrentIndex;

    /**
     * @brief Wird aufgerufen sobald der Nutzer eine Vokabel richtig hat
     * @param p_pvocCurrent Vokabel bei der der Lernstatus verbessert werden soll @see Voc
     */
    void increaseLearningState(Voc *p_pvocCurrent);

    /**
     * @brief Word aufgerufen sobald der Nutzer eine Vokabel falsch hat
     * @param p_pvocCurrent Vokabel bei der der Lernstatus verschlechtert werden soll @see Voc
     */
    void decreaseLearningState(Voc *p_pvocCurrent);

    /**
     * @brief Die aktuelle Vokabel die trainiert wird @see hasNext @see next @see Voc
     */
    Voc *m_pvocCurrentVoc;

public:
    /**
     * @brief Standard-Konstruktor um eine Trainer-Instanz zu erzeugen
     */
    Trainer();

    /**
     * @brief Standard-Destruktor um eine Trainer-Instanz vollständig zu zerstören
     */
    ~Trainer();

    /**
     * @brief Startet das Training<BR>
     * Es wird aus allen Vokabeln einer Sprache eine bestimmte Anzahl an Vokabeln<BR>
     * per Zufall ausgewählt und in eine Liste gespeichert @see m_mppvocVocToTrain
     * @param p_plangValue Sprache aus der die Vokabeln genommen werden sollen @see Language
     * @param p_iSizeOfVocsToLearn Anzahl der Vokabeln die gelernt werden sollen
     */
    void startTraining(Language *p_plangValue, int p_iSizeOfVocsToLearn);

    /**
     * @brief Startet das Training<BR>
     * Es wird aus allen Vokabeln einer Lektion eine bestimmte Anzahl an Vokabeln<BR>
     * per Zufall ausgewäht und in eine Liste gespeichert @see m_mppvocVocToTrain
     * @param p_plectLectionToTrain Lektion aus der die Vokabeln genommen werden sollen @see Lection
     * @param p_iSizeOfVocsToLearn Anzahl der Vokabeln die gelernt werden sollen
     */
    void startTraining(Lection *p_plectLectionToTrain, int p_iSizeOfVocsToLearn);

    /**
     * @brief Überprüft ob die getätigte Eingabe richtig ist<BR>
     * Wenn korrekt, wird automatisch der Lernstatus verbessert<BR>
     * Wenn falsch, wird automatisch der Lernstatus verschlechter @see increaseLearningState @see decreaseLearningState
     * @param p_pvocCurrent Vokabel die überprüft werden soll @see Voc
     * @param p_qstTry Getätigte Eingabe die überprüft werden soll
     * @return Boolean das aussagt, ob die Eingabe richtig, oder falsch war
     */
    bool isCorrect(Voc *p_pvocCurrent, QString p_qstTry);

    /**
     * @brief Überprüft ob der Trainer weitere Vokabeln zum Trainieren besitzt @see m_mppvocVocToTrain
     * @return Boolean das angibt, ob es weitere zu trainierende Vokabeln gibt
     */
    bool hasNext();

    /**
     * @brief Liefert die nächste Vokabel die trainiert wird<BR>
     * Zähler wird automatisch hochgesetzt @see m_stCurrentIndex
     * @return Nächste Vokabel @see Voc
     * @throws std::exception
     */
    Voc* next();

    /**
     * @brief Wählt von allen Definitionen einer Vokabel<BR>
     * eine per Zufall aus
     * @param p_vpocCurrent Vokabel auf die die Aktion angewendet werden soll @see Voc
     * @return Zufälliger Definition der Vokabel
     * @throws std::exception
     */
    QString getRandomDefintion(Voc *p_vpocCurrent);

    /**
     * @brief Stoppt das Training und löscht alle Elemente in der Vokabel-Liste @see m_mppvocVocToTrain
     */
    void stopTraining();

    /**
     * @brief Gibt die aktuell zu trainierende Vokabel zurück
     * @return Aktuelle Vokabel @see Voc
     */
    Voc *getCurrentVoc() const;
};

#endif // TRAINER_H
