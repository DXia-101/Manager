//增加和修改数据时弹出的对话框，以便于填写信息
#ifndef DLG_WARES_H
#define DLG_WARES_H

#include <QDialog>
#include "wares.h"

namespace Ui {
class Dlg_Wares;
}

class Dlg_Wares : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_Wares(QWidget *parent = nullptr);
    ~Dlg_Wares();

    //设置类型，方便添加和修改同用一个对话框
    void setType(bool isAdd,WaresInfo info = {});

private slots:
    void on_btn_save_clicked();

    void on_btn_cancel_clicked();

private:
    Ui::Dlg_Wares *ui;
    bool w_isAdd;
};

#endif // DLG_WARES_H
