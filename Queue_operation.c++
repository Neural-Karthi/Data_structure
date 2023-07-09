#include<iostream>
using namespace std;
#define Max 1000
class queue{
    private:
      int arr[Max],total=0;
      int rear=-1,front=-1;
    public:
      queue(){
        cout<<"hi";
      }
      void initlizater(int totalvalue){
        total=totalvalue;
        for(int i=0;i<totalvalue;i++){
            arr[i]=0;
        }
      }
      int isfull(){
        if(rear==total-1)
           return true;
        else
           return false;
      }
      int isempty(){
        if(rear==-1&&front==-1)
           return true;
        else
           return false;
      }
      void enqueue(int value){
        if(isfull())
           cout<<"Queue is full - unable to Enqueue the value"<<endl;
        else{
           rear++;
           arr[rear]=value;
           cout<<"your value has been enqueued"<<endl;
        }
      }
      int dequeue(){
        int x=0;
        if(isempty()){
            cout<<"queue is full - unable to Enqueue the value"<<endl;
        }
        else if(front==rear){
            rear=front=-1;
        }
        else{
          front++;
          arr[front]=0;
          cout<<"rear : "<<rear<<"front : "<<front<<endl;
          cout<<"your value has been enqueued"<<endl;
        }
      }
      void display(){
        for(int i=0;i<total;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
      }
      int count(){
        return (rear-front)-1;
      }
};
int main(){
    queue q1;
    int option_num,totallist;
    cout<<'\t'<<" Welcome the Queue Operation "<<endl;
    cout<<"Enter the total arrays needed : ";
    cin>>totallist;
    q1.initlizater(totallist);
    do{
        cout<<"Select anyone of the option from the given list else 0 to exit : "<<endl;
        cout<<"1.Enqueue()"<<endl;
        cout<<"2.Dequeue()"<<endl;
        cout<<"3.Isfull()"<<endl;
        cout<<"4.IsEmpty()"<<endl;
        cout<<"5.Clear screen"<<endl;
        cout<<"6.Display()"<<endl;
        cout<<"7.count()"<<endl;
        cout<<"Enter the selected option : ";
        cin>>option_num;
        switch (option_num)
        {
        case 1:
            if(q1.isfull()){
                cout<<"Queue is Full"<<endl;
            }
            else{
                int value;
                cout<<"Enter the value to enqueue : ";
                cin>>value;
                q1.enqueue(value);
            }
            break;
        case 2:
            q1.dequeue();
            break;
        case 3:
            if(q1.isfull()){
                cout<<"Queue is Full"<<endl;
            }
            else{
                cout<<"Queue is Not full"<<endl;
            }
            break;
        case 4:
            if(q1.isempty()){
                cout<<"Queue is Empty"<<endl;
            }
            else{
                cout<<"Queue is Not Empty"<<endl;
            }
            break;
        case 5:
            system("cls");
            break;
        case 6:
            q1.display();
        case 7:
            cout<<"Total element in queue : "<<q1.count()+1<<endl;
        default:
            break;
        }
    }while(option_num!=0);
}