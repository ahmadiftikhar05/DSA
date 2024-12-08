#include<iostream>
#include<string>
using namespace std;
template<class type>
class stack {
private:
	int top;
	type items[100];
public:
	stack()
	{
		top = -1;
	}
	bool isEmpty() {
		return(top == -1);
	}
	bool isFull() {
		return(top >= 99);
	}
	void push(type n) {
		if (isFull())
		{
			cout << "Stack Overflow" << endl;
			exit(1);
		}
		top++;
		items[top] = n;
	}
	type pop() {
		int n;
		if (isEmpty())
		{
			cout << "Stack underflow" << endl;
			exit(1);
		}
		n = items[top];
		top--;
		return n;
	}
};

int main()
{
	stack<char>palendromeChecker;
	string word,revWord;
	cout << "Enter Word to check palendrome = ";
	cin >> word;
	for (int i = 0; i < word.length(); i++)
	{
		palendromeChecker.push(word[i]);
	}
	for (int i = 0; i < word.length(); i++)
	{
		revWord += palendromeChecker.pop(); 
	}

	if (word == revWord)
	{
		cout << "Word is Palendrome" << endl;
	}
	else
	{
		cout << "Word is not a palendrome" << endl;
	}
	return 0;

}