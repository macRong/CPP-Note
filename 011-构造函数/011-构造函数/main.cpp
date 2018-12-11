//
//  main.cpp
//  011-构造函数
//
//  Created by mac on 2018/12/10.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 1. 构造函数可以重载
 2. 一旦有了构造函数 就必须要调其中一个构造函数
 3. 堆、栈  调构造函数， malloc()不会调用构造函数 尽量不要用
 4. 默认情况下，编译器会为每一个类生成y空的无参的构造函数 ❌
     某些特定的情形下 编译器才会生成空的无参的构造函数  ✅
 看下面汇编
 
 // 自己写了构造函数
 ->  0x100000f6a <+26>: movq   %rax, %rdi
 0x100000f6d <+29>: callq  0x100000f80               ; Person::Person at main.cpp:25
 
 
 // 没有写构造函数
 0x100000fa0 <+16>: movq   %rsi, -0x10(%rbp)
 0x100000fa4 <+20>: movl   $0x16, -0x18(%rbp)
 
 5. 自己加的构造函数 它默认不会初始化， 要自己初始化
 
 */

struct Person {
    int m_age;
    
    // 构造函数
    Person()
    {
        cout << "构造函数" << endl;
        
    }
    
    // 如果只写了下面这个构造函数， 必须用这个构造函数初始化
    Person(int age)
    {
        //  Person person(20);
        this -> m_age = age;
        cout << "构造函数(int age)" << endl;
    }
    
    void cleanPerson()
    {
        // 可以这样
        this -> m_age = 0;
        
        // 如果有很多变量可以用memset 清空所有变量
        memset(this, 0, sizeof(Person));
    }
};


// 全局区
// 这是个函数声明 不是构造函数,⚠️
// 全局区 （成员变量默认清0的）
Person g_person();
// 是构造函数
Person g_personA(22);

int main(int argc, const char * argv[])
{
    // 栈 调构造函数
    Person person;  // 成员变量没有初始化
    person.m_age= 22;
    
    // 调参数构造函数
    Person personA(22);

    // 这是个函数声明 不是构造函数,⚠️
    Person personB();

    
    // 堆  调构造函数
    Person *p1 = new Person; // 没有初始化
    Person *p2 = new Person(); // 最好加上()


    // malloc不走构造函数  尽量不要用
    Person *p3 = (Person *)malloc(sizeof(Person));
    
    return 0;
}
