#include <string>
#include <vector>
#include <cstring>
using namespace std;
int initial_val;
int add_val;
int dp[1000001];
int func(int num){
    if(num < initial_val) return 1e9;
    if(num == initial_val) return 0;

    if (dp[num] > -1) return dp[num];

    int res = func(num - add_val) + 1;
    if(num % 2 == 0) res = min(res, func(num / 2) + 1);
    if(num % 3 == 0) res = min(res, func(num / 3) + 1);
    return dp[num] = res;
}
int solution(int x, int y, int n) {
    memset(dp, -1, sizeof(dp));
    initial_val = x;
    add_val = n;
    int answer = func(y);
    int res = answer >= 1e9 ? -1 : answer;
    return res;
}

