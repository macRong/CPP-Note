//
//  main.cpp
//  014-命令空间
//
//  Created by mac on 2018/12/12.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
#include "Car.hpp"
using namespace std;
using namespace Rong_Car;

/**
 1. using namespace Rong; 下面都是Rong空间，  ⚠️不要冲突函数
 2. namespace 可以嵌套
 3. using Rong::g_height;  // 仅Rong::g_height
 4. 默认是namespace  ::run();
 
 */

struct Person {
    int m_age;
};


namespace Rong
{
    // 全局变量
    int g_height;
    
    struct Person {
        int m_age;
    };
}

namespace Mac
{
    // 全局变量
    int g_height;
    
    struct Person
    {
        int m_age;
    };
}

// 命名空间可以嵌套
namespace AA
{
    namespace BB
    {
        // 全局变量
        int g_height;
        
        struct Person
        {
            int m_age;
        };
    }
}

void test()
{
    
}


int main(int argc, const char * argv[])
{
    Person person;
    Rong::Person persona();
    Rong::g_height = 22;
    
    
    // 命名空间可以嵌套
    AA::BB::Person personB;
    
    cout<< &personB << endl;
    
    // 默认的namespace
    ::test();
    
    /*
        // A 如果有一堆函数用Rong:: 麻烦
        using namespace Rong; // 这个开始下面都是Rong的作用域
        Person personn() // Rong::person1();
   */
    
    // B 只使用Rong下的g_height 其他的不可以
    using Rong::g_height;
    
     Rong::Person personn;
    
    return 0;
}
