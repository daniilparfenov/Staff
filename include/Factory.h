// Copyright 2024 by Parfenov Daniil
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_
#include <vector>

#include "Employee.h"

class StaffFactory {
 public:
  static std::vector<Project*> loadProjects();
  static std::vector<Employee*> loadStaff(
      const std::vector<Project*>& projects);
  static void clearData(const std::vector<Project*>& projects,
                        const std::vector<Employee*>& staff);
  ~StaffFactory() = default;
};
#endif  // INCLUDE_FACTORY_H_
