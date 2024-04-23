#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

long long int countComp;
long long int countSwap;
double time_taken;
clock_t t;

//  Utility functions
void tempArray(int size, int* arr1, int* arr2){
    for(int i = 0; i<=size; i++){
        arr1[i]=arr2[i];
    }
}
void nullCount(long long int* x, long long int* y){
    *x = 0;
    *y = 0;
}
void printArray(int size, int* arr){
    int count = 0;
    while(count<=size){
        printf("\narr[%i]=%i",count, arr[count]);
        count++;
    }
}

// 12.1a
void fillArray(int size, int* arr){
    int count = 0;
    srand(time(NULL));
    while(count<=size){
        arr[count] =  1 + rand() % (100 - 1 + 1);
        count++;
    }
}
// 12.1b
int testArray(int size, int *arr){
    int test = TRUE;
    for(int i = 0; i<size-1; i++){
        if(arr[i]<=arr[i+1]){
            test = TRUE;
            continue;
        }
        else{
            test = FALSE;
            break;
        }
    }
    if (test==TRUE){
        // printf("\n|Array is sorted...");
        return TRUE;
    }else{
        // printf("\n|Array is not sorted...");
        return FALSE;
    }
    

}

// Algorithm functions
void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
    countSwap++;
}
void bubbleSort(int n, int* arr){
   int i, j;
   int swapped;
   for (i = 0; i < n-1; i++)
   {
     swapped = FALSE;
     for (j = 0; j < n-i-1; j++)
     {
        countComp++;
        if (arr[j] > arr[j+1])
        {
           swap(&arr[j], &arr[j+1]);
           swapped = TRUE;
        }

     }
 
     if (swapped == FALSE)
        break;

   }
}

int partition(int low, int high, int* array){
  
  int pivot = array[high];
  
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        countComp++;
      i++;
      
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}
void quickSort(int low, int high, int* array){
    
  if (low < high) {
    int pi = partition(low, high, array);
    
    quickSort(low, pi - 1, array);
    
    quickSort(pi + 1, high, array);
  }
}

void insertionSort(int n, int* arr){
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            countSwap++;
            countComp++;
        }
        arr[j + 1] = key;
        countSwap++;
    }
}

void selectionSort(int size, int* array){
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    
    for (int i = step + 1; i < size; i++) {
    countComp++;
      if (array[i] < array[min_idx])
        min_idx = i;
    }
    swap(&array[min_idx], &array[step]);
  }
}

void merge(int l, int m, int r, int* arr){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
  
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        countComp++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
            // countSwap++;
        }
        else {
            arr[k] = R[j];
            j++;
            // countSwap++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int l, int r, int* arr){
    if (l < r) {
        int m = l + (r - l) / 2;
 
        mergeSort(l, m, arr);
        mergeSort(m + 1, r, arr);
 
        merge(l, m, r, arr);
    }
}

void testAlgorithm(int numberOfElements, int numberOfTimes){
int count=0;

while (count<numberOfTimes)
{

printf("\n\nTEST NUMBER: %i", count+1);

int* pArr = (int*)malloc((numberOfElements+1)*sizeof(int));
int* pArrtemp = (int*)malloc((numberOfElements+1)*sizeof(int));

if (pArr==NULL){
    printf("Memory not alocated correctly...");
    exit(1);
}
if (pArrtemp==NULL){
    printf("Memory not alocated correctly...");
    exit(1);
}

fillArray(numberOfElements, pArr);
tempArray(numberOfElements, pArrtemp, pArr);

// BUBBLE SORT
t = clock();
bubbleSort(numberOfElements,pArr);
t = clock() - t;
time_taken = ((double)t)/CLOCKS_PER_SEC; 
char* bubbleTest;
if(testArray(numberOfElements, pArr)==TRUE){
    bubbleTest = "Array sorted";
}else{
    bubbleTest = "Array not sorted";
}
long long int bubbleSwap = countSwap;
long long int bubbleCount = countComp;
double bubbleTime = time_taken;
nullCount(&countComp, &countSwap);
tempArray(numberOfElements, pArr, pArrtemp);

// QUICK SORT
t = clock();
quickSort(0,numberOfElements,pArr);
t = clock() - t;
time_taken = ((double)t)/CLOCKS_PER_SEC; 
char* quickTest;
if(testArray(numberOfElements, pArr)==TRUE){
    quickTest = "Array sorted";
}else{
    quickTest = "Array not sorted";
}
long long int quickSwap = countSwap;
long long int quickCount = countComp;
double quickTime = time_taken;
nullCount(&countComp, &countSwap);
tempArray(numberOfElements, pArr, pArrtemp);

// Insertion Sort
t = clock();
insertionSort(numberOfElements,pArr);
t = clock() - t;
time_taken = ((double)t)/CLOCKS_PER_SEC; 
char* insertionTest;
if(testArray(numberOfElements, pArr)==TRUE){
    insertionTest = "Array sorted";
}else{
    insertionTest = "Array not sorted";
}
testArray(numberOfElements, pArr);
long long int insertionSwap = countSwap;
long long int insertionCount = countComp;
double insertionTime = time_taken;
nullCount(&countComp, &countSwap);
tempArray(numberOfElements, pArr, pArrtemp);

// Selection Sort
t = clock();
selectionSort(numberOfElements,pArr);
t = clock() - t;
time_taken = ((double)t)/CLOCKS_PER_SEC; 
char* selectionTest;
if(testArray(numberOfElements, pArr)==TRUE){
    selectionTest = "Array sorted";
}else{
    selectionTest = "Array not sorted";
}
testArray(numberOfElements, pArr);
long long int selectionSwap = countSwap;
long long int selectionCount = countComp;
double selectionTime = time_taken;
nullCount(&countComp, &countSwap);
tempArray(numberOfElements, pArr, pArrtemp);

// Merge sort
t = clock();
mergeSort(0, numberOfElements, pArr);
t = clock() - t;
time_taken = ((double)t)/CLOCKS_PER_SEC;
char* mergeTest;
if(testArray(numberOfElements, pArr)==TRUE){
    mergeTest = "Array sorted";
}else{
    mergeTest = "Array =not sorted";
} 
long long int mergeSwap = countSwap;
long long int mergeCount = countComp;
double mergeTime = time_taken;
nullCount(&countComp, &countSwap);
tempArray(numberOfElements, pArr, pArrtemp);


// Lentele
printf("\n                    Bubble sort     Quick sort      Insertion Sort      Selection Sort      Merge Sort  \n");
printf("Passed:            %s    %s      %s        %s      %s\n",bubbleTest,quickTest, insertionTest, selectionTest, mergeTest);
printf("Comapre count:       %lld          %lld        %lld              %lld           %lld\n",bubbleCount,quickCount, insertionCount, selectionCount, mergeCount);
printf("Swap count:          %lld          %lld        %lld                %lld               %lld\n",bubbleSwap,quickSwap, insertionSwap, selectionSwap, mergeSwap);
printf("Time taken:          %f         %f       %f              %f          %f\n\n", bubbleTime, quickTime, insertionTime, selectionTime, mergeTime);

free(pArr);
free(pArrtemp);

count++;
}
}

int main(void){

    testAlgorithm(10000,5);

    return 0;
}   

// 15 
//18
// vilnius -> stockholm -> kopenhaga -> grand canarias