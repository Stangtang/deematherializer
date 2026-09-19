#ifndef PROPOSITION_HPP
#define PROPOSITION_HPP

#include "Operation.hpp"
#include <memory>

class Proposition {
private:
  Operation operation_;
  std::shared_ptr<Proposition> arg1_;
  std::shared_ptr<Proposition> arg2_;

public:
  explicit Proposition(bool evaluation);

  explicit Proposition(Operation operation);

  explicit Proposition(Operation operation, std::shared_ptr<Proposition> arg1);

  explicit Proposition(Operation operation, std::shared_ptr<Proposition> arg1,
                       std::shared_ptr<Proposition> arg2);

  [[nodiscard]] Operation &operation() noexcept;

  [[nodiscard]] bool evaluate() const;
};

#endif
