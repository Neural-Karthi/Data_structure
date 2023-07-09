#include<iostream>
using namespace std;
#define MAX 1000
class stack{
    private:
       int top=-1,temp=-1;
       int arr[MAX];
    public:
       void initializer(int totalvalu){
          for(int i=0;i<totalvalu;i++){
            arr[i]=0;
            temp++;
          }
       }
       //ISFULL
       bool isfull(){
          if(top==temp)
            return true;
          else
            return false;
       }
       bool isempty(){
          if(top==-1)
            return true;
          else
            return false;
       }
       //PUSH OPERATION 
       void push(int vlaue){
        if(top==temp)
           cout<<"Stack is full"<<endl;
        else{
          top++;
          arr[top]=vlaue;
          cout<<"Value has been Pushed into stack"<<endl;
        }
       }
       //POP OPERATION
       int pop(){
           if(top!=-1){
              int var=arr[top];
              arr[top]=0;
              top--;
              return var;
           }
       }
       //PEEK OPERATION
       int peek(){
        if(top==-1)
            cout<<"Stack is empty"<<endl;
        else
           return arr[top];
       }
       //COUNT OPREATION
       int count(){
         if(top==-1)
            return 0;
         else
           return top+1;
       }
       //CHANGE OPERATION
       void position(){
        if(top==-1)
            cout<<"Stack is empty"<<endl;
        else{
          cout<<"position : ";
          for(int i=top;i>=0;i--){
            cout<<i<<" ";
          }
          cout<<endl<<"Value :";
          for(int i=top;i>=0;i--){
            cout<<arr[i]<<" ";
          }
        }
       }
       void change(int pos,int val){
           arr[pos]=val;
           cout<<endl<<val<<" has been modified at the position : " <<pos;
       }
       //DISPLAY OPERATION
       void display(int totalvalu){
          for(int i=totalvalu;i>=0;i--){
            cout<<arr[i]<<endl;
          }
       }

};
int main(){
    int option_num,temp;
    stack s1;
    cout<<'\t'<<" Wellcome to Data Structure Algorithm - Stack Operation "<<endl;
    cout<<"Enter the total list value : ";
    cin>>temp;
    s1.initializer(temp);
    do{
        cout<<endl;
        cout<<"Select the operation to perform else Enter 0 to exit"<<endl;
        cout<<"1.PUSH()"<<endl;
        cout<<"2.POP()"<<endl;
        cout<<"3.ISEmpty()"<<endl;
        cout<<"4.ISFull()"<<endl;
        cout<<"5.PEEK()"<<endl;
        cout<<"6.COUNT()"<<endl;
        cout<<"7.CHANGE()"<<endl;
        cout<<"8.DISPLAY()"<<endl;
        cout<<"9.Clear screen()"<<endl;
        cout<<"Enter the input : ";
        cin>>option_num;
        switch (option_num)
        {
            
            case 1:  
                int value;
                cout<<"Enter the value : ";
                cin>>value;
                s1.push(value);
                break;
            case 2:
                if(s1.isempty())
                   cout<<"Stack is Underflow"<<endl;
                else
                   cout<<"Last value has been POPED and value is : "<<s1.pop()<<endl;
                break;
            case 3:
                if(s1.isempty())
                   cout<<"Stack is empty"<<endl;
                else
                   cout<<"stack is not empty"<<endl;
                break;
            case 4:
                if(s1.isfull())
                   cout<<"Stack is full"<<endl;
                else
                   cout<<"stack is not full"<<endl;
                break;
            case 5:
                cout<<"Last value is : "<<s1.peek()<<endl;
                break;
            case 6:
                cout<<"Total array count : "<<s1.count()<<endl;
                break;
            case 7:
                int pos,val;
                char a;
                cout<<"Do you want to see the index and value [Y/N] : ";
                cin>>a;
                if(a=='y'){
                     s1.position();
                     cout<<endl<<"Enter the index number : ";
                     cin>>pos;
                     cout<<"Enter the value : ";
                     cin>>val;
                     s1.change(pos,val);
                }else{
                     cout<<"Enter the index number : ";
                     cin>>pos;
                     cout<<"Enter the value : ";
                     cin>>val;
                     s1.change(pos,val);
                }
                break;
            case 8:
                s1.display(temp);
                break;
            case 9:
                system("cls");
                break;
        }

    }while(option_num!=0);
}