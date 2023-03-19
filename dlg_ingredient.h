#ifndef DLG_INGREDIENT_H
#define DLG_INGREDIENT_H

#include <QDialog>
#include "ingredient.h"

namespace Ui {
class Dlg_Ingredient;
}

class Dlg_Ingredient : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_Ingredient(QWidget *parent = nullptr);
    ~Dlg_Ingredient();

    //设置类型，方便添加和修改同用一个对话框
    void setType(bool isAdd,IngredientInfo info = {});

private slots:
    void on_btn_save_clicked();

    void on_btn_cancel_clicked();

private:
    Ui::Dlg_Ingredient *ui;
    bool i_isAdd;
};

#endif // DLG_INGREDIENT_H
