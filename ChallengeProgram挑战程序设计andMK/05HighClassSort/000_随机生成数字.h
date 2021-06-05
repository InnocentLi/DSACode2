
#ifndef SORT_SORTHELPER_H
#define SORT_SORTHELPER_H

#include<iostream>
#include<ctime>
#include<cassert>

using namespace std;


namespace SortTestHelper{
    
    // 生成一个近乎有序的数组
    // 首先生成一个含有[0...n-1]的完全有序数组, 之后随机交换swapTimes对数据
    // swapTimes定义了数组的无序程度:
    // swapTimes == 0 时, 数组完全有序
    // swapTimes 越大, 数组越趋向于无序
    int *generateNearlyOrderedArray(int n, int swapTimes){

        int *arr = new int[n];
        for(int i = 0 ; i < n ; i ++ )
            arr[i] = i;

        srand(time(NULL));
        for( int i = 0 ; i < swapTimes ; i ++ ){
            int posx = rand()%n;
            int posy = rand()%n;
            swap( arr[posx] , arr[posy] );
        }

        return arr;
    }
    
    int* generateRandomArray(int n,int L,int R){
        int *arr = new int[n];
        
        srand(time(NULL));

        for(int i = 0 ;i < n;i++)
            arr[i] =  rand() % (R-L+1)+L;
        return arr;
    }

    template<typename T>
    void printArray(T arr[],int n){
        for(int i =0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return;
    }

    
    template<typename T>
    bool isSorted(T arr[],int n){
        for(int i = 0;i < n-1; i++){
            if(arr[i]>arr[i+1]){
                return false;
            }
        }
        return true;
    }

    template<typename T>
    void testSort(string sortName, void(*sort)(T[],int),T arr[],int n){
        

        clock_t startTime = clock();
        sort(arr,n);
        clock_t endTime = clock();
        //CLOCKS_PER_SEC 每秒钟运行时间周期个数
        assert(isSorted(arr,n));
        cout<< sortName<<":"<< double(endTime-startTime)/CLOCKS_PER_SEC <<"s"<<endl;

        return;
    }
  
    int* copyIntArray(int a[], int n){
        int* arr = new int[n];
        copy(a,a+n,arr);
        return arr;
    }

    

}
#endif // SORT_SORTHELPER_H