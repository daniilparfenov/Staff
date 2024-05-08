#include <iostream>
#include "..\include\Personal.h"
using namespace std;


int main()
{
  Driver me(1, "sa", 20, 200, 10);
  me.calc_salary();
  me.print_info();
  
  Cleaner she(2, "saaa", 10, 10);
  she.calc_salary();
  she.print_info();
  return 0;
}