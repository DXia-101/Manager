//商品类里包含了操作数据库中商品的操作

#ifndef WARES_H
#define WARES_H

#include <QObject>
#include <QSqlDatabase>

struct WaresInfo{
    int wares_id;
    QString wares_name;
    QString wares_store_unit;
    quint16 wares_amount;
    QString wares_sell_unit;
    double wares_price;
};

#define WARESINFO_ROW 6 //商品所需信息数

class wares : public QObject
{
    Q_OBJECT
public:
    //方便后续添加和修改好直接操作数据库
    static wares *ptrwares;
    static wares *getinstance(){
        if(nullptr == ptrwares){
            ptrwares = new wares();
        }
        return ptrwares;
    }

    //查询所有商品数量
    quint32 getWaresCnt();
    //查询第几页商品数据,页数从0开始
    QList<WaresInfo>  getPageWares(quint32 page,quint32 uiCnt);
    //增加商品
    bool add_Wares(WaresInfo info);
    //删除商品
    bool delete_Wares(int id);
    //清空商品表
    bool clear_WaresTable();
    //修改商品信息
    bool UpdateWaresInfo(WaresInfo info);

private:
    explicit wares(QObject *parent = nullptr);

signals:

};


#endif // WARES_H
