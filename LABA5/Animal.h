#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;
// Виняток для класу Animal
class AnimalException : public exception {
public:
    AnimalException( string& message) : message(message) {}

    const char* what() const noexcept override {
        return message.c_str();
    }

private:
    string message;
};

// Клас Animal
template<typename NameType, typename SpeciesType, typename WeightType>
class Animal {
public:
    Animal() : name(""), species(""), weight(0) {}

    Animal(const NameType& name, const SpeciesType& species, const WeightType& weight)
        : name(name), species(species), weight(weight) {}

    // Конструктор копіювання
    Animal(const Animal& other)
        : name(other.name), species(other.species), weight(other.weight) {}

    // Перевантажена операція присвоювання
    Animal& operator=(Animal& other) {
        if (this != &other) {
            name = other.name;
            species = other.species;
            weight = other.weight;
        }
        return *this;
    }

    // Перевантажена операція доступу до елементу в заданій позиції
    // Використовується оператор []
    template<typename T>
    T operator[](int index) {
        if (index == 0)
            return name;
        else if (index == 1)
            return species;
        else if (index == 2)
            return weight;
        else
            throw AnimalException("Invalid index");
    }

    // Перевантажена операція різниці
    // Використовується оператор -
    template<typename T>
    WeightType operator-( T& other) {
        return weight - other.weight;
    }

    // Перевантажена операція перевірки на рівність
    // Використовується оператор ==
    bool operator==( Animal& other) {
        return name == other.name && species == other.species && weight == other.weight;
    }

    // Деструктор
    ~Animal() {}

private:
    NameType name;
    SpeciesType species;
    WeightType weight;
};