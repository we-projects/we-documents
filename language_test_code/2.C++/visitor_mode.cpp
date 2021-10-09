/*
	* File     : visitor_mode.cpp
	* Author   : sunowsir
	* Mail     : sunowsir@163.com
	* Github   : github.com/sunowsir
	* Creation : 2021年10月09日 星期六 20时02分02秒
*/

#include <iostream>

class Visitor;

/* 被访问者1 */
class Worker_1 {
public: 
    /* 访问者接收方法 */
    bool accept(Visitor *visitor);
public: 
    bool on_work(int arg);
};

/* 被访问者2 */
class Worker_2 {
public: 
    /* 访问者接收方法 */
    bool accept(Visitor *visitor);
public: 
    bool on_work(int arg);
};

/* 访问者 */
class Visitor {
public: 
    /* Worker_1 的访问方法 */
    bool visit(Worker_1 *worker_1);

    /* Worker_2 的访问方法 */
    bool visit(Worker_2 *worker_2);
};

bool Worker_1::accept(Visitor *visitor) {
    std::cout << "bool Worker_1::accept(Visitor *visitor);" << std::endl;
    return visitor->visit(this);
}

bool Worker_1::on_work(int arg) {
    std::cout << "bool Worker_1::on_work(" << arg << ");" << std::endl;
    return true;
}

bool Worker_2::accept(Visitor *visitor) {
    std::cout << "bool Worker_2::accept(Visitor *visitor);" << std::endl;
    return visitor->visit(this);
}

bool Worker_2::on_work(int arg) {
    std::cout << "bool Worker_2::on_work(" << arg << ");" << std::endl;
    return true;
}

bool Visitor::visit(Worker_1 *worker_1) {
    std::cout << "bool Visitor::visit(Worker_1 *worker_1);" << std::endl;
    return worker_1->on_work(1);
}

bool Visitor::visit(Worker_2 *worker_2) {
    std::cout << "bool Visitor::visit(Worker_2 *worker_2);" << std::endl;
    return worker_2->on_work(2);
}

int main() {
    Visitor *visitor = new Visitor;
    Worker_1 *worker_1 = new Worker_1;
    Worker_2 *worker_2 = new Worker_2;

    worker_1->accept(visitor);
    worker_2->accept(visitor);

    return 0;
}

