#include <iostream>
#include <vector>

using namespace std;

class node {
public:
    int data;
    node* next;
    int colour;

    node(int data1, node* next1) {
        data = data1;
        next = next1;
    }
    node(int data1) {
        data = data1;
        next = nullptr;
    }
};

node* arr2ll(vector<int>& arr) {
    if (arr.empty()) return nullptr; 

    node* head = new node(arr[0]);
    node* mover = head;

    for (int i = 1; i < arr.size(); i++) { 
        node* temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printLL(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

node* deletenode(node* head) {
    if (head == nullptr) return nullptr; 

    node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

int getlen(node* head) {
    node* temp = head;
    int cnt = 0;
    while (temp != nullptr) {
        cnt++;
        temp = temp->next; 
    }
    return cnt;
}

node * deletetail(node * head ){
    node * temp = head ; 
    while(temp -> next -> next != nullptr){
        temp = temp -> next ; 

    }
    delete temp -> next ; 
    temp -> next = nullptr ; 
    return head ; 
}
node * deletek(node * head , int k ){
    if(k == 0 )return nullptr ; 
    if(k==1){
        head = head -> next ; 
        return head ; 
    }
    int cnt = 0 ; 
    node * prev = nullptr ; 
    node * temp = head ; 
    while(temp != nullptr ){
     cnt++ ; 
     if(cnt == k ){
        prev -> next = prev -> next -> next ; 
        break ; 
     }
     prev =temp ; 
     temp = temp -> next ; 

    }
    return head ; 

}


node * deleteele(node * head , int ele ){
    if(head  == nullptr )return nullptr ; 
    if(head -> data ==ele){
        head = head -> next 
        ; 
        return head ; 
    }
    
    node * prev = nullptr ; 
    node * temp = head ; 
    while(temp != nullptr ){
    
     if(temp -> data == ele  ){
        prev -> next = prev -> next -> next ; 
        break ; 
     }
     prev =temp ; 
     temp = temp -> next ; 

    }
    return head ; 

}

node * inserthead(node * head , int data  ){
    node * temp = new node(data , head ) ;
    

    return temp ; 
     
}
node * insertend(node * head , int data ){
    node * end = new node (data , nullptr );

    node * temp = head ; 
    node * prev = nullptr ; 
    while(temp !=  nullptr  ){
        prev = temp ; 
        temp = temp -> next ; 
    }
    prev -> next = end;
    return head ; 
}

node * insertk(node * head , int val , int  k ){
    if(head == nullptr ){
        if( k == 1 ){
            return new node (val);
        }
        else return nullptr ; 
    }
    
    node * temp = head ;
    node * prev = nullptr ; 
    int cnt = 0 ; 
    while(temp != nullptr ){
        cnt++ ; 
        if(cnt == k ){
            node * newele = new node(val , temp -> next );
            prev -> next = newele ; 
            break ; 
            

        }
        prev = temp ; 
        temp = temp -> next ; 

    }
    return head ; 

}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    node* head = arr2ll(arr);
    head = insertk(head , 69 , 3 );
    printLL(head);



    

    return 0;
}
