#include <iostream>
#define capacity 5
using namespace std;
//const int capacity=5;
class queue{
private:
	int rear;
	int front;
	int data[capacity];
public:
	queue(){
		rear=-1;
		front=-1;
	}
	bool isEmpty(){
		if(rear==-1 && front==-1)
			return true;
		else
			return false;
	}
	bool isFull(){
		if(rear==capacity-1)
			return true;
		else
			return false;
	}
	void push(int n){
		if(isFull())
		cout<<" the queue is full"<<endl;
		else if(isEmpty())
			front=rear=0;
		else{
			rear++;
		}
			data[rear]=n;
	}
	void pop(){
		if(isEmpty())
		cout<<"the queue is empty"<<endl;
		else if(front==rear)
		 front=rear=-1;
		else
			front++;
	}
	int front_valu(){
		if(isEmpty())	
		cout<<" the queue is empty"<<endl;
		else
			return data[front];
	}

	void show(){
		if(isEmpty())
		cout<<"the queue is empty"<<endl;
		else{
			cout<<" the elements are "<<endl;
		for(int i=front;i<=rear;i++)
			cout<<data[i]<<" ";
		cout<<endl;
	}
	}
};
int main(){
	queue q;
	q.push(12);
	q.push(14);
	q.push(16);
	q.push(18);
	q.push(20);
	q.push(22);
	//q.push(24);
	/*while(!q.isEmpty()){
		cout<<q.front_valu()<<" ";
		q.pop();
	}
	/*/
	//q.pop();
	q.show();
	system("pause");
	return 0;
}