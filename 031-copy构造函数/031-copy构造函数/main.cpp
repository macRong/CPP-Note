//
//  main.cpp
//  031-copy构造函数
//
//  Created by mac on 2018/12/23.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 1. 利用已经存在的对象 copy给一个新的创建对象
 
 
 */


class Car
{
    int m_price;
    int m_length;
    
public:
    Car(int price, int length): m_price(price),m_length(length)
    {
        cout << "Car(int price, int lengt)" << endl;
    }
    
    // copy构造函数 (格式固定的)  自己实现了这个函数要自己写里面的
    Car (const Car &car)
    {
        this -> m_price = car.m_price;
        this -> m_length = car.m_length;
        
        cout << "Car (const Car &car)" << endl;
    }
    
    void display()
    {
        cout << this->m_price << "--" << this->m_length << endl;
    }
};




class Person
{
    int m_age;
public:
    Person(int age = 0) :m_age(age)
    {
        
    }
    
    Person(const Person &person):m_age(person.m_age)
    {
        
    }
};

class Student:Person
{
    int m_score;
public:
    Student(int age = 0, int score = 0) : m_score(score)
    {
        
    }
    
    Student(const Student &student) : Person(student),m_score(student.m_score)
    {
        
    }
};



int main(int argc, const char * argv[])
{
    Car car1(1,2);
    
    // 调用copy构造函数
    Car car2(car1);
    car2.display();
    
    // 等价于 Car car3(car2);
    Car car3 = car2;
    
    return 0;
}
