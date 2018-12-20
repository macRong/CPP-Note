//
//  main.cpp
//  018-父类指针&子类指针
//
//  Created by mac on 2018/12/18.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 1. 父类指向子类安全，反之不安全，
 父: 1   子： 1，2    (父.2)
 
 
 */
class Person
{
public:
    int m_age;
};

class Student: public Person
{
public:
    int m_score;
};

int main(int argc, const char * argv[])
{
    // ✅ 安全
    Person *person = new Student();
    person -> m_age = 22;

    // ❌ 不安全 . m_score 是别的内存
    Student *student = (Student *)new Person();
    student -> m_age = 22;
    student -> m_score = 22;

    
    return 0;
}
