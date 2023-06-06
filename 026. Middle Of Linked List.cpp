/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node *findMiddle(Node *head) {
  // Write your code here
    Node *ptr = head;
    int cnt = 0;
    while (ptr != NULL){
        cnt++;
        ptr = ptr->next;
    }
    cnt = cnt/2;
    ptr = head;
    while(cnt--){
        ptr = ptr->next;
    }
    return ptr;
}

