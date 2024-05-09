#include "Employee.h"
#include "Interfaces.h"
#include "Personal.h"

class Engineer : public Personal, public Project_Budget {
 protected:
  Project* project;

 public:
  Engineer(int id, std::string name, int work_time, int salary,
           Positions position, Project* project);
  virtual ~Engineer() = default;
  int calc_budget_part() override;
  void calc_salary() override;
  void print_info() override;
};

class Tester : public Engineer {
 private:
  int bugsCount;

 public:
  Tester(int id, std::string name, int work_time, int salary, Project* project,
         int bugsCount);
  ~Tester() = default;
  int calc_pro_additions(int bonus) override;
  void calc_salary() override;
  void print_info() override;
};

class Programmer : public Engineer {
 private:
  bool isProjectCompleted = false;

 public:
  Programmer(int id, std::string name, int work_time, int salary,
             Project* project, bool isProjectCompleted,
             Positions position = programmer);
  ~Programmer() = default;
  int calc_pro_additions(int bonus) override;
  void calc_salary() override;
  void print_info() override;
};

class TeamLeader : public Programmer, public Heading {
 private:
  int countOfSubordinates;

 public:
  TeamLeader(int id, std::string name, int work_time, int salary,
             Project* project, bool isProjectCompleted, int countOfSubordinates);
  ~TeamLeader() = default;
  int calc_Heads() override;
  void calc_salary() override;
  void print_info() override;
};
