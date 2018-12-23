//
//  main.cpp
//  032-深拷贝
//
//  Created by mac on 2018/12/23.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;

class Car
{
    int m_price;
    char *m_name;
    
public:
    Car(int price, const char *name = NULL): m_price(price)
    {
        // 字符串要单独处理
        if (name == NULL) return;
        
        // 申请对空间存储字符串的内容  +1: '\0'  {}:清0   全都是\0
        this -> m_name = new char[strlen(name) +1] {};
        // 拷贝字符串内容到对空间 string copy
        strcpy(this -> m_name, name);
        
        cout << "Car(int price, const char *name = NULL)" << endl;
    }
    
    // copy构造函数 (格式固定的)  自己实现了这个函数要自己写里面的
    Car (const Car &car)
    {
        this -> m_price = car.m_price;
        this -> m_name = car.m_name;
        
        cout << "Car (const Car &car)" << endl;
    }
    
    ~Car()
    {
        if (this -> m_name) {
            delete[] this->m_name;
            this -> m_name = NULL;
        }
        
        cout << "~Car()" << endl;
    }
    
    void display()
    {
        cout << this->m_price << "--" << this->m_name << endl;
    }
};


int main(int argc, const char * argv[])
{
    /*
    char name[] = {'a', 'b' , 'w' , '\0'};
    const char *name2 = "rong";
    
    cout << name2 <<endl;  // {'a', 'b' , 'w' , '\0' , 'o'};   abw  遇到\0 停止
    cout << strlen(name) << endl;
     */
    
    // 在栈空间
    char name[] = {'a', 'b' , 'w' , '\0'};
    // ❌ new Car(11,name)  是堆空间， 它指向name栈空间，name是数组是传递的数组地址
    Car *car = new Car(11,name);
    car->display();
    
    delete car;
    // ✅ 应该是用自己的name接受它取传
    

    return 0;
}
