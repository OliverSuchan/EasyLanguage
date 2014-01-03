#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QMainWindow>
#include <QListWidgetItem>
#include <QCloseEvent>
#include <QMessageBox>
#include <QStringList>
#include <iostream>
#include "parser.h"
#include "languagemanager.h"
#include "trainer.h"
#include "writer.h"
#include "translator.h"

namespace Ui {
class MainWindow;
}

/**
 * @brief Die GUI
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor
     * @param parent Default-Parameter
     */
    explicit MainWindow(QWidget *parent = 0);

    /**
      * Destruktor
      */
    ~MainWindow();

private slots:

    /**
     * @brief Auszuführende Aktion nach dem Klicken auf den "Training beginnen"-Button
     */
    void on_commandLinkButton_clicked();

    /**
     * @brief Aktion die ausgeführt wird, wenn der Index der ersten ComboBox im "Trainer"-Tab geändert wird
     * @param arg1 Neuausgewähltes Element der ComboBox
     */
    void on_comboBox_3_currentIndexChanged(const QString &arg1);

    /**
     * @brief  Aktion die ausgeführt wird, wenn der Index der zweiten ComboBox im "Trainer"-Tab geändert wird
     * @param arg1 Neuausgewähltes Element der ComboBox
     */
    void on_comboBox_4_currentIndexChanged(const QString &arg1);

    /**
     * @brief Aktion die ausgeführt wird, sobald der Parser mit dem Parsen der Sprachdatenbanken fertig ist @see Parser
     */
    void onParserFinished();

    /**
     * @brief Aktion die ausgeführt wird, wenn der "Training beenden"-Button geklickt wurde
     */
    void on_commandLinkButton_3_clicked();

    /**
     * @brief Aktion die ausgeführt wird, wenn der "Überprüfen"-Button geklickt wurde
     */
    void on_commandLinkButton_4_clicked();

    /**
     * @brief Aktion die ausgeführt wird, wenn der Index der ersten ComboBox im "Übersetzer"-Tab geändert wird
     * @param arg1 Neuausgewähltes Element der ComboBox
     */
    void on_comboBox_currentIndexChanged(const QString &arg1);

    /**
     * @brief Aktion die ausgeführt wird, wenn der Index der zweiten ComboBox im "Übersetzer"-Tab geändert wird
     * @param arg1 Neuausgewähltes Element der ComboBox
     */
    void on_comboBox_2_currentIndexChanged(const QString &arg1);

    /**
     * @brief Aktion die ausgeführt wird, wenn der "Übersetzen"-Button geklickt wurde
     */
    void on_commandLinkButton_2_clicked();

    /**
     * @brief Aktion die ausgeführt wird, wenn der "Definitionen"-Button geklickt wurde
     */
    void on_pushButton_clicked();

    /**
     * @brief Aktion die ausgeführt wird, wenn der "Synonyme"-Button geklickt wurde
     */
    void on_pushButton_3_clicked();

    /**
     * @brief Aktion die ausgeführt wird, wenn der Index der ersten ComboBox im "Vokabel-Manager;Wort hinzufügen"-Tab geändert wird
     * @param arg1 Neuausgewähltes Element der ComboBox
     */
    void on_comboBox_5_currentIndexChanged(const QString &arg1);

    /**
     * @brief Aktion die ausgeführt wird, wenn der Index der zweiten ComboBox im "Vokabel-Manager;Wort hinzufügen"-Tab geändert wird
     * @param arg1 Neuausgewähltes Element der ComboBox
     */
    void on_comboBox_6_currentIndexChanged(const QString &arg1);

    /**
     * @brief Aktion die ausgeführt wird, wenn der Status der Checkbox "Verb" geändert wird
     * @param arg1 CheckBox-Status
     */
    void on_checkBox_stateChanged(int arg1);

    /**
     * @brief Aktion die ausgeführt wird, wenn der "Vokabel Hinzufügen"-Button geklickt wurde
     */
    void on_commandLinkButton_5_clicked();

    /**
     * @brief Aktion die ausgeführt wird, wenn der Status der Checkbox "Regelmäßig" geändert wird
     * @param arg1 CheckBox-Status
     */
    void on_checkBox_2_stateChanged(int arg1);

    /**
     * @brief Aktion die ausgeführt wird, wenn ein Element des QListWidgets im "Vokabel-Manager; Verb-Einstellungen"-Tab geklickt wird
     * @param item Das geklickte Item
     */
    void on_listWidget_3_itemClicked(QListWidgetItem *item);

    /**
     * @brief Aktion die ausgeführt wird, wenn der "Fertig"-Button geklickt wurde
     */
    void on_pushButton_4_clicked();

    /**
     * @brief Aktion die ausgeführt wird, wenn der "Lektion Hinzufügen"-Button geklickt wurde
     */
    void on_commandLinkButton_6_clicked();

    /**
     * @brief Aktion die ausgeführt wird, wenn der Index der ersten ComboBox im "Vokabel-Manager;Lektion hinzufügen"-Tab geändert wird
     * @param arg1 Neuausgewähltes Element der ComboBox
     */
    void on_comboBox_7_currentIndexChanged(const QString &arg1);

private:
    /**
     * @brief Die GUI
     */
    Ui::MainWindow *ui;

    /**
     * @brief Der Trainer zum Trainieren von Vokabeln
     */
    Trainer m_trnrCurrentTrainer;

    /**
     * @brief Stoppt den Trainer und führt Änderungen an der GUI aus
     */
    void stopTraining();

    /**
     * @brief Aktion die ausgeführt wird, wenn das Programm geschlossen werden soll
     * @param event Das Schließen-Ereignis
     */
    void closeEvent(QCloseEvent *event);

    /**
     * @brief Vokabel zum Zwischenspeichern<BR>
     * Wird für "Wort hinzufügen" benötigt
     */
    Voc *m_pvocCreateNewVocCache;

    /**
     * @brief Verb zum Zwischenspeichern<BR>
     * Wird für "Wort hinzufügen" benötigt
     */
    Verb *m_pverbCreateNewVerbCache;

};

#endif // MAINWINDOW_H
