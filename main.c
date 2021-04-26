#include <stdio.h>
int month(int y, int m){
    switch(m){
        case 4:
        case 6:
        case 9:
        case 11: return 30;
        case 2:
            if ((y % 4 == 0) && ((y % 100 != 0) || (y % 400 == 0))){
                return 29;
            }
            else{
                return 28;
            }
        default: return 31;
    }
}
int main() {
    int d_year, d_month, d_day, d_hour;
    int f_time;

//    scanf("%d %d", &d_lat, &d_lon);
//    scanf("%d %d &d %d", &d_year, &d_month, &d_day, &d_hour);
//    scanf("%d", &f_time);
//    scanf("%d %d", &a_lat, &a_lon);
    
    d_year = 2020;
    d_month = 2;
    d_day = 28;
    d_hour = 22;
    f_time = 74;
    
    int m_day = month(d_year, d_month);
    
    d_hour += f_time;
    
    if(d_hour >= 24){
        d_day += d_hour / 24;
        d_hour %= 24;
    }
    while(d_day > m_day){
        d_month++;
        d_day -= m_day;
        
        if(d_month > 12){
            d_year ++;
            d_month -= 12;
        }
        
        m_day = month(d_year, d_month);
    }
    
    printf("Arrive at %d/%02d/%02d %d o'clock, and it is the spring.\n", d_year, d_month, d_day, d_hour);
    
    return 0;
}
