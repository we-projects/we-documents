/*************************************************************************
	> File Name: luogu_p1914.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年07月23日 星期一 15时43分03秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main () {

    int n;
    string pwd;

    cin >> n >> pwd;

    for (int i = 0; i < pwd.size(); i++) {
        pwd[i] = ((pwd[i] + n - 97) % 26 + 97);
    }

    cout << pwd << endl;

    return 0;
}
