#include <stdio.h>
#include <dlfcn.h> 

int  main()
{
    void *pdlHandle = dlopen("./mylib.so", RTLD_LAZY); 
    char *pszErr = dlerror();
    if( !pdlHandle || pszErr )
    {
      printf("Load mylib failed!\n");
        return 1;
    }

    void (*Print)() = dlsym(pdlHandle, "Print"); 
    if( !Print )
    {
        pszErr = dlerror();
        printf("Find symbol failed!%s\n", pszErr);
        dlclose(pdlHandle);
        return 1;
    }

    Print();

    dlclose(pdlHandle);

    return 0;
}
