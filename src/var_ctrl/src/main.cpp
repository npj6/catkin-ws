#include "controller.cpp"
#include <iostream>

int main (void) {
  VAR_CTRL::Controller c;
  std::cout << c.get() << " es el numero magico" << std::endl;
  return 0;
}
