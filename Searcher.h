#ifndef SEARCHER_H
#define SEARCHER_H
#include <QDir>
#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QString>
#include <QFile>



class searcher
{
private:
    QFileInfoList list;
public:
    searcher();
    void Rsearch(QString dirname);
    void CreateIndex(QString filename);
    QFileInfoList SearchText(QString str);
};
#endif // SEARCHER_H
