#ifndef _SMARTCALCV2_SRC_APP_MODEL_DEBITMODEL_H_
#define _SMARTCALCV2_SRC_APP_MODEL_DEBITMODEL_H_

#include <cmath>
#include <stdexcept>

namespace s21 {
class CalcDebit {
 public:
  CalcDebit() {}

  struct input_param {
    double sum{};
    int term{};
    double percent{};
    double tax_percent{};
    int type_capital{};
    int type_pay{};
    double add_sum{};
  };

  struct output_param {
    double interest_income{};
    double total_sum{};
    double tax_sum{};
  };
  void DepositCalc(input_param in, output_param& out);
};
}  // namespace s21

#endif  // _SMARTCALCV2_SRC_APP_MODEL_DEBITTMODEL_H_