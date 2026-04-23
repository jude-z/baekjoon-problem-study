#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int a,b;
    cin >> a >> b;
    vector<int> v_a(a);
    vector<int> v_b(b);
    for (int i = 0; i<a;i++) {
        cin >> v_a[i];
    }
    for (int i = 0; i<b;i++) {
        cin >> v_b[i];
    }
    sort(v_a.begin(),v_a.end());
    sort(v_b.begin(),v_b.end());
    int res = 0;
    for (auto a_val : v_a) {
        if (!binary_search(v_b.begin(),v_b.end(),a_val)) res++;
    }
    for (auto b_val : v_b) {
        if (!binary_search(v_a.begin(),v_a.end(),b_val)) res++;
    }
    cout << res;

}