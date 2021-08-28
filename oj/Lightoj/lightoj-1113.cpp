/*************************************************************************
	> File Name: lightoj1113.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir/practice
	> Created Time: 2018年03月11日 星期日 14时21分35秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int main() {

    stack<string> backword, forward;
    string url, order;
    int n, N;
    N = 1;

    cin >> n;

    while(n--) {
        printf("Case %d:\n", N++);
        backword.push("http://www.lightoj.com/");
        while(cin >> order) {
            if(order[0] == 'Q') {
                break;
            }
            else if(order[0] == 'B') {
                forward.push(backword.top());
                backword.pop();
                if(backword.empty()) {
                    backword.push(forward.top());
                    forward.pop();
                    cout << "Ignored" << endl;
                }
                else {
                    cout << backword.top() << endl;
                }
            }
            else if(order[0] == 'F') {
                if(!forward.empty()) {
                    backword.push(forward.top());
                    forward.pop();
                    cout << backword.top() << endl;
                }
                else {
                    cout << "Ignored" << endl;
                }
            }
            else if(order[0] == 'V') {
                while(!forward.empty()) {
                    forward.pop();
                }
                cin >> url;
                cout << url << endl;
                backword.push(url);
            }
        }
        while(!backword.empty()) {
            backword.pop();
        }
        while(!forward.empty()) {
            forward.pop();
        }
    }

    return 0;
}
