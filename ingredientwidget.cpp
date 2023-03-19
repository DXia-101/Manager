#include "ingredientwidget.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QMessageBox>

IngredientWidget::IngredientWidget(QWidget *parent)
    : QWidget{parent}
{
    contain_ingredient_Table = new ingredientTable(this);

    ingredient_Add_Btn    = new QPushButton("添加",this);
    ingredient_Delete_Btn = new QPushButton("删除",this);
    ingredient_Update_Btn = new QPushButton("修改",this);
    ingredient_Search_Btn = new QPushButton("查找",this);
    ingredient_LineEdit = new QLineEdit(this);

    ingredient_Add_Btn->resize(75,24);
    ingredient_Delete_Btn->resize(75,24);
    ingredient_Update_Btn->resize(75,24);
    ingredient_Search_Btn->resize(75,24);


    QHBoxLayout * ingredient_ADU_HBoxLayout = new QHBoxLayout();
    ingredient_ADU_HBoxLayout->addWidget(ingredient_Add_Btn);
    ingredient_ADU_HBoxLayout->addWidget(ingredient_Delete_Btn);
    ingredient_ADU_HBoxLayout->addWidget(ingredient_Update_Btn);

    QHBoxLayout * ingredient_SL_HBoxLayout = new QHBoxLayout();
    ingredient_SL_HBoxLayout->addWidget(ingredient_Search_Btn);
    ingredient_SL_HBoxLayout->addWidget(ingredient_LineEdit);

    QGridLayout * ingredient_GridLayout = new QGridLayout(this);
    ingredient_GridLayout->addLayout(ingredient_ADU_HBoxLayout,0,0,1,1);
    ingredient_GridLayout->addLayout(ingredient_SL_HBoxLayout,0,1,1,1);
    ingredient_GridLayout->addWidget(contain_ingredient_Table,1,0,1,2);

    setLayout(ingredient_GridLayout);

    contain_ingredient_Table->updateTable();

    connect(ingredient_Add_Btn,&QPushButton::clicked,this,&IngredientWidget::Add_Action);
    connect(ingredient_Delete_Btn,&QPushButton::clicked,this,&IngredientWidget::Delete_Action);
    connect(ingredient_Update_Btn,&QPushButton::clicked,this,&IngredientWidget::Update_Action);
    connect(ingredient_Search_Btn,&QPushButton::clicked,this,&IngredientWidget::Search_Action);

    //添加用测试代码
//    IngredientInfo ss{2,QString("test"),QString("test"),3000,QString("test"),3.75};
//    ingredient::ptringredient->add_Ingredient(ss);
}

void IngredientWidget::Add_Action()
{
    dlgIngredient.setType(true);
    dlgIngredient.exec();
    contain_ingredient_Table->updateTable();
}

void IngredientWidget::Delete_Action()
{
    int i = contain_ingredient_Table->currentRow();
    if(i >= 0){
        int id = contain_ingredient_Table->item(i,0)->text().toUInt();
        ingredient::ptringredient->delete_Ingredient(id);
        contain_ingredient_Table->updateTable();
        QMessageBox::information(nullptr,"信息","删除成功");
    }
}

void IngredientWidget::Update_Action()
{
    IngredientInfo info;
    int i = contain_ingredient_Table->currentRow();
    if(i >= 0){
        info.ingredient_id = contain_ingredient_Table->item(i,0)->text().toUInt();
        info.ingredient_name= contain_ingredient_Table->item(i,1)->text();
        info.ingredient_store_unit = contain_ingredient_Table->item(i,2)->text();
        info.ingredient_amount = contain_ingredient_Table->item(i,3)->text().toUInt();
        info.ingredient_sell_unit = contain_ingredient_Table->item(i,4)->text();
        info.ingredient_price = contain_ingredient_Table->item(i,5)->text().toDouble();
        dlgIngredient.setType(false,info);
        dlgIngredient.exec();
    }
    contain_ingredient_Table->updateTable();
}

void IngredientWidget::Search_Action()
{
    QString strFilter = ingredient_LineEdit->text();
    if(strFilter.isEmpty()){
        QMessageBox::information(nullptr,"警告","名字筛选为空");
        contain_ingredient_Table->updateTable();
        return;
    }

    contain_ingredient_Table->clear();
    //告诉多少列
    contain_ingredient_Table->setColumnCount(INGREDIENTINFO_ROW);
    QStringList infoList;
    infoList<<"原料编号"<<"原料名"<<"计量单位"<<"原料库存"<<"计价单位"<<"单价";
    contain_ingredient_Table->setHorizontalHeaderLabels(infoList);

    auto cnt = ingredient::ptringredient->getIngredientCnt();
    QList<IngredientInfo> Lingredient = ingredient::ptringredient->getPageIngredient(0,cnt);


    int index = 0;
    for(int i = 0;i < Lingredient.size();++i){
        if(!Lingredient[i].ingredient_name.contains(strFilter)){
            continue;
        }
        contain_ingredient_Table->setItem(index,0,new QTableWidgetItem(QString::number(Lingredient[i].ingredient_id)));
        contain_ingredient_Table->setItem(index,1,new QTableWidgetItem(Lingredient[i].ingredient_name));
        contain_ingredient_Table->setItem(index,2,new QTableWidgetItem(Lingredient[i].ingredient_store_unit));
        contain_ingredient_Table->setItem(index,3,new QTableWidgetItem(QString::number(Lingredient[i].ingredient_amount)));
        contain_ingredient_Table->setItem(index,4,new QTableWidgetItem(Lingredient[i].ingredient_sell_unit));
        contain_ingredient_Table->setItem(index,5,new QTableWidgetItem(QString::number(Lingredient[i].ingredient_price)));
        index++;
    }
    contain_ingredient_Table->setRowCount(index);
}
