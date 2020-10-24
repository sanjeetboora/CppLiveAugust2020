#include <iostream>
using namespace std;

class Car {
	int price;
public:
	char name[10];
	// const int wheels; //only initialization possible
	int wheels;
	int fuleTankCapacity;
	//default constructor
	// Car() {
	// 	cout << "our default constructor" << endl;
	// 	price = 10;
	// }
	//parameterized Constructor
	Car(int cap, char n[10], int w = 4) {
		price = 50;
		wheels = w;
		fuleTankCapacity = cap;
		strcpy(name, n);
	}

	//Constructor with initialization list
	Car(int cap, int p, char n[10], int w = 4): wheels(w), fuleTankCapacity(cap) {
		cout << "Constructor with initialization list" << endl;
		setPrice(p);
		strcpy(name, n);
	}

	//copy Constructor
	Car(Car &X) {
		cout << "our Copy Constructor" << endl;
		wheels = X.wheels;
		setPrice(X.price);
		strcpy(name, X.name);
		fuleTankCapacity = X.fuleTankCapacity;
	}



	//getter
	int getPrice() {
		return price;
	}
	//setter
	void setPrice(int p) {
		if (p >= 50) {
			price = p;
		}
		else {
			cout << "price to too low" << endl;
		}
	}

	void print() {
		cout << "price: " << price << endl;
		cout << "wheels: " << wheels << endl;
		cout << "name: " << name << endl;
		cout << "fuleTankCapacity: " << fuleTankCapacity << endl;

	}
};

int main(int argc, char const *argv[])
{

	// cout << sizeof(Car) << endl;
	// Car c1;
	// cout << sizeof(c1) << endl;
	// cout << c1.getPrice() << endl;
	// //objectName.propertyName
	// // c1.price = 20;
	// // cout << c1.price << endl;
	// c1.wheels = 4;
	// cout << c1.wheels << endl;
	// c1.setPrice(100);
	// cout << c1.getPrice() << endl;
	// c1.setPrice(10);
	// cout << c1.getPrice() << endl;

	// char n[10] = "Abc";
	// Car c2(10, 200, n, 5);
	// cout << c2.wheels << endl;
	// cout << c2.name << endl;
	// cout << c2.fuleTankCapacity << endl;
	// char n[10] = "Abc";
	// Car c4(10, n, 5);
	// cout << c4.wheels << endl;
	// cout << c4.name << endl;
	// cout << c4.fuleTankCapacity << endl;


	// // int a = 5; //intialization
	// // int b;
	// // b =  10; //assignment

	// Car c5(c4);
	// cout << c5.wheels << endl;
	// cout << c5.name << endl;
	// cout << c5.fuleTankCapacity << endl;


	Car c6(10, "ABC", 5);
	c6.print();
	Car c7(c6);
	c7.print();

	c6.name[0] = 'z';
	cout << "--------" << endl;
	c6.print();
	c7.print();

	Car c8 = c7;
	c8.print();

	return 0;
}



