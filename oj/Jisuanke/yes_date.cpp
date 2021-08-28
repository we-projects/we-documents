/*************************************************************************
	> File Name: yes_date.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年04月10日 星期二 16时25分58秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main() {

    int day, mouth, year;
    int mouth_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char date[15];

    scanf("%s", date);

    year = atoi(strtok(date, "-"));
    mouth = atoi(strtok(NULL, "-"));
    day = atoi(strtok(NULL, "-"));
    
    if((year % 100 != 0 && year % 4 == 0) || (year % 400 == 0)) {
        mouth_days[2] = 29;
    }
    if(day > 0 && day <= mouth_days[mouth] && mouth > 0 && mouth <= 12) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}

/*
 *计蒜客c++程序设计->程序中的是与非->日期的合法性；
 */
