#ifndef _SMARTCALCV2_SRC_APP_MODEL_ADITIONAL_CLASES_VALIDATION_H_
#define _SMARTCALCV2_SRC_APP_MODEL_ADITIONAL_CLASES_VALIDATION_H_

#include <cmath>
#include <queue>
#include <stdexcept>

#include "token.h"

namespace s21 {

class Validation {
 public:
  Validation() = default;
  ~Validation() = default;

  std::queue<Token> Validate(std::queue<Token>& parsed);

 private:
  void ValidateFirstToken(std::queue<Token>& validated,
                          std::queue<Token>& parse);
  void ValidateOtherTokens(std::queue<Token>& validated,
                           std::queue<Token>& parse);
  void ValidateLastToken(std::queue<Token>& validated);

  void UnaryChangeType(std::queue<Token>& valid, std::queue<Token>& parsed);
  void AddMultiplication(std::queue<Token>& valid, std::queue<Token>& parsed);
  void ValidateSequense(std::queue<Token>& valid, std::queue<Token>& parsed);

  static constexpr bool validation_matrix_[kNumTokenTypes][kNumTokenTypes] = {
      {false, true, false, false, false, true},   // number
      {true, false, true, true, true, false},     // kBinaryOperation
      {true, false, false, false, true, false},   // eUnaryOperation
      {false, false, false, false, true, false},  // eUnaryFunction
      {true, false, true, true, true, false},     // eOpenBraket
      {false, true, false, false, false, true},   // eCloseBraket
  };
  static constexpr bool multiplication_matrix_[kNumTokenTypes][kNumTokenTypes] =
      {
          {true, false, false, true, true, false},     // number
          {false, false, false, false, false, false},  // kBinaryOperation
          {false, false, false, false, false, false},  // eUnaryOperation
          {false, false, false, false, false, false},  // eUnaryFunction
          {false, false, false, false, false, false},  // eOpenBraket
          {true, false, false, true, true, false}      // eCloseBraket
  };
  static constexpr bool first_token_[kNumTokenTypes] = {true, false, true,
                                                        true, true,  false};
  static constexpr bool last_token_[kNumTokenTypes] = {true,  false, false,
                                                       false, false, true};
};
}  // namespace s21
#endif  //_SMARTCALCV2_SRC_APP_MODEL_ADITIONAL_CLASES_VALIDATION_H_
