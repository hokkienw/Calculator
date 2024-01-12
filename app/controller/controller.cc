#include "controller.h"

namespace s21 {
std::string Controller::Calculate(std::string &input_str, double &x_value) {
  model_->Calculate(input_str, x_value);
  return model_->GetAnswer();
}

std::string Controller::GetRpnString(std::string &input_str, double &x_value) {
  return model_->GetRPN(input_str, x_value);
}

std::pair<std::vector<double>, std::vector<double>> s21::Controller::GraphCalc(
    std::string &input_str, double &x_range, double &y_range, bool &error) {
  model_->CalculateGraph(input_str, x_range, y_range, error);
  return model_->GetGraph();
}

}  // namespace s21
