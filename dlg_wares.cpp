#include "dlg_wares.h"
#include "ui_dlg_wares.h"

#include <QMessageBox>

Dlg_Wares::Dlg_Wares(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_Wares)
{
    ui->setupUi(this);
}

Dlg_Wares::~Dlg_Wares()
{
    delete ui;
}

void Dlg_Wares::setType(bool isAdd, WaresInfo info)
{
    w_isAdd = isAdd;
    ui->lw_id->setText(QString::number(info.wares_id));
    ui->lw_name->setText(info.wares_name);
    ui->lw_stroe_unit->setText(info.wares_store_unit);
    ui->lw_amount->setText(QString::number(info.wares_amount));
    ui->lw_sell_unit->setText(info.wares_sell_unit);
    ui->lw_price->setText(QString::number(info.wares_price));
}

void Dlg_Wares::on_btn_save_clicked()
{
    WaresInfo info;
    info.wares_id = ui->lw_id->text().toInt();
    info.wares_name = ui->lw_name->text();
    info.wares_store_unit = ui->lw_stroe_unit->text();
    info.wares_amount = ui->lw_amount->text().toInt();
    info.wares_sell_unit = ui->lw_sell_unit->text();
    info.wares_price = ui->lw_price->text().toDouble();
    if(w_isAdd){
         wares::ptrwares->add_Wares(info);
    }
    else{
         wares::ptrwares->UpdateWaresInfo(info);
    }
    QMessageBox::information(this,"信息","存储成功");
    this->hide();
}


void Dlg_Wares::on_btn_cancel_clicked()
{
    this->hide();
}

