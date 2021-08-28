/*************************************************************************
	> File Name: lightoj-1412.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir/practice
	> Created Time: 2017年08月31日 星期四 21时31分01秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

deque<int> deq;

void Deque(int n, int m){
    string operate;
    int operate_num;
    while (m--) {
        cin >> operate;
        if (operate[1] == 'u') {
            cin >> operate_num;
            if ( deq.size() == n || deq.size() > n ) {
                cout << "The queue is full" << endl;
            }
            else {
                if ( operate[4] == 'L') {
                    cout << "Pushed in left: " << operate_num << endl;
                    deq.push_front (operate_num);
                }
                else {
                    cout << "Pushed in right: " << operate_num << endl;
                    deq.push_back(operate_num);
                }
            }
        }
        else {
            if ( deq.empty () ) {
                cout << "The queue is empty" << endl;
            }
            else {
                if ( operate[3] == 'L') {
                    cout << "Popped from left: " << deq.front() << endl;
                    deq.pop_front();
                }
                else {
                    cout << "Popped from right: " << deq.back() << endl;
                    deq.pop_back();
                }
            }
        }
    }
}

int main(){
    int T, N, n, m;
    N = 1;
    cin >> T;
    while (T--) {
        deq.clear();
        printf("Case %d:\n",N++);
        cin >> n >> m;
        Deque(n, m);
    }
    return 0;
}
