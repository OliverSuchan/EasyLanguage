#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QObject>
#include <QCloseEvent>
#include <QListWidgetItem>
#include <boost/lexical_cast.hpp>
#include "writer.h"
#include "translator.h"
#include "parser.h"
#include "conjugator.h"
#include "language.h"
#include "lection.h"
#include "voc.h"
#include "verb.h"

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
    void parserFinished();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_listWidget_2_itemClicked(QListWidgetItem *item);

    void on_listWidget_3_itemClicked(QListWidgetItem *item);

    void on_listWidget_4_itemClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;

     void closeEvent(QCloseEvent *event);

};

#else

class MainWindow;

#endif // MAINWINDOW_H
