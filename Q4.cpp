#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int passengers[6];
    int front;
    int rear;
    int count;

public:
    CircularQueue()
    {
        front = 0;
        rear = -1;
        count = 0;
    }

    void enqueue(int id)
    {
        if (count == 6)
        {
            cout << "Gate is full. Passenger " << id << " cannot enter.\n";
            return;
        }

        rear = (rear + 1) % 6;
        passengers[rear] = id;
        count++;
    }

    void dequeue()
    {
        if (count == 0)
        {
            cout << "No passengers waiting.\n";
            return;
        }

        cout << "Boarded passenger: " << passengers[front] << '\n';
        front = (front + 1) % 6;
        count--;
    }

    void display() const
    {
        cout << "Passengers in boarding order:";
        if (count == 0)
        {
            cout << " empty\n";
            return;
        }

        for (int i = 0; i < count; i++)
        {
            cout << ' ' << passengers[(front + i) % 6];
        }
        cout << "\nFront position (0-based): " << front;
        cout << "\nRear position (0-based): " << rear << '\n';
    }
};

int main()
{
    CircularQueue gate;

    for (int id = 101; id <= 106; id++)
    {
        gate.enqueue(id);
    }

    for (int i = 0; i < 3; i++)
    {
        gate.dequeue();
    }

    gate.enqueue(107);
    gate.enqueue(108);
    gate.enqueue(109);

    gate.dequeue();
    gate.dequeue();
    gate.enqueue(110);

    gate.dequeue();
    gate.enqueue(111);
    gate.enqueue(112);

    cout << '\n';
    gate.display();

    return 0;
}
