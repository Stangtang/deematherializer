#include "../include/Variable.hpp"

#include <string>

// Constructors

Variable::Variable(std::string name, bool value) : name_(name), value_(value) {}

Variable::Variable(bool value) : name_(nullptr), value_(value) {}

// Clone

std::shared_ptr<Expression> Variable::clone() const {
  return std::make_shared<Variable>(*this);
}

// Mutators

[[nodiscard]] std::string &Variable::name() noexcept { return name_; }

[[nodiscard]] bool &Variable::value() noexcept { return value_; }

// Evaluate

[[nodiscard]] bool Variable::evaluate() const { return value_; }
