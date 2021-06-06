// 快速排序  双路优化

#include<iostream>
#include"000_随机生成数字.h"
using namespace std;

// 插入排序

template<typename T>
void insertSort(T arr[],int l,int r){
    for(int i = l+1;i<=r;i++){
        //寻找arr[i]合适插入位置

        T e = arr[i];
        int j;
        for( j = i;j > l && arr[j-1] > e;j--){
            // 提前终止内层循环
            arr[j]=arr[j-1];

        }   
        arr[j]  = e;     
    }
}

 /************改进后*************************************************************/
template<typename T>
int __partition2(T arr[],int l,int r){
    swap(arr[l],arr[rand()%(r-l+1)+l] );
    T v = arr[l];
    // arr[l+1.....j]<v; arr[j+1....i] >v
    int j = l;
    for(int i = l +1; i <=r ;i++){
        if( arr[i] < v){
            swap(arr[j+1],arr[i]);
            j++;
        }
    }
    swap(arr[l],arr[j]);
    //索引P
    return j;
}

template<typename T>
void __quickSort2(T arr[],int l,int r){
     if(r-l<=15){
        insertSort(arr,l,r);
        return;
    }

    int p = __partition2(arr,l,r);
    __quickSort2(arr,l,p-1);
    __quickSort2(arr,p+1,r);
}

template<typename T>
void qucickSort2(T arr[],int n){
    srand(time(NULL));
    __quickSort2(arr,0,n-1);
}
 /******************************快速排序双路优化*******************************************/


template<typename T>
void qucickSort3(T arr[],int n){
    srand(time(NULL));
    __quickSort2(arr,0,n-1);
}



 int main(){
    int n = 1000000;
    // int *arr =  SortTestHelper::generateNearlyOrderedArray(n,5);
    // SortTestHelper::testSort("快速排序",qucickSort,arr,n);

    // int *arr2 =  SortTestHelper::generateNearlyOrderedArray(n,5);
    // SortTestHelper::testSort("快速排序随机化",qucickSort2,arr2,n);
    int *arr = SortTestHelper::generateRandomArray(n,0,10);
    SortTestHelper::testSort("快速排序",qucickSort2,arr,n);


    int *arr2 = SortTestHelper::generateRandomArray(n,0,10);
    SortTestHelper::testSort("快速排序双路",qucickSort3,arr2,n);
    
    
    return 0;
 }
