#include <vector>

#include "Employee.h"

class StaffFactory {
 public:
  std::vector<Project*> loadProjects();
  std::vector<Employee*> loadStaff();
  ~StaffFactory() = default;
};