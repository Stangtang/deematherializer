#include "./include/CompoundExpression.hpp"
#include "./include/Connective.hpp"
#include "./include/Variable.hpp"

#include <iostream>
#include <iomanip>
#include <memory>

int main() {
  std::cout << std::boolalpha;
  auto p = std::make_shared<Variable>("var1", true),
       q = std::make_shared<Variable>("var2", false);
  std::cout << "p->name() p->evaluate() = " << p->name() << ' ' << p->evaluate()
            << '\n';
  std::cout << "q->name() q->evaluate() = " << q->name() << ' ' << q->evaluate()
            << '\n';
  auto alpha =
      std::make_shared<CompoundExpression>(Connective::IMPLICATION, p, q);
  std::cout << "p implies q = " << alpha->evaluate() << '\n';
  q->value() = true;
  std::cout << "let q->value() = 1;\np implies q = " << alpha->evaluate()
            << '\n';
  return 0;
}
