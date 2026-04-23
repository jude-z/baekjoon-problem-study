#include <iostream>

using namespace std;
class Date {
public:
    int hour;
    int minutes;
    Date(int hour, int minutes):hour(hour),minutes(minutes){};
    static Date toDate(string str) {
        string hour_str = str.substr(0,2);
        string minutes_str = str.substr(3,2);
        int hour = stoi(hour_str);
        int minutes = stoi(minutes_str);
        return Date(hour,minutes);
    }
    static int totalMinutes(Date date) {
        return 60 * date.hour + date.minutes;
    }
};
class Team {
public:
    int type;
    int total_minutes;
    Team(int type):type(type),total_minutes(0) {}
    void addDate(int total) {
        total_minutes += total;
    }

};
int main() {
    int n;
    cin >> n;
    Team team1(1);
    Team team2(2);
    int pre_time = 0;
    int cur_time = 0;
    int type;
    for (int i = 0; i<n;i++) {
        string date_str;
        cin >> type >> date_str;
        if (type == 1) {
            cur_time = Date::totalMinutes(Date::toDate(date_str));
            team1.addDate(cur_time - pre_time);
            pre_time = cur_time;
        }else if (type == 2) {
            cur_time = Date::totalMinutes(Date::toDate(date_str));
            team2.addDate(cur_time - pre_time);
            pre_time = cur_time;
        }
    }
    if (type == 1) {
        cur_time = 48 * 60;
        team1.addDate(cur_time - pre_time);
    }else if (type == 2) {
        team2.addDate(cur_time - pre_time);
    }


}
