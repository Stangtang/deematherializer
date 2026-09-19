#include "../include/Proposition.hpp"

#include <memory>
#include <stdexcept>

Proposition::Proposition(bool evaluation)
    : operation_(evaluation ? Operation::TRUE : Operation::FALSE),
      arg1_(nullptr), arg2_(nullptr) {};

Proposition::Proposition(Operation operation)
    : operation_(std::move(operation)), arg1_(nullptr), arg2_(nullptr) {};

Proposition::Proposition(Operation operation, std::shared_ptr<Proposition> arg1)
    : operation_(std::move(operation)), arg1_(std::move(arg1)),
      arg2_(nullptr) {};

Proposition::Proposition(Operation operation, std::shared_ptr<Proposition> arg1,
                         std::shared_ptr<Proposition> arg2)
    : operation_(std::move(operation)), arg1_(std::move(arg1)),
      arg2_(std::move(arg2)) {};

[[nodiscard]] Operation &Proposition::operation() noexcept {
  return operation_;
}

[[nodiscard]] bool Proposition::evaluate() const {
  switch (operation_) {
  case Operation::TRUE: {
    return true;
  }
  case Operation::FALSE: {
    return false;
  }
  case Operation::NEGATION: {
    return !arg1_.get()->evaluate();
  }
  case Operation::CONJUNCTION: {
    return arg1_.get()->evaluate() && arg2_.get()->evaluate();
  }
  case Operation::DISJUNCTION: {
    return arg1_.get()->evaluate() || arg2_.get()->evaluate();
  }
  case Operation::IMPLICATION: {
    return !arg1_.get()->evaluate() || arg2_.get()->evaluate();
  }
  default:
    throw std::runtime_error("Invalid Proposition");
  }
}
