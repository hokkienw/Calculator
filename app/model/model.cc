#include "model.h"

namespace s21 {

StandCalcModel::StandCalcModel() {
  parsed_ = std::make_unique<Parse>();
  validate_ = std::make_unique<Validation>();
  postfix_ = std::make_unique<ConvertToPostxix>();
}

std::string s21::StandCalcModel::GetAnswer() { return output_string_; }

std::pair<std::vector<double>, std::vector<double> >
s21::StandCalcModel::GetGraph() {
  return graph_;
}

void s21::StandCalcModel::Calculate(std::string& s, double& x_value) {
  try {
    std::ostringstream stream_obj{};
    MakeRPN(s, x_value);
    stream_obj << std::setprecision(7) << EvaluateRpnExpression();
    output_string_ = stream_obj.str();
  } catch (const std::exception& e) {
    std::string errorMessage = e.what();
    output_string_ = errorMessage;
    AllClear();
  }
}

void s21::StandCalcModel::CalculateGraph(std::string& s, double& x_range,
                                         double& y_range, bool& error) {
  try {
    double step_val = (x_range + y_range) / 10000;
    graph_ = {};
    for (auto i = -x_range; i < x_range; i += step_val) {
      MakeRPN(s, i);
      double result = EvaluateRpnExpression();
      if (fabs(result) > y_range) {
        graph_.first.push_back(i);
        graph_.second.push_back(NAN);
      } else {
        graph_.first.push_back(i);
        graph_.second.push_back(result);
      }
    }
  } catch (...) {
    AllClear();
    error = true;
  }
}

void s21::StandCalcModel::MakeRPN(std::string& s, double& x_value) {
  if (s.empty()) {
    throw std::runtime_error("Empty String");
  }
  auto first_validated = parsed_->ParseExpression(s, x_value);
  auto validated = validate_->Validate(first_validated);
  postfix_queue_ = postfix_->ConvertToRpn(validated);
}

double StandCalcModel::PerformBinaryOperation(double operand1, double operand2,
                                              Token& token) {
  if (token.GetName() == "+") {
    return operand1 + operand2;
  } else if (token.GetName() == "-") {
    return operand1 - operand2;
  } else if (token.GetName() == "*") {
    return operand1 * operand2;
  } else if (token.GetName() == "/") {
    return operand1 / operand2;
  } else if (token.GetName() == "^") {
    return std::pow(operand1, operand2);
  } else {
    return std::fmod(operand1, operand2);
  }
}

double StandCalcModel::PerformUnaryOperation(double operand, Token& token) {
  if (token.GetName() == "-") {
    return -operand;
  } else if (token.GetName() == "+") {
    return operand;
  } else if (token.GetName() == "sin") {
    return std::sin(operand);
  } else if (token.GetName() == "cos") {
    return std::cos(operand);
  } else if (token.GetName() == "tan") {
    return std::tan(operand);
  } else if (token.GetName() == "acos") {
    return std::acos(operand);
  } else if (token.GetName() == "asin") {
    return std::asin(operand);
  } else if (token.GetName() == "atan") {
    return std::atan(operand);
  } else if (token.GetName() == "sqrt") {
    return std::sqrt(operand);
  } else if (token.GetName() == "ln") {
    return std::log(operand);
  } else {
    return std::log10(operand);
  }
}

double StandCalcModel::EvaluateRpnExpression() {
  std::stack<double> value_stack{};
  while (!postfix_queue_.empty()) {
    Token token = postfix_queue_.front();
    postfix_queue_.pop();
    if (token.GetType() == kNumber) {
      value_stack.push(token.GetNumber());
    } else if (token.GetType() == kUnaryFunction ||
               token.GetType() == kUnaryOperation) {
      EvaluateUnaryToken(token, value_stack);
    } else if (token.GetType() == kBinaryOperation) {
      EvaluateBinaryToken(token, value_stack);
    }
  }
  return value_stack.top();
}

void StandCalcModel::EvaluateBinaryToken(Token& token,
                                         std::stack<double>& value_stack) {
  double operand2 = value_stack.top();
  value_stack.pop();
  double operand1 = value_stack.top();
  value_stack.pop();
  double result = PerformBinaryOperation(operand1, operand2, token);
  value_stack.push(result);
}

void StandCalcModel::EvaluateUnaryToken(Token& token,
                                        std::stack<double>& value_stack) {
  double operand = value_stack.top();
  value_stack.pop();
  double result = PerformUnaryOperation(operand, token);
  value_stack.push(result);
}

void s21::StandCalcModel::AllClear() {
  postfix_queue_ = {};
  graph_ = {};
}

std::string s21::StandCalcModel::GetRPN(std::string& s, double& x_value) {
  try {
    output_string_.clear();
    MakeRPN(s, x_value);
    while (!postfix_queue_.empty()) {
      Token token = postfix_queue_.front();
      postfix_queue_.pop();
      if (token.GetType() == kNumber) {
        std::ostringstream stream_obj{};
        stream_obj << std::setprecision(7) << token.GetNumber();
        output_string_ += stream_obj.str();
        output_string_ += " ";
      } else {
        output_string_ += token.GetName();
        output_string_ += " ";
      }
    }
  } catch (const std::exception& e) {
    std::string errorMessage = e.what();
    output_string_ = errorMessage;
    AllClear();
  }
  return output_string_;
}

}  // namespace s21
