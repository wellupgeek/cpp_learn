#include <iostream>

// 定义抽象产品类和具体产品类
class Shoes{
public:
    virtual void show() = 0;
    virtual ~Shoes(){}
};

class Clothes{
public:
    virtual void show() = 0;
    virtual ~Clothes(){}
};

class NikeShoes : public Shoes {
public:
    void show() {
        std::cout << "this is NikeShoes of Shoes" << '\n';
    }
};

class LiNingClothes : public Clothes {
    void show() {
        std::cout << "this is LiNingClothes of Clothes" << '\n';
    }
};

// 定义抽象模板工厂
template <class AbstractProduct_t>
class AbstractFactory{
public:
    virtual AbstractProduct_t* CreateProducer() = 0;
    virtual ~AbstractFactory(){}
};

// 定义抽象模板生产线
template <class AbstractProduct_t, class ConcreateProcuct_t>
class ConcreateProducer : public AbstractFactory<AbstractProduct_t>{
public:
    AbstractProduct_t* CreateProducer() {
        return new ConcreateProcuct_t();
    }
    ~ConcreateProducer(){}
};

int main()
{
    ConcreateProducer<Shoes, NikeShoes> nikeProducer;
    Shoes* nikeProduct = nikeProducer.CreateProducer();
    nikeProduct->show();
    delete nikeProduct;
    nikeProduct = 0;

    ConcreateProducer<Clothes, LiNingClothes> LiNingProducer;
    Clothes* LiNingProduct = LiNingProducer.CreateProducer();
    LiNingProduct->show();
    delete LiNingProduct;
    LiNingProduct = 0;

    return 0;
}