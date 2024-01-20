#include<stdio.h>
void findwaitingtime(int processes[],int n,int bt[],int wt[])
{
    wt[0]=0;
    int i;
    for(i=1;i<n;i++){
        wt[i]=bt[i-1]+wt[i-1];
    }
    
}
void findturnaroundtime(int processes[],int n,int bt[],int wt[],int tat[])
{
    int i;
    for(i=0;i<n;i++)
    tat[i]=bt[i]+wt[i];
}
 void findavgtime(int processes[],int n,int bt[])
{
    int wt[n],tat[n],
    total_wt=0,
    total_tat=0;
    findwaitingtime(processes, n, bt, wt);
    findturnaroundtime(processes,n, bt,wt,tat);
printf("processes burst time waiting time turnaround time\n");
int i;
for(i=0;i<n;i++)
{
    total_wt=total_wt+wt[i];
    total_tat=total_tat+tat[i];
    printf("%d",(i+1));
    printf("%d",bt[i] );
    printf("%d",wt[i]);
    printf("%d",tat[i]);

}
int s=(float)total_wt / (float)n;
int t=(float)total_tat /(float)n;
printf("average waiting time=%d",s);
printf("average turnaround time=%d",t);
}
int main()
{
    int processes[]={1,2,3,4};
    int n=sizeof processes /sizeof processes[0];
    int burst_time[]={5,6,2,4};
    findavgtime(processes,n,burst_time);
    return 0;
}


