/* Program: LRU Page Replacement Algorithm
Description: Implementation of Least Recently Used (LRU) page replacement in C.
Calculates page faults and displays the content of page frames after each page access. */

#include <stdio.h>
int n, pg[30], fr[10];
void lru();
int main()
{
 int i;
 printf("Enter total number of pages: \n");
 scanf("%d", &n);
 printf("Enter page sequence:\n");
 for (i = 0; i < n; i++)
 scanf("%d", &pg[i]);
 lru(); // Call the lru function
 return 0;
}
void lru()
{
 int count[10], i, j, fault = 0, flag, f, temp, min, m, x;
 printf("Enter the frame size: \n");
 scanf("%d", &f);
 // Initialize frame array and count array
 for (i = 0; i < f; i++)
{
 fr[i] = -1; // Set each frame initially to -1 (empty)
 count[i] = -1; // Initialize the count array to -1 for clarity
 }
 for (i = 0; i < n; i++)
{
 flag = 0;
 temp = pg[i];
 // Check if the page is already in a frame
 for (j = 0; j < f; j++)
{
 if (fr[j] == temp)
{
 flag = 1; // Page hit
 count[j] = i; // Update the most recent usage time
 break;
 }
 }
 // Page fault: the page is not in any frame
 if (flag == 0)
{
 // If there's still space in frames, place page in the next empty slot
 if (fault < f)
{
 fr[fault] = temp;
 count[fault] = i; // Record the time of usage for LRU
 fault++;
 }
else
{
 // LRU replacement: find the least recently used page
 min = 0;
 for (m = 1; m < f; m++)
{
 if (count[m] < count[min])
{
 min = m;
 }
 }
 fr[min] = temp; // Replace the least recently used page
 count[min] = i; // Update usage time
 fault++;
 }
 }
 // Print the current state of frames
 printf("\nPage frames after accessing page %d:\t", temp);
 for (x = 0; x < f; x++)
{
 if (fr[x] != -1)
 printf("%d\t", fr[x]);
 else
 printf("-\t"); // Show empty slots
 }
 }
 printf("\n\nTotal number of page faults = %d\n", fault);
}

Output: 
Enter total no of pages : 
6
Enter sequence :
1 0 1 0 1 2

Enter the frame size : 
3
1       -1      -1
1       0       -1
1       0       -1
1       0       -1
1       0       -1
1       0       2
Total no of fault size=3
