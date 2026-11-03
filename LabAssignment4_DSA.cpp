#include <iostream>
#include <queue>
using namespace std;

class QueueDS {
public:
    int arr[5];
    int front, rear;

    // QUESTION 1
    QueueDS() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == 4;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue overflow";
            return;
        }

        if (isEmpty())
            front = 0;

        arr[++rear] = val;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow";
            return -1;
        }

        int val = arr[front];

        if (front == rear)
            front = rear = -1;
        else
            front++;

        return val;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty";
            return -1;
        }

        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty";
            return;
        }

        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
    }


    // QUESTION 2
    bool isCircularEmpty() {
        return front == -1;
    }

    bool isCircularFull() {
        return (rear + 1) % 5 == front;
    }

    void circularEnqueue(int val) {
        if (isCircularFull()) {
            cout << "Queue overflow";
            return;
        }

        if (isCircularEmpty())
            front = 0;

        rear = (rear + 1) % 5;
        arr[rear] = val;
    }

    int circularDequeue() {
        if (isCircularEmpty()) {
            cout << "Queue underflow";
            return -1;
        }

        int val = arr[front];

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % 5;

        return val;
    }

    int circularPeek() {
        if (isCircularEmpty()) {
            cout << "Queue is empty";
            return -1;
        }

        return arr[front];
    }

    void circularDisplay() {
        if (isCircularEmpty()) {
            cout << "Queue is empty";
            return;
        }

        int i = front;

        while (true) {
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % 5;
        }
    }


    // QUESTION 3
    void interleave(queue<int> q) {
        queue<int> first;
        int n = q.size();

        if (n % 2 != 0) {
            cout << "Queue must have even elements";
            return;
        }

        for (int i = 0; i < n / 2; i++) {
            first.push(q.front());
            q.pop();
        }

        while (!first.empty()) {
            q.push(first.front());
            first.pop();

            q.push(q.front());
            q.pop();
        }

        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
    }


    // QUESTION 4
    void firstNonRepeating(string s) {
        int freq[256] = {0};
        queue<char> q;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            freq[(unsigned char)ch]++;
            q.push(ch);

            while (!q.empty() &&
                   freq[(unsigned char)q.front()] > 1) {
                q.pop();
            }

            if (q.empty())
                cout << -1 << " ";
            else
                cout << q.front() << " ";
        }
    }


    // QUESTION 5(a)
    queue<int> q1, q2;

    void pushTwoQueues(int val) {
        q2.push(val);

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }

    int popTwoQueues() {
        if (q1.empty()) {
            cout << "Stack underflow";
            return -1;
        }

        int val = q1.front();
        q1.pop();

        return val;
    }

    int peekTwoQueues() {
        if (q1.empty()) {
            cout << "Stack is empty";
            return -1;
        }

        return q1.front();
    }


    // QUESTION 5(b)
    queue<int> q;

    void pushOneQueue(int val) {
        int n = q.size();
        q.push(val);

        for (int i = 0; i < n; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int popOneQueue() {
        if (q.empty()) {
            cout << "Stack underflow";
            return -1;
        }

        int val = q.front();
        q.pop();

        return val;
    }

    int peekOneQueue() {
        if (q.empty()) {
            cout << "Stack is empty";
            return -1;
        }

        return q.front();
    }
};

int main() {
    QueueDS s;

    // QUESTION 1
    s.enqueue(10);
    s.enqueue(20);
    s.enqueue(30);
    s.display();

    cout << "\nDeleted: " << s.dequeue();
    cout << "\nFront: " << s.peek();


    // QUESTION 2
    QueueDS c;

    c.circularEnqueue(10);
    c.circularEnqueue(20);
    c.circularEnqueue(30);
    c.circularDisplay();


    // QUESTION 3
    queue<int> q;

    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);

    cout << "\nInterleaved: ";
    s.interleave(q);


    // QUESTION 4
    cout << "\nFirst non-repeating: ";
    s.firstNonRepeating("aabc");


    // QUESTION 5(a)
    s.pushTwoQueues(10);
    s.pushTwoQueues(20);
    s.pushTwoQueues(30);

    cout << "\nTwo queues top: " << s.peekTwoQueues();
    cout << "\nTwo queues pop: " << s.popTwoQueues();


    // QUESTION 5(b)
    s.pushOneQueue(10);
    s.pushOneQueue(20);
    s.pushOneQueue(30);

    cout << "\nOne queue top: " << s.peekOneQueue();
    cout << "\nOne queue pop: " << s.popOneQueue();

    return 0;
}