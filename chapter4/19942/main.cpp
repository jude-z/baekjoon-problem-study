#include <iostream>
#include <vector>

using namespace std;
class Food {
public:
    int mp,mf,ms,mv;
    int price;
};
vector<Food> foods;
vector<int> check;
Food target;
bool check_range(Food* food_ptr) {
    return food_ptr -> mp >= target.mp && food_ptr -> mf >= target.mf && food_ptr -> ms >= target.ms && food_ptr -> mv >= target.mv;
}
int res = INT_MAX;
void dfs(Food* food_ptr,int price) {
    if (check_range(food_ptr)) {
        res = min(res,price);
        return;
    }
    for (int i = 0;i<check.size();i++) {
        if (!check[i]) {
            check[i] = 1;
            food_ptr -> mp += foods[i].mp;
            food_ptr -> mf += foods[i].mf;
            food_ptr -> ms += foods[i].ms;
            food_ptr -> mv += foods[i].mv;
            dfs(food_ptr,price + foods[i].price);
            check[i] = 0;
        }
    }

}
int main() {
    int n;
    cin >> n;
    foods = vector<Food>(n);
    cin >> target.mp >> target.mf >> target.ms >> target.mv;
    for (int i = 0; i<n;i++) {
        cin >> foods[i].mp >> foods[i].mf >> foods[i].ms >> foods[i].mv >> foods[i].price;
    }
    check = vector<int>(n);
    Food* food_ptr = new Food();
    dfs(food_ptr,0);
    cout << res;
}
