#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string oper;
        cin >> oper;
        int n;
        cin >> n;
        vector<string> v;
        string source;
        cin >> source;
        source.erase(source.begin());
        source.erase(source.end() -1 );
        stringstream ss(source);
        string token;
        while (getline(ss,token,',')) {
            v.push_back(token);
        }
        for (char ch : oper) {
            if (ch == 'R') {
                reverse(v.begin(),v.end());
            }else if (ch == 'D') {
                if (v.empty()) {
                    cout << "error";
                    break;
                }else {
                    v.erase(v.begin());
                }
            }
        }
        cout << "[";
        for (int i = 0;i<v.size();i++) {
            if ( i == v.size() -1) {
                cout << v[i];
            }else {
                cout << v[i] << ",";
            }
        }
        cout << "]";


    }
}
