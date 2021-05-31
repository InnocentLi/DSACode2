//    选择排序
//    
#include<iostream>
using namespace std;
int main(){
    int a[]={5,2,7,9,4,6,1,3,8};
    int size = sizeof(a)/sizeof(a[0]);
    int min = 0;
    for(int i = 0;i<size;i++){
        min = i;  // 每次确定开头(这个忘了会反复找值排序)
       for(int j = i;j<size;j++){
            if(a[min]>a[j]){
                min = j;          
            }
        }
        swap(a[min],a[i]);
    }

   for(int i = 0;i<size;i++){
       cout<<a[i]<<" ";
   }
   cout<<endl;
}