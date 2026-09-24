#include <iostream>
#include <stack>
#include <stdexcept>
using namespace std;

class MyQueue {
private:
    stack<int> incoming;
    stack<int> outgoing;

public:
    void enqueue(int value) {
        incoming.push(value);
    }

    int dequeue() {
        if (outgoing.empty()) {
            while (!incoming.empty()) {
                outgoing.push(incoming.top());
                incoming.pop();
            }
        }

        if (outgoing.empty()) {
            throw underflow_error("Queue is empty");
        }

        int value = outgoing.top();
        outgoing.pop();
        return value;
    }
};

int main() {
    MyQueue queue;

    queue.enqueue('A');
    queue.enqueue('B');
    cout << static_cast<char>(queue.dequeue()) << ' ';

    queue.enqueue('C');
    cout << static_cast<char>(queue.dequeue()) << ' ';
    cout << static_cast<char>(queue.dequeue()) << '\n';

    return 0;
}
