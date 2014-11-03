#include "Searcher.h"
#include <QString>
#include <QTextStream>
#include <QFile>

searcher::searcher()
{

}
void searcher::Rsearch(QString root)
{
    QDir *dir =new QDir(root);
    if(dir->exists())
    {
        QFileInfoList temp=dir->entryInfoList();
        foreach(QFileInfo info,temp)
        {
           qDebug()<<info.absoluteFilePath();
           // totallist.append(info);

            if(info.isDir() && !info.isHidden())
            {
                this->Rsearch(info.absoluteFilePath());
                this->list.append(info);
            }
        }
    }
}

void searcher::CreateIndex(QString filename)
{
    QFile file(filename);
    if(!file.open(QFile::WriteOnly|QFile::Text))
    {
        qDebug()<< "Error Opening the file system";
    }
    file.close();
    //reopening for indexing.
    file.open(QFile::Append | QFile::Text);
    foreach(QFileInfo info,list)
    {
        QTextStream out(&file);
        out<<info.absoluteFilePath()<<endl;
    }
    file.close();
}

QFileInfoList searcher::SearchText(QString str)
{
   //This will search the index file.
    QFile file("index.idx");
    QFileInfoList result;
    if(!file.open(QFile::ReadOnly|QFile::Text))
    {
        qDebug()<< "Error Opening File";
    }
    QTextStream stream(&file);
    while(!stream.atEnd())
    {
        QString line=stream.readLine();
        QStringList pices=line.split(QRegExp("/"));
        if(pices[pices.length()-1].contains(str))
        {
            qDebug()<<pices[pices.length()-1]<<"present in "<<line;
            QFileInfo info(line);
            result.append(info);
            qDebug()<<info.isDir()<<endl;
        }
    }
    return result;
}

