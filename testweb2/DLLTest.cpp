#include "DateTime.h"

#include <dlfcn.h>

#include <iostream>

using namespace std;

 


typedef int(*FuncDatePtr)(DateType* d);

 


int main(int argc,char* argv[])

{

DateType d;

//TimeType t;

void* dp=0;

char* error=0;

cout<<"Dll Programe Demo:"<<endl;

dp=dlopen("libtime.so",RTLD_NOW);

if(dp==0)

{

cout<<"Open time.so Failed!"<<dlerror()<<endl;

return 1;

}

//int(*f)(DateType* d);

FuncDatePtr f=(FuncDatePtr)dlsym(dp,"getdate2");

//void* test=dlsym(dp,"getdate");

//funcDate=(FuncDate)funcDate;

error=dlerror();


if(error)

{

cout<<"ERROR:"<<error<<endl;

return 1;

}


f(&d);

cout<<"Today Year="<<d.year<<endl;


dlclose(dp);

return 0;

}
