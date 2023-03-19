#include "wares.h"
#include <QSqlQuery>
#include <QSqlError>

wares* wares::ptrwares=nullptr;

wares::wares(QObject *parent)
    : QObject{parent}
{
}

//获取商品数量
quint32 wares::getWaresCnt()
{
    QSqlQuery sql;
    qDebug()<<sql.exec("SELECT COUNT(`商品编号`) FROM wares_info;")<<"  "<<sql.lastError().text();
    quint32 uiCnt = 0;
    while(sql.next()){
        uiCnt = sql.value(0).toInt();
    }
    return uiCnt;
}

//查询第几页商品数据,页数从0开始
QList<WaresInfo> wares::getPageWares(quint32 page, quint32 uiCnt)
{
    QList<WaresInfo> infoList;
    QSqlQuery sql;
    QString strsql = QString("SELECT * FROM wares_info ORDER BY `商品编号` LIMIT %1 OFFSET %2;")
            .arg(uiCnt).arg(page*uiCnt);
    sql.exec(strsql);
    WaresInfo info;
    while(sql.next()){
        info.wares_id = sql.value(0).toInt();
        info.wares_name = sql.value(1).toString();
        info.wares_store_unit = sql.value(2).toString();
        info.wares_amount = sql.value(3).toInt();
        info.wares_sell_unit = sql.value(4).toString();
        info.wares_price = sql.value(5).toDouble();
        infoList.push_back(info);
    }
    return infoList;
}

//增加商品
bool wares::add_Wares(WaresInfo info)
{
    QSqlQuery sql;
    QString strSql = QString("INSERT INTO wares_info VALUES (%1,'%2','%3',%4,'%5',%6)")
                .arg(info.wares_id)
                .arg(info.wares_name)
                .arg(info.wares_store_unit)
                .arg(info.wares_amount)
                .arg(info.wares_sell_unit)
                .arg(info.wares_price);
    if(!sql.exec(strSql)){
        QSqlError error = sql.lastError();
        qDebug()<<"add_Wares_Error: "<<error.text();
        return false;
    }
    return true;
}

//删除商品
bool wares::delete_Wares(int id)
{
    QSqlQuery sql;

    QString strSql = QString("DELETE FROM wares_info WHERE `商品编号` = %1").arg(id);
    if(!sql.exec(strSql)){
        QSqlError error = sql.lastError();
        qDebug()<<"delete_Wares_Error: "<< error.text();
        return false;
    }
    return true;
}

//清空商品表
bool wares::clear_WaresTable()
{
    QSqlQuery sql;
    QString strSql = QString("DELETE FROM Wares_info");
    if(!sql.exec(strSql)){
        QSqlError error = sql.lastError();
        qDebug()<<"clear_Wares_Error: "<< error.text();
        return false;
    }
    return true;
}

//修改商品信息
bool wares::UpdateWaresInfo(WaresInfo info)
{
    QSqlQuery sql;
    QString strSql = QString("UPDATE Wares_info SET `商品名`='%1',`计量单位`='%2',`商品数量`=%3,"
                             "`计价单位`='%4',`单价`=%5 WHERE `商品编号`='%6' ")
            .arg(info.wares_name)
            .arg(info.wares_store_unit)
            .arg(info.wares_amount)
            .arg(info.wares_sell_unit)
            .arg(info.wares_price)
            .arg(info.wares_id);
    if(!sql.exec(strSql)){
        QSqlError error = sql.lastError();
        qDebug()<<"UpdateWares_Error: "<< error.text();
        return false;
    }
    return true;
}
