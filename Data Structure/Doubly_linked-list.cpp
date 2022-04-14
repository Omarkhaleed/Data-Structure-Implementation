 #include<iostream>
#include<malloc.h>
#define null 0
using namespace std;
class DoublyLinkedList{
private:
	struct Node{
		int data;
		Node* next;
		Node* prev;

		Node(){
			next = nullptr;
			prev = nullptr;
			
		}
	};
	Node* const head = nullptr;
public:
	void append(struct Node*head,int val){
		Node* newNode = new Node;
		newNode->data = val;
		if (head == nullptr){
			head = newNode;
		}
		else{
			Node* temp = head;
			while (temp->next != nullptr){
				temp = temp->next;
			}
			temp->next = newNode;
			newNode->prev = temp;
		}
	}
	void push_at_pos(int val, int pos){
		Node* newNode = new Node;
		newNode->data = val;
		if (head == nullptr){//
			head = newNode;
			return;
		}//
		if (pos == 0){
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
			return;
		}

		Node* temp = head;
		for (int i = 0; i < pos && temp != nullptr; i++){
			temp = temp->next;
		}

		if (temp == nullptr){
			this->append(val);
			return;
		}
		 // very important part
		newNode->prev = temp->prev;
		temp->prev->next = newNode;
		temp->prev = newNode;
		newNode->next = temp;
	}

	void remove(int val){
		if (head == nullptr)
			return;

		Node* temp;
		temp = head;

		if (temp->data == val){
			head = temp->next;
			if (head != nullptr)
				head->prev = nullptr;
			delete temp;
			return;
		}
		while (temp != nullptr && temp->data != val){
			temp = temp->next;
		}
		if (temp == nullptr){
			return;
		}
		else{
			temp->prev->next = temp->next;
			if (temp->next != nullptr)
				temp->next->prev = temp->prev;
			delete temp;
		}
	}

	void remove_at_pos(int pos){
		if (head == nullptr)
			return;

		Node* temp = head;
		if (pos == 0){
			head = temp->next;
			if (head)
				head->prev = nullptr;
			delete temp;
			return;
		}

		for (int i = 0; i < pos && temp != nullptr; i++){
			temp = temp->next;
		}
		if (temp == nullptr)
			return;
		temp->prev->next = temp->next;
		if (temp->next)
			temp->next->prev = temp->prev;
		delete temp;

	}

	void show(){
		Node* temp = head;
		while (temp != nullptr){
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout <<endl;

	}

	void reverse_display(){
		Node* temp = head;
		while (temp->next != nullptr){
			temp = temp->next;
		}
		//---------------------------
		while (temp != nullptr){
			cout << temp->data << " ";
			temp = temp->prev;
		}
		cout <<endl;

	}
};
int main()
{
	DoublyLinkedList s;
	Node* head = NULL;
	s.append(&head,5);
	s.append(&head,7);
	s.push_at_pos(9,2);
	s.remove_at_pos(5);
	s.show();
	system("pause");
	return 0;
}
