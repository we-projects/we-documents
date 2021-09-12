/*
 * File Name:    SmartPoint.cpp
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2019年01月21日 星期一 18时40分07秒
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

template <typename T>
class SmartPoint {
    private : 
        T *mp;
    public :
        SmartPoint (T *p = NULL) { 
            printf("p = %p\n", p);
            mp = p;
            printf("SmartPoint(){} end\n");
        }
        SmartPoint (const SmartPoint &new_val) { 
            mp = new_val.mp;
            const_cast<SmartPoint &>(new_val).mp = NULL;
        }
        T * operator -> () { 
            return mp;
        }
        T & operator * () { 
            return *mp;
        }
        SmartPoint &operator = (const SmartPoint &right) { 
            if (this != right) {
                delete this->mp;
                mp = right.mp;
                /* 防止同一个空间被两个指针指向，目的是为了防止double free  */
                const_cast<SmartPoint &>(right).mp = NULL;
            }
            printf("operator = end\n");
            return *this;
        }
        bool operator > (const SmartPoint &right) { 
            return this->mp > right.mp;
        }
        bool operator >= (const SmartPoint &right) { 
            return this->mp >= right.mp;
        }
        bool operator < (const SmartPoint &right) { 
            return this->mp < right.mp;
        }
        bool operator <= (const SmartPoint &right) { 
            return this->mp <= right.mp;
        }
        bool operator == (const SmartPoint &right) { 
            return this->mp == right.mp;
        }
        bool operator != (const SmartPoint &right) { 
            return this->mp != right.mp;
        }
        T &operator [] (const int &index) { 
            return *(this->mp + index);
            // return this->mp[index];
        }
        ~SmartPoint() { 
            if (this->mp != NULL) {
                delete this->mp;
            }
        }
};

int main() {
    SmartPoint<int> pa = new int[10];
    SmartPoint<int> pa1 = pa;
    for (int i = 0; i < 10; i++) {
        pa[i] = 10 - i;
        cout << pa[i] << endl;
    }
    return 0;
}



