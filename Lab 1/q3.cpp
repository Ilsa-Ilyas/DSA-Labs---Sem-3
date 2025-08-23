#include <iostream>
using namespace std;

class Box {
private:
	int* value;
public:
	// Constructor
	Box(int v = 0) {
		value = new int(v);
	}

	// Destructor
	~Box() {
		delete value;
	}

	// Copy constructor (deep copy)
	Box(const Box& other) {
		value = new int(*other.value);
	}

	// Copy assignment operator (deep copy)
	Box& operator=(const Box& other) {
		if (this != &other) {
			delete value;
			value = new int(*other.value);
		}
		return *this;
	}

	void setValue(int v) {
		*value = v;
	}

	int getValue() const {
		return *value;
	}

	// For demonstration: shallow copy (dangerous, for educational purposes only)
	void shallowCopy(const Box& other) {
		delete value;
		value = other.value; // Now both objects share the same memory
	}
};

int main() {
	cout << "Demonstrating deep copy (Rule of Three):" << endl;
	Box b1(10);
	Box b2 = b1; // Deep copy
	b2.setValue(20);
	cout << "b1 value: " << b1.getValue() << endl; // Should print 10
	cout << "b2 value: " << b2.getValue() << endl; // Should print 20

	cout << "\nDemonstrating shallow copy (for educational purposes):" << endl;
	Box b3(30);
	Box b4(40);
	b4.shallowCopy(b3); // Now b3 and b4 share the same memory
	b4.setValue(50);
	cout << "b3 value after b4.setValue(50): " << b3.getValue() << endl; // Will print 50 (shared)
	cout << "b4 value: " << b4.getValue() << endl; // Will print 50
	// When b3 and b4 go out of scope, both will try to delete the same memory, causing undefined behavior
	return 0;
}
