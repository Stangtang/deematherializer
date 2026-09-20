#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include <memory>

class Expression {
public:
  virtual ~Expression() = default;

  virtual std::shared_ptr<Expression> clone() const = 0;

  [[nodiscard]] virtual bool evaluate() const = 0;
};

#endif
