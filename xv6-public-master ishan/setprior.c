#include "types.h"
#include "user.h"
#include "stat.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
  if(argc<3)
  {
    printf(2, "Wrong\n");
    exit();
  }
  int pid = atoi(argv[1]);
  int prio = atoi(argv[2]);
  if(prio<0 || prio >100)
  {
    printf(2, "Wrong\n");
    exit();
  }
    set_priority(pid, prio);
  exit();
}
