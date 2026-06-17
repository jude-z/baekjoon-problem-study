#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool check(string str){
    int len = str.length();
    int idx = 0;
    int final_idx = idx + len;
    int pre_ch = 0;
    while(idx < final_idx){
        char ch = str[idx];
        if (pre_ch == ch) return false;
        if(ch == 'a'){
            if(idx + 2 >= len) return false;
            int end_idx = idx + 3;
            string comp = "aya";
            int comp_idx = 0;
            while(idx < end_idx){
                if(str[idx++] != comp[comp_idx++]) return false;
            }
            pre_ch = ch;
        }else if(ch == 'y'){
            if(idx + 1 >= len) return false;
            int end_idx = idx + 2;
            string comp = "ye";
            int comp_idx = 0;
            while(idx < end_idx){
                if(str[idx++] != comp[comp_idx++]) return false;
            }
            pre_ch = ch;
        }else if(ch == 'w'){
            if(idx + 2 >= len) return false;
            int end_idx = idx + 3;
            string comp = "woo";
            int comp_idx = 0;
            while(idx < end_idx){
                if(str[idx++] != comp[comp_idx++]) return false;
            }
            pre_ch = ch;
        }else if(ch == 'm'){
            if(idx + 1 >= len) return false;
            int end_idx = idx + 2;
            string comp = "ma";
            int comp_idx = 0;
            while(idx < end_idx){
                if(str[idx++] != comp[comp_idx++]) return false;
            }
            pre_ch = ch;
        }else {
            return false;
        }
    }
    return true;
}
int solution(vector<string> babbling) {
    int cnt = 0;
    for(auto val : babbling){
        if(check(val)) {
            cnt++;
        }
    }
    return cnt;
}
