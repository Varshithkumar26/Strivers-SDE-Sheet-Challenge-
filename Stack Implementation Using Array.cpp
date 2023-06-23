#include <bits/stdc++.h> 
// Stack class.
class Stack {
    
public:
    vector<int> arr;
    int size;
    int cnt;
    Stack(int capacity) {
        // Write your code here.
        cnt=-1;
        size=capacity;
        arr.resize(capacity);
    }

    void push(int num) {
        // Write your code here.
        cnt++;
        arr[cnt]=num;
    }

    int pop() {
        // Write your code here.
        if(cnt==-1)
          return -1;
        
        int a=arr[cnt];
        cnt--;
        return a;
    }
    
    int top() {
        // Write your code here.
        if(cnt==-1)
          return -1;

        return arr[cnt];
    }
    
    int isEmpty() {
        // Write your code here.
        return cnt==-1;
    }
    
    int isFull() {
        // Write your code here.
        return cnt+1==size;
    }
    
};
