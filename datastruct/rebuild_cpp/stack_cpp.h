/*
	* File     : stack_cpp.h
	* Author   : sunowsir
	* Mail     : sunowsir@163.com
	* Github   : github.com/sunowsir
	* Creation : Tue 17 Aug 2021 08:23:46 PM CST
*/

#ifndef _STACK_CPP_H
#define _STACK_CPP_H

#include <iostream>

namespace my_project {
    
    class stack {
    private: 
        int *data;
        int top, size;
    public: 
        stack(int);
        ~stack();

    public: 
        int sempty();
        int stop();
        bool spush(int);
        void spop();
        void sclear();
        void s_test_output();
    };

}

#endif
