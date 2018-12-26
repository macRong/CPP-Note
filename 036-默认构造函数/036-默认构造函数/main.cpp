//
//  main.cpp
//  036-默认构造函数
//
//  Created by mac on 2018/12/24.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;

/*
 1. C++在特定的情况下，会生成无参的构造函数
 2. 创建完有事件做会生成默认构造函数
 3. 有定义虚函数
 4. 虚继承了其他类
 5. 父类有构造函数（编译器生成或自定义）
 6. 包含了对象类型的成员（Car *car；是指针类型不是对象类型， Car car）,且这个成员有构造函数（编译器生成或自定义）
 
 对象创建后，需要做一些额外的操作时（r比如内存操作 函数调用）编译器一般都会为其
 */

class Person
{
public:
    // 生成默认构造函数
    int m_age = 10;
    
    // int m_age; 这个不会生成默认构造函数
};

class Car
{
public:
    // 会创建虚表
    virtual void run()
    {
        
    }
};

class Animal
{
    
};

class Cat: virtual public Animal
{
    
};

class A
{
public:
    A()
    {
        
    }
};

class B
{
public:
    A a;
};

int main(int argc, const char * argv[])
{
    if (0) {
        // 不会生成构造函数
        Person person;
        person.m_age = 33;
    }
    
    if (0) {
        // 生成构造函数
        Car car;
    }
    
    if (0) {
        // 生成构造函数
        Cat cat;
    }

    if (0)
    {
        // 生成构造函数
        // 因为A有构造函数  有事情干
        B b;
    }
    
    return 0;
}
