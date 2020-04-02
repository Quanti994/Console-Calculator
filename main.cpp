#include <iostream>
#include "calculator.h"
#include "console.h"

int main()
{
    calculator calc;

    for(;;){

        clearConsole();

        std::cout<<"KALKULATOR\n";
        std::cout<<"=================\n";
        std::cout<<"1.Dodawanie\n";
        std::cout<<"2.Odejmowanie\n";
        std::cout<<"3.Mnozenie\n";
        std::cout<<"4.Dzielenie\n";
        std::cout<<"5.WYJSCIE\n";
        if(calc.checkStatusCalculator()==CHECK_OPERATION) std::cout<<"6.Historia operacji\n";
        std::cout<<"=================\n";
        std::cout<<"WYNIK = "<<calc;
        std::cout<<"=================\n";

        double number;
        size_t numberOperation;
        if(calc.checkStatusCalculator()==START)
        {
           do{
           std::cin.clear();
           std::cin.sync();
           std::cout<<"Podaj pierwsza liczbe: ";
           std::cin >> number;
           if(std::cin.fail()) std::cout<<"BLAD TRESCI!"<<std::endl;
         }while(std::cin.fail());
         calc.enterNumber(number);
         } else if(calc.checkStatusCalculator()==CHECK_OPERATION)
         {
        do{
        std::cin.clear();
        std::cin.sync();
        std::cout<<"Wybierz operacje: ";
        std::cin >> numberOperation;
        if(std::cin.fail()) std::cout<<"BLAD TRESCI!"<<std::endl;
        }while(std::cin.fail());
        calc.enterOperation(numberOperation);
        } else if(calc.checkStatusCalculator()==INTRODUCTION_NEXT_NUMBER)
        {
        do{
        std::cin.clear();
        std::cin.sync();
        std::cout<<"Podaj druga liczbe: ";
        std::cin >> number;
        if(std::cin.fail()) std::cout<<"BLAD TRESCI!"<<std::endl;
        }while(std::cin.fail());
        calc.enterNumber(number);
        calc.calculate();
        }
    }

    return 0;
}
