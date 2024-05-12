// Copyright 2024 by Parfenov Daniil
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>
#include <vector>

enum Positions {
  cleaner,
  driver,
  tester,
  programmer,
  senior_manager,
  project_manager,
  team_leader,
};
class Project {
 public:
  Project(int id, int budget, int number_of_employees);
  Project() = default;
  ~Project() = default;
  int get_num_of_employees() const;
  int get_budget() const;
  int getID() const;

 private:
  int id;
  int budget;
  int number_of_employees;
};
class Employee {
 public:
  Employee(int id, std::string name, int work_time, Positions position);
  virtual ~Employee() = default;
  virtual void calc_salary() = 0;
  virtual void print_info() = 0;
  void setWorkTime(int workTime);
  int getID() const;
  Positions getPosition() const;

 private:
  int id;

 protected:
  Positions position;
  int payment;
  int work_time;
  std::string name;
  std::vector<std::string> enum_print = {
      "cleaner",        "driver",          "tester",     "programmer",
      "senior_manager", "project_manager", "team_leader"};
};

#endif  // INCLUDE_EMPLOYEE_H_
