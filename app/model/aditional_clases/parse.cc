#include "parse.h"

namespace s21 {

void s21::Parse::ConvertToLowerCase(std::string &s) {
  std::transform(s.begin(), s.end(), s.begin(), ::tolower);
}

void s21::Parse::CreateTokenMap(double &x_value) {
  token_map_ = {
      {"x", Token("x", x_value, kDefault, kNone, kNumber)},
      {"(", Token("(", NAN, kDefault, kNone, kOpenBraket)},
      {")", Token(")", NAN, kDefault, kNone, kCloseBraket)},
      {"+", Token("+", NAN, kLow, kLeft, kBinaryOperation)},
      {"-", Token("-", NAN, kLow, kLeft, kBinaryOperation)},
      {"*", Token("*", NAN, kMedium, kLeft, kBinaryOperation)},
      {"/", Token("/", NAN, kMedium, kLeft, kBinaryOperation)},
      {"mod", Token("mod", NAN, kMedium, kLeft, kBinaryOperation)},
      {"^", Token("^", NAN, kHigh, kRight, kBinaryOperation)},
      {"sin", Token("sin", NAN, kFunction, kRight, kUnaryFunction)},
      {"cos", Token("cos", NAN, kFunction, kRight, kUnaryFunction)},
      {"tan", Token("tan", NAN, kFunction, kRight, kUnaryFunction)},
      {"acos", Token("acos", NAN, kFunction, kRight, kUnaryFunction)},
      {"asin", Token("asin", NAN, kFunction, kRight, kUnaryFunction)},
      {"atan", Token("atan", NAN, kFunction, kRight, kUnaryFunction)},
      {"sqrt", Token("sqrt", NAN, kFunction, kRight, kUnaryFunction)},
      {"ln", Token("ln", NAN, kFunction, kRight, kUnaryFunction)},
      {"log", Token("log", NAN, kFunction, kRight, kUnaryFunction)},
  };
}

std::queue<Token> s21::Parse::ParseExpression(std::string &s, double &x_value) {
  std::queue<Token> parsed_expretion{};

  CreateTokenMap(x_value);
  ConvertToLowerCase(s);

  std::regex tokenRegex(
      R"((\d+(\.\d+)?([eE][-+]?\d+)?)|([а-яА-Яa-zA-Z]+)|(.))");
  std::sregex_iterator it(s.begin(), s.end(), tokenRegex);
  std::sregex_iterator end{};
  while (it != end) {
    std::smatch match = *it;
    std::string token = match.str();
    if (token_map_.find(token) != token_map_.end()) {
      parsed_expretion.push(token_map_.find(token)->second);
    } else if (IsValidNumber(token)) {
      double num = std::stod(token);
      Token temp_number_token("number", num, kDefault, kNone, kNumber);
      parsed_expretion.push(temp_number_token);
    } else {
      throw std::runtime_error("Incorrect input");
    }
    ++it;
  }
  return parsed_expretion;
}

bool s21::Parse::IsValidNumber(const std::string &token) {
  return std::regex_match(token, std::regex(R"(^\d+(\.\d+)?([eE][-+]?\d+)?$)"));
}

}  // namespace s21