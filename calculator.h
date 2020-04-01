#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <stack>
#include <iostream>
#include <vector>

enum OPERATIONS{ADD=1,SUB=2,MULTI=3,DIVI=4,EXIT=5};
enum STATUS{START=1,CHECK_OPERATION=2,INTRODUCTION_NEXT_NUMBER=3};

class calculator
{
       std::stack<double>numbers;
       std::vector<std::string>calculatorBufor;
       OPERATIONS operation;
       STATUS calculatorStatus;
    public:
        calculator();
        ~calculator();
        void enterNumber(double number);
        void enterOperation(size_t numberOperation);
        STATUS checkStatusCalculator();
        void calculate();
        friend std::ostream& operator<<(std::ostream& output,calculator &calc);
    private:
        double addNumbers();
        double subNumbers();
        double multiNumbers();
        double diviNumbers();
        void resetBufor();
};

#endif // CALCULATOR_H
