#include "token.h"

namespace s21 {

std::string Token::GetName() { return name_; }

FunctionType Token::GetType() { return type_; }

Percedence Token::GetPrecedence() { return percedence_; }
Associativity Token::GetAssociativity() { return associativity_; }

void Token::ChangeTypeToUnary() {
  type_ = kUnaryOperation;
  percedence_ = kUnaryMinus;
  associativity_ = kRight;
}

double Token::GetNumber() { return number_; }

}  // namespace s21