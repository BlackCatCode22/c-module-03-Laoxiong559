#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>

class Animal {
protected:
    std::string name;
    int age;
    std::string species;

public:
    Animal(std::string n, int a, std::string s) : name(n), age(a), species(s) {}

    std::string getName() const { return name; }
    int getAge() const { return age; }
    std::string getSpecies() const { return species; }

    void setName(std::string n) { name = n; }
    void setAge(int a) { age = a; }
    void setSpecies(std::string s) { species = s; }
};

class Hyena : public Animal {
public:
    Hyena(std::string n, int a) : Animal(n, a, "Hyena") {}
};

class Lion : public Animal {
public:
    Lion(std::string n, int a) : Animal(n, a, "Lion") {}
};

class Tiger : public Animal {
public:
    Tiger(std::string n, int a) : Animal(n, a, "Tiger") {}
};

class Bear : public Animal {
public:
    Bear(std::string n, int a) : Animal(n, a, "Bear") {}
};

int main() {
    std::vector<Animal*> animals;
    std::map<std::string, int> speciesCount;
    std::ifstream inputFile("arrivingAnimals.txt");
    std::ofstream outputFile("newAnimals.txt");
    std::string name, species;
    int age;

    while (inputFile >> name >> age >> species) {
        Animal* animal = nullptr;
        if (species == "Hyena") {
            animal = new Hyena(name, age);
        } else if (species == "Lion") {
            animal = new Lion(name, age);
        } else if (species == "Tiger") {
            animal = new Tiger(name, age);
        } else if (species == "Bear") {
            animal = new Bear(name, age);
        }

        if (animal) {
            animals.push_back(animal);
            speciesCount[species]++;
        }
    }

    for (const auto& entry : speciesCount) {
        outputFile << "Species: " << entry.first << ", Count: " << entry.second << "\n";
    }

    for (const auto& animal : animals) {
        outputFile << "Name: " << animal->getName() << ", Age: " << animal->getAge() << ", Species: " << animal->getSpecies() << "\n";
    }

    inputFile.close();
    outputFile.close();

    for (auto animal : animals) {
        delete animal;
    }

    return 0;
}
