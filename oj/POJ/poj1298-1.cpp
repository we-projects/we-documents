/*************************************************************************
	> File Name: poj-1298.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir/practice
	> Created Time: 2017年08月31日 星期四 22时55分31秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
using namespace std;

map<char, char> m;

int main() {
    char word[210];
    char s[27] = "VWXYZABCDEFGHIJKLMNOPQRSTU";
    while ( gets(word)  && strcmp ( word, "ENDOFINPUT" ) !=0 ) {
        if ( !strcmp( word, "START" ) || !strcmp ( word, "END" ) ) {
            continue;
        }
        for(int i=0; i < strlen( word  ); i++){
            if( word[i] >= 'A' && word[i] <= 'Z' ) {
                word[i] = s[word[i] - 'A'];
            }
            cout << word[i];
        }
        cout << endl;
    }
    return 0;
}
