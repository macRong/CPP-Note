//
//  main.cpp
//  028-静态成员
//
//  Created by mac on 2018/12/23.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 1. 静态成员变量存在全局区
 2. 静态成员变量和全局变量比  是可以限制作用域
 3. 静态成员变量必须要初始化，在类外面 初始化不能带static
 4. 可以用类名访问      Car::m_price = 22;

 
 */


class Car {
public:
    static int m_price;

    void run()
    {
        cout << "run()" << endl;
    }
};

// 初始化static全局变量
int Car::m_price = 22;

int main(int argc, const char * argv[])
{
    Car car;
    car.m_price = 11;
    
    Car car1;
    car1.m_price = 22;
    
    Car car2;
    car2.m_price = 33;
    
    
    cout << Car::m_price << endl;  // 33 它是全局的   是要覆盖
    
    return 0;
}
