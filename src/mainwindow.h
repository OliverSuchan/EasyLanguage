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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_commandLinkButton_clicked();

    void on_comboBox_3_currentIndexChanged(const QString &arg1);

    void on_comboBox_4_currentIndexChanged(const QString &arg1);

    void onParserFinished();

    void on_commandLinkButton_3_clicked();

    void on_commandLinkButton_4_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

    void on_commandLinkButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_comboBox_5_currentIndexChanged(const QString &arg1);

    void on_comboBox_6_currentIndexChanged(const QString &arg1);

    void on_checkBox_stateChanged(int arg1);

    void on_commandLinkButton_5_clicked();

    void on_checkBox_2_stateChanged(int arg1);

    void on_listWidget_3_itemClicked(QListWidgetItem *item);

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    Trainer m_trnrCurrentTrainer;
    void stopTraining();
    void closeEvent(QCloseEvent *event);
    Voc *m_pvocCreateNewVocCache;
    Verb *m_pverbCreateNewVerbCache;

};

#endif // MAINWINDOW_H
