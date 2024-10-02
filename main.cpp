#include<iostream>
#include <memory>
#include "Factory.h"

int main() {
    FactoryManager& manager = FactoryManager::getInstance();

    // ������ƷA��ָ�����Ȳ���
    Product* productA = manager.createProduct("ProductA");
    if (productA) {
        manager.assignStrategy(productA->get,"Heating",productA);
        productA->process();
    }

    // ������ƷB��ָ����ȴ����
    Product* productB = manager.createProduct("ProductB");
    if (productB) {
        manager.assignStrategy(productB->get, "Cooling",productB);
        productB->process();
    }
    std::cout<<"olololol";
    // ������ƷC��ָ����ϲ���
    Product* productC = manager.createProduct("ProductC");
    if (productC) {
        manager.assignStrategy(productC->get, "Mixing",productC);
        productC->process();
    }
    return 0;
}
