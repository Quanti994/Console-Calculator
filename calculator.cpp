#include "calculator.h"
#include "console.h"
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

double calculator::binary_operation(std::function<double(double, double)> const& f)
{
    double a = numbers.top();
    numbers.pop();
    double b = numbers.top();
    numbers.pop();
    return f(a,b);
}

void calculator::perform_operation(std::function<double(double, double)> const& f)
{
      numbers.push(binary_operation(f));
      historyOperation.push_back(" = ");
      historyOperation.push_back(std::to_string(numbers.top()));
      historyOperation.push_back(std::to_string(numbers.top()));
      resetBufor();
}

void calculator::calculate()
{
    switch(operation)
   {
   case ADD:
      perform_operation(std::plus<double>{});
      break;
   case SUB:
      perform_operation(std::minus<double>{});
      break;
   case MULTI:
      perform_operation(std::multiplies<double>{});
      break;
   case DIVI:
      perform_operation(std::divides<double>{});
      break;
   }
}

void calculator::enterNumber(double number)
{
   numbers.push(number);
   calculatorBufor.push_back(std::to_string(number));
   historyOperation.push_back(std::to_string(number));
   if(calculatorStatus==START) calculatorStatus= CHECK_OPERATION;
   if(calculatorStatus==INTRODUCTION_NEXT_NUMBER) calculatorStatus= CHECK_OPERATION;
}

void calculator::enterOperation(size_t numberOperation)
{
    if(numberOperation!=HISTORY) calculatorStatus = INTRODUCTION_NEXT_NUMBER;
    switch(numberOperation)
   {
   case ADD:
      operation = ADD;
      calculatorBufor.push_back(" + ");
      historyOperation.push_back(" + ");
      break;
   case SUB:
      operation = SUB;
      calculatorBufor.push_back(" - ");
      historyOperation.push_back(" - ");
      break;
   case MULTI:
      operation = MULTI;
      calculatorBufor.push_back(" * ");
      historyOperation.push_back(" * ");
      break;
   case DIVI:
      operation = DIVI;
      calculatorBufor.push_back(" / ");
      historyOperation.push_back(" / ");
      break;
   case EXIT:
      exit(0);
      break;
   case HISTORY:
      void ShowHistoryOperation();
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

void calculator::showHistoryOperation()
{
    clearConsole();

    for(size_t i=0;i<historyOperation.size();i++)
    {
        if(i != 0  &&  i%5 == 0) std::cout<<'\n';
        std::cout<<historyOperation[i];
    }
    std::cout<<'\n';
    std::cout<<"Aby powrocic nacisnij dowolny przycisk..."<<std::endl;
}
