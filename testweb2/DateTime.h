
 


#ifdef __cplusplus

extern "C"{

#endif

 


struct DateType

{

int year;

int month;

int day;

};

 


struct TimeType

{

int hour;

int minute;

int second;

};

 

 

 

int getdate2(DateType* d);

 


int gettime2(TimeType* t);

 


#ifdef __cplusplus

}

#endif
