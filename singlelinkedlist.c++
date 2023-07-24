#include<iostream>
using namespace std;
class Node{
     public:
        int key,data;
        Node* next;
    Node(){
        key=0;
        data=0;
        next=NULL;
    }
    Node(int k,int d){
        key=k;
        data=d;
    }
};
class singlinkedliist{
    public:
       Node* head;
    singlinkedliist(){
        head=NULL;
    }
    singlinkedliist(Node *link){
        head=link;
    }
//1.Search
    Node* linkeexist(int k){
       Node* temp=NULL;
       Node* ptr=head;
       while(ptr!=NULL){
          if(ptr->key==k){
            temp=ptr;
          }
          ptr=ptr->next;
       }
       return temp;
    }
//2.Append
    void append(Node* n){
         if(linkeexist(n->key)!=NULL){
            cout<<"The key value : "<<n->key<<" already Exist"<<endl;
         }
         else{
             if(head==NULL){
                head=n;
                cout<<"Value appended";
             }
             else{
                Node* ptr=head;
                while(ptr->next!=NULL){
                    ptr=ptr->next;
                }
                ptr->next=n;
                cout<<"Value appended";
             }
         }
    }
//3.Prepand
    void prepend(Node* n){
        if(linkeexist(n->key)!=NULL){
            cout<<"The key value : "<<n->key<<" already Exist"<<endl;
         }
         else{
            n->next=head;
            head=n;
            cout<<"Value appended";
         }
    }
//4.Display
    void display(){
        Node* ptr=head;
        if(ptr==NULL){
            cout<<"List is Empty";
        }
        else{
             while(ptr!=NULL){
                cout<<"("<<ptr->key<<","<<ptr->data<<")"<<"-->";
                ptr=ptr->next;
             }
        }
    }
//5.Inset Middle
    void insetafter(int k,Node* n){
        Node* temp=NULL;
        Node* ptr=linkeexist(k);
        if(ptr==NULL){
            cout<<"Enter Key value doesn't Exist";
        }
        else{
            if(linkeexist(n->key)!=NULL){
                cout<<"The key value : "<<n->key<<" already Exist"<<endl;
            }
            else{
                 temp=ptr->next;
                 ptr->next=n;
                 n->next=temp;
            }
        }
    }
//6.Update 
    void update(int key){
        Node* ptr=linkeexist(key);
        if(ptr==NULL){
            cout<<"Enter Key value doesn't Exist";
        }
        else{
            int temp;
            cout<<"Present value : "<<ptr->data<<endl;
            cout<<"Enter the value to change : ";
            cin>>temp;
            ptr->data=temp;
        }
    }
//delete
    void deletevalue(int key){
      if(head==NULL){
        cout<<"Unable to delete List is empty";
      }
      else{
        Node* ptr=head;
        if(ptr->key==key){
            head=ptr->next;
            cout<<key<<"key Node unlinked"<<endl;
        }
        else{
             Node* temp=NULL;
             Node* pervious=head;
             Node* current=head->next;
             while(current!=NULL){
                if(current->key==key){
                   temp=current;
                   current=NULL;
                }
                else{
                    pervious=pervious->next;
                    current=current->next;
                }
             }
             if(temp!=NULL){
                pervious->next=temp->next;
                cout<<key<<"Node unlinked";
             }
             else{
                cout<<key<<" not found";
             }
        }
      }
    }
};
int main(){
       singlinkedliist s1;
       int option;
       do{
        cout<<endl;
        cout<<"Select the operation to perform else Enter 0 to exit"<<endl;
        cout<<"1.append()"<<endl;
        cout<<"2.Search()"<<endl;
        cout<<"3.Display()"<<endl;
        cout<<"4.prepand()"<<endl;
        cout<<"5.Inset Inbetween()"<<endl;
        cout<<"6.Update()"<<endl;
        cout<<"7.Delete()"<<endl;
        cout<<"Enter the input : ";
        cin>>option;
        Node* n1=new Node();
        switch (option)
        {
        int key,data;
        case 1:
            cout<<"Enter the key value  : ";
            cin>>key;
            cout<<"Enter the data value : ";
            cin>>data;
            n1->key=key;
            n1->data=data;
            s1.append(n1);
            break;
        case 2: 
            cout<<"Enter the key value : ";
            cin>>key;
            if(s1.linkeexist(key)==NULL){
                cout<<"key value not exist"<<endl;
            }
            else{
                cout<<"key value Exist"<<endl;
            }
            break;
        case 3:
            s1.display();
            break;
        case 4:
            cout<<"Enter the key value  : ";
            cin>>key;
            cout<<"Enter the data value : ";
            cin>>data;
            n1->key=key;
            n1->data=data;
            s1.prepend(n1);
            break;
        case 5:
            int key1;
            cout<<"Enter the key value  : ";
            cin>>key1;
            cout<<"Enter the key value  : ";
            cin>>key;
            cout<<"Enter the data value : ";
            cin>>data;
            n1->key=key;
            n1->data=data;
            s1.insetafter(key1,n1);
            break;
        case 6:
            cout<<"Enter the key value  : ";
            cin>>key;
            s1.update(key);
            break;
        case 7:
            cout<<"Enter the key value  : ";
            cin>>key;
            s1.deletevalue(key);
            break;
        default:
            break;
        }
     }while(option!=0);
}