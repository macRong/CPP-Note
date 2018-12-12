//
//  Car.hpp
//  013-声明和实现分离
//
//  Created by mac on 2018/12/12.
//  Copyright © 2018年 mac. All rights reserved.
//

#ifndef Car_hpp
#define Car_hpp

// 只引用一次
#pragma once

#include <stdio.h>

struct Car {
    int m_age;
    
    Car();
    ~Car();
    void run();
};

#endif /* Car_hpp */
