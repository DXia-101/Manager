#include "ingredienttable.h"

ingredientTable::ingredientTable(QWidget *parent):QTableWidget(parent)
{
    ingredientobj = ingredient::getinstance();
}

ingredientTable::~ingredientTable()
{

}


//初始化表
void ingredientTable::updateTable()
{
    this->clear();

    //设定表格的列数
    this->setColumnCount(INGREDIENTINFO_ROW);
    QStringList listInfo;
    listInfo<<"原料编号"<<"原料名"<<"计量单位"<<"原料库存"<<"计价单位"<<"单价";
    this->setHorizontalHeaderLabels(listInfo);
    //只能选中行
    //this->setSelectionMode(QAbstractItemView::SingleSelection);
    this->setSelectionBehavior(QAbstractItemView::SelectRows);
    //不可编辑
    this->setEditTriggers(QAbstractItemView::NoEditTriggers);
    auto cnt = ingredientobj->getIngredientCnt();
    //ui->lb_cnt->setText(QString("原料总数:%1").arg(cnt));
    QList<IngredientInfo> lIngredient = ingredientobj->getPageIngredient(0,cnt);

    this->setRowCount(cnt);
    for(int i = 0;i < lIngredient.size();++i){
        this->setItem(i,0,new QTableWidgetItem(QString::number(lIngredient[i].ingredient_id)));
        this->setItem(i,1,new QTableWidgetItem(lIngredient[i].ingredient_name));
        this->setItem(i,2,new QTableWidgetItem(lIngredient[i].ingredient_store_unit));
        this->setItem(i,3,new QTableWidgetItem(QString::number(lIngredient[i].ingredient_amount)));
        this->setItem(i,4,new QTableWidgetItem(lIngredient[i].ingredient_sell_unit));
        this->setItem(i,5,new QTableWidgetItem(QString::number(lIngredient[i].ingredient_price)));
    }
}


