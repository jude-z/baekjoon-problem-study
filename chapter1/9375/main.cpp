#include <iostream>
#include <map>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<string,int> m;
        for (int i = 0; i<n;i++) {
            string name,type;
            cin >> name >> type;
            m[type]++;
        }
        int res = 1;
        for (auto val : m) {
            res *= val.second;
        }
        cout << res -1 << endl;
    }
}