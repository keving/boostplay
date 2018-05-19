#ifndef Carproj_CAR_H
#define Carproj_CAR_H
#include <string>

class Car {
 public:
  Car() {};
  Car(std::string name, int speed);

  void drive();
  void increaseSpeed();

 private:
  std::string m_name;
  int m_speed;
};

#endif  // Carproj_CAR_H