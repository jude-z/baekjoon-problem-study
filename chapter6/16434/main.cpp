#include <iostream>
#include <climits>
#include <cmath>
using namespace std;
typedef long long ll;
ll atk, cur_hp, max_hp, monster_atk, monster_hp;
int n;
ll res;
int main() {
    cin >> n >> atk;
    ll left = 1;
    ll right = LONG_LONG_MAX;
    while (left <= right) {
        ll mid = (left + right) / 2;
        max_hp = mid;
        cur_hp = max_hp;
        bool flag = true;
        while (n--) {
            int t,a,h;
            cin >> t >> a >> h;
            if (t == 1) {
                monster_atk = a;
                monster_hp = h;
                int warrior_cnt = (int)(ceil((double)monster_hp / atk));
                int monster_cnt = (int)(ceil((double)cur_hp / atk));
                if (monster_cnt > warrior_cnt) {
                    flag = false;
                    break;
                }
            }else if (t == 2) {
                atk += a;
                cur_hp = cur_hp + h > max_hp ? max_hp : cur_hp + h;
            }
        }
        if (flag) {
            res = mid;
            right = mid -1;
        }else {
            left = mid + 1;
        }
    }
    cout << res;

}
