// 三路快速排序
// 
// v   <v    =v     >v

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
 // 快速排序三路版本 私有函数
template<typename T>
void __quickSOrt3Ways(T arr[],int l,int r){
    if(r - l <= 15){
        insertSort(arr,l,r);
        return;
    }
    //不利用返回值  
    // partition 划分
    swap(arr[l],arr[rand()%(r-l+1)+l]);
    T v = arr[l];
    
    int lt = l; // l+1......lt < v    
    int gt = r +1; // gt......r >v
    int i = l +1; // aer[lt+1.....i) ==v
    while(i<gt){
        if(arr[i]<v){
            swap(arr[i],arr[lt+1]);
            lt++;
            i++;
        }else if(arr[i]>v){
            swap(arr[i],arr[gt-1]);
            gt--;
        }else{ //arr[i] == v;
            i++;
        }
    }
    swap(arr[l],arr[lt]);

    __quickSOrt3Ways(arr,l,lt-1);
    __quickSOrt3Ways(arr,gt,r);
}

// 快速排序三路版本
 template<typename T>
 void quickSOrt3Ways(T arr[],int n){
     
    srand(time(NULL));
    __quickSOrt3Ways(arr,0,n-1);
    
 }


int main(){
    int n = 1000000;
    int* arr = SortTestHelper::generateRandomArray(n,0,n);

    SortTestHelper::testSort("三路快速排序",quickSOrt3Ways,arr,n);
    delete[] arr;

}