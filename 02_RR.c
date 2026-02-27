/* Program: Round Robin (RR) CPU Scheduling Algorithm
Description: Implementation of RR CPU scheduling in C. 
Calculates waiting time, turnaround time, and finishing time for each process 
based on burst time, arrival time, and user-defined time quantum.*/

#include<stdio.h>
#include<stdlib.h>
struct J 
{ 
int bt,tat,wt,at,ft; 
} 
job[100]; 
void scheduler(struct J job[], int n, int q) 
{ 
int burst[100],t=0,done=0,curr=-1,diff=q,i=0; 
float tat_sum=0,wt_sum=0; 
for(i=0;i<n;i++) 
burst[i]=job[i].bt;
while(done<n) 
 { 
       while(1) 
      { 
           curr=(curr+1)%n; 
           if(job[curr].bt!=0) 
           break; 
         }
         diff=(q<=job[curr].bt)?q:job[curr].bt; 
 
  job[curr].bt-=diff; 
  t+=diff; 
  if(job[curr].bt==0) 
  { 
   done++; 
   job[curr].ft=t; 
  } 
  } 
     printf("RR Scheduling Details are \n"); 
    for(i=0;i<n;i++) 
   { 
   job[i].bt=burst[i]; 
   job[i].tat=job[i].ft-job[i].at; 
   job[i].wt=job[i].tat-job[i].bt; 
   tat_sum+=job[i].tat; 
   wt_sum+=job[i].wt; 
        } 
 printf("Job\tBT\tAT\tTAT\tWT\n"); 
 for(i=0;i<n;i++) 
  printf("%d\t%d\t%d\t%d\t%d\n",i+1,job[i].bt,job[i].at,job[i].tat,job[i].wt); 
 printf("Avg TAT=%f\nAvg WT=%f\n",tat_sum/n,wt_sum/n); 
} 
void main() 
{ 
 int n,q,c,i; 
 printf("Enter the number of processes:\n"); 
 scanf("%d",&n); 
 printf("Enter the arrival time and burst time\n"); 
 for(i=0;i<n;i++) 
 { 
  printf("Job%d: ",i+1); 
  scanf("%d%d",&job[i].at,&job[i].bt); 
 } 
 
             printf("Enter time quantum: "); 
             scanf("%d",&q); 
             scheduler(job,n,q); 
}

OUTPUT 

Enter number of processes:
3
Enter burst time for sequences:
24
3
3

Enter time quantum:4

Process_no Burst time Wait time Turn around time
1               24              6               30
2               3               4               7
3               3               7               10

Avg wait time is 5.666667
Avg turn around time is 15.666667
