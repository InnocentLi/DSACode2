// 冒泡排序优化
// 冒泡排序
#include<iostream>
using namespace std;
int main(){
    int a[]={2,5,4,3,6,1};
    int size = sizeof(a)/sizeof(a[0]);
    int flag=0;
    for(int i = 0;i<size;i++){
        for(int j = size-1;j>=i+1;j--){
            if(a[i]>a[j]){
                swap(a[i],a[j]);

            }
            flag++;
        }
    }

    for(int i = 0;i<size;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"flag="<<flag<<endl;
    }