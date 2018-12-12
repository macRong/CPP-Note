//
//  Car.cpp
//  013-声明和实现分离
//
//  Created by mac on 2018/12/12.
//  Copyright © 2018年 mac. All rights reserved.
//

#include "Car.hpp"
#include <iostream>
using namespace std;

Car::Car()
{
    cout << "Car()" << endl;
}

Car::~Car()
{
    cout << "~Car()" << endl;
}


void Car::run()
{
    cout << "run()" << endl;
}
