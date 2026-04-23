#include <iostream>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int,int> cnt_m;
        for (int i = 0; i<n;i++){
            int temp;
            cin >> temp;
            cnt_m[temp]++;
        }
        int m;
        cin >> m;
        for (int i = 0; i<m;i++) {
            int temp;
            cin >> temp;
            if (cnt_m[temp] == 1) cout << 1 << endl;
            else cout << 0 << endl;
        }


    }
}