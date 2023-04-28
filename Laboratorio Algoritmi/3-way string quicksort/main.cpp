#include "quicksort.hpp"
#include <iostream>
using namespace std;

int main(){
    string arr[] = {"ciao", "a", "tutti", "mi", "chiamo", "francesco", "e", "studio", "informatica"};
    cout<<"Multiset: ";
    print(arr, 9);
    sort(arr, 9);
    cout<<"Sorted multiset: ";
    print(arr, 9);
    return 0;
}