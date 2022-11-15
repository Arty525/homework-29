//SUPERDOG
#include <iostream>
#include <vector>

class Talent {
protected:
	std::string talent;
public:
	virtual std::string get_talent() = 0;
};

class Swimming : virtual public Talent {
public:
	virtual std::string  get_talent() {
		return talent;
	}

	Swimming() {
		talent = "swimming";
	}
};

class Dancing : virtual public Talent {
public:
	virtual std::string  get_talent() {
		return talent;
	}

	Dancing() {
		talent = "dancing";
	}
};

class Counting : virtual public Talent {
public:
	virtual std::string  get_talent() {
		return talent;
	}

	Counting() {
		talent = "counting";
	}
};

class Dog {
	std::string name;
	std::vector<Talent*> talents;
public:
	std::string get_name() {
		return name;
	}

	void showTalent() {
		for (int i = 0; i < talents.size(); ++i) {
			std::cout << "It can " << talents[i]->get_talent() << std::endl;
		}
	}


	Dog(std::string inName){
		name = inName;

		Swimming* swimming = new Swimming();
		Dancing* dancing = new Dancing();
		Counting* counting = new Counting();

		talents = { swimming, dancing, counting };
	}
};

int main() {
	std::string input;

	std::cout << "Enter dog's name: ";
	std::cin >> input;

	Dog dog(input);

	std::cout << "Command: ";
	std::cin >> input;

	if (input == "show_talent") {
		std::cout << "Hi, this is " << dog.get_name() << " and it has some talents:" << std::endl;
		dog.showTalent();
	}
	return 0;
}