#ifndef _SMARTCALCV2_SRC_APP_MODEL_ADITIONAL_CLASES_CONVERT_TO_POSTFIX_H_
#define _SMARTCALCV2_SRC_APP_MODEL_ADITIONAL_CLASES_CONVERT_TO_POSTFIX_H_

#include <queue>
#include <stack>
#include <stdexcept>

#include "token.h"

namespace s21 {

class ConvertToPostxix {
 public:
  ConvertToPostxix() = default;
  ~ConvertToPostxix() = default;

  std::queue<Token> ConvertToRpn(std::queue<Token>& validated);

 private:
  void ProcessCloseBracketToken(std::stack<Token>& operator_stack,
                                std::queue<Token>& rpn);
  void ProcessOperators(Token& token, std::stack<Token>& operator_stack,
                        std::queue<Token>& rpn);
  void PushOperatorsToRpn(std::stack<Token>& operator_stack,
                          std::queue<Token>& rpn);
};

}  // namespace s21

#endif  // _SMARTCALCV2_SRC_APP_MODEL_ADITIONAL_CLASES_CONVERT_TO_POSTFIX_H_