// 归并排序  自顶向上
// O（n*logn）

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

//自底向上排序
 template<typename T>
 void mergeSortBU(T arr[],int n){
     //private
    for(int size = 1;size<=n;size+=size){
         for(int i = 0;i<n;i+=size + size){
             //对 arr[i....i+size-1] 和 arr[i+size.....i+2*size -1] 进行归并
             __merge(arr,i,i+size-1,min(i+size+size-1,n-1));
         }
    }

 }

//样例
// i:0size:1
// i:2size:1
// i:4size:1
// i:6size:1
// i:8size:1
// i:10size:1
// i:12size:1
// i:14size:1
// i:0size:2
// i:4size:2
// i:8size:2
// i:12size:2
// i:0size:4
// i:8size:4
// i:0size:8
// i:0size:16
 template<typename T>
 void mergeSortBU2(T arr[],int n){
     //private
    for(int size = 1;size<=n;size+=size){
         for(int i = 0;i<n;i+=size + size){
             cout<<"i:"<<i<<"size:"<<size<<endl;
             //对 arr[i....i+size-1] 和 arr[i+size.....i+2*size -1] 进行归并
             __merge(arr,i,i+size-1,min(i+size+size-1,n-1));
         }
    }
 }

 int main(){
    int n = 50000;
    int *arr = SortTestHelper::generateRandomArray(n,0,n);
    SortTestHelper::testSort("归并排序自定向上",mergeSortBU,arr,n);

    // int n = 16;
    // int *arr = SortTestHelper::generateRandomArray(n,0,n);
    // SortTestHelper::testSort("归并排序自定向上",mergeSortBU2,arr,n);
    return 0;
 }
