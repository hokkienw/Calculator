#ifndef _SMARTCALCV2_SRC_APP_MODEL_ADITIONAL_CLASES_TOKEN_H_
#define _SMARTCALCV2_SRC_APP_MODEL_ADITIONAL_CLASES_TOKEN_H_

#include <string>

#include "associativity.h"
#include "function_type.h"
#include "percedence.h"

namespace s21 {

class Token {
 public:
  Token() = default;
  Token(const std::string& name, double number, Percedence percedence,
        Associativity associativity, FunctionType type)
      : name_(name),
        number_(number),
        percedence_(percedence),
        associativity_(associativity),
        type_(type) {}
  ~Token() = default;

  std::string GetName();
  FunctionType GetType();
  Percedence GetPrecedence();
  Associativity GetAssociativity();
  double GetNumber();
  void ChangeTypeToUnary();

 private:
  std::string name_{};
  double number_{};
  Percedence percedence_{};
  Associativity associativity_{};
  FunctionType type_{};
};
}  // namespace s21

#endif  //_SMARTCALCV2_SRC_APP_MODEL_ADITIONAL_CLASES_TOKEN_H_