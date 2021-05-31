//    选择排序双端优化   暂时有问题

//  即每次找最大值和最小值
//    
#include<iostream>
using namespace std;
int main(){
    int a[]={5,2,7,9,4,6,1,3,8,0};
    int size = sizeof(a)/sizeof(a[0]);
    int min = 0;
    int max = size-1;
    for(int i = 0;i<size-1-i;i++){
        min = i; 
        max = size -1-i;
        if (a[min] > a[max]){
            swap( min, max);
        }         
        for(int j = i+1;j<size-1-i;j++){
            if(a[min]>a[j]){
                min = j;           
            }
            if(a[max]<a[j]){
                max = j;
            }
        }
        swap(a[min],a[i]);
        swap(a[max],a[size-i-1]);
    }

   for(int i = 0;i<size;i++){
       cout<<a[i]<<" ";
   }
   cout<<endl;
}