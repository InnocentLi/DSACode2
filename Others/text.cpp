#include<iostream>
#include <assert.h>
#include<stdio.h>
using namespace std;
int find(const char* targetString,const char* subString){
	assert(NULL!=targetString||NULL!=subString);
	int i=0;
	int j=0;
	int num=0;
	while(targetString[i]!='\0'){
		if(subString[j]!='\0'){
			if(targetString[i]==subString[j]){i++;j++;}
			else {i=i-j+2;j=1;}
		}
		else {num++;i=i-j+2;j=1;}
	}
	return num;
}
int main(){

        int str;
        cin>>str;
        int white = 0;
        int black = 0;
        white=find("str","white");
        black=find("str","black");
        if(black>=white){
             cout<<"Yes"<<endl;
             return 0;
        }else{
            cout<<"No"<<endl;
            return 0;
        }
	return 0;
}