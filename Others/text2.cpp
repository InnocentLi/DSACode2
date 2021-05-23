#include<iostream>
#include<string>
using namespace std;

int main(){
	int index = 0;	//下标 
	int count = 0;	//次数 
	int index2 = 0;
	int count2 = 0;
	string str;
	string sub = "black";
	string sub2 = "white";
	getline(cin,str);	
	while( (index=str.find(sub,index)) < str.length() ){
		count++;
		index++;
	}	
	while( (index2=str.find(sub2,index2)) < str.length() ){
		count2++;
		index2++;
	}
	if(count>=count2){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}

}
