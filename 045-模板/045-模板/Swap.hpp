//
//  Swap.hpp
//  045-模板
//
//  Created by mac on 2018/12/31.
//  Copyright © 2018年 mac. All rights reserved.
//

#ifndef Swap_hpp
#define Swap_hpp

#include <stdio.h>
//#pragma once;

template <class T> void swapVal(T &v1, T &v2)
{
    T temp = v1;
    v2 = v2;
    v2 = temp;
}

#endif /* Swap_hpp */
