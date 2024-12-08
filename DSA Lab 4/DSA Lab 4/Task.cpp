#include<iostream>
using namespace std;
int arr_size;
template<class T>
class queue {
private:
	int front, rear, count;
	T* array;
public:
	queue() {
		front = rear = -1;
		array = new T[arr_size];
		count = 0;
	}
	bool isEmpty() {
		if (front > rear || front == -1)
		{
			return true;
		}
		return false;
	}
	bool isFull() {
		if (rear == arr_size - 1)
		{
			return true;
		}
		return false;
	}
	void Push(T value)
	{
		if (!isFull()) {
			if (front == -1)
				front = 0;

			rear++;
			array[rear] = value;
			count++;
		}
		else
			cout << "queue overflow" << endl;
	}
	T pop() {
		T val;
		if (!isEmpty()) {
			val = array[front];
			front++;
			return val;
		}
		else
			cout << "queue underflow" << endl;
	}
	int getCount()
	{
		return count;
	}
};

int main()
{
	unsigned int size, choice;
	string value, admin_name, fac_name, stud_name;
	cout << "How many persons will enter in queue = ";
	while (true) {
		cin >> size;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Invalid input. Please enter a valid integer: ";
		}
		else {
			break;
		}
	}
	arr_size = size;

	queue<string>Admin;
	queue<string>Faculity;
	queue<string>Student;
	queue<string>priority_queue;

	for (int i = 1; i <= size; i++) {
		do {
			cout << "Select person who entered queue at " << i << " number" << endl;
			cout << "1) Add Admin \n2) Add Faculity \n3) Add Student \n4)Exit " << endl;
			cout << "Enter (e.g 1,2,3) = ";
			//bool loop = true;
			while (true) {
				cin >> choice;
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
					cout << "Invalid input. Please enter a valid integer: ";
				}
				else {
					break;
				}
			}
			if (choice == 1)
			{
				cout << "Enter Name of Admin = ";
				cin >> admin_name;
				Admin.Push(admin_name);
			}
			else if (choice == 2)
			{
				cout << "Enter faculity Name = ";
				cin >> fac_name;
				Faculity.Push(fac_name);
			}
			else if (choice == 3)
			{
				cout << "Enter student name = ";
				cin >> stud_name;
				Student.Push(stud_name);
			}
			else if (choice == 4)
			{
				return 0;
			}
			else
			{
				cout << "Invalid Input" << endl;
			}
		} while (choice != 1 && choice != 2 && choice != 3);
	}
	for (int i = 0; i < Admin.getCount(); i++) {
		value = " ";
		value = Admin.pop();
		priority_queue.Push(value);
	}
	for (int i = 0; i < Faculity.getCount(); i++)
	{
		value = " ";
		value = Faculity.pop();
		priority_queue.Push(value);
	}
	for (int i = 0; i < Student.getCount(); i++)
	{
		value = " ";
		value = Student.pop();
		priority_queue.Push(value);
	}
	cout << "Preiorty Queue = { ";
	for (int i = 0; i < priority_queue.getCount(); i++)
	{
		cout << priority_queue.pop() << "  ";
	}
	cout << "}" << endl;
	return 0;
}