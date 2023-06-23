#include <bits/stdc++.h> 
class Queue {
public:
vector<int> arr;
int cnt;
int f;
int rear;
    Queue() {
        // Implement the Constructor
        cnt=0;
        f=0;
        rear=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return cnt==0;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        cnt++;
        arr.push_back(data);
        rear++;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(cnt==0)
          return -1;
        
        int a=arr[f];
        f++;
        cnt--;
        return a;
        
    }

    int front() {
        // Implement the front() function
        if(cnt==0)
          return -1;
        return arr[f];
    }
};
