// 归并排序
// O（n*logn）
// 耗费N的空间
// 通过比较头部

 #include<iostream>
 #include"000_随机生成数字.h"
 using namespace std;

// 递归 归并排序 对 arr[l...r]
template<typename T>
void __merge(T arr[],int l,int mid,int r){
    // 临时辅助空间赋值
    T aux[r-l+1];
    for(int i = l;i <= r;i++){
        aux[i-l] = arr[i];
    }

    // 归并
    int i = l,j = mid +1;
    for(int k = l;k<=r;k++){
        
        if(i>mid){
            arr[k] = aux[j-l];
            j++;
        }else if(j > r){
            arr[k] = aux[i-l];
            i++;
        }else if(aux[i-l]<aux[j-l]){
            arr[k] = aux[i-l];
            i++;
        }
        else{
            arr[k] = aux[j-l];
            j++;
        }
    }
}


template<typename T>
void __mergeSort(T arr[],int l,int r){
    if( l >= r ){
        return;
    }      
    int mid = (l+r)/2;      // 溢出风险
    __mergeSort(arr,l,mid);
    __mergeSort(arr,mid+1,r);
    
    __merge(arr,l,mid,r);
}

 template<typename T>
 void mergeSort(T arr[],int n){
     //private
     __mergeSort(arr,0,n-1);
 }

 int main(){
     int n = 50000;
     int *arr = SortTestHelper::generateRandomArray(n,0,n);
     SortTestHelper::testSort("归并排序排序",mergeSort,arr,n);
     return 0;
 }
