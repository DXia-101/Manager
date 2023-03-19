#include "warestable.h"

waresTable::waresTable(QWidget *parent):QTableWidget(parent)
{
    waresobj = wares::getinstance();
}

waresTable::~waresTable()
{

}


//初始化表
void waresTable::updateTable()
{
    this->clear();

    //设定表格的列数
    this->setColumnCount(WARESINFO_ROW);
    QStringList listInfo;
    listInfo<<"商品编号"<<"商品名"<<"计量单位"<<"商品数量"<<"计价单位"<<"单价";
    this->setHorizontalHeaderLabels(listInfo);
    //只能选中行
    //this->setSelectionMode(QAbstractItemView::SingleSelection);
    this->setSelectionBehavior(QAbstractItemView::SelectRows);
    //不可编辑
    this->setEditTriggers(QAbstractItemView::NoEditTriggers);
    auto cnt = waresobj->getWaresCnt();
    //ui->lb_cnt->setText(QString("商品总数:%1").arg(cnt));
    QList<WaresInfo> lWares = waresobj->getPageWares(0,cnt);

    this->setRowCount(cnt);
    for(int i = 0;i < lWares.size();++i){
        this->setItem(i,0,new QTableWidgetItem(QString::number(lWares[i].wares_id)));
        this->setItem(i,1,new QTableWidgetItem(lWares[i].wares_name));
        this->setItem(i,2,new QTableWidgetItem(lWares[i].wares_store_unit));
        this->setItem(i,3,new QTableWidgetItem(QString::number(lWares[i].wares_amount)));
        this->setItem(i,4,new QTableWidgetItem(lWares[i].wares_sell_unit));
        this->setItem(i,5,new QTableWidgetItem(QString::number(lWares[i].wares_price)));
    }
}


