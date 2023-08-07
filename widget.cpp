#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffe->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);

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

void Widget::canBuy()
{
    if(money >= 100){
        ui->pbCoffe->setEnabled(true);
    }
    if(money >= 150){
        ui->pbTea->setEnabled(true);
    }
    if(money >= 200){
        ui->pbMilk->setEnabled(true);
    }
}

void Widget::cantBuy()
{
    if(money < 100){
        ui->pbCoffe->setEnabled(false);
    }
    if(money < 150) {
        ui->pbTea->setEnabled(false);
    }
    if(money < 200) {
        ui->pbMilk->setEnabled(false);
    }
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
    canBuy();
}


void Widget::on_pb50_clicked()
{
    changeMoney(50);
    canBuy();
}


void Widget::on_pb100_clicked()
{
    changeMoney(100);
    canBuy();
}


void Widget::on_pb500_clicked()
{
    changeMoney(500);
    canBuy();
}


void Widget::on_pbCoffe_clicked()
{
    changeMoney(-100);
    cantBuy();
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
    cantBuy();
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
    cantBuy();
}


void Widget::on_pbReset_clicked()
{
    if(money == 0) {
        QMessageBox mb;
        mb.information(this, "잔돈반환", "총 투입 금액이 0원이므로 반환할 돈이 없습니다!!!");
    }
    else {
        int coins[] = {500, 100, 50, 10};
        int count[4] = {0};

        for(int i = 0; i < 4; i++) {
            count[i] = money / coins[i];
            money %= coins[i];
        }

        // 결과를 문자열로 변환
        QString result = "500원: " + QString::number(count[0]) + "\n" + "100원: " + QString::number(count[1]) + "\n" +"50원: " + QString::number(count[2]) + "\n" + "10원: " + QString::number(count[3]) + "\n";

                         money = 0;
        ui->lcdNumber->display(money);

        QMessageBox mb;
        mb.information(this, "잔돈반환", result);
    }

}

