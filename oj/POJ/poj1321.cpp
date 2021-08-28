/*************************************************************************
	> File Name: poj1321.cpp
	> Author: sunowsir
	> GetHub:github.com/sunowsir/practice 
	> Created Time: 2017年10月12日 星期四 21时59分51秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;


#define cls(x, y) memset(x, y, sizeof(x))
int n, k, ans, num;
char Map[15][15];
bool book[20];

int dfs(int x, int num) {
    if(num == k) {
        ans++;
        return ans;
    }
    if(x >= n) {
        return ans;
    }
    for(int i = 0; i < n; i++) {
        if(Map[x][i] == '#' && !book[i]) {
            book[i] = true;
            dfs(x + 1, num + 1);
            book[i] = false;
        }
    }
    dfs(x + 1, num);
    return ans;
}

int main() {
    while(cin >> n >> k && n != -1 && k != -1) {
        cls(Map, 0);
        cls(book, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> Map[i][j];
            }
        }
        ans = 0;
        num = 0;
        cout << dfs(0, 0) << endl;
    }
    return 0;
}
