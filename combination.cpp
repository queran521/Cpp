#include<iostream>
using namespace std;
int f(int x);//函数声明部分
int main(){
	int m,n,ans;
	cout<<"please input two integer numbers:"<<endl;
	cin>>m>>n;//输入两个整数
	if(m<=0||n<0||n>m)
		cout<<"input error"<<endl;//判断输入是否合法
	else
	{
		ans=f(m)/(f(m-n)*f(n));
		cout<<"the answer is "<<ans<<endl;//利用组合公式调用递归函数求结果
	}
	return 0;
}
int f(int x){
	if(x==0||x==1){
		return 1;}
	else{
		return(x*f(x-1));
	}
}//递归函数求阶乘
