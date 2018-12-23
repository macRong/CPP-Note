//
//  main.cpp
//  030-const成员
//
//  Created by mac on 2018/12/23.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 const成员
 1. const成员： 被const修饰的成员变量，非静态成员函数
 2. 必须初始化（类内部初始化）可以在声明的时候直接初始化赋值
 3. 非static的const成员变量还可以在初始化列表中初始化
 
 4. const成员函数 （非静态） 声明和实现都要加上const
 5. const函数内部不能修改非static变量
 6. const函数不能修改变量,const函数可以调用const或static函数，不可以调用非const函数
 7. const函数可以重载
 8. const只能调用const
 9. 应用类型的成员变量必须初始化 （不考虑static情况） 通过初始化列表初始化
 10.
 
 */

class Car
{
public:
    const int m_price;
    const int m_wheelsCount = 4;
    
    Car() : m_price(0)
    {
        
    }
    
    void test()
    {
        cout << "test()" << endl;
    }
    
    void test() const
    {
        cout << "test() const" << endl;

    }
 //
    // 不能再这个函数内部修改当前对象的成员变量
    void run() const
    {
//        Car car;
//        car . m_price = 33;
//        this -> m_price = 33;  // ❌
        
        test();
    }
    
    void eat();
    // const Car car;
    // car.eat();
    void eat() const;
};

void Car::eat() const
{
    
}




class Person
{
    int age;
    int &m_price = age;

public:
    Person(int &age):m_price(age)
    {
        
    }
};




int main(int argc, const char * argv[])
{
    const Car car;
    car.test();
    
    return 0;
}
