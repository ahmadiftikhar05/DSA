#include<iostream>
using namespace std;
int arraysize;
template<class Type>

class Queue {
private:
	int front, rear, count;
	Type* Array;
public:
	Queue() {
		front = -1; rear = -1; count = 0;
		Array = new Type[arraysize];
	};
	~Queue() {};
	bool isEmpty() {
		if (count == 0)
			return true;
		return false;
	}
	bool isFull() {
		if (count == arraysize)
			return true;
		return false;
	}
	void Push(Type value) {
		if (!isFull()) {
			if (rear == arraysize - 1)
			{
				rear = (rear + 1) % arraysize;
				Array[rear] = value;
			}
			else {
				rear++;
				Array[rear] = value;
				if (count == 0) {
					front++;
				}
			}
			count++;
		}
		else
			cout << "Queue overflow" << endl;
	}
	Type Pop() {
		if (!isEmpty()) {
			Type value = Array[front];
			front = (front + 1) % arraysize;
			count--;
			if (count == 0) {
				front = rear = -1;
			}
			return value;
		}
		else {
			return 1;
		}
	}
	int getCount() {
		return count;
	}

};

int main() {
	int size, val, pop;
	bool check;
	char cho;
	string choice;
	do {
		cout << "Enter number of elements that you have to insert in queue = ";
		cin >> size;


		arraysize = size;
		Queue<int> q;
		for (int i = 0; i < size; i++) {
			while (true) {
				cout << "\n1)push \n2)pop \n3)check isEmpty \n4)Check isFull \n5)Display Queue \n6)exit" << endl;
				cout << "Enter your choice = ";
				cin >> choice;
				if (choice == "1")
				{
					cout << "Enter value to push it to stack = ";
					while (true) {
						cin >> val;
						if (cin.fail())
						{
							cin.clear();
							cin.ignore();
							cout << "Invalid input ! Enter valid integer = ";
						}
						else
						{
							break;
						}
					}
					q.Push(val);
					cout << "\n" << val << " is pushed Successfully " << endl;
					break;
				}
				else if (choice == "2")
				{
					pop = q.Pop();
					if (pop == 1)
					{
						cout << "Queue underflow" << endl;
						continue;
					}
					cout << q.Pop() << " is removed from queue " << endl;
					i--;
				}
				else if (choice == "3")
				{
					check = q.isEmpty();
					if (check == 1)
					{
						cout << "Stack is Empty " << endl;
					}
					else
					{
						cout << "Stack is Not Empty" << endl;
					}
				}
				else if (choice == "4")
				{
					check = q.isFull();
					if (check == 1)
					{
						cout << "Stack is Full " << endl;
					}
					else
					{
						cout << "Stack is Not Full" << endl;
					}
				}
				else if (choice == "5")
				{
					check = q.isEmpty();
					if (check == 1)
					{
						cout << "Queue is Empty ! Nothing to Display" << endl;
						continue;
					}
					cout << " { ";
					for (int i = 0; i < q.getCount(); i++)
					{
						cout << q.Pop() << " ";
					}
					cout << " } " << endl;
				}
				else if (choice == "6")
				{
					exit(1);
				}
				else
				{
					cout << "invalid input! Try again " << endl;
				}
			}
		}
		cout << " { ";
		for (int i = 0; i < q.getCount(); i++)
		{
			cout << q.Pop() << " ";
		}
		cout << " } " << endl;
		cout << "Do you want to use it again (y/n) = ";
		cin >> cho;
	} while (cho == 'Y' || cho == 'y');
	return 0;
}