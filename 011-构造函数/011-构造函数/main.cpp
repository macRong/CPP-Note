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
};

int main(int argc, const char * argv[])
{

    Person person;
    
    return 0;
}
