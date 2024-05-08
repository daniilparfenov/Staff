#include "../include/Employee.h"

Employee::Employee(int id, std::string name, int work_time, Positions position)
    : id(id), name(name), work_time(work_time), position(position) {}

void Employee::setWorkTime(int workTime) { this->work_time = workTime; }

int Employee::getID() const { return id; }

Project::Project(int id, int budget, int number_of_employees)
    : id(id), budget(budget), number_of_employees(number_of_employees) {}

int Project::get_budget() const { return budget; }

int Project::get_num_of_employees() const { return number_of_employees; }

int Project::getID() const { return id; }