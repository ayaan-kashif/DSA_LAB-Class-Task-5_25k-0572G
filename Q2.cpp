#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
    struct Node
    {
        string word;
        Node *next;
    };

    Node *topNode;

public:
    Stack() : topNode(nullptr)
    {
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

    void push(string word)
    {
        topNode = new Node{word, topNode};
    }

    void pop()
    {
        if (empty())
        {
            throw "Stack is empty";
        }

        Node *oldTop = topNode;
        topNode = topNode->next;
        delete oldTop;
    }

    string top() const
    {
        if (empty())
        {
            throw "Stack is empty";
        }
        return topNode->word;
    }
};

class TextEditor
{
private:
    Stack undoStack;
    Stack redoStack;
    string text;

public:
    void type(string word)
    {
        if (!undoStack.empty())
        {
            text += " ";
        }
        text += word;
        undoStack.push(word);

        while (!redoStack.empty())
        {
            redoStack.pop();
        }
    }

    void undo()
    {
        if (undoStack.empty())
        {
            return;
        }

        string word = undoStack.top();
        undoStack.pop();
        redoStack.push(word);
        text.erase(text.size() - word.size());

        if (!undoStack.empty())
        {
            text.pop_back();
        }
    }

    void redo()
    {
        if (redoStack.empty())
        {
            return;
        }

        string word = redoStack.top();
        redoStack.pop();

        if (!undoStack.empty())
        {
            text += " ";
        }
        text += word;
        undoStack.push(word);
    }

    void print() const
    {
        cout << "Current text: \"" << text << "\"" << endl;
    }
};

int main()
{
    TextEditor editor;

    cout << "After type(\"Hello\"):" << endl;
    editor.type("Hello");
    editor.print();

    cout << "After type(\"World\"):" << endl;
    editor.type("World");
    editor.print();

    cout << "After undo():" << endl;
    editor.undo();
    editor.print();

    cout << "After redo():" << endl;
    editor.redo();
    editor.print();

    cout << "After undo():" << endl;
    editor.undo();
    editor.print();

    cout << "After type(\"There\"):" << endl;
    editor.type("There");
    editor.print();

    cout << "After redo():" << endl;
    editor.redo();
    editor.print();

    return 0;
}
