// Copyright 2024 by Parfenov Daniil
#include "..\include\Engineer.h"

Engineer::Engineer(int id, std::string name, int work_time, int salary,
                   Positions position, Project* project)
    : Personal(id, name, work_time, salary, position), project(project) {}

void Engineer::calc_salary() {
  payment = calc_base_salary(salary, work_time) + calc_budget_part();
}

int Engineer::calc_budget_part() {
  return project->get_budget() / project->get_num_of_employees();
}

void Engineer::print_info() {
  Personal::print_info();
  std::cout << "ID of project: " << project->getID() << std::endl;
}

Tester::Tester(int id, std::string name, int work_time, int salary,
               Project* project, int bugsCount)
    : Engineer(id, name, work_time, salary, tester, project),
      bugsCount(bugsCount) {}

int Tester::calc_pro_additions(int bonus) { return bonus * bugsCount; }

void Tester::calc_salary() {
  payment = calc_base_salary(salary, work_time) + calc_budget_part() +
            calc_pro_additions(1000);
}

void Tester::print_info() {
  Engineer::print_info();
  std::cout << "Count of found bugs: " << bugsCount << std::endl;
}

Programmer::Programmer(int id, std::string name, int work_time, int salary,
                       Project* project, bool isProjectCompleted,
                       Positions position)
    : Engineer(id, name, work_time, salary, position, project),
      isProjectCompleted(isProjectCompleted) {}

int Programmer::calc_pro_additions(int bonus) {
  if (isProjectCompleted) {
    return bonus * 10;
  }
  return 0;
}

void Programmer::calc_salary() {
  payment = calc_base_salary(salary, work_time) + calc_budget_part() +
            calc_pro_additions(salary / 2);
}

void Programmer::print_info() {
  Engineer::print_info();
  std::cout << "Project is already completed: ";
  if (isProjectCompleted) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
  std::cout << std::endl;
}

TeamLeader::TeamLeader(int id, std::string name, int work_time, int salary,
                       Project* project, bool isProjectCompleted,
                       int countOfSubordinates)
    : Programmer(id, name, work_time, salary, project, isProjectCompleted,
                 team_leader),
      countOfSubordinates(countOfSubordinates) {}

int TeamLeader::calc_Heads() { return countOfSubordinates * salary * 0.1; }

void TeamLeader::calc_salary() {
  payment =
      calc_base_salary(salary, work_time) + calc_budget_part() + calc_Heads();
}

void TeamLeader::print_info() {
  Programmer::print_info();
  std::cout << "Count of subordinates: " << countOfSubordinates << std::endl;
}
