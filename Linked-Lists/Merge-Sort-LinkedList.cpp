#include <iostream>
using namespace std;
//Linked Lists example structure [10 | *] ? [20 | *] ? [30 | *] ? [40 | NULL]
struct Node //structure for making a linked list 
{
    int data;
    Node* next; // storing the address for the next node 
};
// Insert node at end 
void insertEnd(Node*& head, int value)
{
    Node* newNode = new Node{value, NULL};

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

/* Print the list */
void printList(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

/* Find middle of list */
Node* getMiddle(Node* head)
{
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

/* Merge two sorted lists */
Node* mergeLists(Node* a, Node* b)
{
    if(a == NULL) return b;
    if(b == NULL) return a;

    Node* result;

    if(a->data <= b->data)
    {
        result = a;
        result->next = mergeLists(a->next, b);
    }
    else
    {
        result = b;
        result->next = mergeLists(a, b->next);
    }

    return result;
}

/* Merge Sort function */
Node* mergeSort(Node* head)
{
    if(head == NULL || head->next == NULL)
        return head;

    Node* mid = getMiddle(head);
    Node* second = mid->next;

    mid->next = NULL;

    Node* left = mergeSort(head);
    Node* right = mergeSort(second);

    return mergeLists(left, right);
}

int main()
{
    Node* head = NULL;

    insertEnd(head, 5);
    insertEnd(head, 2);
    insertEnd(head, 8);
    insertEnd(head, 1);
    insertEnd(head, 3);

    cout << "Original List: ";
    printList(head);

    head = mergeSort(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}