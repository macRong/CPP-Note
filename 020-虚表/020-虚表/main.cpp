//
//  main.cpp
//  020-虚表
//
//  Created by mac on 2018/12/19.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 多态的实现:
 1. 在对象内存的首地址增加8字节（arm64环境）用于存放续表
内存地址           内存数据
 8字节的续表地址    0x9349932
 int age;        20
 int height;     22
 
 8字节的虚表地址（map）：
内存地址        内存数据
 0x9349932     0x2376784  // 函数的调用地址 // 0x9349932: 是dog对应的地址  函数的地址,Dog::run()
 0x732743      0x8743763
 
 Animal *animal = new Dog();
 animal -> run();  //  Animal::run()
 
 
 
 
 // 证明
 // dog指针地址指向的内存地址
 0x00000001020096b0 > F0 20 00 00 01 00 00 00 14 00 00 00 00 00 00 00
 // 虚表地址
 F0 20 00 00 01 00 00 00 > 00000001000020F0 > 0x1000020F0
 // 续表地址取前8个字节的函数地址
 0x1000020F0 > 70 10 00 00 01 00 00 00 C0 10 00 00 01 00 00 00
 
 70 10 00 00 01 00 00 00 > 0000000100001070 > 0x100001070
 C0 10 00 00 01 00 00 00 > 00000001000010C0 > 0x1000010C0
 
// 汇编指令对照 (⚠️： 断点在汇编处， step into 进入函数去看函数地址 就行)
 020-虚表`Dog::run:
 0x100001070 <+0>:  pushq  %rbp
 0x100001071 <+1>:  movq   %rsp, %rbp
 0x100001074 <+4>:  subq   $0x20, %rsp
 0x100001078 <+8>:  movq   0xf91(%rip), %rax         ; (void *)0x00007fff9fe65660: std::__1::cout
 0x10000107f <+15>: leaq   0xe85(%rip), %rsi         ; "Dog::run()"
 0x100001086 <+22>: movq   %rdi, -0x18(%rbp)
 

 020-虚表`Dog::sleep:
 0x1000010c0 <+0>:  pushq  %rbp
 0x1000010c1 <+1>:  movq   %rsp, %rbp
 0x1000010c4 <+4>:  subq   $0x20, %rsp
 0x1000010c8 <+8>:  movq   0xf41(%rip), %rax         ; (void *)0x00007fff9fe65660: std::__1::cout
 0x1000010cf <+15>: leaq   0xe40(%rip), %rsi
 
 
 
 2. 所有的同一个对象（new Dog()）公用一个虚表,也就是每个类一个虚表
 3. 如果子类没有重写父类的虚函数， 子类中虚表就是存的父类的虚函数
 4. 每个类都有自己的虚表，虚表不存在继承
 
 */

class Animal
{
public:
    int age;
public:
    virtual void run()
    {
        cout << "Animal::run()" << endl;
    }
    
    virtual void sleep()
    {
        cout << "Animal::sleep()" << endl;
    }
};

class Dog: public Animal
{
    int height;
    
public:
    void run()
    {
        cout << "Dog::run()" << endl;
    }
    
    void sleep()
    {
        // 相当于super.sleep()
        Animal::sleep();
        
        cout << "Dog::sleep()" << endl;
    }
};

class Cat: public Animal
{
public:
    void run()
    {
        cout << "Cat::run()" << endl;
    }
    

};


int main(int argc, const char * argv[])
{
//    cout << sizeof(Dog) << endl;
    
    Animal *animal = new Dog();
    animal -> age = 20;
    animal -> run();  //  Animal::run()
    animal -> sleep();  //  Animal::run()

    
    return 0;
}
