#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MIN -100

double maxSubarray1(double arr[],int size); /*bruteforce O(n^3)*/
double maxSubarray2(double arr[],int size); /*O(n^2)*/
double maxSubarray3(double arr[],int size); /*O(n^2) with prefixSum*/
double maxSubarray4(double arr[],int start,int stop); /*O(nlogn) divide and conquer*/
double maxSubarray5(double arr[],int size); /*O(n) memoization*/

void main(){
    srand(time(NULL));
    int dim[] = {100,200,500,2000};
    int size;
    clock_t t;
    double max;
    for(int i=0; i<5; i++){
        size = dim[i];

        double arr[size];
        for(int j=0; j<size; j++)
            arr[j] = MIN+(rand()/(double)RAND_MAX)*(MAX-MIN);

        printf("-----------\n\n");
        printf("Size: %d\n",size);
        
        t = clock();
        max = maxSubarray1(arr,size);
        t = clock()-t;
        printf("\nMax: %f",max);
        printf("\nTime1: %fs\n\n",(double)t/CLOCKS_PER_SEC);
       
        t = clock();
        max = maxSubarray2(arr,size);
        t = clock()-t;
        printf("\nMax: %f",max);
        printf("\nTime2: %fs\n\n",(double)t/CLOCKS_PER_SEC);

        t = clock();
        max = maxSubarray3(arr,size);
        t = clock()-t;
        printf("\nMax: %f",max);
        printf("\nTime3: %fs\n\n",(double)t/CLOCKS_PER_SEC);

        t = clock();
        max = maxSubarray4(arr,0,size-1);
        t = clock()-t;
        printf("\nMax: %f",max);
        printf("\nTime4: %fs\n\n",(double)t/CLOCKS_PER_SEC);

        t = clock();
        max = maxSubarray5(arr,size);
        t = clock()-t;
        printf("\nMax: %f",max);
        printf("\nTime5: %fs\n\n",(double)t/CLOCKS_PER_SEC);
    }
}

double maxSubarray1(double arr[],int size){
    double sum,max=0;
    for(int i=0; i<size; i++){
        for(int j=i; j<size; j++){
            sum = 0;
            for(int k=i; k<=j; k++)
                sum += arr[k];
            max = sum>max ? sum:max;
        }
    }
    return max;
}

double maxSubarray2(double arr[],int size){
    double sum,max=0;
    for(int i=0; i<size; i++){
        sum = 0;
        for(int j=i; j<size; j++){
            sum += arr[j];
            max = sum>max ? sum:max;
        }
    }
    return max;
}

double maxSubarray3(double arr[],int size){
    double prefixSum[size+1];
    prefixSum[0] = 0;
    for(int i=0; i<size; i++)
        prefixSum[i+1] = prefixSum[i]+arr[i];
    
    double sum,max = 0;
    for(int i=0; i<size; i++){
        for (int j=i+1; j<size+1; j++){
            sum = prefixSum[j]-prefixSum[i];
            max = sum>max ? sum:max;
        }
    }
    return max;
}

double maxSubarray4(double arr[],int start,int stop){
    if (start>stop) //empty array
        return 0;
    if (start==stop) //only one element
        return arr[start]>0 ? arr[start]:0;
    
    int mid = start + (stop-start)/2;
    double sum=0;
    double maxleft=0;
    double maxright=0;
    for(int i=mid; i>=start; i--){
        sum += arr[i];
        maxleft = sum>maxleft ? sum:maxleft;
    }
    sum = 0;
    for(int i=mid+1; i<=stop; i++){
        sum += arr[i];
        maxright = sum>maxright ? sum:maxright;
    }
    double max = maxleft+maxright;
    
    maxleft = maxSubarray4(arr,start,mid-1);
    maxright = maxSubarray4(arr,mid+1,stop);

    max = maxleft>max ? maxleft:max;
    return maxright>max ? maxright:max;
}

double maxSubarray5(double arr[],int size){
    double max = 0;
    double currMax = 0;
    for(int i = 0; i<size; i++){
        currMax = currMax+arr[i]>0 ? currMax+arr[i]:0;
        max = currMax>max ? currMax:max;
    }
    return max;
}