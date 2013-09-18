#include<iostream>
using namespace std;
long f(int x,int y);//函数声明部分
int main(){
	cout<<"please input two integers:"<<endl;
	int x,y;long ans;
	cin>>x>>y;
	if(x<=0||y<0)
		cout<<"input error"<<endl;//判断输入数据是否合格 
	if(x==1)
		cout<<"the answer is 1"<<endl;//1的任何次幂都是1
	else{
	   if(y==0)
		  ans=1;//任何数的零次方都是1
	   else
		   ans=x*f(x,y-1);
	   cout<<"the answer is "<<ans<<endl;//调用递归函数求结果
	}
	return 0;
}
long f(int x,int y){
	long ans;
	if(y==1)
		ans=x;
	else
		ans=x*f(x,y-1);
	return ans;
}//递归函数部分
