/*************************************************************************
> File Name: cf-975a.cpp
> Author: sunowsir
> GitHub: github.com/sunowsir
> Created Time: 2018年05月05日 星期六 15时01分18秒
************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <map>
using namespace std;

bool judge (string root, string *last_root, int tempi) {
    for (int i = 0; i <= tempi; i++) {
        if (last_root[i] == root) {
            return false;
        }
    }
    return true;
}

int main () {

    int n, temp, num_root, tempi;
    map<char, bool> letter;
    string str, root, last_root[1000];

    num_root = 0;
    tempi = 0;
    root = "";
    cin >> n;
    temp = n;

    for (int i = 0; i < 1000; i++) {
        last_root[i] = "";
    }

    while (n--) {

        root = "";

        cin >> str;

        letter.clear();
        for (int i = 0; i < str.size(); i++) {
            if (!letter[str[i]]) {
                letter[str[i]] = true;
                root += str[i];
            }
        }
        sort(root.begin(), root.end());
        if (judge(root, last_root, tempi)) {
            //if (n < temp - 1) {
            //    cout << " ";
            //}
            //cout << root;
            num_root++;
            last_root[tempi++] = root;
        }
    }

    //cout << endl;

    cout << num_root << endl;

    return 0;
}
