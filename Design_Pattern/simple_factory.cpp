#include <iostream>
// 以鞋厂为例，理解简单工厂模式
// 分为 鞋子的抽象类、具体鞋子类、鞋子工厂类

// 抽象类,设置接口show，以及析构函数
class Shoes{
public:
    virtual void show() = 0;
    ~Shoes(){}
};

// 具体鞋子类, 分为耐克、阿迪达斯、李宁
class NikeShoes : public Shoes {
public:
    void show() {
        std::cout << "Nike, Just do it" << '\n';
    }
};

class AdidasShoes : public Shoes {
public:
    void show() {
        std::cout << "Adidas, Impossible is nothing" << '\n';
    }
};

class LiNingShoes : public Shoes {
public:
    void show() {
        std::cout << "LiNing, Everything is possible" << '\n';
    }
};

// 鞋子工厂类
enum SHOES_TYPE
{
    NIKE,
    LINING,
    ADIDAS
};

// class ShoesFactory
// {
// public:
//     // 根据鞋子类型创建对应的鞋子对象
//     Shoes *CreateShoes(SHOES_TYPE type) {
//         switch (type) {
//             case NIKE :
//                 return new NikeShoes();
//                 break;
//             case LINING : 
//                 return new LiNingShoes();
//                 break;
//             case ADIDAS :
//                 return new AdidasShoes();
//                 break;
//             default :
//                 return NULL;
//                 break;
//         }
//     }
// };

// 工厂模式
class ShoesFactory {
public:
    virtual Shoes* CreateShoes() = 0;
    ~ShoesFactory(){};
};

class NikeProducer : public ShoesFactory {
public: 
    Shoes* CreateShoes() {
        return new NikeShoes();
    }
};

class AdidasProducer : public ShoesFactory {
public:
    Shoes* CreateShoes() {
        return new AdidasShoes();
    }
};

class LiNingProducer : public ShoesFactory {
public:
    Shoes* CreateShoes() {
        return new LiNingShoes();
    }
};

// int main()
// {
//     // 构造工厂对象
//     ShoesFactory shoesFactory;

//     // 从鞋厂对象创建耐克鞋对象
//     Shoes *pNikeShoes = shoesFactory.CreateShoes(NIKE);
//     if (pNikeShoes != NULL) {
//         pNikeShoes->show();
//         // 释放资源
//         delete pNikeShoes;
//         pNikeShoes = NULL;
//     }

//     // 同理对于阿迪达斯和耐克
//     Shoes *pAdidasShoes = shoesFactory.CreateShoes(ADIDAS);
//     if (pAdidasShoes != NULL) {
//         pAdidasShoes->show();
//         // 释放资源
//         delete pAdidasShoes;
//         pAdidasShoes = NULL;
//     }

//     Shoes *pLingNingShoes = shoesFactory.CreateShoes(LINING);
//     if (pLingNingShoes != NULL) {
//         pLingNingShoes->show();
//         //释放资源
//         delete pLingNingShoes;
//         pLingNingShoes = NULL;
//     }

//     return 0;
// }

int main()
{
    // Nike 流水线
    ShoesFactory *pnikeProducer = new NikeProducer();
    // 生产线产出球鞋
    Shoes *pnikeShoes = pnikeProducer->CreateShoes();
    // show()
    pnikeShoes->show();
    // 释放资源
    delete pnikeShoes;
    delete pnikeProducer;

}