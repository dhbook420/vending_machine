#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , money(0)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff)
{
    money += diff;
    ui->lcdNumber->display(money);
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}


void Widget::on_pb50_clicked()
{
    changeMoney(50);
}


void Widget::on_pb100_clicked()
{
    changeMoney(100);
}


void Widget::on_pb500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbTea_clicked()
{
    if (money >= 150)
        changeMoney(-150);
}


void Widget::on_pbCoffee_clicked()
{
    if (money >= 100)
        changeMoney(-100);
}


void Widget::on_pbCoke_clicked()
{
    if (money >= 200)
        changeMoney(-200);
}


void Widget::on_pbReset_clicked()
{
    QMessageBox mb;
    if (money > 0)
    {
        int remaining = money;

        int n_500 = remaining / 500;
        remaining %= 500;

        int n_100 = remaining / 100;
        remaining %= 100;

        int n_50 = remaining / 50;
        remaining %= 50;

        int n_10 = remaining / 10;
        remaining %= 10;

        QString text = QString("change\n500 won: %1 \n100 won: %2 \n50  won: %3 \n10  won: %4 ").arg(n_500).arg(n_100).arg(n_50).arg(n_10);

        mb.information(this, "Reset", text);
        changeMoney(-money);
    }
}

