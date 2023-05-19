#include<bits/stdc++.h>
using namespace std;


void merge(int a[], int p, int q, int r){
    
}

void mergeSort(int a[], int p, int r ){
    if(p>=r){
        return;
        int q = p + ((r-p )/2);
        mergeSort(a,p,q);
        mergerSort(a,q+1,r);
        merge(a,p,q,r);
    }

}


void main(){
    int[] a ={6,4,2,1,9,8,3,5};
    int asize = sizeof(a)/sizeof(a[0]);

    mergeSort(a,0,asize-1);
}