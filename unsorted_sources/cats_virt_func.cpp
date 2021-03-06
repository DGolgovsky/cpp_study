#include <iostream>

using std::cout;
using std::endl;

class Cat
{
public:
	virtual ~Cat() {
		sayGoodbye();
	}

	void askForFood() const {
		speak();
		eat();
	}

	virtual void speak() const { cout << "Meow! "; }

	void eat() const { cout << "*champing*" << endl; }

	virtual void sayGoodbye() const { cout << "Meow-meow!" << endl; }
};

class CheshireCat : public Cat
{
public:
	~CheshireCat() {
		sayGoodbye();
	}

	void speak() const {
		cout << "WTF?! Where\'s my milk? =) ";
	}

	void sayGoodbye() const { cout << "Bye-bye! (:" << endl; }
};

int main(void) {
	Cat *cats[] = {new Cat, new CheshireCat};

	cout << "Ordinary Cat: ";
	cats[0]->askForFood();
	cout << "Cheshire Cat: ";
	cats[1]->askForFood();

	delete cats[0];
	delete cats[1];
	return 0;
}

