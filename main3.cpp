#include <iostream>

class Animal {
    private:
        std::string name_;
    public:
        Animal() : name_("animal") {}
        Animal(const std::string& name) : name_(name) {}
        virtual void Sound() const = 0;
        std::string GetName() const {
            return name_;
        }
};

class Dog : public Animal {
    public:
        Dog(const std::string& name = "dog"): Animal(name) {}
        void Sound() const override {
            std::cout << "The " << GetName() << " says \"woof!\"" << std::endl;
        }
};

class Cat : public Animal {
    public:
        Cat(const std::string& name = "cat"): Animal(name) {}
        void Sound() const override {
            std::cout << "The " << GetName() << " says \"meow!\"" << std::endl;
        }
};

class Parrot : public Animal {
    public:
        Parrot(const std::string& name = "parrot"): Animal(name) {}
        void Sound() const override {
            std::cout << "The " << GetName() << " says \"Karamba!\"" << std::endl;
        }
};


int main() {
    std::cout << "Enter the amount of animals: " << std::endl;
    int animals_amount;
    std::cin >> animals_amount;


    Animal ** arr = new Animal* [animals_amount];
    for (int i = 0; i < animals_amount; ++i) {
        std::cout << "What animal do you wanna add?\n";
        std::cout << "Enter the letter: \'c\' for cat, \'d\' for dog, \'p\' for parrot: ";
        char ch;
        std::cin >> ch;
        switch (tolower(ch)) {
            case 'c': 
                arr[i] = new Cat; 
                std::cout << "Class Cat created\n" << std::endl; 
                break;
            case 'd': 
                 arr[i] = new Dog;
                std::cout << "Class Dog created\n" << std::endl; 
                break;
            case 'p': 
                 arr[i] = new Parrot;
                std::cout << "Class Parrot created\n" << std::endl; 
                break;
            default: 
                std::cout << "Invalid input. Class haven't been created\n" << std::endl;
        }
    }

    for (int i = 0; i < animals_amount; ++i) {
        arr[i]->Sound();
    }

    for (int i = 0; i < animals_amount; ++i) {
        delete [] arr[i];
    }

    delete [] arr;
    return 0;
}