// Copyright 2024 by Parfenov Daniil
#include <ctime>
#include <iostream>

#include "Factory.h"

int main() {
  // Загрузка проектов и штаба сотрудников из файлов
  std::vector<Project*> projects = StaffFactory::loadProjects();
  std::vector<Employee*> staff = StaffFactory::loadStaff(projects);

  srand(time(NULL));
  // Присвоение отработанного времени
  for (auto& emp : staff) {
    emp->setWorkTime(std::rand() % 100 + 1);
  }
  // Вычисление заработной платы
  for (auto& emp : staff) {
    emp->calc_salary();
  }
  // Вывод данных о сотруднике
  for (auto& emp : staff) {
    emp->print_info();
    std::cout << "--------------------------------------------" << std::endl;
  }

  // Освобождение памяти
  StaffFactory::clearData(projects, staff);
  return 0;
}
