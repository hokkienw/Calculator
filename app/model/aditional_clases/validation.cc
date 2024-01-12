#include "validation.h"

namespace s21 {

std::queue<Token> Validation::Validate(std::queue<Token>& parsed) {
  std::queue<Token> validated{};
  ValidateFirstToken(validated, parsed);
  ValidateOtherTokens(validated, parsed);
  ValidateLastToken(validated);
  return validated;
}

void Validation::ValidateFirstToken(std::queue<Token>& valid,
                                    std::queue<Token>& parsed) {
  if (parsed.front().GetName() == "+" || parsed.front().GetName() == "-") {
    parsed.front().ChangeTypeToUnary();
  }
  if (!first_token_[parsed.front().GetType()]) {
    throw std::runtime_error("Wrong Beginning");
  } else {
    valid.push(parsed.front());
    parsed.pop();
  }
}

void Validation::ValidateOtherTokens(std::queue<Token>& valid,
                                     std::queue<Token>& parsed) {
  while (!parsed.empty()) {
    UnaryChangeType(valid, parsed);
    AddMultiplication(valid, parsed);
    ValidateSequense(valid, parsed);
    valid.push(parsed.front());
    parsed.pop();
  }
}

void Validation::UnaryChangeType(std::queue<Token>& valid,
                                 std::queue<Token>& parsed) {
  if ((parsed.front().GetName() == "+" || parsed.front().GetName() == "-") &&
      !((valid.back().GetType() == kNumber ||
         valid.back().GetType() == kCloseBraket))) {
    parsed.front().ChangeTypeToUnary();
  }
}

void Validation::AddMultiplication(std::queue<Token>& valid,
                                   std::queue<Token>& parsed) {
  if (multiplication_matrix_[valid.back().GetType()]
                            [parsed.front().GetType()]) {
    valid.push(Token("*", NAN, kMedium, kLeft, kBinaryOperation));
  }
}

void Validation::ValidateSequense(std::queue<Token>& valid,
                                  std::queue<Token>& parsed) {
  if (!validation_matrix_[valid.back().GetType()][parsed.front().GetType()]) {
    throw std::runtime_error("Wrong Sequence");
  }
}

void Validation::ValidateLastToken(std::queue<Token>& valid) {
  if (!last_token_[valid.back().GetType()]) {
    throw std::runtime_error("Wrong Ending");
  }
}
}  // namespace s21