/*************************************************************************
	> File Name: HDU2072.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir/practice
	> Created Time: 2017年09月01日 星期五 12时13分51秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int main() {
    string word;
    while ( getline (cin, word) && word != "#" ) {
        istringstream stream (word);
        set<string> str;
        string treated_word;
        while ( stream >> treated_word ) {
            str.insert ( treated_word );
        }
        cout << str.size() << endl;
    }
    return 0;
}
