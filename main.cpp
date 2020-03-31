#include <iostream>
#include "calculator.h"

int main()
{
    calculator calc;

    std::cout<<"KALKULATOR\n";
    std::cout<<"=================\n";
    std::cout<<"1.Dodawanie\n";
    std::cout<<"2.Odejmowanie\n";
    std::cout<<"3.Mnozenie\n";
    std::cout<<"4.Dzielenie\n";
    std::cout<<"5.WYJSCIE\n";
    std::cout<<"=================\n";
    std::cout<<"Podaj pierwsza liczbe: ";
    calc.enterNumber(std::cin);
    std::cout<<"Wybierz operacje: ";
    calc.enterOperation(std::cin);
    std::cout<<"Podaj druga liczbe: ";
    calc.enterNumber(std::cin);
    std::cout<<"WYNIK = "<<calc.calculate()<<'\n';

    return 0;
}
