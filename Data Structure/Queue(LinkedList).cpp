#include <iostream>
#define capacity 5
#define null 0
using namespace std;
class queue {
private:
	struct node {
		int value;
		node* next;
	};
	node* front =  null; 

	node* rear  =  null;
public:
	void push(int n) {
		node* new_node = new node;
		new_node->value = n;
		new_node->next = null;
		if (isEmpty()) {
			front = rear = new_node;
		}
		else {
			rear->next = new_node;
			rear = new_node;
		}
	}
	void pop() {
		if (isEmpty())
			return;
		node* temp = front;
		if (front == rear)
			front = rear = null;
		else {
			front = front->next;
		}
		delete temp;
	}
	int front_value() {
		if (isEmpty())
			return -1;
		else
			return front->value;
	}
	bool isEmpty() {
		if (front == null && rear == null)
			return true;
		else
			return false;
	}
	void display() {
		if (isEmpty()) {
			cout << "Sorry the queue is Empty";
		}
		else
		{
			while (front != NULL) {
				cout << front->value << " ";
				front = front->next;
			}
		}
			cout << endl;
	}
};
int main() {
	 class queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.pop();
	q.display();
	system("pause");
	return 0;
}
/*
Like Stack, Queue is a linear structure which follows a particular order
in which the operations are performed.
The order is First In First Out(FIFO).
A good example of queue is any queue of consumers for a resource 
where the consumer that came first is served first.
The difference between stacks and queues is in removing.
In a stack we remove the item the most recently added;
in a queue, we remove the item the least recently added.
Operations on Queue :
Mainly the following four basic operations are performed on queue :
Enqueue: Adds an item to the queue.If the queue is full, then it is said to be an Overflow condition.
Dequeue : Removes an item from the queue.The items are popped in the same order in which they are pushed.If the queue is empty, then it is said to be an Underflow condition.
Front : Get the front item from queue.
Rear : Get the last item from queue.

Time Complexity:
Operations              Complexity
Enque(insertion)           O(1)
Deque(deletion)            O(1)
Front(Get front)           O(1)
Rear(Get Rear)             O(1)


*/