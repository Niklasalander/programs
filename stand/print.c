/***** print functions *****/

#include "defs.h"


/***** prints current time *****/
void printTime()
{
    time_t tNow;
    time(&tNow);
    tm *myTime = localtime(&tNow);
    if (myTime->tm_hour > 9 && myTime->tm_min > 9 && myTime->tm_sec > 9)
        printf("Time when pressed (h/m/s) %d:%d:%d\n", myTime->tm_hour, myTime->tm_min, myTime->tm_sec);
    else if (myTime->tm_hour <= 9 && myTime->tm_min > 9 && myTime->tm_sec > 9)
        printf("Time when pressed (h/m/s) 0%d:%d:%d\n", myTime->tm_hour, myTime->tm_min, myTime->tm_sec);
    else if (myTime->tm_hour > 9 && myTime->tm_min <= 9 && myTime->tm_sec > 9)
        printf("Time when pressed (h/m/s) %d:0%d:%d\n", myTime->tm_hour, myTime->tm_min, myTime->tm_sec);
    else if (myTime->tm_hour <= 9 && myTime->tm_min <= 9 && myTime->tm_sec > 9)
        printf("Time when pressed (h/m/s) 0%d:0%d:%d\n", myTime->tm_hour, myTime->tm_min, myTime->tm_sec);
    else if (myTime->tm_hour > 9 && myTime->tm_min > 9 && myTime->tm_sec <= 9)
        printf("Time when pressed (h/m/s) %d:%d:0%d\n", myTime->tm_hour, myTime->tm_min, myTime->tm_sec);
    else if (myTime->tm_hour <= 9 && myTime->tm_min > 9 && myTime->tm_sec <= 9)
        printf("Time when pressed (h/m/s) 0%d:%d:0%d\n", myTime->tm_hour, myTime->tm_min, myTime->tm_sec);
    else if (myTime->tm_hour > 9 && myTime->tm_min <= 9 && myTime->tm_sec <= 9)
        printf("Time when pressed (h/m/s) %d:0%d:0%d\n", myTime->tm_hour, myTime->tm_min, myTime->tm_sec);
    else if (myTime->tm_hour <= 9 && myTime->tm_min <= 9 && myTime->tm_sec <= 9)
        printf("Time when pressed (h/m/s) 0%d:0%d:0%d\n", myTime->tm_hour, myTime->tm_min, myTime->tm_sec);
}
