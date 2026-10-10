class Solution {
public:
    bool leapyear(int year) {
        if (year % 400 == 0) return true;
        if (year % 100 == 0) return false;
        return year % 4 == 0;
    }
    int dayOfYear(string date) {
        int year=stoi(date.substr(0,4));
        int month=stoi(date.substr(5,2));
        int day=stoi(date.substr(8,2));

        vector<int> days = {
            31,28,31,30,31,30,
            31,31,30,31,30,31
        };

        if (leapyear(year)) {
            days[1]=29;
        }
        int daynumber=day;

        for (int i = 0; i < month - 1; i++) {
            daynumber += days[i];
        }

        return daynumber;
    }
};