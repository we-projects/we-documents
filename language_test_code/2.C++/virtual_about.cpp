/*
	* File     : virtual_about.cpp
	* Author   : sunowsir
	* Mail     : sunowsir@163.com
	* Github   : github.com/sunowsir
	* Creation : 2021年09月02日 星期四 16时03分30秒
*/

#include <bits/stdc++.h>

using namespace std;

class Animal {
private:
    int CName;
public:
    Animal(int New_Name);

public:
    virtual void output_test();
    int get_cname();
};

typedef void (*vfunc)(void);


class Empty_test {
};

class Empty_test_sun : public Empty_test {
public: 
    virtual void vfunc_test();
};







Animal::Animal(int New_Name) : CName(New_Name) {
};

void Animal::output_test() {
    std::cout << "Animal::output_test()" << std::endl;
}

int Animal::get_cname() {
    return this->CName;
}

void Empty_test_sun::vfunc_test() {
    
}

int main() {
    /* 
     * 通过地址访问类中的徐函数表、属性以及虚函数
     */


    Animal *ani = new Animal(1123);

    /* 虚函数表的地址*/
    vfunc **vtbptr_anim = (vfunc**)ani;
    /* Animal::CName 的地址 */
    int *cname_anim = (int*)((long*)ani + 1);
    /* 虚函数表里第一个函数的地址 */
    vfunc *vfunc_anim = *vtbptr_anim;

    /* 输出以及调用测试 */

    /* 通过对象调用public接口打印Animal::CName */
    std::cout << "by ani->getcname() access Animal::CName : " << ani->get_cname() << std::endl;
    /* 通过地址访问Animal::CName */
    std::cout << "by address access Animal::CName : " << *(cname_anim) << std::endl;

    /* 通过地址调用 Animal::output_test() */
    std::cout << "by address call Animal::output_test() : " << std::endl;
    (*vfunc_anim)();


    /* 
     * 空类系列测试
     */

    std::cout << "sizeof(Empty_test) == " << sizeof(Empty_test) << std::endl;
    std::cout << "sizeof(Empty_test_sun) == " << sizeof(Empty_test_sun) << std::endl;


    return 0;
}

