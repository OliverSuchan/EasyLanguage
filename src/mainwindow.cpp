#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(Parser::instance(), SIGNAL(onParserFinished()), this, SLOT(parserFinished()));
    Parser::instance()->parseLanguageDatabases();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::on_pushButton_clicked()
//{
//    for(size_t stIndex = 0; stIndex < LanguageManager::INSTANCE()->getLanguageListSize(); stIndex++)
//    {
//        Language langCur = LanguageManager::INSTANCE()->getLanguage(stIndex);
//        std::cout << langCur.getLanguageName().toStdString() << std::endl;
//        std::cout << "------------------------------------------------" << std::endl;
//        for(size_t stIndex_1 = 0; stIndex_1 < langCur.getLectionListSize(); stIndex_1++)
//        {
//            Lection lectCur = langCur.getLection(stIndex_1);
//            std::cout << "Lektionsnummer: " << QString::number(lectCur.getLectionNumber()).toStdString() << std::endl;
//            std::cout << "------------------------------------------------" << std::endl;
//            for(size_t stIndex_2 = 0; stIndex_2 < lectCur.getVocListSize(); stIndex_2++)
//            {
//                Voc *vocCur = new Verb;
//                vocCur = lectCur.getVoc(stIndex_2);
//                if(vocCur->getVocType() == Global::VERB)
//                {
//                    Verb *verbCur = dynamic_cast<Verb*>(vocCur);
//                    for(size_t stIndex_3 = 0; stIndex_3 < langCur.getLanguageConjugator().getPronounListSize(); stIndex_3++)
//                        std::cout << verbCur->getWord().toStdString() << " -> " << "Yo :" << langCur.getLanguageConjugator().conjugate(verbCur->getWordPostFix(), langCur.getLanguageConjugator().getPronoun(stIndex_3), verbCur->getWordRoot()).toStdString() << std::endl;
//                }
//            }
//            std::cout << "------------------------------------------------" << std::endl;
//        }
//        std::cout << "------------------------------------------------" << std::endl;
//    }
//}

void MainWindow::parserFinished()
{
    std::cout << "Finished" << std::endl;
    for(size_t stIndex = 0; stIndex < LanguageManager::INSTANCE()->getLanguageListSize(); stIndex++)
    {
        Language langCur = LanguageManager::INSTANCE()->getLanguage(stIndex);
        ui->listWidget->addItem(langCur.getLanguageName());
    }
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    ui->listWidget_2->clear();
    for(size_t stIndex = 0; stIndex < LanguageManager::INSTANCE()->getLanguageListSize(); stIndex++)
    {
        Language langCur = LanguageManager::INSTANCE()->getLanguage(stIndex);
        if(item->text() == langCur.getLanguageName())
        {
            for(size_t stIndex_1 = 0; stIndex_1 < langCur.getLectionListSize(); stIndex_1++)
            {
                ui->listWidget_2->addItem(QString::number(langCur.getLection(stIndex_1).getLectionNumber()));
            }
            return;
        }
    }
}

void MainWindow::on_listWidget_2_itemClicked(QListWidgetItem *item)
{
    ui->listWidget_3->clear();
    for(size_t stIndex = 0; stIndex < LanguageManager::INSTANCE()->getLanguageListSize(); stIndex++)
    {
        Language langCur = LanguageManager::INSTANCE()->getLanguage(stIndex);
        if(ui->listWidget->selectedItems()[0]->text() == langCur.getLanguageName())
        {
            for(size_t stIndex_1 = 0; stIndex_1 < langCur.getLectionListSize(); stIndex_1++)
            {
                Lection lectCur = langCur.getLection(stIndex_1);
                if(lectCur.getLectionNumber() == item->text().toInt())
                {
                    for(size_t stIndex_2 = 0; stIndex_2 < lectCur.getVocListSize(); stIndex_2++)
                    {
                        ui->listWidget_3->addItem(lectCur.getVoc(stIndex_2)->getWord());
                    }
                }
            }
            return;
        }
    }
}

void MainWindow::on_listWidget_3_itemClicked(QListWidgetItem *item)
{
    ui->listWidget_4->clear();
    for(size_t stIndex = 0; stIndex < LanguageManager::INSTANCE()->getLanguageListSize(); stIndex++)
    {
        Language langCur = LanguageManager::INSTANCE()->getLanguage(stIndex);
        if(ui->listWidget->selectedItems()[0]->text() == langCur.getLanguageName())
        {
            Conjugator cjCur = langCur.getLanguageConjugator();
            for(size_t stIndex_1 = 0; stIndex_1 < cjCur.getPronounListSize(); stIndex_1++)
            {
                ui->listWidget_4->addItem(cjCur.getPronoun(stIndex_1) + "|" + QString::number(cjCur.getIsSingular(stIndex_1)));
            }
            return;
        }
    }
}

void MainWindow::on_listWidget_4_itemClicked(QListWidgetItem *item)
{
    Language langCur = LanguageManager::INSTANCE()->getLanguage(ui->listWidget->selectedItems()[0]->text());
    for(size_t stIndex_1 = 0; stIndex_1 < langCur.getLectionListSize(); stIndex_1++)
    {
        Lection lectCur = langCur.getLection(stIndex_1);
        if(QString::number(lectCur.getLectionNumber()) == ui->listWidget_2->selectedItems()[0]->text())
        {
            for(size_t stIndex_2 = 0; stIndex_2 < lectCur.getVocListSize(); stIndex_2++)
            {
                Verb *pverbCur = dynamic_cast<Verb*>(lectCur.getVoc(stIndex_2));
                if(pverbCur->getWord() == ui->listWidget_3->selectedItems()[0]->text())
                {
                    if(pverbCur->getVocType() == Global::VERB)
                    {
                        QStringList verbShit = item->text().split("|");
                        bool bBool = boost::lexical_cast<bool>(verbShit[1].toStdString());
                        QString qstVerbConjugation = langCur.getLanguageConjugator().conjugate(verbShit[0], *pverbCur, bBool);
                        ui->label->setText("Konjugation: " + qstVerbConjugation);
                        ui->label_2->setText("Wortstamm: " + pverbCur->getWordRoot());
                        ui->label_3->setText("Wortendung: " + pverbCur->getWordPostFix());
                    }
                    ui->label_4->setText("Bedeutung: " + pverbCur->getDefinition(0));
                    return;
                }
            }
        }
    }
}

void MainWindow::closeEvent (QCloseEvent *event)
{
    if(LanguageManager::INSTANCE()->languagesGotModified())
    {
        QMessageBox::StandardButton resBtn = QMessageBox::question( this, "APP_NAME",
                                                                    tr("Neu schreiben?\n"),
                                                                    QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                                    QMessageBox::Yes);

        if (resBtn == QMessageBox::Yes) {
            Writer::INSTANCE()->rewriteModifiedLanguageDatabases();
        } else {
            event->accept();
        }
    }
}
