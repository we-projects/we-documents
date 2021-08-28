/*************************************************************************
	> File Name: party.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年03月22日 星期四 18时06分10秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {

    int start, all_sum, ans, now;
    bool flag;
    start = -1;
    all_sum = -1;
    ans = -1;
    now = -1;
    flag = false;

    for(int i = 200; i > 1; i--) {
        
        if(flag) {
            break;
        }

        all_sum = i * (i + 1) / 2;
        
        for(int j = 1; j < i; j++) {
            start = j * (j + 1) / 2;
            if(all_sum - start == 236) {
                ans = j;
                now = i;
                flag = true;
                break;
            }
        }
    }

    cout << ans + 1 << endl;
    cout << "now years = " << now << endl;

    return 0;

}
