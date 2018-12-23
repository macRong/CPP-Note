//
//  main.cpp
//  032-深拷贝
//
//  Created by mac on 2018/12/23.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;

class Car
{
    int m_price;
    char *m_name;
    
public:
    Car(int price, const char *name = NULL): m_price(price)
    {
        // 字符串要单独处理
        if (name == NULL) return;
        
        // 申请对空间存储字符串的内容  +1: '\0'  {}:清0   全都是\0
        this -> m_name = new char[strlen(name) +1] {};
        // 拷贝字符串内容到对空间 string copy
        strcpy(this -> m_name, name);
        
        cout << "Car(int price, const char *name = NULL)" << endl;
    }
    
    // copy构造函数 (格式固定的)  自己实现了这个函数要自己写里面的
    Car (const Car &car):m_price(car.m_price)
    {
        // 字符串要单独处理
        if (car.m_name == NULL) return;
        
        // 申请对空间存储字符串的内容  +1: '\0'  {}:清0   全都是\0
        this -> m_name = new char[strlen(car.m_name) +1] {};
        // 拷贝字符串内容到对空间 string copy
        strcpy(this -> m_name, car.m_name);
        cout << "Car (const Car &car)" << endl;
    }
    
    // 深copy构造函数
    ~Car()
    {
        if (this -> m_name) {
            delete[] this->m_name;
            this -> m_name = NULL;
        }
        
        cout << "~Car()" << endl;
    }
    
    void display()
    {
        cout << this->m_price << "--" << this->m_name << endl;
    }
};


int main(int argc, const char * argv[])
{
    /*
    char name[] = {'a', 'b' , 'w' , '\0'};
    const char *name2 = "rong";
    
    cout << name2 <<endl;  // {'a', 'b' , 'w' , '\0' , 'o'};   abw  遇到\0 停止
    cout << strlen(name) << endl;
     */
    
    // 在栈空间
    char name[] = {'a', 'b' , 'w' , '\0'};
    // ❌ new Car(11,name)  是堆空间， 它指向name栈空间，name是数组是传递的数组地址
    Car *car = new Car(11,name);
    car->display();
    
    delete car;
    // ✅ 应该是用自己的name接受它取传
    
    
    
    // ❌ 内存覆盖  是一个内存 car2会析构一次car1的内存   浅拷贝,
    // ✅需要深拷贝  就是 深copy构造函数就可以用下面的写法
    /*
    (lldb) p &car1.m_name
    (char **) $0 = 0x00007ffeefbff598
    (lldb) p &car2.m_name
    (char **) $1 = 0x00007ffeefbff588
     */
    Car car1(11, "sdds");
    Car car2 = car1;
    
    
    
    //
    Car car11(11, "sdds");
    Car car22(11, "sdds");
    car22 = car11; // 不会调构造函数  s只是内存覆盖

    return 0;
}
