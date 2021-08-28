/*************************************************************************
	> File Name: P1540.cpp
	> Author:    sunowsir
	> Mail:      sunowsir@protonmail.com
	> Created:   2018年08月25日 星期六 17时16分58秒
 ************************************************************************/

#include <cstring>
#include <iostream>
using namespace std;

int main() {

    int n, m, used_m_num, search_num;
    int used_m[1010];

    memset(used_m, 0, sizeof(used_m));
    cin >> m >> n;
    used_m_num = 0;
    search_num = 0;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        if (!!used_m[input]) {
            continue;
        }
        else if (used_m_num < m) {
            search_num++;
            used_m_num++;
            used_m[input] = used_m_num;
        }
        else if (used_m_num >= m) {
            search_num++;
            used_m_num++;
            used_m[input] = used_m_num;
            int min_in, min_index;
            min_in = 1010;
            min_index = 1001;
            for (int j = 0; j <= 1000; j++) {
                if (min_in > used_m[j] && used_m[j] != 0) {
                    min_in = used_m[j];
                    min_index = j;
                }
            }
            used_m[min_index] = 0;
            used_m[input] = used_m_num;
        }
    }

    cout << search_num << endl;

    return 0;
}
