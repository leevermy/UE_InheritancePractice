#include <iostream>


class Animal {
    private:
        std::string name_;
    public:
        Animal() : name_("animal") {}
        Animal(const std::string& name) : name_(name) {}
        virtual void Sound() const = 0;
};

class Dog : public Animal {
    public:
        Dog(const std::string& name = "dog"): Animal(name) {}
        void Sound() const override {
            std::cout << "Woof!" << std::endl;
        }
};

class Cat : public Animal {
    public:
        Cat(const std::string& name = "cat"): Animal(name) {}
        void Sound() const override {
            std::cout << "Meow!" << std::endl;
        }
};

class Parrot : public Animal {
    public:
        Parrot(const std::string& name = "parrot"): Animal(name) {}
        void Sound() const override {
            std::cout << "Karamba!" << std::endl;
        }
};


int main() {
    Animal* arr[3] {new Cat(), new Dog(), new Parrot()};

    for (int i = 0; i < 3; ++i) {
        arr[i]->Sound();
    }

    return 0;
}