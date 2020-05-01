struct proc_stat{
    int pid;
    int num_run;
    int runtime;
    int level;
    int ticks[5];
};