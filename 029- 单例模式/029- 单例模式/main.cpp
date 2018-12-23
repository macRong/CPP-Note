//
//  main.cpp
//  029- 单例模式
//
//  Created by mac on 2018/12/23.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 单例：
 1. 构造函数privetej 外部禁止创建
 2. 多线程 p_thread 跨平台的线程
 3.
 
 
 */


class Person
{
public:
    int age;
    
    static Person *sharePerson()
    {
        if (ms_person == NULL)
        {
            ms_person = new Person();
        }
        
        return ms_person;
    }
    
    // 一般不存在
    static void deletePerson()
    {
        if (ms_person == NULL)
        {
            return;
        }

        delete ms_person;
        ms_person = NULL;
    }

    
private:
    // 延迟调用
    // 如果是  static Person ms_person    就是直接在栈创建了
    // 只是一个指针8字节
    static Person *ms_person;
    
    Person()
    {
        cout << "Person()" << endl;
    }
};




// ---------


class Aniaml
{
public:
    static int m_age;
};

class Cat : public Aniaml
{
public:
    static int m_age;
};


// 初始化
int Aniaml::m_age = 0;
int Cat::m_age = 0;

// 初始化
Person *Person::ms_person = NULL;

int main(int argc, const char * argv[])
{
//    // A
//    Person *p1 = Person::sharePerson();
//    Person *p2 = Person::sharePerson();
//    Person *p3 = Person::sharePerson();

    
    

    // B
//    Cat::m_age = 22;
//    Dog::m_age = 33;

//    cout << &Cat::m_age << "---" << Cat::m_age << endl;
//    cout << &Dog::m_age << "---" << Dog::m_age << endl;
    /**
     0x1000020d0---33
     0x1000020d0---33
     */
    
    
    
    
    // C
    Cat cat;
    cat:Cat::m_age = 22;
    
    cout << Cat::m_age << endl;
    cout << Aniaml::m_age << endl;

    return 0;
}
