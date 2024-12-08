#include<iostream>
#include<climits> 
using namespace std;

template<class type>
class Stack
{
private:
    int top;
    type array[100];
public:
    Stack() {
        top = -1;
    }
    ~Stack() {}

    bool isEmpty() {
        if (top < 0) {
            return true;
        }
        else return false;
    }

    bool isFull() {
        if (top >= 99) {
            return true;
        }
        else return false;
    }

    void Push(type item) {
        if (!isFull()) {
            top++;
            array[top] = item;
        }
    }

    int pop() {
        if (!isEmpty()) {
            int item = array[top];
            top--;
            return item;
        }
    }

    int topElement() {
        if (!isEmpty()) {
            return array[top];
        }
    }
};

int main() {
    int array[4] = { 4, 5, 2, 25 };
    int result[4];
    Stack<int> stack;

    for (int i = 3; i >= 0; i--) 
    {
        while (!stack.isEmpty() && stack.topElement() <= array[i]) 
        {
            stack.pop();
        }

        if (stack.isEmpty()) {
            result[i] = -1;
        }
        else {
            result[i] = stack.topElement();
        }
        stack.Push(array[i]);
    }

    for (int i = 0; i < 4; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}