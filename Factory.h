using namespace std;
class jiagong
{
public :
    virtual void Fangfa()=0;
    int so;
};
class Heating :public jiagong
{
    void Fangfa() override;
};
class Cooling :public jiagong
{
    void Fangfa() override;
};
class Mixing :public jiagong
{
    void Fangfa() override;
};

class Product
{
public:
    jiagong* jg;
    void get(char b[]);
    void process();
    //Product();
};
class ProductA:public Product
{
};
class ProductB:public Product
{
};
class ProductC:public Product
{
};



class FactoryManager
{
private:
    FactoryManager(){};
    ~FactoryManager(){};
public:
    Product *pro;
    static FactoryManager& getInstance();
    void assignStrategy(void (Product::*a)(char b[]),char c[],Product *lei);
    Product* createProduct(char a[]);
};
