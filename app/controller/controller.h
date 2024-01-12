#ifndef _SMARTCALCV2_SRC_APP_CONTROLLER_CONTROLLER_H_
#define _SMARTCALCV2_SRC_APP_CONTROLLER_CONTROLLER_H_

#include "../model/model.h"

namespace s21 {
class Controller {
 public:
  explicit Controller(StandCalcModel *m) : model_(m) {}
  std::string Calculate(std::string &input_str, double &x_value);
  std::pair<std::vector<double>, std::vector<double> > GraphCalc(
      std::string &input_str, double &x_range, double &y_range, bool &error);
  std::string GetRpnString(std::string &input_str, double &x_value);

 private:
  s21::StandCalcModel *model_;
};

}  // namespace s21
#endif  // _SMARTCALCV2_SRC_APP_CONTROLLER_CONTROLLER_H_