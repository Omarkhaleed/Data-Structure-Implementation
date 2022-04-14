
// A complete working C++ program to demonstrate
//  all insertion methods on Linked List
#include<iostream>
//#include <bits/stdc++.h>
using namespace std;

// A linked list node
class Node
{
public:
    int data;
    Node* next;
};

/* Given a reference (pointer to pointer)
to the head of a list and an int, inserts
a new node on the front of the list. */
void push(Node** head, int new_data)
{
    /* 1. allocate node */
    Node* new_node = new Node();
    /* 2. fill the node to be the first one*/
    new_node->data = new_data;
    new_node->next = (*head);

    /* 3. move the head to point to the new node */
    (*head) = new_node;
}

/* Given a node prev_node, insert a new node after the given
prev_node */
void insertAfter(Node* prev_node, int new_data)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL)
    {
        cout << "the given previous node cannot be NULL";
        return;
    }

    /* 2. allocate new node */
    Node* new_node = new Node();

    /* 3. put in the data */
    new_node->data = new_data;

    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;

    /* 5. move the next of prev_node as new_node */
    prev_node->next = new_node;
}

/* appends a new node at the end */
void append(Node** head, int new_data)
{
    /* 1. allocate node */
    Node* new_node = new Node();
    /*fill the node to be the last one*/
    new_node->data = new_data;
    new_node->next = NULL;

    /* 4. If the Linked List is empty,
    then make the head point to the first node */
    if (*head== NULL)
    {
        *head = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    Node* last = *head;
    while (last->next != NULL)
        last = last->next;
    /* 6. Change the next of last node */
    last->next = new_node;
    return;
}
/*Delete the node */
void deleteNode(Node** head_ref, int key)
{

    // Store head node
    Node* temp = *head_ref;
    Node* prev = NULL;

    // If head node itself holds
    // the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; // Changed head
        delete temp;            // free old head
        return;
    }

    // Else Search for the key to be deleted,
    // keep track of the previous node as we
    // need to change 'prev->next' */
    else
    {
        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }
        // If key was not present in linked list
        if (temp == NULL)
            cout << "Sorry this node doesn't exist";
            return;

        // Unlink the node from linked list
        prev->next = temp->next;
        // Free memory
        delete temp;
    }
}
void searchNode(Node** head_ref, int key) {
    Node* temp = *head_ref;
    if (temp != NULL && temp->data == key) {
        cout << " yes,your node is exist";
        return;
    }
    else{
        while (temp != NULL && temp->data != key) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Sorry this node doesn't exist";
            return;
        }
        else {
            cout << " yes,your node is exist";
            return;
             
        }


    }
}


// This function prints contents of
// linked list starting from head
void printList(Node* node)
{
    while (node != NULL)
    {
        cout << " " << node->data;
        node = node->next;
    }
}

/* Driver code*/
int main()
{
    /* Start with the empty list */
    Node* head = NULL;
    // Insert 6. So linked list becomes 6->NULL
    append(&head, 6);
    // Insert 7 at the beginning.
    // So linked list becomes 7->6->NULL
    push(&head, 7);
    // Insert 1 at the beginning.
    // So linked list becomes 1->7->6->NULL
    push(&head, 1);
    // Insert 4 at the end. So
    // linked list becomes 1->7->6->4->NULL
    append(&head, 4);
    // Insert 8, after 7. So linked
    // list becomes 1->7->8->6->4->NULL
    insertAfter(head->next, 8);
    cout << "Created Linked list is: ";
    printList(head);
    cout << endl;
    deleteNode(&head, 10);
    cout << "After delete the node  the Linked list is: ";
    printList(head);
    cout << endl;
    searchNode(&head, 1);
    system("pause");
    return 0;
}
   

/////NOTE THAT 
/*   
//THE TIME OF EACH OPERATION IN Array
=====================================
Constant-time access to any element.
Constant time to add/remove at the end.
 O(n) to add/remove at the beginning && the middle
 because every element should be moved in *(begining) 
 and some elements should be moved in *(middle) 
 ===========================================================
//THE TIME OF EACH OPERATION IN SINGL LINKEDLIST
               NoTail      WithTail(that mean in double linkedlist)
PushFront(Key)  O(1)
TopFront()      O(1)
PopFront()      O(1)
PushBack(Key)   O(n)         O(1)
TopBack()       O(n)         O(1)
PopBack()       O(n)
Find(Key)       O(n)
Erase(Key)      O(n)
Empty()         O(1)
AddBefore()     O(n)
AddAfter()      O(1)





*/