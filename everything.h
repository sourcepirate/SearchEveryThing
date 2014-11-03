#ifndef EVERYTHING_H
#define EVERYTHING_H

#include <QMainWindow>
#include <QListView>
namespace Ui {
class EveryThing;
}

class EveryThing : public QMainWindow
{
    Q_OBJECT

public:
    explicit EveryThing(QWidget *parent = 0);
    ~EveryThing();

private slots:
    void on_pushButton_clicked();

private:
    Ui::EveryThing *ui;

};

#endif // EVERYTHING_H
