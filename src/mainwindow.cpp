#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->removeTab(1);
    ui->tabWidget_2->removeTab(1);
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget_2->setCurrentIndex(0);
    ui->pushButton->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->statusBar->showMessage("Lade Sprach-Datenbanken...");
    QObject::connect(Parser::INSTANCE(), SIGNAL(onParserFinished()), this, SLOT(onParserFinished()));
    Parser::INSTANCE()->parseLanguageDatabases();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_commandLinkButton_clicked()
{
    ui->tabWidget->insertTab(1, ui->tab_6, "Training");
    ui->tabWidget->removeTab(0);
    ui->statusBar->showMessage("Training wurde gestartet.");
    if(ui->comboBox_3->currentText() != "Alle")
        m_trnrCurrentTrainer.startTraining(LanguageManager::INSTANCE()->getLanguage(ui->comboBox_3->currentText())->getLection(ui->comboBox_3->itemData(ui->comboBox_3->currentIndex()).toInt()), 10);
    else
        m_trnrCurrentTrainer.startTraining(LanguageManager::INSTANCE()->getLanguage(ui->comboBox_3->currentText()), 10);

    if(m_trnrCurrentTrainer.hasNext())
    {
        Voc *pvocNextVoc = m_trnrCurrentTrainer.next();
        if(pvocNextVoc->getVocType() == Global::WORD)
            ui->label_9->setText(pvocNextVoc->getWord());
        else
            ui->label_9->setText(dynamic_cast<Verb*>(pvocNextVoc)->getOnlyVerb());
    }
}

void MainWindow::on_comboBox_3_currentIndexChanged(const QString &arg1)
{
    ui->comboBox_4->clear();
    for(size_t stIndex = 0; stIndex < LanguageManager::INSTANCE()->getLanguage(arg1)->getLectionListSize(); stIndex++)
    {
        ui->comboBox_4->addItem(QString::number(LanguageManager::INSTANCE()->getLanguage(arg1)->getLection(stIndex)->getLectionNumber()), QVariant(stIndex));
    }
    ui->comboBox_4->addItem("Alle");
    if(ui->comboBox_4->count() > 0)
        ui->comboBox_4->setEnabled(true);
}

void MainWindow::on_comboBox_4_currentIndexChanged(const QString &arg1)
{
    ui->commandLinkButton->setEnabled(true);
}

void MainWindow::onParserFinished()
{
    ui->statusBar->clearMessage();
    for(size_t stIndex = 0; stIndex < LanguageManager::INSTANCE()->getLanguageListSize(); stIndex++)
    {
        ui->comboBox->addItem(LanguageManager::INSTANCE()->getLanguage(stIndex)->getLanguageName());
        ui->comboBox_3->addItem(LanguageManager::INSTANCE()->getLanguage(stIndex)->getLanguageName());
        ui->comboBox_5->addItem(LanguageManager::INSTANCE()->getLanguage(stIndex)->getLanguageName());
    }
    ui->tabWidget->setEnabled(true);
}

void MainWindow::on_commandLinkButton_3_clicked()
{
    stopTraining();
}

void MainWindow::on_commandLinkButton_4_clicked()
{
    bool bIsCorrect = m_trnrCurrentTrainer.isCorrect(m_trnrCurrentTrainer.getCurrentVoc(), ui->lineEdit_5->text());
    if(bIsCorrect)
        ui->statusBar->showMessage("Die Eingabe war richtig. (+1)");
    else
        ui->statusBar->showMessage("Die Eingabe war falsch. (-1)");

    if(m_trnrCurrentTrainer.hasNext())
    {
        Voc *pvocNextVoc = m_trnrCurrentTrainer.next();
        if(pvocNextVoc->getVocType() == Global::WORD)
            ui->label_9->setText(pvocNextVoc->getWord());
        else
            ui->label_9->setText(dynamic_cast<Verb*>(pvocNextVoc)->getOnlyVerb());
    }
    else
    {
        QMessageBox::information(this, "Training vorbei", tr("Das Training ist nun vorbei und wird beendet\n"));
        stopTraining();
    }
}

