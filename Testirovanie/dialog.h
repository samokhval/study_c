#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    const int max = 5;//количество вопросов в тесте
    int count = 0;
    int answer = 0;
    int count1,count2;
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    Ui::Dialog *ui;
    void CreateTable();
    void InsertValue(int, QString, int, int, QString, QString);
    int randInt(int, int);

private:

public slots:
    void next_q();
    void GetDataBase();
    void ChangeAnswer();

private slots:
    void on_pushButton_3_clicked();
};

#endif // DIALOG_H