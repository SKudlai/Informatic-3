#include <iostream>
#include "Clock.h"
using namespace std;
int main() {
    bool form;
    cout << "Hello!\nPlease choose the format of time\nPress 1 for 24\nPress 0 for 12\nAny other button will be counted as 0!" << endl;
    cin >> form;
    Clock* watch = new Clock(form);
    watch->operator()();
    watch->setTime(17,59,59);
    watch->print_Time();
    for (int i = 0; i < 1000; ++i) {
        watch->secpp();
        watch->print_Time();
    }
    return 0;
}