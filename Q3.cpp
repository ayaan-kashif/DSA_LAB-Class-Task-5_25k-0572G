#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string data;
    Node *next;
};

class Queue
{
private:
    Node *first;
    Node *last;
    int count;

public:
    Queue()
    {
        first = nullptr;
        last = nullptr;
        count = 0;
    }

    Queue(const Queue &) = delete;
    Queue &operator=(const Queue &) = delete;

    ~Queue()
    {
        while (!empty())
        {
            pop();
        }
    }

    bool empty() const
    {
        return first == nullptr;
    }

    int size() const
    {
        return count;
    }

    void push(string value)
    {
        Node *node = new Node{value, nullptr};
        if (empty())
        {
            first = node;
        }
        else
        {
            last->next = node;
        }
        last = node;
        count++;
    }

    void pop()
    {
        if (empty())
        {
            throw "Queue is empty";
        }
        Node *node = first;
        first = first->next;
        delete node;
        count--;
        if (empty())
        {
            last = nullptr;
        }
    }

    string front() const
    {
        if (empty())
        {
            throw "Queue is empty";
        }
        return first->data;
    }
};

class Stack
{
private:
    Node *head;

public:
    Stack()
    {
        head = nullptr;
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
        return head == nullptr;
    }

    void push(string value)
    {
        head = new Node{value, head};
    }

    void pop()
    {
        if (empty())
        {
            throw "Stack is empty";
        }
        Node *node = head;
        head = head->next;
        delete node;
    }

    string top() const
    {
        if (empty())
        {
            throw "Stack is empty";
        }
        return head->data;
    }
};

void reverseFirstK(Queue &q, int k)
{
    int size = q.size();

    if (k < 0 || k > size)
    {
        cout << "Invalid k: it must be between 0 and " << size << "." << endl;
        return;
    }
    if (k <= 1)
    {
        return;
    }

    Stack jobs;
    for (int i = 0; i < k; i++)
    {
        jobs.push(q.front());
        q.pop();
    }

    while (!jobs.empty())
    {
        q.push(jobs.top());
        jobs.pop();
    }

    for (int i = 0; i < size - k; i++)
    {
        q.push(q.front());
        q.pop();
    }
}

void printQueue(Queue &q)
{
    int size = q.size();

    for (int i = 0; i < size; i++)
    {
        cout << q.front();
        if (i < size - 1)
        {
            cout << " ";
        }
        q.push(q.front());
        q.pop();
    }
    cout << endl;
}

int main()
{
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
