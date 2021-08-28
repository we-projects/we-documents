/*************************************************************************
	> File Name: cf-988a.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年06月01日 星期五 22时46分18秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>

int search (int *num, int n, int search_num) {

    for (int i = 0; i < n; i++) {
        if (num[i] == search_num) {
            return (i + 1);
        }
    }

    return -1;

}

using namespace std;

int main () {

    int num[110];
    int n, k, input;
    set<int> stu_gra;
    stu_gra.clear();

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> input;
        num[i] = input;
        stu_gra.insert(input);
    }

    if (stu_gra.size() < k) {
        cout << "NO" << endl;
    }
    else {

        cout << "YES" << endl;

        int grup_num;
        int grup[110];
        grup_num = 0;

        for (set<int>::iterator i = stu_gra.begin(); i != stu_gra.end(); i++) {
            if (grup_num == k) {
                break;
            }
            //cout << *i;
            grup[grup_num] = search(num, n, *i);
            grup_num++;
        }
        
        sort(grup, grup + grup_num);

        for (int i = 0; i < grup_num; i++) {
            if (i > 0) {
                //cout << "i = " << i << endl;
                cout << " ";
            }
            cout << grup[i] ;
        }
        cout << endl;

    }

    return 0;
}
