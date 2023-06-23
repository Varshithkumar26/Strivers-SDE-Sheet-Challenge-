#include <bits/stdc++.h> 
class Stack {
	// Define the data members.

queue<int> q;

   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return q.size()==0;
    }

    void push(int element) {
        // Implement the push() function.
        q.push(element);
        int size=q.size()-1;
        while(size)
        {
            int a=q.front();
            q.pop();
            q.push(a);
            size--;
        }
        
        
    }

    int pop() {
        // Implement the pop() function.
        if(q.size()==0)
          return -1;
        int a=q.front();
        q.pop();
        return a;
    }

    int top() {
        // Implement the top() function.
        if(q.size()==0)
          return -1;
        return q.front();
    }
};
