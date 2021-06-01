// MK模板  
// 模板目的是为了泛型
#include<iostream>

#include "000_6student.h"
#include "000_随机生成数字.h"

using namespace std;


// 插入排序基本算法
template<typename T>
void selectionSort(T arr[],int n){
    for(int i = 0;i<n;i++){
        // 寻找最小值
        int minIndex = i;
        for(int j = i+1;j<n;j++){
            if(arr[j]<arr[minIndex])
                minIndex = j;
        }
        swap(arr[i],arr[minIndex]);
    }
}
int main(){
    //整数排序
     int a[10] = {8,9,6,4,3,1,10,2,5,7};
     selectionSort(a,10);
     for(int i = 0;i<10;i++){
         cout<<a[i]<<" ";
     }
     cout<<endl;
    //浮点数排序
    float b[5] = {4.4,3.2,6.7,5.5,1.8};
    selectionSort(b,5);
    for(int i = 0;i<5;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;

    //字符串排序
    string c[5] = {"D","A","B","C","E"};
    selectionSort(c,5);
    for(int i = 0;i<5;i++){
        cout<<c[i]<<" ";
    }
    cout<<endl;


    //结构体排序
    Student d[4] = {{"h",80},{"x",70},{"u",95},{"s",85}};
    selectionSort(d,4);
    for(int i;i<4;i++){
        cout<<d[i];
    }
    cout<<endl;


    // 利用模板进行排序
    // 随机的种子数量
    int n = 100000;
    int *arr = SortTestHelper::generateRandomArray(n,0,n);
    // selectionSort(arr,n);
    // for(int i = 0;i<n;i++)
    //     cout<<arr[i]<<" ";
    // cout<<endl;
    
    //SortTestHelper::printArray(arr,n);
    SortTestHelper::testSort("选择排序",selectionSort,arr,n);


    delete[] arr;

    return 0;

   

    //随机生成数字测试

}