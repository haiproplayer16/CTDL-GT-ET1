#include<iostream>
struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
class LinkedList{
    ListNode* head;
    ListNode* tail;
public:
    
    LinkedList():head(nullptr),tail(nullptr){}
    bool IsEmpty() const {return head==nullptr;}
    void addfirst(int val){
        ListNode* newNode=new ListNode(val);
        if(IsEmpty()){
            head=tail=newNode;
        }
        else {
            newNode->next=head;
            head=newNode;
        }
    }
    void addlast(int val){
        ListNode* newNode=new ListNode(val);
        if (IsEmpty()){
            head=tail=newNode;
        }
        else {
            tail->next=newNode;
            tail=newNode;
        }
    }
    void deletefirst(){
        if (IsEmpty()) return;
        ListNode* p=head;
        head=head->next;
        delete p;
        if (IsEmpty()) tail=nullptr;
    }
    void clear(){
        while (!IsEmpty()){
            ListNode* p=head;
            head=head->next;
            delete p;
        }
        tail=nullptr;
    }
    void removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        while (curr != nullptr) {
            if (curr->val == val) {
                prev->next = curr->next;  
                delete curr;              
                curr = prev->next;        
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        head = dummy->next;
        delete dummy;  // xóa node giả
    }
    ~LinkedList(){clear();}
};

int main(){
    
}