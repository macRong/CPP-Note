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
 数据段 data segement（全局区）
 1. 静态成员变量存在全局区   内存在内存只有一份
 2. 静态成员变量和全局变量比  是可以限制作用域
 3. 静态成员变量必须要初始化，在类外面 初始化不能带static
 4. 可以用类名访问      Car::m_price = 22;
 5. 内部不可以用this (this用在非静态成员函数)
 6. 不能是虚函数 (虚函数只能是非静态成员函数)
 7. 内部不能访问非静态成员变量/函数， 只能访问static的
 8. 只要是函数都在代码区
 9. 当声明和实现分离， 实现不能带static
 
 
 访问：
 1. 对象.访问
 2. 指针 -> 访问
 3. 类名::访问
 
 */



/*

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
 */



// 简单用处
class Car {
private:
    static int ms_count;
public:
   Car ()
    {
        ms_count ++;
    }
    
    ~Car ()
    {
        ms_count --;
    }
    
    // 静态函数
    static void eeat()
    {
        cout << "static sleep()" << endl;
        
    }
    
    
   static int getCount()
    {
        return ms_count;
    }
    

    
    

};

// 初始化static变量
int Car::ms_count = 0;

int main(int argc, const char * argv[])
{
    /*
    Car car1;
    Car car2;
    
    Car *p = new Car();
    delete p;
    
    cout << "m_count = " << car2.getCount() << endl;
     */
    
    
//    cout << Car::sleep() << endl;

    Car::eeat();

    
    return 0;
}
