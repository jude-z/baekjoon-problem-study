#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int num;
        cin >> num;
        int temp = num;
        int two_cnt = 0;
        int five_cnt = 0;
        for (int i = 2;i<=temp;i*=2) {
            two_cnt += num / i;
        }
        for (int i = 5; i<=temp;i*=5) {
            five_cnt += num / i;
        }
        cout << min(five_cnt,two_cnt) << endl;
    }
}