#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;


int main()
{
    //vector is a dynamic array that can resize itself automatically when elements are added or removed. It provides random access to elements and is part of the C++ Standard Library.
    vector<int> v = {1, 2, 3, 4, 5};
    v.push_back(7);
    v.pop_back();
    cout<< v.size()<<endl;
    cout<< v.front()<<endl;
    cout<< v.back()<<endl;
    cout<< v.empty()<<endl;
    for(int value : v)
    {
        cout<<value<<" ";
    }
    cout << endl;
    v.clear();
//stack is a data structure that follows the Last In First Out (LIFO) principle. It allows elements to be added and removed from the top of the stack.
    stack<int> s;
    cout<<"Stack"<<endl<<endl;
    s.push(10);
    s.push(29);
    s.push(30);
    cout<< s.top()<<endl;
    s.pop();
    cout<< s.top()<<endl;
    cout<< s.empty()<<endl;
//FIFO
    //queue is a data structure that follows the First In First Out (FIFO) principle. It allows elements to be added at the back and removed from the front.
    queue <int> q;
    cout<<"Queue"<<endl<<endl;

    q.push(10);
    q.push(20);
    q.push(30);
    cout<< q.front()<<endl;
    q.pop();
    cout<< q.front()<<endl;
    cout<< q.empty()<<endl;

}