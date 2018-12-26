//
//  main.cpp
//  038-内部类
//
//  Created by mac on 2018/12/26.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;

/*
内部类有点像友元
 1. 支持public，private。。。
 2. 成员函数可以直接访问其外部类对象的所有成员（反过来则不行）
 3. 成员函数可以直接不带类名、对象名访问其外部类的static成员
 4，不影响外部类内存布局
 5. 可以在外部类内部声明，在外定义
 
 
 用处：
 这个A类只用在B类里， 可以用内部使用
 
 */

// Person
class Person
{
    int m_age;
    static int ms_aa;
    static void test();
public:
    Person()
    {
        cout << "Person()" << endl;
    }
    
    // Public private 等支持这些权限
    // Car
    class Car
    {
    public:
        int m_price;

        Car()
        {
            cout << "Car()"  << endl;
        }
        
        void run()
        {
            ms_aa = 11;
            Person::test();
            test(); // 可以直接调
        }
    };
};

class Student:Person
{
  void test()
    {
        Car car;
    }
};


#pragma mark -A

class Point
{
    class Math;
};

class Point::Math
{
    void test()
    {
        
    }
};


#pragma mark -B

class Point1
{
    class Math1;
};

class Point1::Math1
{
    void test();
};


void Point1::Math1::test()
{
    
}


#pragma mark -C

class Point3
{
  class Math3
    {
        void test();
    };
};

void Point3::Math3::test()
{
    
}

int main(int argc, const char * argv[])
{
    Person::Car car;
    car.m_price = 11;
    
    return 0;
}
