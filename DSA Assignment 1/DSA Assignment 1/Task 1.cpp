//#include<iostream>
//using namespace std;
//template<class type>
//class Stack
//{
//private:
//    int top;
//    type* array;
//    int minterm, size;
//public:
//    Stack() 
//    { 
//        top = -1;
//        minterm = INT_MAX;
//        size = 0;
//    }
//    ~Stack() {};
//    bool isEmpty() {
//        if (top < 0) {
//            // cout << "Stack is Empty Nothing to POP" << endl;
//            return true;
//        }
//        else return false;
//    }
//    bool isFull() {
//        if (top >= 99) {
//            cout << "Stack is FUll can't Push" << endl;
//            return true;
//        }
//        else return false;
//    }
//    void Push(type item) {
//        
//        if (isFull() == false) {
//            if (item < minterm)
//            {
//                minterm = item;
//            }
//            top++;
//            array[top] = item;
//            
//            size++;
//        }
//    }
//    char pop() {
//        if (isEmpty() == false) {
//            char character = array[top];
//            top--;
//            return character;
//
//        }
//    }
//    void set_maxstack(int max)
//    {
//        array = new type [max];
//    }
//    int get_minterm()
//    {
//        return minterm;
//    }
//    int get_size()
//    {
//        return size;
//    }
//};
//int main()
//{
//    int  num, exp;
//    Stack<int>stack;
//    cout << "Enter number of values in stack = ";
//    cin >> num;
//    stack.set_maxstack(num);
//    cout << "Enter values = ";
//    for (int i = 0; i < num; i++)
//    {
//        cin >> exp;
//        stack.Push(exp);
//    }
//    cout << "Minterm = " << stack.get_minterm() << endl;
//    cout << "Size = " << stack.get_size() << endl;
//    return 0;
//}