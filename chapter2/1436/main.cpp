#include <iostream>

using namespace std;
bool check(int num){
    int cnt = 0;
    while(num > 0){
        if(num % 10 == 6){
            cnt++;
        }else{
            cnt = 0;
        }
        if(cnt >= 3) return true;
    }
    return false;
}
int main(){
    int n;
    int cnt = 0;
    for(int i = 1;;i++){
        if(check(i)) cnt++;
        if(cnt == n){
            cout << i;
            break;
        }
    }
}