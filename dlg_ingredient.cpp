#include "dlg_ingredient.h"
#include "ui_dlg_ingredient.h"
#include <QMessageBox>

Dlg_Ingredient::Dlg_Ingredient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_Ingredient)
{
    ui->setupUi(this);
}

Dlg_Ingredient::~Dlg_Ingredient()
{
    delete ui;
}

void Dlg_Ingredient::setType(bool isAdd, IngredientInfo info)
{
    i_isAdd = isAdd;
    ui->li_id->setText(QString::number(info.ingredient_id));
    ui->li_name->setText(info.ingredient_name);
    ui->li_store_unit->setText(info.ingredient_store_unit);
    ui->li_amount->setText(QString::number(info.ingredient_amount));
    ui->li_sell_unit->setText(info.ingredient_sell_unit);
    ui->li_price->setText(QString::number(info.ingredient_price));
}

void Dlg_Ingredient::on_btn_save_clicked()
{
    IngredientInfo info;
    info.ingredient_id = ui->li_id->text().toInt();
    info.ingredient_name = ui->li_name->text();
    info.ingredient_store_unit = ui->li_store_unit->text();
    info.ingredient_amount = ui->li_amount->text().toInt();
    info.ingredient_sell_unit = ui->li_sell_unit->text();
    info.ingredient_price = ui->li_price->text().toDouble();
    if(i_isAdd){
         ingredient::ptringredient->add_Ingredient(info);
    }
    else{
         ingredient::ptringredient->UpdateIngredientInfo(info);
    }
    QMessageBox::information(this,"信息","存储成功");
    this->hide();
}


void Dlg_Ingredient::on_btn_cancel_clicked()
{
    this->hide();
}

