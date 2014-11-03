#include "everything.h"
#include "ui_everything.h"
#include "Searcher.h"
#include <QDesktopServices>
#include <QUrl>
EveryThing::EveryThing(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EveryThing)
{
    ui->setupUi(this);
    this->setFixedSize(400,311);
}

EveryThing::~EveryThing()
{
    delete ui;
}

void EveryThing::on_pushButton_clicked()
{
   ui->listWidget->clear();
   searcher *search=new searcher();
   search->Rsearch("/home/sathyagriffin/Documents");
 //  qDebug()<<"creating index file";
   search->CreateIndex("index.idx");
   QFileInfoList lists=search->SearchText(ui->lineEdit->text());
   foreach(QFileInfo file,lists)
   {
      ui->listWidget->addItem(file.absoluteFilePath());
   }
}


void EveryThing::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QString file=ui->listWidget->currentItem()->text();
    QDesktopServices::openUrl(QUrl(file));
}
