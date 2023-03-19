//用于将原料类中读取的数据库信息具象化到表中

#ifndef INGREDIENTTABLE_H
#define INGREDIENTTABLE_H

#include <QTableWidget>
#include <QObject>
#include "ingredient.h"

class ingredientTable : public QTableWidget
{
    Q_OBJECT
public:
    explicit ingredientTable(QWidget *parent = nullptr);
    ~ingredientTable();
    void updateTable();

private:
    ingredient *ingredientobj;



};

#endif // INGREDIENTTABLE_H
