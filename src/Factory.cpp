#include "..\include\Factory.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "..\include\Engineer.h"
#include "..\include\Manager.h"
#include "..\include\Personal.h"

Project* findProject(int projectID, std::vector<Project*>& projects) {
  Project* requiredProject = NULL;
  for (auto& project : projects) {
    if (project->getID() == projectID) {
      requiredProject = project;
      break;
    }
  }
  return requiredProject;
}

std::vector<Project*> StaffFactory::loadProjects() {
  std::ifstream FILE("../../bd/projects_info.txt");
  std::string line = "";
  if (!FILE.is_open()) {
    std::cout << "File projects_info.txt is not open" << std::endl;
    return {};
  }
  int id, budget, countOfEmployees;
  std::vector<Project*> projects;
  while (std::getline(FILE, line)) {
    std::istringstream lineStream(line);
    lineStream >> id >> budget >> countOfEmployees;
    Project* project = new Project(id, budget, countOfEmployees);
    projects.push_back(project);
  }
  return projects;
}

std::vector<Employee*> StaffFactory::loadStaff() {
  std::vector<Project*> projects = loadProjects();

  std::ifstream FILE("../../bd/staff_info.txt");
  std::string line = "";
  if (!FILE.is_open()) {
    std::cout << "File staff_info.txt is not open" << std::endl;
    return {};
  }

  std::vector<Employee*> staff;
  int id, workHours, salary, position, bonusFeature, projectID;
  bool isProjectCompleted;
  Project* project = NULL;
  std::string name, fName, sName, mName;

  while (std::getline(FILE, line)) {
    std::istringstream lineStream(line);
    lineStream >> id >> sName >> fName >> mName >> workHours;
    name = sName + ' ' + fName + ' ' + mName;
    lineStream >> position;
    Employee* newEmp = NULL;
    switch (position) {
      case cleaner:
        lineStream >> salary;
        newEmp = new Cleaner(id, name, workHours, salary);
        staff.push_back(newEmp);
        break;
      case driver:
        lineStream >> salary >> bonusFeature;
        newEmp = new Driver(id, name, workHours, salary, bonusFeature);
        staff.push_back(newEmp);
        break;
      case tester:
        lineStream >> salary >> projectID >> bonusFeature;
        project = findProject(projectID, projects);
        newEmp = new Tester(id, name, workHours, salary, project, bonusFeature);
        staff.push_back(newEmp);
        break;
      case programmer:
        lineStream >> salary >> projectID >> isProjectCompleted;
        project = findProject(projectID, projects);
        newEmp = new Programmer(id, name, workHours, salary, project,
                                isProjectCompleted);
        staff.push_back(newEmp);
        break;
      case project_manager:
        lineStream >> projectID;
        project = findProject(projectID, projects);
        staff.push_back(new ProjectManager(id, name, workHours, project));
        break;
      case senior_manager:
        lineStream >> projectID;
        project = findProject(projectID, projects);
        newEmp = new SeniorManager(id, name, workHours, project);

        while (lineStream >> projectID) {
          project = findProject(projectID, projects);
          ((SeniorManager*)newEmp)->addProject(project);
        }
        staff.push_back(newEmp);
        break;
      case team_leader:
        lineStream >> salary >> projectID >> isProjectCompleted >> bonusFeature;
        project = findProject(projectID, projects);
        newEmp = new TeamLeader(id, name, workHours, salary, project,
                                isProjectCompleted, bonusFeature);
        staff.push_back(newEmp);
        break;
      default:
        break;
    }
  }
  return staff;
}