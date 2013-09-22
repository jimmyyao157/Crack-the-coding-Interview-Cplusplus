#include<iostream>

using namespace std ;

class stack{
private:
    int* buf;
    int topIdx;
public:
    stack(int size = 100){
       buf = new int[size];
       topIdx = -1 ;              
    }    
    ~stack(){
       delete[] buf;
    }
    
    bool isEmpty(){
         return (topIdx == -1) ;
    }
    void pop(){
         if(isEmpty()){
                       cout << "Stack is Empty!!" << endl;
                       return;
         }
         topIdx--;
    }
    void push(int val){
         buf[++topIdx] = val;       
    }
    int top(){
        return buf[topIdx];
    }
    
    void printStack(){
         cout << "Printing===============" << endl;
         for(int i = 0 ; i < topIdx+1 ; i++)
                 cout << buf[i] << endl;
    }
};

class stack_min{
private:
        stack s_data,s_min;
public:
       void push(int val){
            s_data.push(val);
            if(s_min.isEmpty()||s_min.top()>val)
                 s_min.push(val);
       }
       void pop(){
            if(s_data.top()==s_min.top()) s_min.pop();
            s_data.pop();
       }
       int min(){
           return s_min.top();
       }
};

int main(){
    stack_min s;
    for(int i = 0 ; i < 5; i++){
            int tmp;
            cin >> tmp;
            s.push(tmp);
    }
    cout << s.min() << endl;

    system("pause");
    return 0 ;
}
