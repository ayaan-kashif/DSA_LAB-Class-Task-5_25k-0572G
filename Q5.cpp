#include <iostream>
using namespace std;

class Stack
{
private:
    struct Node
    {
        int value;
        Node *next;
    };

    Node *topNode;

public:
    Stack()
    {
        topNode = nullptr;
    }

    Stack(const Stack &) = delete;
    Stack &operator=(const Stack &) = delete;

    ~Stack()
    {
        while (!empty())
        {
            pop();
        }
    }

    bool empty() const
    {
        return topNode == nullptr;
    }

    void push(int value)
    {
        Node *node = new Node;
        node->value = value;
        node->next = topNode;
        topNode = node;
    }

    int pop()
    {
        if (empty())
        {
            throw "Stack is empty";
        }

        Node *node = topNode;
        int value = node->value;
        topNode = node->next;
        delete node;
        return value;
    }
};

class MyQueue
{
private:
    Stack incoming;
    Stack outgoing;

public:
    void enqueue(int value)
    {
        incoming.push(value);
    }

    int dequeue()
    {
        if (outgoing.empty())
        {
            while (!incoming.empty())
            {
                outgoing.push(incoming.pop());
            }
        }

        if (outgoing.empty())
        {
            throw "Queue is empty";
        }

        return outgoing.pop();
    }
};

int main()
{
    MyQueue queue;

    queue.enqueue('A');
    queue.enqueue('B');
    cout << static_cast<char>(queue.dequeue()) << ' ';

    queue.enqueue('C');
    cout << static_cast<char>(queue.dequeue()) << ' ';
    cout << static_cast<char>(queue.dequeue()) << '\n';

    return 0;
}
