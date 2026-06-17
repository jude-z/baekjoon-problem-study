#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v(9);
    int sum = 0;
    for (int i = 0; i<9;i++) {
        cin >> v[i];
        sum += v[i];
    }
    int target = sum - 100;
    sort(v.begin(),v.end());
    int left = 0;
    int right = 8;
    while (left < right) {
        int temp = v[left] + v[right];
        if (temp == target) {
            v.erase(v.begin() + left);
            v.erase(v.begin() + left);
        }else if (temp < target) left++;
        else if (temp > target) right--;
    }
    for (auto val : v) {
        cout << val << endl;
    }

}