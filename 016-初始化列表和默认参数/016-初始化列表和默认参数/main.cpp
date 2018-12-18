//
//  main.cpp
//  016-初始化列表和默认参数
//
//  Created by mac on 2018/12/18.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 如果声明和实现要分离
 1. 默认参数只能写s函数声明中
 2. 构造函数的初始化列表只能写在实现中
 
 
 */
struct Person {
    int m_age;
    int m_height;
    
    //  默认参数只能写s函数声明中
    Person(int age = 0, int height = 0);
};

// 构造函数的初始化列表只能写在实现中
Person::Person(int age, int height) :m_age(age),m_height(height)
{
    cout << "Person::Person(int age, int height)" << endl;
}


int main(int argc, const char * argv[])
{

    Person person;
    Person person1(10);
    Person person2(1,3);
    
    cout << person1.m_age << endl;
    cout << person2.m_age << endl;

    return 0;
}
