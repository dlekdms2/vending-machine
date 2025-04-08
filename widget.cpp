#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    updateUI();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pb10_clicked()
{
    money += 10;
    updateUI();
}

void Widget::on_pb50_clicked()
{
    money += 50;
    updateUI();
}

void Widget::on_pb100_clicked()
{
    money += 100;
    updateUI();
}

void Widget::on_pb500_clicked()
{
    money += 500;
    updateUI();
}

void Widget::on_pbCoffee_clicked()
{
    if (money >= 100) {
        money -= 100;
        updateUI();
    }
}

void Widget::on_pbTea_clicked()
{
    if (money >= 150) {
        money -= 150;
        updateUI();
    }
}

void Widget::on_pbMilk_clicked()
{
    if (money >= 200) {
        money -= 200;
        updateUI();
    }
}

void Widget::on_pbReset_clicked()
{
    int remainingMoney = money;
    int coins500 = remainingMoney / 500;
    remainingMoney %= 500;
    int coins100 = remainingMoney / 100;
    remainingMoney %= 100;
    int coins50 = remainingMoney / 50;
    remainingMoney %= 50;
    int coins10 = remainingMoney / 10;

    QMessageBox::information(this, "잔돈",
                             QString("500원: %1개\n100원: %2개\n50원: %3개\n10원: %4개")
                                 .arg(coins500)
                                 .arg(coins100)
                                 .arg(coins50)
                                 .arg(coins10));

    money = 0;
    updateUI();
}

void Widget::updateUI()
{
    ui->lcdNumber->display(money);
    updateButtons();
}

void Widget::updateButtons()
{
    ui->pbCoffee->setEnabled(money >= 100);
    ui->pbTea->setEnabled(money >= 150);
    ui->pbMilk->setEnabled(money >= 200);
}
