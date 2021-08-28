/*************************************************************************
	> File Name: lanqiao7_8.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月13日 星期二 20时24分54秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

void init(int *n, bool mpt[]){
    for(int i = 0; i * i <= *n; i++) {
        for(int j = 0; j * j <= *n; j++) {
            if(i * i + j * j <= *n) {
                mpt[i * i + j * j] = true;
            }
        }
    }
}

void traverse(int *n, bool mpt[]) {

    for(int i = 0; i * i <= *n; i++) {
        for(int j = 0; j * j <= *n; j++) {
            if(!mpt[*n - i * i - j * j]) {
                continue;
            }
            for(int k = 0; k * k <= *n; k++) {
                int temp = *n - i * i - j * j - k * k;
                double l = sqrt((double)temp);
                if(l == (int)l) {
                    printf("%d %d %d %d\n", i, j, k, (int)l);
                    return;
                }
            }
        }
    }

}

int main() {
    
    int n;
    bool mpt[5000010];
    memset(mpt, false, sizeof(mpt));
    
    cin >> n;

    init(&n, mpt);
    
    traverse(&n, mpt);

    return 0;
}
