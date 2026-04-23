#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n+1);
    v[0] = "default";
    map<string,int> cnt_m;
    for (int i = 1; i<=n;i++) {
        cin >> v[i];
        cnt_m[v[i]] = i;
    }
    for (int i = 0; i<m;i++) {
        string str;
        cin >> str;
        if (isdigit(str[0])) {
            int idx = stoi(str);
            cout << v[idx] << endl;
        }else {
            cout << cnt_m[str] << endl;
        }
    }

    return 0;
}
