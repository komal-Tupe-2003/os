#include<stdio.h>
int N;//Number of Process
int M;//Number of Resources
int Alloc[10][10];
int Max[10][10];
int Need[10][10];
int Avail[10];
int Work[10];
void DisplayNeed()
{
int i,j;
printf("\n Need\n");
for(i=0;i<M;i++)
printf("\t%c",65+i);
for(i=0;i<N;i++)
{
printf("\nP%d",i);
for(j=0;j<M;j++)
{
printf("\t%d",Need[i][j]);
}
}
printf("\n");
}
void GetInputData()
{
int i,j;
printf("\n Enter Number of Process:");
scanf("%d",&N);
printf("\nEnter Number of Resoureces:");
scanf("%d",&M);
printf("\nEnter Max requirement for Process");
for(i=0;i<N;i++)
{
printf("\nEnter Max for Process P%d:",i);
for(j=0;j<M;j++)
{
printf("\nEnter for Rsources %c:",65+j);
scanf("%d",&Max[i][j]);
}
}
printf("\n Enter Allocated Resources for Process:");
for(i=0;i<N;i++)
{
printf("\nEnter Alloc for Process P%d:",i);
for(j=0;j<M;j++)
{
printf("\nEnter for Alloc Resources %c:",65+j);
scanf("%d",&Alloc[i][j]);
}
}
printf("\nEnter Available Resoureces:");
for(i=0;i<M;i++)
{
printf("\nEnter Available for Resources %c:",65+i);
scanf("%d",&Avail[i]);
}
}
void DisplayInputData()
{
int i,j;
printf("\n Max\n");
for(i=0;i<M;i++)
printf("\t%c",65+i);
for(i=0;i<N;i++)
{
printf("\n P%d",i);
for(j=0;j<M;j++)
{
printf("\t%d",Max[i][j]);
}
}
printf("\n");
printf("\n Allocated\n");
for(i=0;i<M;i++)
printf("\t%c",65+i);
for(i=0;i<N;i++)
{
printf("\nP%d",i);
for(j=0;j<M;j++)
{
printf("\t%d",Alloc[i][j]);
}
}
printf("\n");
printf("\n Avaible\n");
for(i=0;i<M;i++)
printf("\t%c",65+i);
printf("\n");
for(i=0;i<M;i++)
printf("\t%d",Avail[i]);
printf("\n");
}
void CalculateNeed()
{
int i,j;
for(i=0;i<N;i++)
for(j=0;j<M;j++)
Need[i][j]=Max[i][j]-Alloc[i][j];
}
int IsFeasible(int pi)
{
int i;
for(i=0;i<M;i++)
if(Need[pi][i]>Work[i])
return 0;
return 1;
}
void SafetyCheck()
{
int i;
int k=0;
int flag;
int j;
int finish[10]={0};
int SafeSeq[10]={-1};
for(i=0;i<M;i++)
Work[i]=Avail[i];
while(1)
{
flag=0;
for(i=0;i<N;i++)
{
if(finish[i]!=1&&IsFeasible(i))
{
for(j=0;j<M;j++)
Work[j]+=Alloc[i][j];
finish[i]=1;
SafeSeq[k++]=i;
flag=1;
}
}
if(flag==0)
{
printf("\nUnsafe state\n");
return ;
}
if(flag==1)
{
for(i=0;i<N;i++)
if(finish[i]!=1)
break;
if(i==N)
{
printf("\nSafe State\n");
printf("\n<");
for(i=0;i<N;i++)
printf("\nP%d",SafeSeq[i]);
printf("\nb>\n");
return;
}
}
}
}
void NewRequest()
{
int n;
int request[10];
int i;
int flag1='n';
printf("\n Do You Want to Generate Immediate Request(press1->Yes or 0->No)");
scanf("%d",&flag1);
if(flag1==1)
printf ("\Enter the process number with new request:");
scanf("%d",&n);
printf("\n Enter Request:");
for(i=0;i<M;i++)
{
printf("\nEnter for %c",65+i);
scanf("%d",&request[i]);
}
for(i=0;i<M;i++)
{
if(request[i]>Need[n][i])
{
printf("\nReason:Req>Need\n");
printf("\nCannot grant request for Process P%d\n",n);
return ;
}
}
for(i=0;i<M;i++)
{
Alloc[n][i]+=request[i];
Need[n][i]-=request[i];
Avail[i]-=request[i];
}
SafetyCheck();
}
int main()
{
GetInputData();
DisplayInputData();
CalculateNeed();
DisplayNeed();
SafetyCheck();
NewRequest();
return 0;
}


