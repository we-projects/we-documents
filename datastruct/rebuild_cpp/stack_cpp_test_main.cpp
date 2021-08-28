/*
	* File     : stack_cpp_test_main.cpp
	* Author   : sunowsir
	* Mail     : sunowsir@163.com
	* Github   : github.com/sunowsir
	* Creation : Tue 17 Aug 2021 08:49:38 PM CST
*/

#include <time.h>
#include "stack_cpp.h"

#define MAX_OP 20

int main () {
    srand(time(0));

    my_project::stack *s = new my_project::stack(MAX_OP);
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 4, value = rand() % 100;
        switch (op) {
            case 0 :
            case 1 : 
            case 2 : 
                std::cout << "push " << value << " to Stack" << std::endl;
                s->spush(value);
                s->s_test_output();
                break;
            case 3 : 
                std::cout << "pop " << s->stop() << " from Stack" << std::endl;
                s->spop();
                s->s_test_output();
                break;
        }
    }

    return 0;
}
