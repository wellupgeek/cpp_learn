// 产品注册模板类+单例工厂类
// 产品注册模板接口

#include <map>
#include <string>
#include <iostream>

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

template <class Product_Type>
class IProductRegister{
public:
    virtual Product_Type* CreateProduct() = 0;
protected:
    // 禁止外部构造
    IProductRegister(){}
    ~IProductRegister(){}
private:
    // 禁止拷贝和赋值
    IProductRegister(const IProductRegister &);
    const IProductRegister& operator=(const IProductRegister &);
};

template <class Product_Type>
class Factory{
public:
    static Factory<Product_Type>& Instance() {
        static Factory<Product_Type> temp;
        return temp;
    }
    void Register(std::string name, IProductRegister<Product_Type>* IPR) {
        m_save[name] = IPR;
    }
    Product_Type* GetRegister(std::string name) {
        if (m_save.find(name) != m_save.end()){
            IProductRegister<Product_Type>* t = m_save[name];
            return t->CreateProduct();
        }
        return nullptr;
    }

private:
    // 禁止外部构造和虚构
    Factory(){}
    ~Factory(){}

    // 禁止拷贝和赋值
    Factory(const Factory&);
    const Factory& operator=(const Factory&);

    std::map<std::string, IProductRegister<Product_Type>* > m_save;
};

template <class Product_Type, class Concreate_Product_Type>
class ProductRegister : IProductRegister<Product_Type>{
public:
    explicit ProductRegister(const std::string name) {
        Factory<Product_Type>::Instance().Register(name, this);
    }
    Product_Type* CreateProduct() {
        return new Concreate_Product_Type();
    }
};

int main()
{
    ProductRegister<Shoes, NikeShoes> nikePr("nike");
    Shoes* nikeShoe = Factory<Shoes>::Instance().GetRegister("nike");
    nikeShoe->show();
    if (nikeShoe)
        delete nikeShoe;
    nikeShoe = 0;

    ProductRegister<Clothes, LiNingClothes> lilingPr("lining");
    Clothes* liningClothes = Factory<Clothes>::Instance().GetRegister("lining");
    liningClothes->show();
    if (liningClothes)
        delete liningClothes;
    liningClothes = 0;
}