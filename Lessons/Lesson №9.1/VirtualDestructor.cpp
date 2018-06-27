#include <iostream>
using namespace std;

class VirtualDestructor {
public:
	virtual ~VirtualDestructor() {
		cout << "Called virualDestructor" << endl;
	}
};

class ChildVirtualDestructor : public VirtualDestructor {
public:
	~ChildVirtualDestructor() {
		cout << "Called childVirualDestructor" << endl;
	}
};

int main() {
	VirtualDestructor* parentClass = new ChildVirtualDestructor;
	delete parentClass;

	system("pause");
	return 0;
}