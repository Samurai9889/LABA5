#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;
// ������� ��� ����� Animal
class AnimalException : public exception {
public:
    AnimalException( string& message) : message(message) {}

    const char* what() const noexcept override {
        return message.c_str();
    }

private:
    string message;
};

// ���� Animal
template<typename NameType, typename SpeciesType, typename WeightType>
class Animal {
public:
    Animal() : name(""), species(""), weight(0) {}

    Animal(const NameType& name, const SpeciesType& species, const WeightType& weight)
        : name(name), species(species), weight(weight) {}

    // ����������� ���������
    Animal(const Animal& other)
        : name(other.name), species(other.species), weight(other.weight) {}

    // ������������� �������� ������������
    Animal& operator=(Animal& other) {
        if (this != &other) {
            name = other.name;
            species = other.species;
            weight = other.weight;
        }
        return *this;
    }

    // ������������� �������� ������� �� �������� � ������ �������
    // ��������������� �������� []
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

    // ������������� �������� ������
    // ��������������� �������� -
    template<typename T>
    WeightType operator-( T& other) {
        return weight - other.weight;
    }

    // ������������� �������� �������� �� ������
    // ��������������� �������� ==
    bool operator==( Animal& other) {
        return name == other.name && species == other.species && weight == other.weight;
    }

    // ����������
    ~Animal() {}

private:
    NameType name;
    SpeciesType species;
    WeightType weight;
};