//用于将商品表与其他组件放于同一个widget中好让stackwidget通过切换page来切换不同的表

#ifndef INGREDIENTWIDGET_H
#define INGREDIENTWIDGET_H

#include <QWidget>
#include "ingredienttable.h"
#include "dlg_ingredient.h"

class QPushButton;
class QLineEdit;

class IngredientWidget : public QWidget
{
    Q_OBJECT
public:
    explicit IngredientWidget(QWidget *parent = nullptr);

private:
    ingredientTable *contain_ingredient_Table;

    //增删改查四个按钮以及搜索框
    QPushButton *ingredient_Add_Btn;
    QPushButton *ingredient_Delete_Btn;
    QPushButton *ingredient_Update_Btn;

    QPushButton *ingredient_Search_Btn;
    QLineEdit *ingredient_LineEdit;

    Dlg_Ingredient dlgIngredient;

private slots:
    void Add_Action();
    //void Clear_Action();
    void Delete_Action();
    void Update_Action();
    void Search_Action();
};

#endif // INGREDIENTWIDGET_H
