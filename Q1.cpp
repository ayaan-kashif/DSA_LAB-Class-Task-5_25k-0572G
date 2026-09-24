#include <iostream>
using namespace std;

class EditStack {
private:
    int operations[8];
    int top;

public:
    EditStack() {
        top = -1;
    }

    void printTop() const {
        if (top == -1) {
            cout << "Current top: empty\n";
        } else {
            cout << "Current top: " << operations[top] << '\n';
        }
    }

    void push(int operation) {
        if (top == 7) {
            cout << "Stack is full. Cannot add " << operation << ".\n";
        } else {
            operations[++top] = operation;
            cout << "New operation: " << operation << '\n';
        }
        printTop();
    }

    void undo() {
        if (top == -1) {
            cout << "Nothing to undo.\n";
        } else {
            cout << "Undo operation: " << operations[top--] << '\n';
        }
        printTop();
    }

    void display() const {
        cout << "Remaining operations (top to bottom):";
        if (top == -1) {
            cout << " empty";
        }
        for (int i = top; i >= 0; i--) {
            cout << ' ' << operations[i];
        }
        cout << '\n';
    }
};

int main() {
    EditStack editor;
    int operations[] = {12, 25, 17, 31, 44, 19};

    for (int i = 0; i < 6; i++) {
        editor.push(operations[i]);
    }

    for (int i = 0; i < 3; i++) {
        editor.undo();
    }

    editor.push(52);
    editor.undo();
    editor.undo();
    editor.display();

    cout << "\nTesting Undo on an empty stack:\n";
    EditStack emptyEditor;
    emptyEditor.undo();

    return 0;
}
