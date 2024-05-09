#include "..\include\Manager.h"

#include <iostream>

ProjectManager::ProjectManager(int id, std::string name, int work_time,
                               Project* startProject)
    : Employee(id, name, work_time, project_manager) {
  this->projectCount = 1;
  projects.push_back(startProject);
}

int ProjectManager::calc_Heads() {
  int res = 0;
  for (int i = 0; i < projectCount; i++) {
    res += projects[i]->get_num_of_employees() * 1000;
  }

  return res;
}

int ProjectManager::calc_budget_part() {
  int res = 0;
  for (int i = 0; i < projectCount; i++) {
    res += projects[i]->get_budget() / projects[i]->get_num_of_employees();
  }

  return res;
}

void ProjectManager::calc_salary() {
  payment = calc_budget_part() + calc_Heads();
}

void ProjectManager::print_info() {
  std::cout << "ID: " << getID() << std::endl;
  std::cout << "Name: " << name << std::endl;
  std::cout << "Position: " << enum_print[position] << std::endl;
  std::cout << "Work Time: " << work_time << std::endl;
  std::cout << "Payment: " << payment << std::endl;
  std::cout << "Count of projects: " << projectCount << std::endl;
  std::cout << "Projects: ";
  for (int i = 0; i < projectCount; i++) {
    std::cout << projects[i]->getID() << ' ';
  }
  std::cout << std::endl;
}

int ProjectManager::calc_pro_additions(int bonus) { return bonus; }

SeniorManager::SeniorManager(int id, std::string name, int work_time,
                             Project* startProject)
    : ProjectManager(id, name, work_time, startProject) {
  this->position = senior_manager;
}

void SeniorManager::addProject(Project* project) {
  projects.push_back(project);
  projectCount++;
}
