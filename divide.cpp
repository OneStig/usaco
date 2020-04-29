/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int divide(int a, int b) {
    if (b == 0) {
        return INT_MAX;
    } else if (b == 1) {
        return a;
    } else if (b == -1) {
        return b == INT_MIN ? INT_MAX : -a;
    } else if (a == 0) {
        return 0;
    }

    if (a <= INT_MIN && b == -1) {
      return INT_MAX;
    }


    int sign = 1;

    if (a < 0) {
        sign *= -1;
    }

    if (b < 0) {
        sign *= -1;
    }

    int c = 0;

    for (int x = abs(a); x - abs(b) >= 0; x -= abs(b)) {
        c++;
    }

    c *= sign;

    return c >= INT_MAX ? INT_MAX : c <= INT_MIN ? INT_MIN : c;
}

int main()
{
    cout << divide(-3, 1);

    return 0;
}
