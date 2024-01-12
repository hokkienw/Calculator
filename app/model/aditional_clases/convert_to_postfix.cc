#include "convert_to_postfix.h"

namespace s21 {

std::queue<Token> ConvertToPostxix::ConvertToRpn(std::queue<Token>& validated) {
  std::queue<Token> rpn{};
  std::stack<Token> operator_stack{};
  while (!validated.empty()) {
    Token token = validated.front();
    validated.pop();
    if (token.GetType() == kNumber) {
      rpn.push(token);
    } else if (token.GetType() == kOpenBraket) {
      operator_stack.push(token);
    } else if (token.GetType() == kCloseBraket) {
      ProcessCloseBracketToken(operator_stack, rpn);
    } else if (token.GetType() == kUnaryFunction ||
               token.GetType() == kUnaryOperation ||
               token.GetType() == kBinaryOperation) {
      ProcessOperators(token, operator_stack, rpn);
    }
  }
  PushOperatorsToRpn(operator_stack, rpn);
  return rpn;
}

void ConvertToPostxix::ProcessCloseBracketToken(
    std::stack<Token>& operator_stack, std::queue<Token>& rpn) {
  while (!operator_stack.empty() &&
         operator_stack.top().GetType() != kOpenBraket) {
    rpn.push(operator_stack.top());
    operator_stack.pop();
  }
  if (operator_stack.empty()) {
    throw std::runtime_error("Mismatched brackets");
  }
  operator_stack.pop();
}

void ConvertToPostxix::ProcessOperators(Token& token,
                                        std::stack<Token>& operator_stack,
                                        std::queue<Token>& rpn) {
  while (!operator_stack.empty() &&
         ((operator_stack.top().GetType() == kUnaryFunction ||
           operator_stack.top().GetType() == kUnaryOperation) ||
          (operator_stack.top().GetType() == kBinaryOperation &&
           (operator_stack.top().GetPrecedence() > token.GetPrecedence() ||
            (operator_stack.top().GetPrecedence() == token.GetPrecedence() &&
             operator_stack.top().GetAssociativity() == kLeft)) &&
           operator_stack.top().GetType() != kUnaryOperation))) {
    rpn.push(operator_stack.top());
    operator_stack.pop();
  }
  operator_stack.push(token);
}

void ConvertToPostxix::PushOperatorsToRpn(std::stack<Token>& operator_stack,
                                          std::queue<Token>& rpn) {
  while (!operator_stack.empty()) {
    if (operator_stack.top().GetType() == kOpenBraket ||
        operator_stack.top().GetType() == kCloseBraket) {
      throw std::runtime_error("Mismatched brackets");
    }
    rpn.push(operator_stack.top());
    operator_stack.pop();
  }
}

}  // namespace s21
