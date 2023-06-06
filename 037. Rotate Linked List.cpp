/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     // Write your code here.
     if(head == NULL){
          return head;
     }
     int cnt = 0;
     Node * ptr = head,* res = head;
     while(ptr != NULL){
          cnt++;
          ptr = ptr->next;
     }
     k = k%cnt;
     if(k == 0 || k == cnt){
          return head;
     }
     ptr = head;
     for(int i = 0 ; i < cnt - k-1; i++){
          ptr = ptr->next;
     }
     Node * firstend = ptr;
     Node * secondstart = ptr->next;
     firstend->next = NULL;
     ptr = secondstart;
     while(ptr->next != NULL){
          ptr = ptr->next;
     }
     ptr->next = head;
     head = secondstart;
     return head;
}
