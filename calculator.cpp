#include "calculator.h"
#include <string>
#include <stdlib.h>

calculator::calculator()
{

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

void calculator::exitCalculator()
{
  exit(0);
}

double calculator::calculate()
{
   switch(operation)
   {
   case ADD:
      return addNumbers();
      break;
   case SUB:
      return subNumbers();
      break;
   case MULTI:
      return multiNumbers();
      break;
   case DIVI:
      return diviNumbers();
      break;
   case EXIT:
      exitCalculator();
      break;
   }
}

void calculator::enterNumber(double number)
{
   numbers.push(number);
}

void calculator::enterOperation(size_t numberOperation)
{
    switch(numberOperation)
   {
   case ADD:
      operation = ADD;
      break;
   case SUB:
      operation = SUB;
      break;
   case MULTI:
      operation = MULTI;
      break;
   case DIVI:
      operation = DIVI;
      break;
   case EXIT:
      exitCalculator();
      break;
   }
}
