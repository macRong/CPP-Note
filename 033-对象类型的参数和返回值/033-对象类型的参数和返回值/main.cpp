//
//  main.cpp
//  033-对象类型的参数和返回值
//
//  Created by mac on 2018/12/24.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 
 只要copy中有指针要copy的时候要实现copy构造函数
 
 // 在栈区
 char a[] = "abc";
 */

class Car
{
    int m_price;
public:
    Car(int price =0) : m_price(price)
    {
        cout << "Car(int price =0)" << endl;
    }
    
    Car(const Car &car):m_price(car.m_price)
    {
        cout << "Car(const Car &car)" << endl;
    }
};

//  等价 void test(Car car = car) 回调用copy构造函数, 临时生成
void test(Car car)
{
    
}

// 可以
void test1(const Car &car)
{
    
}


Car test2()
{
    Car car (11);
    
    // 看到外面有人用car， 就类似  Car（car）；新对象给你   是栈空间
    return car;
}

int main(int argc, const char * argv[])
{
    Car car (11);
    test(car);
    
    // 3次
    Car car3;
    car3 = test2();
    
    
    // 也是copy构造  2次  是对的， 用右边的取初始化左边的    copy优化
    Car car2 = test2();
    
    
    return 0;
}
