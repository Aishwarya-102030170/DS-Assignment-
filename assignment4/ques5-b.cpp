#include <iostream>
using namespace std;

class queue {
    int frontIdx;
    int rearIdx;
    int arr[100];
    int count;

public:
    queue() {
        frontIdx = 0;
        rearIdx = -1;
        count = 0;
    }

    void enqueue(int x) {
        if (rearIdx >= 99) {
            cout << "queue overflow" << endl;
            return;
        }
        rearIdx++;
        arr[rearIdx] = x;
        count++;
    }

    int dequeue() {
        if (isempty()) {
            cout << "empty queue" << endl;
            return -1;
        }
        int x = arr[frontIdx];
        frontIdx++;
        count--;
        if (count == 0) {
            frontIdx = 0;
            rearIdx = -1;
        }
        return x;
    }

    int size() const {
        return count;
    }

    bool isempty() const {
        return (count == 0);
    }

    int front() const {
        if (isempty()) {
            cout << "empty queue front() call" << endl;
            return -1;
        }
        return arr[frontIdx];
    }
};

class stackUsingQueue {
    queue q;

public:
    void push(int x) {
        q.enqueue(x);
        int s = q.size();
        for (int i = 0; i < s - 1; i++) {
            int y = q.dequeue();
            q.enqueue(y);
        }
    }

    int pop() {
        if (q.isempty()) {
            cout << "Stack empty on pop()" << endl;
            return -1;
        }
        return q.dequeue();
    }

    int top() {
        if (q.isempty()) {
            cout << "Stack empty on top()" << endl;
            return -1;
        }
        return q.front();
    }

    bool empty() const {
        return q.isempty();
    }
};

int main(){
    stackUsingQueue st;

    st.push(10);
    cout << "Top is: " << st.top() << endl;
    st.push(20);
    cout << "Top is: " << st.top() << endl;
    st.push(30);
    cout << "Top is: " << st.top() << endl;

    cout << "Pop: " << st.pop() << endl;
    cout << "Top is now: " << st.top() << endl;

    st.pop();
    cout << "Pop: " << st.pop() << endl;

    cout << "Empty? " << (st.empty() ? "Yes" : "No") << endl;
    cout << "Pop on empty: " << st.pop() << endl;

    return 0;
}
