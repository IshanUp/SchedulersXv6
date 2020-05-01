#include "types.h"
#include "stat.h"
#include "user.h"
#include "process_stat.h"
int main(int argv,char *argc[])
{
    if(argv<=1)
    {
        printf(2,"No PID PROVIDED\n");
    }
    else
    {
        int x=atoi(argc[1]);
        struct proc_stat info;
        if(getpinfo(&info,x)==1)
        {
            printf(2,"pid is :%d runtime is %d numrun is %d \n",info.pid,info.runtime,info.num_run);
            for(int i=0;i<=4;i++){
                printf(2, "%d queue has ticked %d times\n",i,info.ticks[i]);
            }
        }
        else
        {
            printf(2,"FAILED\n");
        }
    }
    exit();
}