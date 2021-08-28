/*************************************************************************
	> File Name: cf946b.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir/practice
	> Created Time: 2018年03月10日 星期六 15时23分33秒
 ************************************************************************/

#include <iostream>
using namespace std;

#define ll long long int

bool judge(ll a, ll b) {
    if(a != 0 && b != 0) {
        return true;
    }
    return false;
}

bool judge_two(ll *a, ll *b) {
    if(*a >= 2 * *b) {
        *a %= 2 * *b;
        return true;
    }
    return false;
}

bool judge_three(ll *a, ll *b) {
    if(*b >= 2 * *a) {
        *b %= 2 * *a;
        return true;
    }
    return false;
}

int main() {

    ll a, b;

    cin >> a >> b;

    while(judge(a, b)) {

        if(judge_two(&a, &b)) {
            continue;
        }
        else {
            if(judge_three(&a, &b)) {
                continue;
            }
            else {
                break;
            }
        }
    }

    cout << a << " " << b << endl;

    return 0;
}
