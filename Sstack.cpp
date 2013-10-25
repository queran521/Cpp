#include<iostream>
using namespace std;
class Node{
public:
	Node(int d):data(d){};
	Node* next;
	Node(){};
	int getData(){
    return data;
	}
private:
	int data;
};
class Sstack{
public:
	void push(int item);
	int pop();
	bool isEmpty();
Sstack(){
    head=new Node();
}
~Sstack(){
	delete head;
}
private:
	Node* head;
};
void Sstack::push(int item){
	Node* node=new Node(item);
	node->next=head->next;
	head->next=node;
}
int Sstack::pop(){
	int n;
	Node *p=head->next;
	head->next=p->next;
	n=p->getData();
	cout<<"出栈数据为："<<n<<endl;
	delete p;
	return 0;
}
bool Sstack::isEmpty(){
	return(head==NULL);
}
int main(){
	Sstack sstack;
	sstack.push(100);
	sstack.pop();
}



