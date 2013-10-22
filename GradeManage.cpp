#include<iostream>
using namespace std;
struct Student{
	char name[20];
	long SID;
	int sex;//男生为0，女生为1
	int grade;
}students[100];

void list();
void addstd();
void deletestd();
void inputgra();
void add(struct Student &student);
void input();
int find(long SID);
int stdCount=0;
int j=1;//选课号，按选课顺序排列，第一个选该课的选课号为1
int main(){
		int action;
		do{
			cout<<"--------------菜单-----------------"<<endl;
			cout<<"1)查看学生名单"<<endl;
			cout<<"2)选课（添加学生）"<<endl;
			cout<<"3)退选（删除学生）"<<endl;
			cout<<"4)录入成绩"<<endl;
			cout<<"5)退出程序"<<endl;
			cin>>action;
		    if(cin.fail()){
				cin.clear(ios::goodbit);
				cin.get();
			}
			switch(action){
			case 1:
				list();
				break;
			case 2:
				addstd();
				break;
			case 3:
				deletestd();
				break;
			case 4:
				inputgra();
				break;
			case 5:
				return 0;
			default:
				cout<<"您输入了错误的菜单项，请重新选择！"<<endl;
			}
		}while(1);
	}
	void list(){
		cout<<"-------已选学生-------"<<endl;
		cout<<"姓名\t"<<"学号\t     "<<"性别"<<endl;
		for(int i=0;i<stdCount;i++){
			cout<<students[i].name<<"\t"<<students[i].SID<<"\t"<<students[i].sex<<endl;
			}
			cout<<"-------已选学生-------"<<endl;
	}
	void addstd(){
		struct Student student;
		add(student);
		int i=find(student.SID);
		if(i==stdCount){
			students[i].SID=student.SID;
			strcpy(students[i].name,student.name);
			students[i].sex=student.sex;
			stdCount++;
		}else{
			cout<<"该生已选此课"<<endl;
		}
	}
	void deletestd(){
		struct Student student;
		add(student);
		int i=find(student.SID);
		if(i==stdCount){
			cout<<"输入错误，该生未选此课！"<<endl;
		}else{
			stdCount--;
		}
	}
	void inputgra(){
		int isgoing;
		do{
			if(j>stdCount){
				cout<<"已全部输入"<<endl;
				break;
			}
			input();
			cout<<"是否继续？'是'输入1，‘否’输入0"<<endl;
			cin>>isgoing;
			j++;
		}while(isgoing==1);
	}
    void add(struct Student &student){
		cout<<"姓名: "<<endl;
		cin>>student.name;
		cout<<"学号："<<endl;
		cin>>student.SID;
		cout<<"性别："<<endl;
		cin>>student.sex;
	}
	void input(){
		cout<<"请输入选课号为"<<j<<"的学生的成绩:"<<endl;
		cin>>students[j-1].grade;
	}
	int find(long SID){
		int i;
		for(i=0;i<stdCount;i++){
                if(students[i].SID==SID){
                        break;
                }
        }
        return i;
	}










