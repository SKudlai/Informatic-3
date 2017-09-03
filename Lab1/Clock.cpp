//
// Created by 28-07-2014 on 02.09.2017.
//
#include <iostream>
#include "Clock.h"
#define forever for( ; ; )
using namespace std;

Clock::Clock(const Clock &obj) {
    format = obj.format;
    hours = obj.hours;
    minutes = obj.minutes;
    seconds = obj.seconds;
}
void Clock::setTime(unsigned short h, unsigned short m, unsigned short s, bool day_state){
    day = day_state;
   if(h <= MaxHours)
       if((hours = h) >= MID_DAY )
           day = day_state;
    if(m <= MAX_MINTS_SEC)
        minutes = m;
    if(s <= MAX_MINTS_SEC)
        seconds = s;
}
inline void Clock::null_Time() {
    hours = 0;
    minutes = 0;
    seconds = 0;
    }
inline unsigned short* Clock::getTime() {
    auto giving = new unsigned short [4];
    giving[0] = hours;
    giving[1] = minutes;
    giving[2] = hours;
    giving[3] = day;
    return giving;
}
void Clock::print_Time(){
    printf("%2u:%2u:%2u %c%c\n",hours,minutes,seconds,(format ? ' ': day ? morning: evening),(format ? ' ': 'm'));
}
inline void Clock::secpp() {
    if (seconds < MAX_MINTS_SEC)
        seconds++;
    else if (minutes < MAX_MINTS_SEC){
        seconds = 0;
        minutes++;
}
    else if(hours <= MaxHours) {
        seconds = 0;
        minutes = 0;
        if(++hours == 12)
            day = ! day;
    }
    else if(!format){
        day = ! day;
        hours = 1;
        minutes = 0;
        seconds = 0;
    }
    else {
        day = ! day;
        null_Time();
    }
}
void Clock::timer(){
    forever { ;
        secpp();
        print_Time();
    }
}