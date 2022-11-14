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
	std::vector<std::string> talents;
public:
	void showTalent() {
		for (int i = 0; i < talents.size(); ++i) {
			std::cout << "It can " << talents[i] << std::endl;
		}
	}


	Dog(std::string inName){
		name = inName;

		Swimming swimming;
		Dancing dancing;
		Counting counting;

		talents = { swimming.get_talent(), dancing.get_talent(), counting.get_talent() };
	}
};

int main() {
	std::string input;

	std::cout << "Enter dog's name: ";
	std::cin >> input;

	Dog dog(input);

	std::cout << "Command: ";
	std::cin >> input;

	if(input == "show_talent") dog.showTalent();

	return 0;
}