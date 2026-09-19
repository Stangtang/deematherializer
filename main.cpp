#include "./include/Operation.hpp"
#include "./src/Proposition.cpp"

#include <iostream>
#include <memory>

int main() {
  auto p = std::make_shared<Proposition>(true);
  auto q = std::make_shared<Proposition>(false);
  auto alpha = std::make_shared<Proposition>(Operation::IMPLICATION, p, q);
  std::cout << "alpha->evaluate: " << alpha->evaluate() << '\n';
  q.get()->operation() = Operation::TRUE;
  std::cout << "alpha->evaluate: " << alpha->evaluate() << '\n';
  q = std::make_shared<Proposition>(false);
  std::cout << "alpha->evaluate: " << alpha->evaluate() << '\n';
  return 0;
}
