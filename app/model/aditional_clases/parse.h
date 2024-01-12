#ifndef _SMARTCALCV2_SRC_APP_MODEL_ADITIONAL_CLASES_PARSE_H_
#define _SMARTCALCV2_SRC_APP_MODEL_ADITIONAL_CLASES_PARSE_H_

#include <cmath>
#include <map>
#include <queue>
#include <regex>
#include <stdexcept>

#include "token.h"

namespace s21 {
class Parse {
 public:
  Parse() = default;
  ~Parse() = default;
  std::queue<Token> ParseExpression(std::string &s, double &x_value);

 private:
  std::map<std::string, Token> token_map_{};

  void CreateTokenMap(double &x_value);
  bool IsValidNumber(const std::string &token);
  void ConvertToLowerCase(std::string &s);
};
}  // namespace s21

#endif  // _SMARTCALCV2_SRC_APP_MODEL_ADITIONAL_CLASES_PARSE_H_