#include<iostream>
#include<iomanip>
using namespace std;

class house
{
private:
	string owner, address;
	int bedroom;
	float price;
public:
	house() {};
	house(string own, string addr, int bedr, float pri) :owner(own), address(addr), bedroom(bedr), price(pri) {};

	string getowner()
	{
		return owner;
	}
	string getaddress()
	{
		return address;
	}
	int getbedroom()
	{
		return bedroom;
	}
	float getprice()
	{
		return price;
	}
};
int main()
{
	house houses[100] = {};
	char choice;
	int count = 0;
	do {
		
		choice = ' ';
		string ownername, address;
		int bedrooms;
		float price;

		cout<< "Enter owner name : ";
		cin >> ownername;
		cout << "Enter address : ";
		cin >> address;
		cout << "Enter no. of bedrooms you have to book : ";
		cin >> bedrooms;

		cout << "Enter price : ";
		cin >> price;
		houses[count] = house(ownername, address, bedrooms, price);
		
		cout << "Do you want to enter another house?(y/n)";
		cin >> choice;
		count++;
	} while (choice == 'y');
	cout << "owner" << setw(15) << "address" << setw(15) << "bedroom" << setw(15) << "price" << endl;
	for (int i = 0;i<=count-1 ; i++)
	{
		cout << houses[i].getowner() << setw(15) << houses[i].getaddress() << setw(15) << houses[i].getbedroom() << setw(15) << houses[i].getprice() << endl;
	}
		return 0;
}
