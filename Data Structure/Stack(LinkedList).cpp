#include<iostream>
#include<malloc.h>
#define Null 0
using namespace std;
class stack {
	struct node {
		int value;
		node* next;
	};
	node* top;
public:
	stack() {
		top = Null;
	}
	void push(int n) {
		node* new_node = new node;
		new_node->value = n;
		if (isEmpty()) {
			new_node->next = Null;
			top = new_node;
		}
		else
			//unlike the linkedlist(1<=2<=3<=4)
		   //in     linkedlist     (1=>2=>3=>4)
			new_node->next = top;
		     top = new_node;
	}
	void pop() {
		if (isEmpty())
			cout << "stack is empty" << endl;
		else {
			node* temp = top;
			top = top->next;
			delete temp;
		}
	}
	bool isEmpty() {
		if (top == Null)
			return true;
		else
			return false;
	}
	void topValue() {
		if (!isEmpty())
			cout << top->value << endl;
		else
			cout << "stack is empty" << endl;
	}
	void show() {
		while (top != Null) {
			cout << top->value << endl;
			top = top->next;
		}
	}
};

int main() {

	stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	int num;
	cout << "TO Display all elemeents Enter 1 " << "          " << "TO Display the last element Enter 2 " << endl;
	cin >> num;
	if (num == 1) {
		s.show();
	}else
	{
		s.topValue();
	}
	
	system("pause");
	return 0;
}
// Stack 
/*
Time Complexities of operations on stack:
push(), pop(), isEmpty() and peek() all take O(1) time.
We do not run any loop in any of these operations.
Stack with array (Easy to implement and non dynamic)
Stack with linkedlist{
Pros: The linked list implementation of stack can grow and 
shrink according to the needs at runtime.
Cons: Requires extra memory due to involvement of pointers.


}


*/