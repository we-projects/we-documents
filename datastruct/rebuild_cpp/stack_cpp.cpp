/*
	* File     : stack_cpp.cpp
	* Author   : sunowsir
	* Mail     : sunowsir@163.com
	* Github   : github.com/sunowsir
	* Creation : Tue 17 Aug 2021 08:24:37 PM CST
*/

#include "stack_cpp.h"

my_project::stack::stack(int value) {
    this->data = (int *)malloc(sizeof(int) * value);
    this->top = -1;
    this->size = value;
}

my_project::stack::~stack() {
    free(this->data);
}

int my_project::stack::sempty() {
    return this->top == -1;
}

int my_project::stack::stop() {
    return this->data[this->top];
}

bool my_project::stack::spush(int value) {
    if (this->top + 1 == this->size) {
        return false;
    }
    this->top += 1;
    this->data[this->top] = value;
    return true;
}

void my_project::stack::spop() {
    this->top -= 1;
    return ;
}

void my_project::stack::sclear() {
    free(this->data);
}

void my_project::stack::s_test_output() {
    std::cout << "Stack = [ " << std::endl;
    for (int i = this->top; i>= 0; --i) {
        std::cout << " " << this->data[i];
        i && std::cout << ",";
    }
    std::cout << " ]" << std::endl;;
    return ;
}