void MainWindow::stopTraining()
{
    m_trnrCurrentTrainer.stopTraining();
    ui->tabWidget->insertTab(0, ui->tab, "Trainer");
    ui->tabWidget->removeTab(1);
    ui->statusBar->showMessage("Training wurde beendet.");
    ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::closeEvent (QCloseEvent *event)
{
    if(LanguageManager::INSTANCE()->languagesGotModified())
    {
        QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Änderungen",
                                                                    tr("Es wurden Änderungen an den Sprach-Datenbanken festgestellt, wollen Sie sie speichern?\n"),
                                                                    QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                                    QMessageBox::Yes);

        if (resBtn == QMessageBox::Yes) {
            Writer::INSTANCE()->rewriteModifiedLanguageDatabases();
        } else {
            event->accept();
        }
    }
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    ui->comboBox_2->clear();
    for(size_t stLanguageIndex = 0; stLanguageIndex < LanguageManager::INSTANCE()->getLanguageListSize(); stLanguageIndex++)
    {
        if(LanguageManager::INSTANCE()->getLanguage(arg1)->getLanguageName() != LanguageManager::INSTANCE()->getLanguage(stLanguageIndex)->getLanguageName())
            ui->comboBox_2->addItem(LanguageManager::INSTANCE()->getLanguage(stLanguageIndex)->getLanguageName());
    }
    ui->comboBox_2->addItem("Deutsch");
    ui->comboBox_2->setEnabled(true);
}

void MainWindow::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    ui->lineEdit_2->setEnabled(true);
    ui->commandLinkButton_2->setEnabled(true);
}

