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

Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    Node* ptr = head;
    int cnt = 0;
    while(ptr != NULL){
        ptr = ptr->next;
        cnt++;
    }
    if(cnt-K == 0){
        return head->next;
    }
    ptr = head;
    int t = cnt-K;
    while(t-->1){
        ptr = ptr->next;
    }
    ptr->next = ptr->next->next;
    return head;
}
