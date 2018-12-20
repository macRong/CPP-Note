//
//  main.cpp
//  019-多态
//
//  Created by mac on 2018/12/19.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 1. 不同对象对同一事件的不同响应
 2. c++是静态语言 没有动态运行那， 所以在调用是在看编译是指针类型
 Animal *animal = new Dog();
 animal -> run();  //  Animal::run()    // 加上virtual就行了
 
 3. C++中多态通过虚函数 (virtual function)实现
 4. 只要父类中声明为虚函数，子类中重写的函数也自动为虚函数，子类中重写的函数可以不加virtual关键字, 多层继承也是虚函数
 Animal *animal = new Dog();  // 必须从Animal或者它上 开始写virtual ，
 Dog *erha = new ErHa(); //
 
 5. class 默认是private继承
 
 
 多态要素：
 1. 子类重写父类的成员函数 （override）
 2. 父类指针指向子类对象
 3. 利用父类指针调用重写的成员函数

 
 */
class Animal
{
public:
   virtual void run()
    {
        cout << "Animal::run()" << endl;
    }
};

class Dog: public Animal
{
public:
    void run()
    {
        cout << "Dog::run()" << endl;
    }
};

class Cat: public Animal
{
public:
    void run()
    {
        cout << "Cat::run()" << endl;
    }
};


int main(int argc, const char * argv[])
{
    Animal *animal = new Dog();
    animal -> run();  //  Animal::run()
    
    return 0;
}
