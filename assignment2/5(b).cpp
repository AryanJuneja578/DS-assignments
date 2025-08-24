#include <iostream>
using namespace std;

void Display(int* arr, int n) {
	for(int i=0; i<n; i++) {
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
}

int main()
{
    int matrix[4][4]={{10,2,0,0},{100,20,4,0},{0,200,30,6},{0,0,300,40}};
    int size=sizeof(matrix[0])/sizeof(matrix[0][0]);
    
    int maindiag[size];
    int subdiag[size-1];
    int supdiag[size-1];
    
    for(int i=0; i<size; i++){
        maindiag[i]=matrix[i][i];
        
        if(i<size-1){
            supdiag[i]=matrix[i][i+1];
        }
        
        if(i>0){
            subdiag[i-1]=matrix[i][i-1];
        }
    }
    Display(maindiag,size);
    Display(supdiag,size-1);
    Display(subdiag,size-1);
    return 0;
}
