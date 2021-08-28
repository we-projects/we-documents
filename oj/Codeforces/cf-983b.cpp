/*************************************************************************
	> File Name: cf-983b.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年05月16日 星期三 15时58分35秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int wise[5010];

int bitwise (int *dl, int *dr, int num) {
    int index;
    index = 0;

    for (int *id = dl; id < dr; id++) {
        //cout << "*id = " << *id << endl;
        //cout << "*(id + 1) = " << *(id + 1) << endl;
        wise[index++] = *id ^ *(id + 1);
    }

    //cout << "index = " << index << endl;

    if (index < 2) {
        return wise[0];
    }

    dl = &wise[0];
    dr = &wise[index - 1];

    return bitwise(dl, dr, index);

}

int main () {

    int n, t, a[5010];
    int *dl, *dr, l, r;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> t;

    while (t--) {
        cin >> l >> r;
        dl = &a[l - 1];
        dr = &a[r - 1];
        cout << bitwise(dl, dr, l - r) << endl;
    }

    return 0;
}
