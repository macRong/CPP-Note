//
//  main.cpp
//  025-同名函数
//
//  Created by mac on 2018/12/22.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;

/* 1️⃣ 同名函数
class Student
{
public:
    void eat()
    {
        cout << "Student::eat()" << endl;
    }
    
};

class Woker
{
public:
    void eat()
    {
        cout << "Woker::eat()" << endl;
    }
};

class Undergraduate : public Student, public Woker
{
public:
    void eat()
    {
        cout << "Undergraduate::eat()" << endl;
    }
};


int main(int argc, const char * argv[])
{
    Undergraduate ug;
    ug.eat();
    ug.Student::eat();
    ug.Woker::eat();
    
    return 0;
}
*/


/**
 同名变量 是通过作用域取得，
 */
// 2️⃣同名成员变量
class Student
{
public:
    int m_age;
    
};

class Woker
{
public:
    int m_age;

};

class Undergraduate : public Student, public Woker
{
public:
    int m_age;

};

int main(int argc, const char * argv[])
{
    Undergraduate ug;
    ug.m_age = 11;
    ug.Student::m_age = 22;
    ug.Woker::m_age = 33;

    cout << sizeof(ug);  // 12
    
    return 0;
}
