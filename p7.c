#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#define TRUE 1 
#define FALSE 0 
void heapbottomup(int h[], int n) { 
int i, heap, v, j, k; 
for (i = n / 2; i > 0; i--) { 
k = i; 
v = h[k]; 
heap = FALSE; 
while (!heap && (2 * k) <= n) { 
j = 2 * k; 
if (j < n) { 
if (h[j] < h[j + 1]) { 
j = j + 1; 
} 
} 
if (v >= h[j]) { 
heap = TRUE; 
} else { 
h[k] = h[j]; 
k = j; 
} 
} 
h[k] = v; 
} 
} 
void heapsort(int h[], int n) { 
int i, temp; 
heapbottomup(h, n); 
for (i = n; i > 1; i--) { 
temp = h[1]; 
h[1] = h[i]; 
h[i] = temp; 
heapbottomup(h, i - 1); 
} 
} 
int main() { 
int h[20], n, i; 
double clk; 
clock_t starttime, endtime; 
printf("\nEnter the number of resumes: "); 
scanf("%d", &n); 
srand(time(NULL)); // Initialize random number generator 
printf("The candidates' ranks are:\n"); 
for (i = 1; i <= n; i++) { 
h[i] = rand() % 100; 
printf("%d\t", h[i]); 
} 
printf("\n"); 
starttime = clock(); 
heapsort(h, n); 
endtime = clock(); 
clk = (double)(endtime - starttime) / CLOCKS_PER_SEC; 
printf("The ranks in sorted order:\n"); 
for (i = 1; i <= n; i++) { 
printf("%d\t", h[i]); 
} 
printf("\n"); 
printf("The run time is %f seconds\n", clk); 
return 0; 
}