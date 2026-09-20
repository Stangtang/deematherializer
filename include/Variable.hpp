#ifndef VARIABLE_HPP
#define VARIABLE_HPP

#include "Expression.hpp"
#include <string>

class Variable : public Expression {
private:
  std::string name_;
  bool value_;

public:
  // Constructors

  explicit Variable(std::string name, bool value);

  Variable(bool value);

  // Clone

  std::shared_ptr<Expression> clone() const override;

  // Mutators

  [[nodiscard]] std::string &name() noexcept;

  [[nodiscard]] bool &value() noexcept;

  // Evaluate

  [[nodiscard]] bool evaluate() const override;
};
#endif
