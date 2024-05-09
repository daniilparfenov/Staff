#include <vector>

#include "Employee.h"
#include "Interfaces.h"

class ProjectManager : public Employee, public Heading, public Project_Budget {
 protected:
  std::vector<Project*> projects;
  int projectCount;

 public:
  ProjectManager(int id, std::string name, int work_time,
                 Project* startProject);
  ~ProjectManager() = default;
  int calc_budget_part() override;
  int calc_Heads() override;
  void calc_salary() override;
  void print_info() override;
  int calc_pro_additions(int bonus) override;
};

class SeniorManager : public ProjectManager {
 public:
  SeniorManager(int id, std::string name, int work_time, Project* startProject);
  void addProject(Project* project);
  ~SeniorManager() = default;
};