//
//  main.cpp
//  026-菱形继承
//
//  Created by mac on 2018/12/22.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;

// 看图

/** 菱形继承
 问题：
1、最底下子类从基类继承的成员变量冗余、重复
2、最底下子类无法访问基类的成员，有二义性
 
 解决：
 virtual 解决菱形继承的问题
 
 如果有多个重复的变量， 内存会减少内容，
 如果有1 或少个重复的变量， 内存会增大内容，  但这不是问题   ✅

 
 
 
 */

class Person
{
public:
    int m_age =1 ;
};

class Student : public Person
{
public:
    int m_score =2;
};

class Woker : public Person
{
public:
    int m_salary =3;
    
};

class Undergraduate : virtual public Student, virtual public Woker
{
public:
    int m_grade =4;
};


int main(int argc, const char * argv[])
{
    Undergraduate ug;
    ug.Student::m_age = 22;
    ug.Woker::m_age = 23;

    cout << sizeof(ug)<<endl; // 20
    
    return 0;
}
