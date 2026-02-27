/* Program: Banker's Algorithm for Deadlock Avoidance
Description: Implementation of the Banker's Algorithm in C.
Calculates need matrix, available resources, and determines if the system is in a safe state.
Displays safe sequence of process execution if system is safe. */

#include <stdio.h> 
void displayMatrix(int matrix[][10], int rows, int cols) 
{ 
    for (int i = 0; i < rows; i++) 
{ 
    for (int j = 0; j < cols; j++) 
{ 
    printf("%d ", matrix[i][j]); 
  } 
        printf("\n"); 
    } 
} 
int main() 
 { 
  intMax[10][10],alloc[10][10],need[10][10],avail[10],completed[10], safeSequence[10]; 
   int p, r, i, j, process, count = 0;
    // Get the number of processes with validation 
    do 
 { 
        printf("Enter the number of processes (max 10): "); 
        scanf("%d", &p); 
    } while (p <= 0 || p > 10); 
    // Get the number of resources with validation 
    do 
 { 
        printf("Enter the number of resources (max 10): "); 
        scanf("%d", &r); 
    } while (r <= 0 || r > 10); 
    // Initialize completed array 
    for (i = 0; i < p; i++) 
     completed[i] = 0; 
    // Input Max matrix with validation 
    printf("Enter the Max Matrix for each process:\n"); 
    for (i = 0; i < p; i++) 
 { 
        printf("For process %d: ", i + 1); 
        for (j = 0; j < r; j++) 
         scanf("%d", &Max[i][j]); 
    }
    // Input allocation matrix with validation 
    printf("Enter the allocation for each process:\n"); 
    for (i = 0; i < p; i++)  
{ 
        printf("For process %d: ", i + 1); 
        for (j = 0; j < r; j++) 
            scanf("%d", &alloc[i][j]); 
    } 
    // Input available resources with validation 
    printf("Enter the Available Resources:\n"); 
    for (i = 0; i < r; i++) 
    scanf("%d", &avail[i]); 
    // Calculate need matrix 
    for (i = 0; i < p; i++) 
    for (j = 0; j < r; j++) 
     need[i][j] = Max[i][j] - alloc[i][j]; 
 
    // Display Max, Allocation, and Need matrices 
    printf("\nMax Matrix:\n"); 
    displayMatrix(Max, p, r); 
    printf("\nAllocation Matrix:\n"); 
    displayMatrix(alloc, p, r);
    printf("\nNeed Matrix:\n"); 
    displayMatrix(need, p, r); 
    // Banker's algorithm 
    Do 
   { 
        process = -1; 
        for (i = 0; i < p; i++) 
       { 
            if (completed[i] == 0)  
           { 
                process = i; 
                for (j = 0; j < r; j++) 
               { 
                    if (avail[j] < need[i][j])  
                   { 
                       process = -1; 
                        break; 
                    } 
                } 
            }
               if (process != -1) 
                break; 
        } 
        if (process != -1)  
       { 
            printf("\nProcess %d runs to completion!", process + 1);  
            // Release resources held by the completed process 
            for (j = 0; j < r; j++) 
          { 
                avail[j] += alloc[process][j]; 
                alloc[process][j] = 0; 
                Max[process][j] = 0; 
            } 
            // Mark the process as completed outside the loop 
            completed[process] = 1; 
            // Update safe sequence and increment count 
            safeSequence[count] = process + 1; 
            count++; 
        } 
    } while (count != p && process != -1); 
    // Display results based on the outcome of the Banker's algorithm 
    if (count == p)  
{ 
        printf("\nThe system is in a safe state!!\n"); 
        printf("Safe Sequence : < "); 
        for (i = 0; i < p; i++) 
            printf("%d ", safeSequence[i]); 
            printf(">\n"); 
    }  
else 
        printf("\nThe system is in an unsafe state!!\n"); 
        return 0; 
} 

OUTPUT

No of process required : 5
No of resources required : 3

Enter the maximum matrix for each process :
 for each process 1 : 7 5 3
 for each process 2 : 3 2 2
 for each process 3 : 7 0 2
 for each process 4 : 2 2 2
 for each process 5 : 4 3 3

Enter the allocation matrix for each process :
 for each process 1: 0 1 0
 for each process 2: 2 0 0
 for each process 3: 3 0 2
 for each process 4: 2 1 1
 for each process 5: 0 0 2

Enter the available resources : 3 3 2

MAX MATRIX		ALLOC MATRIX		NEED MATRIX
 7       5       3       		0       1       0      		7       4       3
 3       2       2      		2       0       0       		1       2       2
 7       0       2       		3       0       2       		4       0       0
 2       2       2       		2       1       1       		0       1       1
 4       3       3       		0       0       2       		4       3       1
Process 2 runs to the completion

New Availability of Resource : 5 3 2
MAX MATRIX		ALLOC MATRIX		NEED MATRIX
 7       5       3       		0       1       0       		7       4       3
 0       0       0       		0       0       0       		0       0       0
 7       0       2       		3       0       2       		4       0       0
 2       2       2       		2       1       1       		0       1       1
 4       3       3       		0       0       2       		4       3       1
Process 3 runs to the completion

New Availability of Resource : 8 3 4

MAX MATRIX		ALLOC MATRIX		NEED MATRIX
 7       5       3       		0       1       0       		7       4       3
 0       0       0       		0       0       0       		0       0       0
 0       0       0       		0       0       0       		0       0       0
 2       2       2       		2       1       1       		0       1       1
 4       3       3       		0       0       2      		4       3       1
Process 4 runs to the completion

New Availability of Resource : 1 0 4 5


MAX MATRIX              ALLOC MATRIX            NEED MATRIX
 7       5       3                       0       1       0                       7       4       3
 0       0       0                       0       0       0                       0       0       0
 0       0       0                       0       0       0                       0       0       0
 0       0       0                       0       0       0                       0       0       0
 4       3       3                       0       0       2                       4       3       1
Process 1 runs to the completion

New Availability of Resource : 1  0  5  5

MAX MATRIX		ALLOC MATRIX		NEED MATRIX
 0       0       0       		0       0       0       		0       0       0
 0       0       0       		0       0       0       		0       0       0
 0       0       0       		0       0       0       		0       0       0
 0       0       0       		0       0       0       		0       0       0
 4       3       3       		0       0       2       		4       3       1
Process 5 runs to the completion

New Availability of Resource : 10 5 7

System is in SAFE STATE

SAFE STATE SEQUENCE < 2 3 4 1 5>
