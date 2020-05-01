#include "types.h"
#include "stat.h"
#include "user.h"
int
sum(int a,int b)
{
	sleep(2);
	return a+b;
}
void waiter()
{
	int waitTime;
	int runTime;
	int pid;
	pid=fork();
	if(pid==0)
	{
		int c=sum(2,6);
		printf(1,"%d\n",c);
		exit();
	}
	waitx(&waitTime,&runTime);
	printf(1,"waitTime: %d runTime: %d\n",waitTime,runTime);
}
int main()
{
	waiter();
	exit();
}