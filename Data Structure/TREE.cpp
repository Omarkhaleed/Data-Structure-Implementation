#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
class BST{
private:
struct Node{
	int data;
	Node *left;
	Node *right;

};
Node *root=nullptr;
int getHeightHelper(Node* temp){
	if(temp==nullptr)
		return -1;
	int left_subtree=getHeightHelper(temp->left);
	int right_subtree=getHeightHelper(temp->right);
	return 1+max(left_subtree,right_subtree);
}
void preOrder(Node *temp){
	if(temp==nullptr)return;
	cout<<temp->data<<" ";
	preOrder(temp->left);
	preOrder(temp->right);
}
Node* removeHelper(Node* root,int data){
	if(root==nullptr) return root;
	else if(data<root->data)
		root->left=removeHelper(root->left,data);
	else if(data>root->data)
		root->right=removeHelper(root->right,data);
	else
	{
		if(root->left==nullptr){
			Node* temp=root->right;
			delete root;
			return temp;
		}
		else if(root->right==nullptr){
			Node* temp=root->left;
			delete root;
			return temp;
		}
		else{
			int maxValue=this->getMaxHelper(root->left);
			root->data=maxValue;
			root->left=removeHelper(root->left,maxValue);
		}
	}
	return root;
}
	;
public:
	
	void add(int value){
		Node *newnode=new Node;
		newnode->data=value;
		newnode->left=nullptr;
		newnode->right=nullptr;
		if(root==nullptr){
			root=newnode;
		return;
		}
		Node *temp=root;
		Node *parent=nullptr;
		while(temp!=nullptr){
			parent=temp;
			if(value<=temp->data){
				temp=temp->left;
		}
		else{
			temp=temp->right;
		}
		}
		if(value<=parent->data)
			parent->left=newnode;
		else
			parent->right=newnode;
	}
	int getMax(){
		Node *temp=root;
		while(temp->right!=nullptr){
			temp=temp->right;
		}
		return temp->data;
	}
	int getMin(){
		Node *temp=root;
		while(temp->left!=nullptr){
			temp=temp->left;
		}
		return temp->data;
	}
	int getHeight(){
		if(root==nullptr)
			return -1;
		else
			return getHeightHelper(root);
	}
	void print_levelOrder(){
		if(root==nullptr)return;
		queue<Node*>q;
		q.push(root);
		while(!q.empty()){
			Node* current=q.front();
			q.pop();
			cout<<current->data<<" ";
			if(current->left!=nullptr)
			q.push(current->left);
			if(current->right!=nullptr)
			q.push(current->right);
		}
		cout<<endl;
	}
	void print_preOrder(){
		if(root!=nullptr)return;
		preOrder(root);
	}
	void remove(int data){
		root=removeHelper(root,data);
	}

};
int main(){
	BST obg;
	obg.add(8);
	obg.add(5);
	obg.add(13);
	obg.add(3);
	obg.add(7);
	obg.add(10);
	obg.add(15);
	/*cout<<obg.getMax()<<endl;
	cout<<obg.getMin()<<endl;
	cout<<obg.getHeight()<<endl;*/
	obg.print_levelOrder();


	system ("pause");
	return 0;
}