//
//  main.cpp
//  022-纯虚函数
//
//  Created by mac on 2018/12/21.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 1. 纯虚函数：没有函数体，并且初始化为0,用接口规范       virtual void run() = 0；
 2. 抽象类：
    a) 含有纯虚函数的类是抽象类，像Animal就是抽象类，
    b) 抽象类(纯虚函数)不可以初始化
    c) 抽象类可以保护非纯虚函数
    d) 如果子类没有全部重写父类的纯虚函数，子类也是抽象类
 
 */


// 抽象类
class Animal
{
public:
    virtual void run() = 0;
    virtual void sleep() = 0;
    
    virtual ~Animal()
    {
        cout << "~Animal()" << endl;
    }
};

class Cat: public Animal
{
public:

    /**
     如果没有全部c重写父类的纯虚函数  子类也是纯虚函数
     
    void run()
    {
        
    }
    
    void sleep()
    {
        
    }
     
     */
    
    ~Cat()
    {
        cout << "~Cat()" << endl;
    }
    
};

class Dog: public Animal
{
public:
    void run()
    {
        cout << "Dog::run()" << endl;
    }
    
    ~Dog()
    {
        cout << "~Dog()" << endl;
    }
    
};

int main(int argc, const char * argv[])
{
    
    Cat animal;
    
    
    return 0;
}
