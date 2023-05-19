// linklist implimentation of josephres problem

#include<bits/stdc++.h>
using namespace std;

template <typename D>
class node{
    public:
    D val;
    node *next=NULL;
    
    node(int value){
        this->val = value;
    }
};
//append
//delete
template <typename D>
class ll{
    public:
    node<D> *head=NULL;
    void append(D value){
        if(this->head==NULL){
            this->head= new node<D>(value);
            this->head->next = this->head;
            
        }
        else{
            node<D> *tra = this->head;
            while(tra->next != this->head)
                tra = tra->next;
            node<D> *newnode = new node<D>(value);
            newnode->next = this->head;
            tra->next = newnode;
        }
    }



    void dlt()
    {
        node<D> *temp;
        
        node<D> *prev;
        temp = this->head;
        prev = this->head;
        // cout<<(this->head->next == this->head)<<endl;
        // if(this->head->next == this->head){
        //     this->head = NULL;
        //     return;
        // }
        // if (i == position - 1 && temp) {
        temp = temp->next;
        prev->next = temp->next;
        free(temp);
        this->head = this->head->next;
        // }
        // else {
        // prev = temp;

        // Position was greater than
        // number of nodes in the list
        // if (prev == NULL)
            // break;
        // temp = temp->next;
        // }   
        
    }
    int print(){
        cout<<endl;
        node<D> *tra = this->head;

        if(tra != NULL){
           cout<<tra->val<< " ";
            while(tra->next != this->head){
                tra=tra->next;
                cout<<tra->val<< " ";
            
            }
        }else{
            cout<<"linked List is empty"<<endl;            
            return 0;
        }
        cout<<endl;

        return 1;
    }
};





int main(){
    int n = 10;
    ll<int> list ;
    for(int i = 0 ; i< n ; i++)
        list.append(i);
    list.print();
    // cout<<list.head->val;
    // cout<<(list.head != NULL && list.head->next != list.head)<<endl;
    node<int> *tra = list.head;

    while(list.head != NULL && list.head->next != list.head){
        cout<<"Killing : "<<list.head->next->val<< " ";
        list.dlt();
        list.print();

        // list.head = list.head->next;
        cout<<endl;

    }
    cout<<"Last One Alive :" ;
    list.print();
}