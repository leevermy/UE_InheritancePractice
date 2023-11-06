#include <iostream>
#include <vector>
#include <memory>

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


void AddAnimals(std::vector<std::shared_ptr<Animal>>& animals) {
    char ch;
    for (auto& an : animals) {
        std::cout << "What animal do you wanna add?\n";
        std::cout << "Enter the letter: \'c\' for cat, \'d\' for dog, \'p\' for parrot: ";
        std::cin >> ch;
        switch (tolower(ch)) {
            case 'c': 
                an = std::make_shared<Cat>(); 
                std::cout << "Class Cat created\n" << std::endl; 
                break;
            case 'd': 
                an = std::make_shared<Dog>(); 
                std::cout << "Class Dog created\n" << std::endl; 
                break;
            case 'p': 
                an = std::make_shared<Parrot>(); 
                std::cout << "Class Parrot created\n" << std::endl; 
                break;
            default: 
                std::cout << "Invalid input. Class haven't been created\n" << std::endl;
        }
    }
    std::cout << std::endl;
}
   

int main() {
    std::cout << "Enter the amount of animals: " << std::endl;
    int animals_amount;
    std::cin >> animals_amount;

    // заполнение вектора можно было сделать через while и push_back(),
    // но решил пойти таким путём
    std::vector<std::shared_ptr<Animal>> animals (animals_amount);
    AddAnimals(animals);
    
    for (const auto& an : animals) {
        an->Sound();
    }

    return 0;
}