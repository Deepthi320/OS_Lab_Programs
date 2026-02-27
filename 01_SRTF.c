/* Program: Shortest Remaining Time First (SRTF) Scheduling Algorithm
Description: Implementation of preemptive CPU scheduling algorithm in C.*/

#include<stdio.h>
int arr[10], bur[10], rt[10], n, pr[10], t = 0, ft[10], wt[10], tat[10], pos, total = 0, ttat = 0, twt = 0; 
float avgtat, avgwt; 
int main() 
{ 
int comp = 0, i; 
// Input for number of processes 
printf("\nEnter the number of processes: "); 
scanf("%d", &n); 
// Input for arrival time and burst time for each process 
for (i = 0; i < n; i++) { 
printf("\nEnter the arrival and burst time for process %d: ", i + 1); 
scanf("%d %d", &arr[i], &bur[i]); 
pr[i] = i + 1; // Process ID 
}
 // Initialize remaining time (rt) with burst time (bur) 
for (i = 0; i < n; i++) 
rt[i] = bur[i]; 
// Main loop to simulate SRTF 
while (comp < n) 
{ 
// Finding the process with shortest remaining time that has arrived
 pos = -1; // Reset pos before each loop 
for (i = 0; i < n; i++) 
{ 
if (arr[i] <= t && rt[i] > 0) 
{ 
// Process must have arrived and still have burst time left 
if (pos == -1 || rt[i] < rt[pos]) 
{ // First eligible process or shorter burst time 
pos = i; 
} 
} 
} 
// If no process found, move time forward 
if (pos == -1) 
{ 
t++; 
continue; 
}
 // Decrease the remaining time for the selected process 
rt[pos]--; 
t++; 
// If process is completed 
if (rt[pos] == 0) 
{ 
comp++;     // Completed process count 
ft[pos] = t;  // Finish time of the process 
tat[pos] = ft[pos] - arr[pos];   // Turnaround time = Finish time - Arrival time
wt[pos] = tat[pos] - bur[pos]; // Waiting time = Turnaround time - Burst time 
} 
} 
// Calculate total TAT and WT for average calculation 
for (i = 0; i < n; i++) 
{ 
ttat += tat[i]; 
twt += wt[i]; 
} 
// Calculate averages 
avgtat = (float)ttat / n; 
avgwt = (float)twt / n; 
//Output the process details and average times 
printf("\nProcess\tBT\tAT\tTAT\tWT\n"); 
for (i = 0; i < n; i++) 
{ 
printf("%d\t%d\t%d\t%d\t%d\n", pr[i], bur[i], arr[i], tat[i], wt[i]); 
} 
printf("Avg TAT = %.2f\nAvg WT = %.2f\n", avgtat, avgwt); 
return 0; 
}

OUTPUT:

 Enter the number of processes: 4

Enter the arrival time for process 1: 0
Enter the burst time for process   1: 8

Enter the arrival time for process 2: 1
Enter the burst time for process   2: 4

Enter the arrival time for process 3: 2
Enter the burst time for process   3: 9

Enter the arrival time for process 4: 3
Enter the burst time for process   4: 5

                        ---SHORTEST REMAINING TIME FIRST---

 Process Arrival Burst Waiting Finishing turnaround Tr/Tb

   id      time    time       time     time      time
    1        0       8        9         17        17        2.1
    2        1       4        0          5         4        1.0
    3        2       9       15         26        24        2.7
    4        3       5        2         10         7        1.4

tavg=13.000000   wavg=6.500000
