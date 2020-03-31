#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <stack>
#include <iostream>

enum OPERATIONS{ADD=1,SUB=2,MULTI=3,DIVI=4,EXIT=5};

class calculator
{
    std::stack<double>numbers;
    OPERATIONS operation;
    bool errorFlag;
    public:
        calculator();
        ~calculator();
        double calculate();
        void enterNumber(double number);
        void enterOperation(size_t numberOperation);
    private:
        double addNumbers();
        double subNumbers();
        double multiNumbers();
        double diviNumbers();
        void exitCalculator();
};

#endif // CALCULATOR_H
