#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "qtablewidget.h"
#include "wareswidget.h"
#include "ingredientwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QTableWidget;
class QTreeWidgetItem;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //初始化选项树
    void InitTreeWidget();

private slots:
    //退出按钮
    void on_Logout_Btn_clicked();


    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

private:
    Ui::MainWindow *ui;

    void updateTable();

    wares *ptr_wares;

    WaresWidget *wares_Table;
    IngredientWidget *ingredient_Table;
    QTableWidget *buyTable;
};
#endif // MAINWINDOW_H
