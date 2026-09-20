#include "../include/CompoundExpression.hpp"

#include <memory>
#include <stdexcept>

// Constructors - std::shared_ptr<Expression>

CompoundExpression::CompoundExpression(Connective connective,
                                       std::shared_ptr<Expression> left)
    : connective_(connective), left_(std::move(left)), right_(nullptr) {};

CompoundExpression::CompoundExpression(Connective connective,
                                       std::shared_ptr<Expression> left,
                                       std::shared_ptr<Expression> right)
    : connective_(connective), left_(std::move(left)),
      right_(std::move(right)) {};

// Clone

std::shared_ptr<Expression> CompoundExpression::clone() const {
  return std::make_shared<CompoundExpression>(*this);
}

// Mutators

[[nodiscard]] Connective &CompoundExpression::connective() noexcept {
  return connective_;
}

[[nodiscard]] std::shared_ptr<Expression> CompoundExpression::left() noexcept {
  return left_;
}

[[nodiscard]] std::shared_ptr<Expression> CompoundExpression::right() noexcept {
  return right_;
}

// Evaluate

[[nodiscard]] bool CompoundExpression::evaluate() const {
  switch (connective_) {
  case Connective::NEGATION: {
    return !left_->evaluate();
  }
  case Connective::CONJUNCTION: {
    return left_->evaluate() && right_->evaluate();
  }
  case Connective::DISJUNCTION: {
    return left_->evaluate() || right_->evaluate();
  }
  case Connective::IMPLICATION: {
    return !left_->evaluate() || right_->evaluate();
  }
  case Connective::CONVERSE: {
    return left_->evaluate() || !right_->evaluate();
  }
  case Connective::BICONDITIONAL: {
    bool leftEval = left_->evaluate(), rightEval = right_->evaluate();
    return (leftEval && rightEval) || (!leftEval && !rightEval);
  }
  default:
    throw std::runtime_error("Error: Invalid CompoundExpression");
  }
}
