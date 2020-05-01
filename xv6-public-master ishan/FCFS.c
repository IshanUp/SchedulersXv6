#include "types.h"
#include "stat.h"
#include "user.h"
#include "process_stat.h"

void load(int loading, int q)
{
    
    struct proc_stat p;
    getpinfo(&p, getpid());
    loading = loading * 43200;
    int j=0;
    
    int i=0;
    printf(1, "%d with %d and %d\n", getpid(), loading, p.runtime);
    while (i<loading)
    {
        j+=1;
        i+=1;
    }
    getpinfo(&p, getpid());
    printf(2, "Process %d with load %d times run %d\n", p.pid, j, p.num_run);
    printf(1,"proc  %d\n", q);
}
void loaderfun(void)
{
    
    int i=0;
    int pid[10];
    while (i < 10)
    {

        pid[i] = fork();
        if (pid[i] == 0)
        {
            if (i == 0 || i == 1){
                load(60000, i);
            }
            else if (i==1){
                load(60000, i);
            }
            else
                load(2000, i);

            exit();
        }
        i++;
    }
    wait();
    exit();
}
int main(int argc, char *argv[])
{
    int x;
    int y;
    int id;
    id = fork();
    if ( id == 0)
    {
        loaderfun();
        exit();
    }
    if (argc < 1){
        printf(2,"less args\n");
    }
    else if (argc > 1)
    {
        waitx(&x, &y);
        printf(2, "waitTime %d : runTime %d\n", x, y);
    }
    exit();
}