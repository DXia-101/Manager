//原料类里包含了操作数据库中原料的操作

#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <QObject>
#include <QSqlDatabase>

struct IngredientInfo{
    int ingredient_id;
    QString ingredient_name;
    QString ingredient_store_unit;
    quint16 ingredient_amount;
    QString ingredient_sell_unit;
    double ingredient_price;
};

#define INGREDIENTINFO_ROW 6 //原料所需信息数

class ingredient : public QObject
{
    Q_OBJECT
public:
    //方便后续添加和修改好直接操作数据库
    static ingredient *ptringredient;
    static ingredient *getinstance(){
        if(nullptr == ptringredient){
            ptringredient = new ingredient();
        }
        return ptringredient;
    }

    //查询所有原料数量
    quint32 getIngredientCnt();
    //查询第几页原料数据,页数从0开始
    QList<IngredientInfo>  getPageIngredient(quint32 page,quint32 uiCnt);
    //增加原料
    bool add_Ingredient(IngredientInfo info);
    //删除原料
    bool delete_Ingredient(int id);
    //清空原料表
    bool clear_IngredientTable();
    //修改原料信息
    bool UpdateIngredientInfo(IngredientInfo info);

private:
    explicit ingredient(QObject *parent = nullptr);

signals:

};


#endif // INGREDIENT_H