void MainWindow::on_commandLinkButton_2_clicked()
{
    if(ui->lineEdit_2->text() != "")
    {
        ui->listWidget->clear();
        ui->listWidget_2->clear();
        ui->pushButton->setVisible(true);
        if(ui->comboBox_2->currentText() == "Deutsch")
        {
            std::tuple<std::vector<QString>, std::vector<QString>> tplmpqstWordInformations = Translator::INSTANCE()->translate(LanguageManager::INSTANCE()->getLanguage(ui->comboBox->currentText()), ui->lineEdit_2->text());
            for(size_t stDefinitionIndex = 0; stDefinitionIndex < Translator::INSTANCE()->getDefinitionListSize(tplmpqstWordInformations); stDefinitionIndex++)
            {
                ui->listWidget->addItem(Translator::INSTANCE()->getDefinition(tplmpqstWordInformations, stDefinitionIndex));
            }
            for(size_t stSynonymIndex = 0; stSynonymIndex < Translator::INSTANCE()->getSynonymListSize(tplmpqstWordInformations); stSynonymIndex++)
            {
                ui->listWidget_2->addItem(Translator::INSTANCE()->getSynonym(tplmpqstWordInformations, stSynonymIndex));
            }
            ui->pushButton_3->setVisible(true);
        }
        else
        {
            std::vector<QString> tplmpqstWordInformations = Translator::INSTANCE()->translate(LanguageManager::INSTANCE()->getLanguage(ui->comboBox->currentText()), LanguageManager::INSTANCE()->getLanguage(ui->comboBox_2->currentText()), ui->lineEdit_2->text());
            for(size_t stDefinitionIndex = 0; stDefinitionIndex < tplmpqstWordInformations.size(); stDefinitionIndex++)
            {
                ui->listWidget->addItem(tplmpqstWordInformations.at(stDefinitionIndex));
            }
            ui->pushButton_3->setVisible(false);
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_comboBox_5_currentIndexChanged(const QString &arg1)
{
    m_pvocCreateNewVocCache = new Verb();
    m_pverbCreateNewVerbCache = new Verb();
    ui->label_4->setText(arg1 + ":");
    ui->comboBox_6->clear();
    for(size_t stLectionIndex = 0; stLectionIndex  < LanguageManager::INSTANCE()->getLanguage(arg1)->getLectionListSize(); stLectionIndex++)
    {
        ui->comboBox_6->addItem(QString::number(LanguageManager::INSTANCE()->getLanguage(arg1)->getLection(stLectionIndex)->getLectionNumber()), QVariant(stLectionIndex));
    }
    ui->comboBox_6->setEnabled(true);
}

void MainWindow::on_comboBox_6_currentIndexChanged(const QString &arg1)
{
    ui->lineEdit->setEnabled(true);
    ui->lineEdit_3->setEnabled(true);
    ui->lineEdit_6->setEnabled(true);
    ui->commandLinkButton_5->setEnabled(true);
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    m_pvocCreateNewVocCache->setVocType(static_cast<Global::VocType>(arg1 - 1));
    m_pvocCreateNewVocCache->setLearningState(Global::BAD);
    if(arg1)
    {
        ui->tabWidget_2->insertTab(1, ui->tab_7, "Verb-Einstellungen");
        ui->tabWidget_2->setCurrentIndex(1);
        m_pverbCreateNewVerbCache = dynamic_cast<Verb*>(m_pvocCreateNewVocCache);
    }
    else
    {
        ui->tabWidget_2->removeTab(1);
        ui->tabWidget_2->setCurrentIndex(0);
    }
}

void MainWindow::on_commandLinkButton_5_clicked()
{   if(ui->lineEdit->text() == "" || ui->lineEdit_3->text() == "")
    {
        ui->statusBar->showMessage("Bitte füllen Sie alle Felder aus.");
        return;
    }

    if(ui->checkBox->checkState() == Qt::Checked && (ui->lineEdit_7->text() == "" || ui->lineEdit_8->text() == ""))
    {
        ui->statusBar->showMessage("Bitte füllen Sie alle Felder aus.");
        return;
    }

    QStringList mpqstDefinitions = ui->lineEdit->text().split(";");
    for(size_t stDefinitionIndex = 0; stDefinitionIndex < mpqstDefinitions.size(); stDefinitionIndex++)
    {
        if(mpqstDefinitions.at(stDefinitionIndex) != "")
        {
            if(ui->checkBox->checkState() == Qt::Checked) m_pverbCreateNewVerbCache->addDefinition(mpqstDefinitions.at(stDefinitionIndex));
            else m_pvocCreateNewVocCache->addDefinition(mpqstDefinitions.at(stDefinitionIndex));
        }
    }

    QStringList mpqstSynonyms = ui->lineEdit_6->text().split(";");
    for(size_t stSynonymIndex = 0; stSynonymIndex < mpqstSynonyms.size(); stSynonymIndex++)
    {
        if(mpqstSynonyms.at(stSynonymIndex) != "")
        {
            if(ui->checkBox->checkState() == Qt::Checked) m_pverbCreateNewVerbCache->addSynonym(mpqstSynonyms.at(stSynonymIndex));
            else m_pvocCreateNewVocCache->addSynonym(mpqstSynonyms.at(stSynonymIndex));
        }
    }
    Language *langCur = LanguageManager::INSTANCE()->getLanguage(ui->comboBox_5->currentText());
    Lection *lectCur = langCur->getLection(ui->comboBox_6->itemData(ui->comboBox_6->currentIndex()).toInt());
    if(ui->checkBox->checkState() == Qt::Checked)
    {
        lectCur->addVoc(m_pverbCreateNewVerbCache);
    }
    else
    {
        m_pvocCreateNewVocCache->setWord(ui->lineEdit_6->text());
        lectCur->addVoc(m_pvocCreateNewVocCache);
    }
}

void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    ui->listWidget_3->clear();
    if(arg1)
    {
        m_pverbCreateNewVerbCache->setVerbType(Global::REGULAR);
    }
    else
    {
        m_pverbCreateNewVerbCache->setVerbType(Global::IRREGULAR);
    }
    ui->checkBox_3->setVisible(!arg1);
    Language *langCurrent = LanguageManager::INSTANCE()->getLanguage(ui->comboBox_5->currentIndex());
    for(size_t stPronounIndex = 0; stPronounIndex < langCurrent->getLanguageConjugator().getPronounListSize(); stPronounIndex++)
    {
        QListWidgetItem *qlwiCurrentPronoun = new QListWidgetItem;
        qlwiCurrentPronoun->setData(Qt::UserRole, QVariant(QString::number(langCurrent->getLanguageConjugator().getIsSingular(stPronounIndex))));
        qlwiCurrentPronoun->setText(langCurrent->getLanguageConjugator().getPronoun(stPronounIndex));
        ui->listWidget_3->addItem(qlwiCurrentPronoun);
    }
    if(ui->lineEdit_7->text() == "" || ui->lineEdit_8->text() == "")
        ui->statusBar->showMessage("Wortstamm- oder Wortendung-Feld leer.");
    else
    {
        ui->statusBar->showMessage("Automatisch konjugiert. Bitte auf Fehler prüfen");
    }
    m_pverbCreateNewVerbCache->setWordRoot(ui->lineEdit_7->text());
    m_pverbCreateNewVerbCache->setWordPostFix(ui->lineEdit_8->text());
    m_pverbCreateNewVerbCache->setWord(ui->lineEdit_7->text() + ";" + ((ui->lineEdit_7->text() == "") ? ("[x]") : (ui->lineEdit_8->text())));
}

void MainWindow::on_listWidget_3_itemClicked(QListWidgetItem *item)
{
    Language *langCurrent = LanguageManager::INSTANCE()->getLanguage(ui->comboBox_5->currentIndex());
    ui->label_13->setText((item->data(Qt::UserRole).toString() == "1") ? ("Ja") : ("Nein"));
    ui->lineEdit_9->setText(langCurrent->getLanguageConjugator().conjugate(item->text(), *m_pverbCreateNewVerbCache, item->data(Qt::UserRole).toBool()));
}

void MainWindow::on_pushButton_4_clicked()
{
    try
    {
        if(ui->checkBox_3->checkState() == Qt::Checked && ui->listWidget_3->currentIndex().row() > -1)
        {
            m_pverbCreateNewVerbCache->addIrregularPerson(ui->listWidget_3->currentItem()->text(), ui->lineEdit_9->text(), ui->listWidget_3->currentItem()->data(Qt::UserRole).toBool());
        }
    }
    catch(std::exception &e) { std::cerr << e.what() << std::endl;}
}
