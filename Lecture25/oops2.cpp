#include <iostream>
using namespace std;

class Car
{	int price = 100;
public:

	char* name;
	int fuleCapacity;
	int wheels;

	Car() {
		name = new char[10];
		cout << "inside my constructor" << endl;
	}

	Car(int f, char* n, int w = 4) {
		wheels = w;
		fuleCapacity = f;
		name = new char[10];
		strcpy(name, n);
	}
	//copy Constructor
	// //shallow copy
	// Car(Car &X) {
	// 	cout << "our shallow copy constructor called" << endl;
	// 	wheels = X.wheels;
	// 	name = X.name;
	// 	fuleCapacity = X.fuleCapacity;
	// }

	//deep copy
	// Car(Car &X) {
	// 	cout << "our deep copy constructor called" << endl;
	// 	wheels = X.wheels;
	// 	name = new char[10];
	// 	strcpy(name, X.name);
	// 	fuleCapacity = X.fuleCapacity;
	// }

	void operator = (Car &X) {
		cout << "our = operator" << endl;
		wheels = X.wheels;
		name = new char[10];
		strcpy(name, X.name);
		fuleCapacity = X.fuleCapacity;
	}

	void operator + (Car &X) {
		price += X.price;
	}



	void print() {
		cout << "wheels: " << wheels << endl;
		cout << "fuleCapacity: " << fuleCapacity << endl;
		cout << "name: " << name << endl;
		cout << "price: " << price << endl;
	}

};


// cin >> abc;

// cout << "abc";

// void operator <<(ostream& os, Car X) {
// 	cout << "#############################################" << endl;
// 	os << "wheels: " << X.wheels << endl;
// 	os << "fuleCapacity: " << X.fuleCapacity << endl;
// 	os << "name: " << X.name << endl;
// 	// os << "price: " << X.getPrice() << endl;
// 	cout << "#############################################" << endl;
// }

ostream& operator <<(ostream& os, Car X) {
	os << "#############################################" << endl;
	os << "wheels: " << X.wheels << endl;
	os << "fuleCapacity: " << X.fuleCapacity << endl;
	os << "name: " << X.name << endl;
	// os << "price: " << X.getPrice() << endl;
	os << "#############################################" << endl;
	return os;
}
istream& operator >>(istream& os, Car X) {
	os >> X.wheels;
	os >> X.fuleCapacity;
	os >> X.name ;
	return os;
}

int main(int argc, char const *argv[])
{
	Car c1(10, "ABC", 5);
	// c1.print();
	cout << "--------" << endl;
	// Car c2(c1);
	Car c2 = c1;
	// c2.print();

	// cout << "-----c1.name[0] = '1';---" << endl;
	// c1.name[0] = '1';
	// c1.fuleCapacity = 5000;
	// c1.print();
	// cout << "---c2.print();-----" << endl;
	// c2.print();


	// cout << "price" << endl;
	// c1 + c1;
	// c1.print();
	// c2.print();
	//cout << c1
//cascading
	cout << c1 << c2 << endl;
	//ostream obj << "----to print----";
	return 0;
}




