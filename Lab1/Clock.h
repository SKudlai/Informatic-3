//
// Created by 28-07-2014 on 02.09.2017.
//

#ifndef HOME_WORK_CLOCK_H
#define HOME_WORK_CLOCK_H

#include <iostream>

class Clock {
#define MAX_MINTS_SEC 59
#define MID_DAY 12
    unsigned short hours;
    unsigned short minutes;
    unsigned short seconds;
    bool format;//24 hours = true; 12 hours = false
    bool day;
#define morning  'a'
#define evening  'p'
#define MaxHours  (format ? 23:  MID_DAY )
public:
    Clock(bool frmt){
        day = true;
        format = frmt;
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
    Clock(const Clock &obj);
    bool getFormat(){
        return format;
    }
    void setTime(unsigned short h, unsigned short m, unsigned short s,bool day_state = true);
    inline void null_Time();
    inline unsigned short* getTime();
    void print_Time();
    inline void secpp();
    void timer();
    void operator()(){
        std::cout << "Hello, I works in " << (format ? "24-" : "12-") << "hours format!" << std::endl;
    };
    ~Clock(){
        delete this;
    } //https://isocpp.org/wiki/faq/freestore-mgmt#delete-this
};

#endif //HOME_WORK_CLOCK_H
