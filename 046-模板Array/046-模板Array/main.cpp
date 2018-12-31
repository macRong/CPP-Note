//
//  main.cpp
//  046-模板Array
//
//  Created by mac on 2018/12/31.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
#include "Array.hpp"
using namespace std;

/*
 1. 如果申请5个空间 后面再增加怎么办？
    🌲：申请一个更大的空间 把5个元素迁移过去，之前5个空间释放掉，为了array连续  （地址会改变）   扩容
 
 */


// 模板声明连在一起就行， 换行也行
/* ❌No matching constructor for initialization of 'Person'
   初始化没有找到构造函数
 🌲：1. 可以在构造函数加上默认参数值  也就是可不可以传值都行
     2. 写无参构造函数
 
 */

class Person
{
    friend ostream &operator<<(ostream &, const Person &);
    int m_age;
public:
    Person(int age = 0) :m_age(age) { }
};

ostream &operator<<(ostream &cout, const Person &person)
{
    return cout << "age=" << person.m_age;
}


int main(int argc, const char * argv[])
{
//    Array<Person > arr(5);
////    arr.add(1);
//    arr.add(Person(22));
//
////    arr.display();
////
////    cout << arr << endl;
    
    Array<Person> array(3);
    array.add(Person(11));
//    array.add(Person(12));
//    array.add(Person(13));
//    cout << array << endl;

    
    return 0;
}
