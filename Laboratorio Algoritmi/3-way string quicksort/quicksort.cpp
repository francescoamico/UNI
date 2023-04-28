#include "quicksort.hpp"
#include <iostream>
using namespace std;

void sort(std::string arr[], int len){
    quicksort(arr, 0, len-1, 0);
}

void quicksort(std::string arr[], int start, int stop, int l){ 
    if(start>=stop) return;

    int a = start, b = start;
    int c = stop, d = stop;

    for(int i = start; i <= stop; i++)
        if(arr[i].length() < l+1) swap(arr, i, b++);

    if(b>stop) return; //array already sorted

    int ascii_char_pivot = arr[b].at(l); //arr[i] = pivot
    while(true){
        while(b <= c && arr[b].at(l) <= ascii_char_pivot){ //stable partition (Bentley-Mcllroy)
            if(arr[b].at(l) == ascii_char_pivot) swap(arr, a++, b);
            b++;
        }
        while(b <= c && arr[c].at(l) >= ascii_char_pivot){
            if(arr[c].at(l) == ascii_char_pivot) swap(arr, d--, c);
            c--;
        }
        if(b>c) break;
        swap(arr, b++, c--);
    }
    int s = min(a,b-a);
    int k,h;
    for(k = start, h = b-s; s; s--) swap(arr, k++, h++);
    s = min(d-c, stop-d);
    for(k = b, h = stop+1-s; s; s--) swap(arr, k++, h++);
    quicksort(arr, start, b-a-1, l);
    quicksort(arr, b-a, stop-(d-c), l+1);
    quicksort(arr, stop-(d-c)+1, stop, l); 
}

void swap(std::string arr[], int i, int j){
    std::string tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void print(string arr[], int len){
    for(int i=0; i<len-1; i++)
        cout<<arr[i]<<", ";
    cout<<arr[len-1]<<"\n";
}