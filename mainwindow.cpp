#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QTreeWidget>



MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    InitTreeWidget();

    wares_Table = new WaresWidget(ui->wares_page);
    wares_Table->resize(ui->wares_page->width(),ui->wares_page->height());

    ingredient_Table = new IngredientWidget(ui->ingredient_page);
    ingredient_Table->resize(ui->ingredient_page->width(),ui->ingredient_page->height());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitTreeWidget()
{
    ui->treeWidget->setColumnCount(1);
    QStringList infoList;
    infoList<<"汽车内饰库存管理系统";
    QTreeWidgetItem *treeHead = new QTreeWidgetItem(ui->treeWidget,infoList);
    ui->treeWidget->addTopLevelItem(treeHead);
    infoList.clear();
    infoList<<"原材料库存";
    QTreeWidgetItem *twig_1 = new QTreeWidgetItem(treeHead,infoList);
    infoList.clear();
    infoList<<"产品库存";
    QTreeWidgetItem *twig_2 = new QTreeWidgetItem(treeHead,infoList);
    infoList.clear();
    infoList<<"生产记录";
    QTreeWidgetItem *twig_3 = new QTreeWidgetItem(treeHead,infoList);
    infoList.clear();
    infoList<<"采购记录";
    QTreeWidgetItem *twig_4 = new QTreeWidgetItem(treeHead,infoList);
    infoList.clear();
    infoList<<"销售库存";
    QTreeWidgetItem *twig_5 = new QTreeWidgetItem(treeHead,infoList);
    infoList.clear();
    infoList<<"项目报表";
    QTreeWidgetItem *twig_6 = new QTreeWidgetItem(treeHead,infoList);
    treeHead->addChild(twig_1);
    treeHead->addChild(twig_2);
    treeHead->addChild(twig_3);
    treeHead->addChild(twig_4);
    treeHead->addChild(twig_5);
    treeHead->addChild(twig_6);
    ui->treeWidget->expandAll();
}

void MainWindow::on_Logout_Btn_clicked()
{
    exit(0);
}

void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    if(item->text(column)=="原材料库存"){
        ui->StackWidget->setCurrentWidget(ui->ingredient_page);
    }
    if(item->text(column)=="产品库存"){
        ui->StackWidget->setCurrentWidget(ui->wares_page);
    }
}

