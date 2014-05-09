#include <time.h>

#include <iostream>

#include "DateTime.h"

using namespace std;

 

 

 

int getdate2(DateType* d)

{

long ti;

struct tm *tm;

time(&ti);

tm=localtime(&ti);

d->year=tm->tm_year+1900;

d->month=tm->tm_mon+1;

d->day=tm->tm_mday;

cout<<"function getdate() loaded!"<<endl;

return 0;

}

 


int gettime2(TimeType* t)

{

long ti;

struct tm *tm;

time(&ti);

tm=localtime(&ti);

t->hour=tm->tm_hour;

t->minute=tm->tm_min;

t->second=tm->tm_sec;

return 0;

}

 
