#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q;  
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;

    q.pop();
    cout << "After popping one element, Front: " << q.front() << endl;

    // Check if the queue is empty

    
    if (q.empty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }

    cout << "Queue size: " << q.size() << endl;

    return 0;
}
v