#include <vector>

#include "Employee.h"

class StaffFactory {
 private:
  static std::vector<Project*> loadProjects();

 public:
  static std::vector<Employee*> loadStaff();
  ~StaffFactory() = default;
};