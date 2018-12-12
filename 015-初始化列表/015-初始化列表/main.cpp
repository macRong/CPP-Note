//
//  main.cpp
//  015-初始化列表
//
//  Created by mac on 2018/12/12.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 1. 初始化列表 Person(int age, int height) : m_age(age),m_height(height)  语法糖看起来挺x 其实一样功能
 2. 顺序和初始化成员变量顺序有关
 3. 构造函数调构造函数  必须用初始化列表才行
 
 */

struct Person {
    int m_age;
    int m_height;
    
    
    // 构造函数调构造函数
    Person() : Person(1,1) // ✅
    {
        // 不能这样写 必须初始化列表 ❌   这只是临时对象
        //        Person(1,1);
    }
    
    // 初始化列表
    //    Person(int age, int height) : m_age(1),m_height(2) 也可以
    // 顺序和初始化成员变量顺序有关 先走 m_age(age)，因为int m_age在前
    Person(int age, int height) : m_age(age),m_height(height)
    {
        // 就是和下面一样的实现
        
        // 这个不用写， 如果写了 就是  4，5 赋值
        //        this -> m_age = 4;
        //        this -> m_height = 5;
    }
    
    
    
    ~Person ()
    {
        
    }
};

int main(int argc, const char * argv[])
{
    
    Person person;
    
    
    cout<< person.m_age << endl;
    cout<< person.m_height << endl;
    
    
    return 0;
}
