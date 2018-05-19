#include "car.h"
#include <string>
#include <iostream>
#include <boost/python.hpp>

Car::Car(std::string name, int speed) {
  m_name = name;
  m_speed = speed;
}

void Car::drive() {
  std::cout << "Driving " << m_name << " at " << m_speed << "mph" << std::endl;
}

void Car::increaseSpeed() {
  m_speed+=30;
}

BOOST_PYTHON_MODULE(car_ext)
{
  using namespace boost::python;

  class_<Car>("Car", init<std::string, int>())
    .def("drive",&Car::drive)
    .def("increaseSpeed",&Car::increaseSpeed);
}