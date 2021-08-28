/*************************************************************************
	> File Name: lanqiao_min_matrix.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年03月22日 星期四 22时58分33秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main() {

    int n, m, sum[501][501], max_sum, now_sum;

    cin >> n >> m;
    max_sum = -0xffffff;
    memset(sum, 0, sizeof(sum));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            
            int input;
            
            cin >> input;
            sum[i][j] = sum[i - 1][j] + input;
        
        }
    }

    for(int i = 1; i <= n; i++) {
        //j = i !!!!! 不是 j = 1;
        for(int j = i; j <= n; j++) {
            
            now_sum = 0;
            
            for(int k = 1; k <= m; k++) {
                
                now_sum += sum[j][k] - sum[i - 1][k];

                max_sum = max(max_sum, now_sum);
                
                if(now_sum < 0) {
                    now_sum = 0;
                }
            
            }
        }
    }

    cout << max_sum << endl;

    return 0;
}
