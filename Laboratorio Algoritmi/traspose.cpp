#include <iostream>
using namespace std;

#define MAX 100
#define MIN -100

void printMatrix(int **mat, int size){
    cout<<"\n----------";
    for(size_t i=0; i<size; i++){
        cout <<"\n";
        for(size_t j=0; j<size; j++){
            cout <<mat[i][j]<<" ";
        }
    }
}

void transpose(int **mat,int size){
    int tmp;
    for(size_t i=0; i<size; i++){
        for(size_t j=i; j<size; j++){
           tmp = mat[i][j];
           mat[i][j] = mat[j][i];
           mat[j][i] = tmp; 
        }
    }
}

int main(){
    srand(time(NULL));
    int size;
    cout<<"Insert size: ";
    cin>>size;

    int **mat = new int*[size];
    for(size_t i=0; i<size; i++){
        mat[i] = new int[size];
        for(size_t j=0; j<size; j++){
            mat[i][j] = rand()%(MAX-MIN+1)+MIN;
        }
    }

    cout<<"\nmatrix";
    printMatrix(mat,size);

    transpose(mat,size);

    cout<<"\n\ntranspose";
    printMatrix(mat,size);
    cout<<"\n";

    return 0;
}