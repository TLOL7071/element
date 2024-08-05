#include "Factory.h"
#include <iostream>
#include<memory>

using namespace std;
void Heating::Fangfa()
{
    cout<<"加工方法是Heating\n";
}
void Cooling::Fangfa()
{
    cout<<"加工方法是Cooling\n";
}
void Mixing::Fangfa()
{
    cout<<"加工方法是Mixing\n";
}



/*Product::Product()
{
    jg=new Heating;
}*/
void Product::process()
{
    jg->Fangfa();
}
void Product::get(char b[])
{

    if(b[0]=='H')
        jg=new Heating;
    else if(*b=='C')
        jg=new Cooling;
    else if(*b=='M')
        jg=new Mixing;
}


Product* FactoryManager::createProduct(char a[])
{
    if(a=="ProductA")
       return  new ProductA;
    else if(a=="ProductB")
        return new ProductB;
    else
        return new ProductC;
}
void FactoryManager::assignStrategy(void (Product::*a)(char b[]),char c[],Product *lei)
{
    (lei->*a)(c);
}
FactoryManager& FactoryManager::getInstance()
{
    static FactoryManager instance;
    return instance;
}
