// 插入排序未优化版本

#include<iostream>
using namespace std;
int main(){  
    int a[9]={3,2,8,7,4,6,9,5,1};
    int b[6]={5,2,4,6,1,3};

    int call = 0;

    int size = sizeof(a)/sizeof(a[0]);
    int sizeb = sizeof(b)/sizeof(b[0]);
    for(int i = 0;i<sizeb-1;i++){
        for(int j = i;j>=0;j--){
            if(b[j]>b[j+1]){
                for(int i = 0;i<sizeb;i++){
                    cout<<b[i]<<" ";
                }
                cout<<endl;
                swap(b[j],b[j+1]);
                call++;
            }else{
                call++;
                break;
            }
        }
    }

    for(int i = 0;i<sizeb;i++){
        cout<<b[i]<<" "; 
    }
    
    cout<<endl;
   cout<<call<<endl;
    return 0;
} // namespace std;


