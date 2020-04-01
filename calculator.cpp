#include "calculator.h"
#include <string>
#include <stdlib.h>

calculator::calculator()
{
  numbers.push(0);
  calculatorStatus = START;
}

calculator::~calculator()
{
    //dtor
}

double calculator::addNumbers()
{
  double a = numbers.top();
  numbers.pop();
  double b = numbers.top();
  return a+b;
}

double calculator::subNumbers()
{
  double a = numbers.top();
  numbers.pop();
  double b = numbers.top();
  return b-a;
}

double calculator::multiNumbers()
{
  double a = numbers.top();
  numbers.pop();
  double b = numbers.top();
  return a*b;
}

double calculator::diviNumbers()
{
  double a = numbers.top();
  numbers.pop();
  double b = numbers.top();
  return b/a;
}

void calculator::calculate()
{
   switch(operation)
   {
   case ADD:
      numbers.push(addNumbers());
      resetBufor();
      break;
   case SUB:
       numbers.push(subNumbers());
       resetBufor();
      break;
   case MULTI:
       numbers.push(multiNumbers());
       resetBufor();
      break;
   case DIVI:
       numbers.push(diviNumbers());
       resetBufor();
      break;
   }
}

void calculator::enterNumber(double number)
{
   numbers.push(number);
   calculatorBufor.push_back(std::to_string(number));
   if(calculatorStatus==START) calculatorStatus= CHECK_OPERATION;
   if(calculatorStatus==INTRODUCTION_NEXT_NUMBER) calculatorStatus= CHECK_OPERATION;
}

void calculator::enterOperation(size_t numberOperation)
{
    calculatorStatus = INTRODUCTION_NEXT_NUMBER;
    switch(numberOperation)
   {
   case ADD:
      operation = ADD;
      calculatorBufor.push_back(" + ");
      break;
   case SUB:
      operation = SUB;
      calculatorBufor.push_back(" - ");
      break;
   case MULTI:
      operation = MULTI;
      calculatorBufor.push_back(" * ");
      break;
   case DIVI:
      operation = DIVI;
      calculatorBufor.push_back(" / ");
      break;
   case EXIT:
      exit(0);
      break;
   }
}

STATUS calculator::checkStatusCalculator()
{
    return calculatorStatus;
}

void calculator::resetBufor()
{
    calculatorBufor.clear();
    calculatorBufor.push_back(std::to_string(numbers.top()));
}

std::ostream& operator<<(std::ostream& output,calculator &calc)
{
    for(size_t i=0;i<calc.calculatorBufor.size();i++)
    {
        output<<calc.calculatorBufor[i];
    }
    output<<'\n';

    return output;
}
