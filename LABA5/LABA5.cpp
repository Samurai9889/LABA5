#include <iostream>
#include <stdexcept>
#include "Animal.h"
using namespace std;
int main() {
    try {
        // Використання шаблону Animal для стандартних типів даних
        Animal<string, string, int> animal1("Dog", "Canine", 10);
        Animal<string, string, int> animal2("Cat", "Feline", 8);

        //cout << "Animal 1: " << animal1[0] << " " << animal1[1] << " " << animal1[2] endl;
        //cout << "Animal 2: " << animal2[0] << " " << animal2[1] << " " << animal2[2] endl;

        if (animal1 == animal2)
            cout << "Animal 1 and Animal 2 are equal" << endl;
        else
            cout << "Animal 1 and Animal 2 are not equal" << endl;

        int weightDiff = animal1 - animal2;
        cout << "Weight difference: " << weightDiff << endl;
    }
    catch (AnimalException& e) {
        cout << "Animal Exception: " << e.what() << endl;
    }

    return 0;
}
