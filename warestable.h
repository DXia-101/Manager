//用于将商品类中读取的数据库信息具象化到表中

#ifndef WARESTABLE_H
#define WARESTABLE_H

#include <QTableWidget>
#include <QObject>
#include "wares.h"

class waresTable : public QTableWidget
{
    Q_OBJECT
public:
    explicit waresTable(QWidget *parent = nullptr);
    ~waresTable();
    void updateTable();

private:
    wares *waresobj;



};

#endif // WARESTABLE_H
