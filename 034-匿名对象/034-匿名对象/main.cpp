//
//  main.cpp
//  034-匿名对象
//
//  Created by mac on 2018/12/24.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 匿名对象（临时对象）
 匿名对象：没有变量名、没有被指针指向的对象，用完后马上析构
 
 */

class Person
{
public:
    Person()
    {
        cout << "Person()" << endl;
    }
    
    Person(const Person &person)
    {
        cout << "Person(const Person &person)" << endl;
    }
    
    ~Person()
    {
        cout << "~Person()" << endl;
    }
    
    void display()
    {
        cout << "display()" << endl;
    }
};

// Person() 相当于覆盖下面的参数
void test(Person person)
{
    
}

Person test2()
{
    Person person;
    return person;
}

Person test3()
{
    return Person();
}

int main(int argc, const char * argv[])
{
    if (0) {
        Person().display();
    }
    
    if (0) {
        // 匿名对象传递  1次构造
        test(Person());
    }

    
    if (0) {
        // 2次  已经存在的传进去  要调copy构造
        Person person;
        test(person);
    }
    
    if (0) {
        // 1次构造
       Person person = test2();
    }
    
    if (0) {
        /*
         Person()
         Person(const Person &person)
         ~Person()
         ~Person()
         */
        Person person;
        Person p1 = person;
    }

    if (0)
    {
        // 2次   应该是3次， 在函数返回的时候应该会copy一个对象给外面赋值
//        Person *person = new Person();  一样

        Person person;
        person = test2();
    }
    
    if (0) {
        // 2次  编译器有响应的优化
        Person person;
        person = test3();
    }
    
    
    
    return 0;
}
