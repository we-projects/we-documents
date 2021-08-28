/*************************************************************************
> File Name: cf-976b.cpp
> Author: sunowsir
> GitHub: github.com/sunowsir
> Created Time: 2018年05月02日 星期三 20时05分17秒
************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int main() {

    long long n, m, k, x, y;

    cin >> n >> m >> k;

    if (k < n) {
        x = k + 1;
        y = 1;
    }
    else {
        long long mm, ms, jm, mms;
        ms = k - n + 1;
        mm = ms / (m - 1);
        mms = ms % (m - 1);
        jm = mm % 2;
        x = n - mm;
        //cout << "ms = " << ms << endl;
        //cout << "mm = " << mm << endl;
        //cout << "mms = " << mms << endl;
        //cout << "jm = " << jm << endl;
        if (jm == 0) {
            if (mms == 0) {
                x++;
                y = 2;
            }
            else {
                y = 2 + mms - 1;
            }
        }
        else {
            if (mms == 0) {
                x++;
                y = m;
            }
            else {
                y = m - mms + 1;
            }
        }
    }

    cout << x << " " << y << endl;

    return 0;
}
