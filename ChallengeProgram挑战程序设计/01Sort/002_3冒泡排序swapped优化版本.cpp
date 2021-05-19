#include<iostream>
using namespace std;
void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
    cout<<"交换"<<endl;
}

int main(){
    int a[]={2,9,5,4,3,8,6,1,7};
    int size = sizeof(a)/sizeof(a[0]);
    int swapped;
    for(int i = 0;i<size-1;i++){
        swapped = 1;
        for(int j = 0;j<size-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                 swapped = 1;     // 当完全没有进入这个循环说明排序成功可以退出
            }
                      
        }

        if(swapped == 0){
            break;
        }
    }

    for(int i = 0;i<size;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}