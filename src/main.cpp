#include <iostream>
#include "..\include\Personal.h"
#include "..\include\Engineer.h"
using namespace std;


int main()
{
  Driver me(1, "sa", 20, 200, 10);
  me.calc_salary();
  me.print_info();
  
  Cleaner she(2, "saaa", 10, 10);
  she.calc_salary();
  she.print_info();

  Project myPr(0, 1000, 2);
  Project* MyPrp = &myPr;

  Programmer proger(3, "Bob", 12, 10201, MyPrp, true);
  Tester testir(4, "Meme", 12, 1111, MyPrp, 22);

  proger.calc_salary();
  proger.print_info();
  testir.calc_salary();
  testir.print_info();

  return 0;
}