//利用二分查找
#include<iostream>
using namespace std;
int main(){
    int a[]={5,2,4,6,1,3};
    int size = sizeof(a)/sizeof(a[0]);
    int temp,j;
    for(int i = 1;i<size;i++){
        temp = a[i];
        j = i-1;
        while(j>=0&&a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1] = temp;
    }

    for(int i = 0;i<size;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
}