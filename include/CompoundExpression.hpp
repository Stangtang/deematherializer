#ifndef COMPOUNDEXPRESSION_HPP
#define COMPOUNDEXPRESSION_HPP

#include "Connective.hpp"
#include "Expression.hpp"
#include <memory>

class CompoundExpression : public Expression {
private:
  Connective connective_;
  std::shared_ptr<Expression> left_;
  std::shared_ptr<Expression> right_;

public:
  // Constructors - std::shared_ptr<Expression>

  explicit CompoundExpression(Connective connective,
                              std::shared_ptr<Expression> left);

  explicit CompoundExpression(Connective connective,
                              std::shared_ptr<Expression> left,
                              std::shared_ptr<Expression> right);

  // Clone

  std::shared_ptr<Expression> clone() const override;

  // Mutators

  [[nodiscard]] Connective &connective() noexcept;

  [[nodiscard]] std::shared_ptr<Expression> left() noexcept;

  [[nodiscard]] std::shared_ptr<Expression> right() noexcept;

  // Evaluate

  [[nodiscard]] bool evaluate() const override;

  // Parse Operand

  // [[nodiscard]] static Connective parseOperand(char c);
};

#endif
