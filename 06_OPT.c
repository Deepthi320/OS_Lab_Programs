/* Program: Optimal Page Replacement Algorithm
Description: Implementation of the Optimal (OPT) page replacement algorithm in C.
Calculates total page faults and displays the state of page frames after each page insertion. */

#include <stdio.h> 
#include <stdbool.h> 
bool contains(int frame[], int frameSize, int page) 
 { 
    for (int i = 0; i < frameSize; i++)  
{ 
        if (frame[i] == page) 
 { 
            return true; 
        } 
    } 
    return false; 
} 
 
int findOptimalPage(int pages[], int n, int frame[], int frameSize, int currentIndex)  
{ 
    int res = -1, farthest = currentIndex; 
    for (int i = 0; i < frameSize; i++) 
   { 
        int j; 
        for (j = currentIndex; j < n; j++) 
        { 
            if (frame[i] == pages[j]) 
           { 
                if (j > farthest)  
              { 
                    farthest = j; 
                    res = i; 
                } 
                break; 
            } 
        } 
        if (j == n) 
         return i; 
    } 
    return (res == -1) ? 0 : res; 
} 
void optimalPageReplacement(int pages[], int n, int frameSize)  
{ 
    int frame[frameSize]; 
    bool isPageFault[n]; 
    int pageFaults = 0; 
    // Initialize frame and page faults 
    for (int i = 0; i < frameSize; i++) 
    frame[i] = -1; 
    for (int i = 0; i < n; i++) 
     isPageFault[i] = false; 
    for (int i = 0; i < n; i++) 
    { 
        // Check if page is already in the frame 
        if (!contains(frame, frameSize, pages[i]))  
      { 
            // Page fault occurs 
            int replaceIndex; 
            if (i < frameSize)  
           { 
                // If there’s an empty slot in the frame, use it 
                replaceIndex = i; 
            }  
          else 
           { 
             // Otherwise, find the optimal page to replace 
                replaceIndex = findOptimalPage(pages, n, frame, frameSize, i + 1); 
            } 
            frame[replaceIndex] = pages[i]; 
            isPageFault[i] = true; 
            pageFaults++; 
            // Print current frame state 
            printf("Frame state after inserting page %d: ", pages[i]); 
            for (int j = 0; j < frameSize; j++) 
           { 
                if (frame[j] != -1) 
                printf("%d ", frame[j]); 
                else 
                    printf("- "); 
            } 
            printf("\n"); 
        } 
    } 
    printf("Total Page Faults: %d\n", pageFaults); 
} 
int main()  
{ 
    int pages[50], n, frameSize, i; 
    printf("Enter the number of pages: "); 
    scanf("%d", &n); 
    printf("Enter the page sequence of %d pages: ", n); 
    for (i = 0; i < n; i++) 
    scanf("%d", &pages[i]); 
    printf("Enter the frame size: "); 
    scanf("%d", &frameSize); 
    optimalPageReplacement(pages, n, frameSize); 
    return 0; 
}
Output: 
Enter total no of pages : 
5
Enter sequence :
4 5 3 5 2

Enter the frame size : 
3
4       -1      -1
4       5       -1
4       5       3
2       5       3

Total no of fault size=4
