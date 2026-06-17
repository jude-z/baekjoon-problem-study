#include <iostream>
#include <vector>
using namespace std;
int main() {
    int a,b,c;
    cin >> a >> b >> c;
    int cnt[200] = {0};
    for (int i = 0; i<3;i++) {
        int start_time,end_time;
        cin >> start_time >> end_time;
        for (int j = start_time;j<end_time;j++) cnt[j]++;
    }
    int sum = 0;
    for (int i = 1;i<=99;i++) {
        if (cnt[i] == 1) sum += a;
        else if (cnt[i] == 2) sum += (2*b);
        else if (cnt[i] == 3) sum += (3*c);
    }
    cout << sum;
};