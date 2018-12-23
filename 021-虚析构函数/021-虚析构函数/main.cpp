//
//  main.cpp
//  021-虚析构函数
//
//  Created by mac on 2018/12/21.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 1. 多态在delete的时候， 父类析构函数需要加上virtual
 
 */

class Animal
{
public:
    int age;

    virtual void run()
    {
        cout << "Animal::run()" << endl;
    }
    
    virtual void sleep()
    {
        cout << "Animal::sleep()" << endl;
    }
    
    virtual ~Animal()
    {
        cout << "~Animal()" << endl;
    }
};

class Cat: public Animal
{
public:
    void run()
    {
        cout << "Cat::run()" << endl;
    }
    
    ~Cat()
    {
        cout << "~Cat()" << endl;
    }
    
};

int main(int argc, const char * argv[])
{
    /*  ✅
     Cat::run()
    ~Cat()
    ~Animal()
     */
//    Cat cat;
//    cat.run();
    
    
    
    
    /* ❌ 没有调 ~Cat()   父类析构添加virtual就行了
     Cat::run()
     ~Animal()
     */
    Animal *cat2 = new Cat();
    cat2->run();
    
    delete cat2;
    
    return 0;
}
