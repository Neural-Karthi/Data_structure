#include<iostream>
using namespace std;
class Node{
    public:
       int key;
       int data;
       Node* next;
       Node* pervious;
       Node(){
        key=0;
        data=0;
        next=NULL;
        pervious=NULL;
       }
       Node(int k,int d){
        key=k;
        data=k;
        next=NULL;
        pervious=NULL;
       }
};
class doublylinklist{
     public:
        Node* head;
    doublylinklist(){
        head=NULL;
    }
    doublylinklist(Node* n){
        head=n;
    }
//2.Search
    Node* Linkexist(int key){
        Node* temp=NULL;
        Node* ptr=head;
        while(ptr!=NULL){
            if(ptr->key==key){
                temp=ptr;
            }
            ptr=ptr->next;
        }
        return temp;
    }
//Append
    void append(Node* n){
        if(Linkexist(n->key)!=NULL){
            cout<<"Key value already exist";
        }
        else{
           Node* ptr=head;
           if(head==NULL){
                 head=n;
                 cout<<"Value appended"<<endl;
            }  
           else{
                 while(ptr->next!=NULL){
                 ptr=ptr->next;
            }
            ptr->next=n;
            n->pervious=ptr;
            cout<<"Value appended"<<endl;
          }
        }
    }
//prepend
    void prepend(Node* n){
        if(Linkexist(n->key)!=NULL){
            cout<<"Key value already exist";
        }
        else{
          head->pervious=n;
          n->next=head;
          head=n;
          cout<<"value prepended ";
        }
    }
//update
    void update(int k){
        Node* ptr=head;
         if(Linkexist(k)==NULL){
            cout<<"Key value Not exist";
        }
        else{
          while(ptr!=NULL){
               if(ptr->key==k){
                   int value;
                   cout<<"Enter the data value to change : ";
                   cin>>value;
                   ptr->data=value;
                   cout<<"Value updated";
               }
               ptr=ptr->next;
          }
        }
    }
//Inbetween
    void inbetween(int key,Node* n){
        Node* temp=NULL;
        Node* ptr=head;
        Node* next=head->next;
            if(Linkexist(n->key)==NULL){
                  while(ptr!=NULL&&next!=NULL){  
                    if(ptr->key==key){
                       temp=ptr->next;
                       n->pervious=ptr;
                       n->next=temp;
                       ptr->next=n;
                       next->pervious=n;
                      cout<<"Value inseted";
                    }
                     ptr=ptr->next;
                     next=next->next;
                  }
            }
           else{
              cout<<n->key<<" key value already exist ";
            }
    }
//delete
   void deletevalue(int key){
       Node* ptr=Linkexist(key);
       if(ptr==NULL){
         cout<<"value doesnt exist";
       }
       else{
          if(head->key==key){
              head=head->next;
              cout<<"Node Unlinked";
          }
          else{
             Node* nextnode=ptr->next;
             Node* perviousnode=ptr->pervious;
             if(nextnode==NULL){
                perviousnode->next=NULL;
                cout<<"Node Unlinked";
             }
             else{
                perviousnode->next=nextnode;
                nextnode->pervious=perviousnode;
                cout<<"Node Unlinked";
             }
          }
       }
   }
//Display
    void display(){
        Node* ptr=head;
        while(ptr!=NULL){
            cout<<"("<<ptr->key<<","<<ptr->data<<")"<<"("<<"pervious : "<<ptr->pervious<<" next : "<<ptr->next<<")"<<"-->"<<endl;
            ptr=ptr->next;
        }
    }
};
int main(){
    doublylinklist d1;
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
        case 1:
            int keyvalue,datavalue;
            cout<<"Enter the key value : ";
            cin>>keyvalue;
            cout<<"Enter the data value : ";
            cin>>datavalue;
            n1->key=keyvalue;
            n1->data=datavalue;
            d1.append(n1);
            break;
        case 2:
            int keysearch;
            cout<<"Enter the key value to found : ";
            cin>>keysearch;
             if(d1.Linkexist(keysearch)==NULL){
                cout<<"Entered key value not found";
             }
             else{
                cout<<"value found";
             }
            break;
        case 3:
             d1.display();
             break;
        case 4:
            int prekey,predata;
            cout<<"Enter the key value : ";
            cin>>prekey;
            cout<<"Enter the data value : ";
            cin>>predata;
            n1->key=prekey;
            n1->data=predata;
            d1.prepend(n1);
            break;
        case 5:
            int keybefore,keyafter,dataafter;
               cout<<"Enter the key value after to inset value : ";
               cin>>keybefore;
               if(d1.Linkexist(keybefore)!=NULL){
                   cout<<"Enter the key value : ";
                   cin>>keyafter;
                   cout<<"Enter the data value : ";
                   cin>>dataafter;
                      n1->key=keyafter;
                      n1->data=dataafter;
                      d1.inbetween(keybefore,n1);
               }else{
                cout<<keybefore<<" key value Doesnt exist ";
               }
            break;
        case 6:
            int key;
            cout<<"Enter the key value to be change the data : ";
            cin>>key;
            d1.update(key);
            break;
        case 7:
            int keydelete;
            cout<<"Enter the key vlaue to be deleted : ";
            cin>>keydelete;
            d1.deletevalue(keydelete);
        default:
            break;
        }
    }while(option!=0);
}