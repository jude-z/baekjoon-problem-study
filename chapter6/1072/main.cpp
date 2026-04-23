#include <iostream>

using namespace std;

int main() {
    int x,y;
    cin >> x >> y;
    int z = (int)((double)y / x * 100);
    int left = 0;
    int right = 1000000000;
    int res = -1;
    while (left <= right) {
        int middle = (left + right)/2;
        int rate = (int)((double)(y + middle) / x * 100);
        if (rate > z) {
            right = middle - 1;
            res = middle;
        }else {
            left = middle + 1;
        }
    }
    cout << res;
}