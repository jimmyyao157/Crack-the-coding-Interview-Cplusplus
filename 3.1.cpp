#include <iostream>

using namespace std ;

class stack_3{

public:
       stack_3(int size = 100){
                   buf = new int[3*size];
                   memset(buf,0,sizeof(buf));
                   this->size = size;
       }
       
       ~stack_3(){
                  delete[] buf;
       }
       
       int pop(int stackNum){
           if(buf[size*stackNum]==0){
                   cout << "The stack is empty!!" << endl;
                   return 0;
           }
           int cursor = size*stackNum + buf[size*stackNum];
           int val = buf[cursor];
           buf[size*stackNum]--;
           return val;
       }
       
       void push(int stackNum,int val){
           if(buf[size*stackNum]==size){
                cout << "the Stack is full!!" << endl;
                return;
           }
           buf[size*stackNum]++;
           int cursor = size*stackNum + buf[size*stackNum];
           buf[cursor] = val;
           return;
       }
         
       
       void printStack(){
            for(int s = 0 ; s < 3 ; s++){
                    cout << "Stack" << s+1 << ":" << endl ;
                    if(buf[s*size] == 0){
                      cout << "Stack" << s+1 <<" is empty " << endl ;
                    }
                    else{
                         cout << "the size of the stack = " << buf[s*size] << endl;
                         for(int i = 1 ; i < buf[s*size]+1 ; i++){                    
                                 cout << buf[s*size+i] << endl;
                         }
                    }
                    cout << endl ;
            }
       }
       
private:
        int *buf;
        int size ;
};

int main(){
    stack_3 test;
    test.push(0,1990);
    test.push(0,199);
    cout << test.pop(0) << endl ;
    
    test.push(1,1990);
    test.push(1,10);
    test.printStack();
    system("pause");
    return 0 ;
}
