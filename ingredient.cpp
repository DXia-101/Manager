#include "ingredient.h"
#include <QSqlQuery>
#include <QSqlError>

ingredient* ingredient::ptringredient=nullptr;

ingredient::ingredient(QObject *parent)
    : QObject{parent}
{
}

//获取原料数量
quint32 ingredient::getIngredientCnt()
{
    QSqlQuery sql;
    qDebug()<<sql.exec("SELECT COUNT(`原料编号`) FROM ingredient_info;")<<"  "<<sql.lastError().text();
    quint32 uiCnt = 0;
    while(sql.next()){
        uiCnt = sql.value(0).toInt();
    }
    return uiCnt;
}

//查询第几页原料数据,页数从0开始
QList<IngredientInfo> ingredient::getPageIngredient(quint32 page, quint32 uiCnt)
{
    QList<IngredientInfo> infoList;
    QSqlQuery sql;
    QString strsql = QString("SELECT * FROM ingredient_info ORDER BY `原料编号` LIMIT %1 OFFSET %2;")
            .arg(uiCnt).arg(page*uiCnt);
    sql.exec(strsql);
    IngredientInfo info;
    while(sql.next()){
        info.ingredient_id = sql.value(0).toInt();
        info.ingredient_name = sql.value(1).toString();
        info.ingredient_store_unit = sql.value(2).toString();
        info.ingredient_amount = sql.value(3).toInt();
        info.ingredient_sell_unit = sql.value(4).toString();
        info.ingredient_price = sql.value(5).toDouble();
        infoList.push_back(info);
    }
    return infoList;
}

//增加原料
bool ingredient::add_Ingredient(IngredientInfo info)
{
    QSqlQuery sql;
    QString strSql = QString("INSERT INTO ingredient_info VALUES (%1,'%2','%3',%4,'%5',%6)")
                .arg(info.ingredient_id)
                .arg(info.ingredient_name)
                .arg(info.ingredient_store_unit)
                .arg(info.ingredient_amount)
                .arg(info.ingredient_sell_unit)
                .arg(info.ingredient_price);
    if(!sql.exec(strSql)){
        QSqlError error = sql.lastError();
        qDebug()<<"add_Ingredient_Error: "<<error.text();
        return false;
    }
    return true;
}

//删除原料
bool ingredient::delete_Ingredient(int id)
{
    QSqlQuery sql;

    QString strSql = QString("DELETE FROM ingredient_info WHERE `原料编号` = %1").arg(id);
    if(!sql.exec(strSql)){
        QSqlError error = sql.lastError();
        qDebug()<<"delete_Ingredient_Error: "<< error.text();
        return false;
    }
    return true;
}

//清空原料表
bool ingredient::clear_IngredientTable()
{
    QSqlQuery sql;
    QString strSql = QString("DELETE FROM Ingredient_info");
    if(!sql.exec(strSql)){
        QSqlError error = sql.lastError();
        qDebug()<<"clear_Ingredient_Error: "<< error.text();
        return false;
    }
    return true;
}

//修改原料信息
bool ingredient::UpdateIngredientInfo(IngredientInfo info)
{
    QSqlQuery sql;
    QString strSql = QString("UPDATE Ingredient_info SET `原料名`='%1',`计量单位`='%2',`原料库存`=%3,"
                             "`计价单位`='%4',`单价`=%5 WHERE `原料编号`='%6' ")
            .arg(info.ingredient_name)
            .arg(info.ingredient_store_unit)
            .arg(info.ingredient_amount)
            .arg(info.ingredient_sell_unit)
            .arg(info.ingredient_price)
            .arg(info.ingredient_id);
    if(!sql.exec(strSql)){
        QSqlError error = sql.lastError();
        qDebug()<<"UpdateIngredient_Error: "<< error.text();
        return false;
    }
    return true;
}
