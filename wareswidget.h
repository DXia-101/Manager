//用于将商品表与其他组件放于同一个widget中好让stackwidget通过切换page来切换不同的表

#ifndef WARESWIDGET_H
#define WARESWIDGET_H

#include <QWidget>
#include "warestable.h"
#include "dlg_wares.h"

class QPushButton;
class QLineEdit;

class WaresWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WaresWidget(QWidget *parent = nullptr);

private:
    waresTable *contain_wares_Table;

    //增删改查四个按钮以及搜索框
    QPushButton *wares_Add_Btn;
    QPushButton *wares_Delete_Btn;
    QPushButton *wares_Update_Btn;

    QPushButton *wares_Search_Btn;
    QLineEdit *wares_LineEdit;

    Dlg_Wares dlgWares;

private slots:
    void Add_Action();
    //void Clear_Action();
    void Delete_Action();
    void Update_Action();
    void Search_Action();
};

#endif // WARESWIDGET_H
