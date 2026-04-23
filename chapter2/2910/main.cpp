#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
struct  Node {
    int value;
    int cnt;
    int order;
    Node(int value, int cnt, int order):value(value),cnt(cnt),order(order){}
};
int main() {
    int n, c;
    cin >> n >> c;
    map<int,int> cnt_map;
    map<int,int> order_map;
    int idx = 1;
    for (int i = 0; i<n;i++) {
        int value;
        cin >> value;
        cnt_map[value]++;
        if (order_map[value] == 0) order_map[value] = idx++;
    }
    vector<Node> v;
    for (auto val : cnt_map) {
        v.push_back(Node{val.first,val.second,order_map[val]});
    }
    sort(v.begin(),v.end(),[](Node n1, Node n2) {
        if (n1.cnt != n2.cnt) return n1.cnt > n2.cnt;
        return n1.order < n2.order;
    });
}
