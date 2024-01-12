#ifndef _SMARTCALCV2_SRC_APP_MODEL_MODEL_H_
#define _SMARTCALCV2_SRC_APP_MODEL_MODEL_H_

#include <cctype>
#include <cmath>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <memory>
#include <queue>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "aditional_clases/convert_to_postfix.h"
#include "aditional_clases/parse.h"
#include "aditional_clases/validation.h"

namespace s21 {

class StandCalcModel {
 public:
  StandCalcModel();

  void Calculate(std::string& s, double& x_value);
  std::string GetAnswer();
  void CalculateGraph(std::string& s, double& x_range, double& y_range,
                      bool& error);
  std::pair<std::vector<double>, std::vector<double> > GetGraph();
  std::string GetRPN(std::string& s, double& x_value);

 private:
  std::unique_ptr<Parse> parsed_;
  std::unique_ptr<Validation> validate_;
  std::unique_ptr<ConvertToPostxix> postfix_;
  std::string output_string_{};
  std::queue<Token> postfix_queue_{};
  std::pair<std::vector<double>, std::vector<double> > graph_{};

  void EvaluateBinaryToken(Token& token, std::stack<double>& valueStack);
  void EvaluateUnaryToken(Token& token, std::stack<double>& valueStack);
  double EvaluateRpnExpression();

  double PerformBinaryOperation(double operand1, double operand2, Token& token);
  double PerformUnaryOperation(double operand, Token& token);

  void MakeRPN(std::string& s, double& x_value);

  void AllClear();
};
}  // namespace s21

#endif  // _SMARTCALCV2_SRC_APP_MODEL_MODEL_H_