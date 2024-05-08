#include "..\include\Personal.h"

Personal::Personal(int id, std::string name, int workTime, int salary,
                   Positions position)
    : Employee(id, name, workTime, position), salary(salary){};

int Personal::calc_base_salary(int salary, int work_time_salary) {
  return salary * work_time_salary;
}

int Personal::calc_bonus_salary(int bonus) { return bonus; }

void Personal::print_info() {
  std::cout << "ID: " << getID() << std::endl;
  std::cout << "Name: " << name << std::endl;
  std::cout << "Position: " << enum_print[position] << std::endl;
  std::cout << "Work Time: " << work_time << std::endl;
  std::cout << "Salary: " << salary << std::endl;
  std::cout << "Payment: " << payment << std::endl;
}

Cleaner::Cleaner(int id, std::string name, int work_time, int salary)
    : Personal(id, name, work_time, salary, cleaner) {}

void Cleaner::calc_salary() { payment = calc_base_salary(salary, work_time); }

Driver::Driver(int id, std::string name, int work_time, int salary,
               int nightHours)
    : Personal(id, name, work_time, salary, driver), nightHours(nightHours) {}

int Driver::calc_bonus_salary(int bonus) { return bonus * nightHours; }

void Driver::calc_salary() {
  payment = calc_base_salary(salary, work_time) + calc_bonus_salary(salary / 2);
}

void Driver::print_info() {
  Personal::print_info();
  std::cout << "Night hours: " << nightHours << std::endl;
}