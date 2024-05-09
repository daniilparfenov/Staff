#include <iostream>

#include "..\include\Engineer.h"
#include "..\include\Manager.h"
#include "..\include\Personal.h"
using namespace std;

int main() {
  Driver me(1, "sa", 20, 200, 10);
  me.calc_salary();
  me.print_info();

  Cleaner she(2, "saaa", 10, 10);
  she.calc_salary();
  she.print_info();

  Project myPr(0, 1000, 3);
  Project* MyPrp = &myPr;

  Programmer proger(3, "Bob", 12, 10201, MyPrp, true);
  Tester testir(4, "Meme", 12, 1111, MyPrp, 22);

  proger.calc_salary();
  proger.print_info();
  testir.calc_salary();
  testir.print_info();

  TeamLeader John(5, "John", 12, 100000, MyPrp, true, 2);
  John.calc_salary();
  John.print_info();
  Project* projects = new Project[2];
  projects[0] = myPr;
  Project otherPr(2, 102101, 1);
  projects[1] = otherPr;
  SeniorManager senior(6, "SIR", 12, MyPrp);
  senior.addProject(&otherPr);
  senior.calc_salary();
  senior.print_info();
  ProjectManager manager(7, "pprman", 12, MyPrp);
  manager.calc_salary();

  manager.print_info();
  return 0;
}