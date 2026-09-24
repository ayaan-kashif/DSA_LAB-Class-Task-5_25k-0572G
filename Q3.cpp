#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

typedef queue<string> Queue;

void reverseFirstK(Queue &q, int k) {
    int size = static_cast<int>(q.size());

    if (k < 0 || k > size) {
        cout << "Invalid k: it must be between 0 and " << size << "." << endl;
        return;
    }
    if (k <= 1) {
        return;
    }

    stack<string> jobs;
    for (int i = 0; i < k; i++) {
        jobs.push(q.front());
        q.pop();
    }

    while (!jobs.empty()) {
        q.push(jobs.top());
        jobs.pop();
    }

    for (int i = 0; i < size - k; i++) {
        q.push(q.front());
        q.pop();
    }
}

void printQueue(Queue &q) {
    int size = static_cast<int>(q.size());

    for (int i = 0; i < size; i++) {
        cout << q.front();
        if (i < size - 1) {
            cout << " ";
        }
        q.push(q.front());
        q.pop();
    }
    cout << endl;
}

int main() {
    Queue q;
    q.push("J1");
    q.push("J2");
    q.push("J3");
    q.push("J4");
    q.push("J5");
    q.push("J6");
    q.push("J7");

    int k = 3;
    cout << "Original queue: ";
    printQueue(q);

    reverseFirstK(q, k);

    cout << "After reversing the first " << k << " jobs: ";
    printQueue(q);

    return 0;
}
