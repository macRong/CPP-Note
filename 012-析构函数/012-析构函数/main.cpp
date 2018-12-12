//
//  main.cpp
//  012-析构函数
//
//  Created by mac on 2018/12/12.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 1. 析构不可以重载
 2. malloc/free 不调构造函数 析构函数
 3. 析构的作用，防止内存泄露， 如成员变量是指针
 
 */


struct Car
{
    Car()
    {
        cout << "Car()" << endl;
    }
    
    ~Car()
    {
        cout << "~Car()" << endl;
    }
};

struct Person {
    int m_age;
    Car *car; // 指针 要在析构中销毁
    
    Person()
    {
        cout << "Person()" << endl;
        
        this -> car = new Car();
    }
    
    // 不可以重载
    ~Person()
    {
        cout << "~Person()" << endl;
        
        delete this->car;
        
    }
};
int main(int argc, const char * argv[])
{
    
//    Person person;
    
    /**
     不调构造函数 析构函数 ，最好不要这么写
     Person *person1 = (Person *)malloc(sizeof(Person));
     free(person1);
   */
    
    Person *p = new Person();
    
    
    delete p;
    
    
    return 0;
}
