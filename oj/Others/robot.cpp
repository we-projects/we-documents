/*************************************************************************
	> File Name: robot.cpp
	> Author: sunowsir
	> GitHub: github.com/sunowsir
	> Created Time: 2018年03月18日 星期日 15时32分56秒
 ************************************************************************/

#include <iostream>
using namespace std;


int main() {

    int n, step, now_x, now_y;
    string forward_direction;
    int now_direction = 1, direction[4] = {0};

    cin >> n;
    now_x = 0;
    now_y = 0;

    while(n--) {
        
        cin >> forward_direction >> step;
        if(forward_direction == "forward") {
            direction[now_direction] += step;
        }
        else if(forward_direction == "right") {
            now_direction = (now_direction + 1) % 4;
            direction[now_direction] += step;
        }
        else if(forward_direction == "back") {
            now_direction = (now_direction + 2) % 4;
            direction[now_direction] += step;
        }
        else if(forward_direction == "left") {
            now_direction = (now_direction + 3) % 4;
            direction[now_direction] += step;
        }

    }

    now_x = direction[1] - direction[3];
    now_y = direction[0] - direction[2];

    cout << now_x << " " << now_y << endl;

    return 0;
}
