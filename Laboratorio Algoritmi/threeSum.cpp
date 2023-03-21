#include <bits/stdc++.h>
using namespace std;

#define MAX 100
#define MIN -100
#define SIZE 10

void printList(int arr[]){
    cout<<"Sorted list:\n";
    for(size_t i=0; i<SIZE; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

void countingSort(int *arr,int max,int min){
    int range = max - min + 1;
    int count[range];
    for (int i = 0; i < range; i++)
        count[i]=0;
 
    for (int i = 0; i < SIZE; i++)
        count[arr[i] - min]++;
 
    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];
    
    int output[SIZE];
    for (int i = SIZE - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
 
    for (int i = 0; i < SIZE; i++)
        arr[i] = output[i];
}

void twoSum(int arr[],int start){
    int i = start+1;
    int j = SIZE-1;
    int sum;
    while(i<j){
        sum = arr[start]+arr[i]+arr[j]; 
        if(sum<0){
            i++;
        }
        else{
            if(sum>0)
                j--;
            else{
                cout<<"["<<arr[start]<<","<<arr[i]<<","<<arr[j]<<"]\n";
                i++;
                j--;
                while (i < j && arr[i] == arr[i-1]) //If the current value is the same as the one before, skip it.
                    i++;
            }
        }
    }
}

void threeSum(int arr[]){
    for(int i = 0; i<SIZE; i++){
        if(arr[i]>0)
            break; //Remaining values cannot sum to zero.
        if(i==0 || arr[i-1]!=arr[i]){ //If the current value is the same as the one before, skip it.
            twoSum(arr,i);
        }
    }
}

int main(){
    srand(time(NULL));
    int *arr = new int[SIZE];
    int max=-101,min=101;
    for(size_t i=0; i<SIZE; i++){
        arr[i] = rand()%(MAX-MIN+1)+MIN;
        max = arr[i]>max ? arr[i]:max;
        min = arr[i]<min ? arr[i]:min;
    }
       
    countingSort(arr,max,min);
    printList(arr);
    cout<< "\nTriplets that sum to zero:\n";
    threeSum(arr);

    return 0;
}