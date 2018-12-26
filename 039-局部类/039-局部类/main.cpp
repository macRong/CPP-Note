//
//  main.cpp
//  039-局部类
//
//  Created by mac on 2018/12/26.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 局部类:函数内部定义的类
 
 1. 作用域仅限于所在函数内部
 2. 其所有的成员必须定义在类内部，不允许定义static成员变量
 3. 成员函数不能直接访问函数的局部变量（static变量除外）
 
 */

void test()
{
    int age =22;
    static int height;
    
    // 不是每次调用test（）； 不是Person每次内存布局
    // 局部类
    class Person
    {

    public:
        void run()
        {
            height = 44;
          
            cout << "run()" << endl;
            // 不能访问外面函数的变量
//          age = 33;
        }
        
        static void eat()
        {
            cout << "eat()" << endl;
        }
    };
    
    Person person;
    person.run();
    
    Person::eat();
    
}


int main(int argc, const char * argv[])
{
    test();
    
    return 0;
}
