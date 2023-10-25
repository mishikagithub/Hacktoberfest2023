#include<stdio.h>

void printarray(int *A, int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}
void merge(int A[], int  mid,int low, int high){
      int i,j,k, b[100];
      i= low;
      j= mid+1;
      k=low;

      while(i<=mid && j<=high){
        if(A[i]< A[j]){
            b[k]= A[i];
            i++;
            k++;
        }else{
            b[k]=A[j];
            k++;j++;
        }
      }
      while(i<=mid){
        b[k]=A[i];
        k++;i++;
      }
      while(j<=high){
        b[k]= A[j];
        k++;j++;
      }
      for (int i = low; i <=high; i++)
      {
        A[i]=b[i];
      }
      
}

void mergesort(int A[],int low , int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        mergesort(A,low, mid);
        mergesort(A,mid+1, high);
        merge(A,mid,low,high);
    }
}

int main(){
    int A[]= {98,34,2,54,33,65,4};
    int n= 7;
    printarray(A,n);
    mergesort(A,0,6);
    printarray(A,n);
}
