#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
private:
	Ui::Widget *ui;
	int money;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void changeMoney(int diff);



private slots:
    void on_pb10_clicked();

    void on_pb50_clicked();

    void on_pb100_clicked();

    void on_pb500_clicked();

    void on_pbTea_clicked();

    void on_pbCoffee_clicked();

    void on_pbCoke_clicked();

    void on_pbReset_clicked();

};
#endif // WIDGET_H


