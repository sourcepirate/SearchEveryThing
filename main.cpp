#include "everything.h"
#include <QApplication>
#include "Searcher.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EveryThing w;
    w.show();

  /*  searcher *search=new searcher();
    search->Rsearch("/home/sathyagriffin/Scripts");
    search->CreateIndex("index.idx");
    search->SearchText("sstack.c");*/
    return a.exec();
}
