#include<iostream>
#include <chrono>
#include <iomanip>

using namespace std::chrono;
using namespace std;


struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
class sort
{
public:
		int* array = new int[ 100000 ];
	
public:
	int value;
	sort() {};
	void get_val(int val)
	{
		value = val;
		for (int i = 0; i < val; i++)
		{
			int num = rand() % 100;
			array[i] = num;
		}
	}
	void selection_Sort()
	{
		
		for (int i = 0; i < value; i++)
		{
			for (int j = i + 1; j < value; j++)
			{
				if (array[i] > array[j])
				{
					swap(array[i], array[j]);
				}
			}
		}
		/*for (int i = 0; i < value; i++)
		{
			cout << array[i] << endl;
		}*/

	}

	void bubbleSort()
	{
		for (int i = 0; i < value-1 ; i++)
		{
			for (int j = 0; j < value-1; j++)
			{
				if (array[j] > array[j + 1])
				{
					swap(array[j], array[j + 1]);
				}
			}
		}
	}

	Node* insert(Node* root, int value) {
		if (!root) return new Node(value);
		if (value < root->data)
			root->left = insert(root->left, value);
		else
			root->right = insert(root->right, value);
		return root;
	}

	void inOrderTraversal(Node* root, int& index) {
		if (!root) return;
		inOrderTraversal(root->left, index);
		array[index++] = root->data;
		inOrderTraversal(root->right, index);
	}

	void binaryTreeSort() {
		Node* root = nullptr;
		for (int i = 0; i < value; i++) {
			root = insert(root, array[i]);
		}

		int index = 0;
		inOrderTraversal(root, index);
	}

};
	 int main()
	 {

		 sort* s = new sort();
	//	 s->get_val(100000);

	//	 auto start = std::chrono::high_resolution_clock::now();
	//	 s->binaryTreeSort();
	//	 auto end = std::chrono::high_resolution_clock::now();


	//	// auto start = std::chrono::high_resolution_clock::now();
	//	// s->selection_Sort();
	//	// auto end = std::chrono::high_resolution_clock::now();
	//	auto duration = duration_cast<milliseconds>(end - start);
	///*	for (int i = 0; i < s->value; i++)
	//	{
	//		cout << s->array[i] << endl;
	//	}*/
	//	cout << "Duration = " << duration.count();

		cout << "Value" << setw(15) << "SelectionSort" << setw(15) << "BubbleSort" << setw(20) << "BinarySort" << endl;

		for (int i = 10; i <= 100000; i = i * 10)
		{
			s->get_val(i);

			auto binarystart = std::chrono::high_resolution_clock::now();
			s->binaryTreeSort();
			auto binaryend = std::chrono::high_resolution_clock::now();
			auto binaryduration = duration_cast<milliseconds>(binaryend - binarystart);

			auto bubble_start = std::chrono::high_resolution_clock::now();
			s->bubbleSort();
			auto bubble_end = std::chrono::high_resolution_clock::now();
			auto bubble_duration = duration_cast<milliseconds>(bubble_end - bubble_start);

			auto s_start = std::chrono::high_resolution_clock::now();
			s->selection_Sort();
			auto s_end = std::chrono::high_resolution_clock::now();
			auto s_duration = duration_cast<milliseconds>(s_end - s_start);


			cout << left << setw(10) << i
				<< setw(20) << s_duration.count()
				<< setw(20) << bubble_duration.count()
				<< setw(20) << binaryduration.count() << endl;
			//cout<< i << setw(15) << s_duration.count() << setw(10) << bubble_duration.count() << setw(8) << binaryduration.count() << endl;


		}
		 return 0;
	 }
