#include <iostream>

using namespace std;

class Parent {
public:
	virtual void show() = 0;
	//	cout << "Parent" << endl;
	//}
};

class Child_1 : public Parent {
public:
	void show() {
		cout << "Child_1" << endl;
	}
};

class Child_2 : public Parent {
public:
	void show() {
		cout << "Child_2" << endl;
	}
};

int main() {
	Child_1 objCh1;
	Child_2 objCh2;
	Parent* objPar;
	//Parent objPar2;
	//int var = 10;
	//void* ptrVar = &var;
	//cout << *ptrVar << endl;

	objPar = &objCh1;
	objPar->show();

	objPar = &objCh2;
	objPar->show();

	system("pause");
	return 0;
}