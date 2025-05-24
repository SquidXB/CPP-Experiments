#include <iostream>

int pesos = 0;
int reais = 0;
int soles = 0;
double usd = 0;

int main() {

    std::cout << "Enter Colombian Pesos: ";
    std::cin >> pesos;
    std::cout << "Enter Brazilian Reais: ";
    std::cin >> reais;
    std::cout << "Enter Peruvian Soles: ";
    std::cin >> soles;

    usd += (pesos / 4170) + (reais / 5.65) + (soles / 3.65);
    std::cout << "You have $" << usd;

    return 0;
}