//
//  main.cpp
//  008-类
//
//  Created by mac on 2018/12/9.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 1. struct: 默认权限是public   class： 默认权限是private
 2. 成员函数在全局就一份，通过隐士this来取,系统可以让隐藏this
 
 
 规范：
 int g_age;
 int m_age; // member
 int c_age; // const
 */


#pragma mark - A

// 类
struct Person
{
    // public: 默认写了public
    // 成员变量
    int m_id;
    int m_age;
    int m_height;
    
    // 成员函数
    void run()
    {
        // this = &person;  系统可以让隐藏this
        cout << "m_id=" << this -> m_id << endl;
        cout << "m_age=" << this -> m_age << endl;
        cout << "m_height=" << this -> m_height << endl;
    }
};


class Student
{
private:
    int count;
    
public:  // 默认不写public
    // 成员变量
    int age;
    
    // 成员函数
    void run()
    {
        cout << "run(), age=" << age << endl;
        cout << "count = " << count << endl;
    }
};

void funcA()
{
    // 栈空间 不需要手动释放   默认：auto
    Person person;
    person.m_age = 20;
    person.run();
    
    Student student;
    student.age = 33;  // 如果上面不写public，默认是b私有的  不能访问
    student.run();  // 如果上面不写public，默认是b私有的  不能访问
    
    
    //
    Person *rPerson = &person;
    rPerson -> m_age = 22;
    rPerson -> run();
}

#pragma mark - B

// ⚠️问题：
void funcB()
{
    Person person;
    person.m_id = 10;
    person.m_age = 20;
    person.m_height = 30;
    
    Person *pPerson = (Person *)&person.m_age;
    pPerson -> m_id = 40;
    pPerson -> m_age = 50;
    
    person.run(); // 10, 40 ,50
}


#pragma mark - C


#pragma mark - D

int main(int argc, const char * argv[]) {
    
//    funcA();
    funcB();

    return 0;
}
