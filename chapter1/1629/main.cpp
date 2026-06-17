#include <iostream>

using namespace std;

int func(int a, int b, int c);
int main() {
    int a,b,c;
    cin >> a >> b >> c;
    cout << func(a,b,c);
}
int func(int a, int b, int c) {
    if (b == 1) return a % c;
    int ret = func(a, b/2,c);
    ret = (ret * ret) % c;
    if (b % 2 == 1) ret = (ret * a) % c;
    return ret;
}