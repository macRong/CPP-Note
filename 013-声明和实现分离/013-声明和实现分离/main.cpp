//
//  main.cpp
//  013-声明和实现分离
//
//  Created by mac on 2018/12/12.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
#include "Car.hpp"

using namespace std;

struct Person {
    int m_age;
public:
    Person();
    ~Person();

    void run();
};

Person::Person()
{
    cout << "Person()" << endl;
}

Person::~Person()
{
    cout << "~Person()" << endl;
}

void Person::run()
{
    cout << "run()" << endl;
}



int main(int argc, const char * argv[])
{
    Person person;
    
    Car car;
    
    return 0;
}
