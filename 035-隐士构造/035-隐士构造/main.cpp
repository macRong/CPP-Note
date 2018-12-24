//
//  main.cpp
//  035-隐士构造
//
//  Created by mac on 2018/12/24.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 
 隐士构造：
 1. 单参数的构造
 2. explicit 可以禁用隐士构造
 3.
 
 */

class Person
{
    int m_age;
public:
    Person()
    {
        cout << "Person()" << this << endl;
    }
    
    Person(int age) : m_age(age)
    {
        cout << "Person(int age)" << this << endl;
    }
    
    /*
        explicit Person(int age) : m_age(age)
        {
            cout << "Person(int age)" << this << endl;
        }
     */
    
    Person(const Person &person)
    {
        cout << "Person(const Person &person)"  << this << endl;
    }
    
    ~Person()
    {
        cout << "~Person()"  << this << endl;
    }
    
    void display()
    {
        cout << "display()" << this->m_age << endl;
    }
};

void test(Person person)
{
    
}

Person test2()
{
    return 30;
}

int main(int argc, const char * argv[])
{
    if (0) {
        Person person(10);
        // 临时对象  相当于Person(20)   用完马上销毁
        person = 20;  // Person(20);
        person.display();
    }
    
    if (0) {
        /*
         Person()0x7ffeefbff598
         Person(const Person &person)0x7ffeefbff590
         ~Person()0x7ffeefbff590
         ~Person()0x7ffeefbff598
         */
        Person person;
        test(person);
    }
    
    if (1) {
        /*
         Person(int age)0x7ffeefbff598
         Person(int age)0x7ffeefbff590
         ~Person()0x7ffeefbff590
         ~Person()0x7ffeefbff598
         */
        Person person(11);
        person = test2();
    }

    
    return 0;
}
