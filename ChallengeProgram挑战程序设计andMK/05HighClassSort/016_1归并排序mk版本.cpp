// 归并排序
// O（n*logn）
// 耗费N的空间
// 通过比较头部

 #include<iostream>
 using namespace std;

// 递归 归并排序 对 arr[l...r]
template<typename T>
void __merge(T arr[],int l,int mid,int r){

    T aux[r-l+1];
    for(int i = l;i <= r;i++){
        aux[i-l] = arr[i];
    }
     int i = l,j = mid +1;
     for(int k = l;k<=r;k++){
         if(aux[i-l]<aux[j-1]){
             arr[k] = aux[i-l];
         }
         else{
             
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
     __nergeSort(arr,0,n-1){
        
     }
    

 }

 int main(){

 }