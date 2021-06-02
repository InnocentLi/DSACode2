#include<iostream>
#include<algorithm>
#include"000_随机生成数字.h"

using namespace std;

template<typename T>
void insertSort(T arr[],int n){
    for(int i = 1;i<n;i++){
        //寻找arr[i]合适插入位置
        for(int j = i;j>0&&arr[j]<arr[j-1];j--){
            //最多考虑到j=1
             swap(arr[j],arr[j-1]);
        }        
    }
}


//优化   不重复交换位置



template<typename T>
void insertSort2(T arr[],int n){
    for(int i = 1;i<n;i++){
        //寻找arr[i]合适插入位置

        T e = arr[i];
        int j;
        for( j = i;j > 0 && arr[j-1] > e;j--){
            // 提前终止内层循环
            arr[j]=arr[j-1];

        }   
        arr[j]  = e;     
    }
}


int main(){
     int n = 100000;
     int *arr = SortTestHelper::generateRandomArray(n,0,n);
     int *arr2= SortTestHelper::copyIntArray(arr,n);
    
     SortTestHelper::testSort("插入排序",insertSort,arr,n);
     SortTestHelper::testSort("插入排序优化版",insertSort2,arr2,n);

     //插入排序对已经排序的数组有非常好的优化性能
     delete[] arr;
     delete[] arr2;
     return 0;
}