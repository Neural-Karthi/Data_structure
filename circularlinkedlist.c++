#include<iostream>
using namespace std;
class Node{
    public:
      int key;
      int data;
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
class circularlist{
   public:
     Node* head;
    circularlist(){
        head=NULL;
    }
    circularlist(Node* n){
        head=n;
    }
//search
   Node* linkExist(int k){
       Node* ptr=head;
       Node* temp=NULL;
       do{
          if(ptr->key==k){
            temp=ptr;
          }
          ptr=ptr->next;
       }while(ptr!=head);
    
    return temp;
   }
//Append
    void append(Node* n){
            if(head==NULL){
               head=n;
               head->next=head;
               cout<<"value appened";
            }     
            else{
               Node* ptr=head;
               while(ptr->next!=head){
                   ptr=ptr->next;
               }
               n->next=head;
               ptr->next=n;
               cout<<"value appened";
            }
    }
//prepend 
    void prepend(Node* n){
        Node* ptr=head;
        while(head!=ptr->next){
            ptr=ptr->next;
        }
        ptr->next=n;
        n->next=head;
        head=n;
    }
//Inset at Middle
   void inbetween(int key,Node* n){
       Node* ptr=linkExist(key);
       if(ptr==NULL){
        cout<<"key value doesnt Exist";
       }
       else{
        if(linkExist(n->key)==NULL){
            n->next=ptr->next;
            ptr->next=n;
        }
        else{
            cout<<"Key value after Exist";
        }
       }
   }
//Delete
   void deletevalue(int keyvalue){
       Node* ptr=linkExist(keyvalue);
       if(ptr!=NULL){
          if(ptr==head){
             if(head->next=NULL){
                head=NULL;
                cout<<"Node is Unlinked";
             }
             else{
                Node* ptr=head;
                while(ptr->next!=head){
                    ptr=ptr->next;
                }
                ptr->next=head->next;
                head=head->next;
                cout<<"Unlinked";
             }
          }
          else{
             Node* temp=NULL;
             Node* pervious=head;
             Node* current=head->next;
             while(current!=NULL){
                if(current->key==keyvalue){
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
                cout<<keyvalue<<"Node unlinked";
             }
             else{
                cout<<keyvalue<<" not found";
             }
          }
       }
       else{
          cout<<"Enter key value doesnt exist";
       }
   }
//display
    void display(){
           Node* ptr=head;
           do{
                cout<<"("<<ptr->key<<","<<ptr->data<<","<<ptr->next<<")"<<"-->";
                ptr=ptr->next;
            } while(ptr!=head);
    }
};
int main(){
       circularlist c1;
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
            c1.append(n1);
            break;
        case 2:
            int keysearch;
            cout<<"Enter the key value : ";
            cin>>keysearch;
            if(c1.linkExist(keysearch)!=NULL){
                cout<<"key value already Exist";
            }
            else{
                cout<<"Key value doesnt Exist";
            }
            break;
        case 3:
            c1.display();
            break;
        case 4:
            int prekey,predata;
            cout<<"Enter the key value : ";
            cin>>prekey;
            cout<<"Enter the data value : ";
            cin>>predata;
            n1->key=prekey;
            n1->data=predata;
            c1.prepend(n1); 
            break;
        case 5:
            int keyv,keyin,datain;
            cout<<"Enter the key value after inset : ";
            cin>>keyv;
            cout<<"Enter the key value of new data : ";
            cin>>keyin;
            cout<<"Enter the data value  : ";
            cin>>datain;
            n1->key=keyin;
            n1->data=datain;
            c1.inbetween(keyv,n1);
            break;
        case 7:
            int keytodelete;
            cout<<"Enter the key value to delete : ";
            cin>>keytodelete;
            c1.deletevalue(keytodelete);
        default:
            break;
        }
       }while(option!=0);
}