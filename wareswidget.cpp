#include "wareswidget.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QMessageBox>

WaresWidget::WaresWidget(QWidget *parent)
    : QWidget{parent}
{
    contain_wares_Table = new waresTable(this);

    wares_Add_Btn    = new QPushButton("添加",this);
    wares_Delete_Btn = new QPushButton("删除",this);
    wares_Update_Btn = new QPushButton("修改",this);
    wares_Search_Btn = new QPushButton("查找",this);
    wares_LineEdit = new QLineEdit(this);

    wares_Add_Btn->resize(75,24);
    wares_Delete_Btn->resize(75,24);
    wares_Update_Btn->resize(75,24);
    wares_Search_Btn->resize(75,24);


    QHBoxLayout * wares_ADU_HBoxLayout = new QHBoxLayout();
    wares_ADU_HBoxLayout->addWidget(wares_Add_Btn);
    wares_ADU_HBoxLayout->addWidget(wares_Delete_Btn);
    wares_ADU_HBoxLayout->addWidget(wares_Update_Btn);

    QHBoxLayout * wares_SL_HBoxLayout = new QHBoxLayout();
    wares_SL_HBoxLayout->addWidget(wares_Search_Btn);
    wares_SL_HBoxLayout->addWidget(wares_LineEdit);

    QGridLayout * wares_GridLayout = new QGridLayout(this);
    wares_GridLayout->addLayout(wares_ADU_HBoxLayout,0,0,1,1);
    wares_GridLayout->addLayout(wares_SL_HBoxLayout,0,1,1,1);
    wares_GridLayout->addWidget(contain_wares_Table,1,0,1,2);

    setLayout(wares_GridLayout);

    contain_wares_Table->updateTable();

    connect(wares_Add_Btn,&QPushButton::clicked,this,&WaresWidget::Add_Action);
    connect(wares_Delete_Btn,&QPushButton::clicked,this,&WaresWidget::Delete_Action);
    connect(wares_Update_Btn,&QPushButton::clicked,this,&WaresWidget::Update_Action);
    connect(wares_Search_Btn,&QPushButton::clicked,this,&WaresWidget::Search_Action);

    //添加用测试代码
//    WaresInfo ss{2,QString("test"),QString("test"),3000,QString("test"),3.75};
//    wares::ptrwares->add_Wares(ss);
}

void WaresWidget::Add_Action()
{
    dlgWares.setType(true);
    dlgWares.exec();
    contain_wares_Table->updateTable();
}

void WaresWidget::Delete_Action()
{
    int i = contain_wares_Table->currentRow();
    if(i >= 0){
        int id = contain_wares_Table->item(i,0)->text().toUInt();
        wares::ptrwares->delete_Wares(id);
        contain_wares_Table->updateTable();
        QMessageBox::information(nullptr,"信息","删除成功");
    }
}

void WaresWidget::Update_Action()
{
    WaresInfo info;
    int i = contain_wares_Table->currentRow();
    if(i >= 0){
        info.wares_id = contain_wares_Table->item(i,0)->text().toUInt();
        info.wares_name= contain_wares_Table->item(i,1)->text();
        info.wares_store_unit = contain_wares_Table->item(i,2)->text();
        info.wares_amount = contain_wares_Table->item(i,3)->text().toUInt();
        info.wares_sell_unit = contain_wares_Table->item(i,4)->text();
        info.wares_price = contain_wares_Table->item(i,5)->text().toDouble();
        dlgWares.setType(false,info);
        dlgWares.exec();
    }
    contain_wares_Table->updateTable();
}

void WaresWidget::Search_Action()
{
    QString strFilter = wares_LineEdit->text();
    if(strFilter.isEmpty()){
        QMessageBox::information(nullptr,"警告","名字筛选为空");
        contain_wares_Table->updateTable();
        return;
    }

    contain_wares_Table->clear();
    //告诉多少列
    contain_wares_Table->setColumnCount(WARESINFO_ROW);
    QStringList infoList;
    infoList<<"商品编号"<<"商品名"<<"计量单位"<<"商品数量"<<"计价单位"<<"单价";
    contain_wares_Table->setHorizontalHeaderLabels(infoList);

    auto cnt = wares::ptrwares->getWaresCnt();
    QList<WaresInfo> Lwares = wares::ptrwares->getPageWares(0,cnt);


    int index = 0;
    for(int i = 0;i < Lwares.size();++i){
        if(!Lwares[i].wares_name.contains(strFilter)){
            continue;
        }
        contain_wares_Table->setItem(index,0,new QTableWidgetItem(QString::number(Lwares[i].wares_id)));
        contain_wares_Table->setItem(index,1,new QTableWidgetItem(Lwares[i].wares_name));
        contain_wares_Table->setItem(index,2,new QTableWidgetItem(Lwares[i].wares_store_unit));
        contain_wares_Table->setItem(index,3,new QTableWidgetItem(QString::number(Lwares[i].wares_amount)));
        contain_wares_Table->setItem(index,4,new QTableWidgetItem(Lwares[i].wares_sell_unit));
        contain_wares_Table->setItem(index,5,new QTableWidgetItem(QString::number(Lwares[i].wares_price)));
        index++;
    }
    contain_wares_Table->setRowCount(index);
}
