#ifndef _SMARTCALCV2_SRC_APP_MODEL_CREDITMODEL_H_
#define _SMARTCALCV2_SRC_APP_MODEL_CREDITMODEL_H_

#include <cmath>

namespace s21 {

class CalcCredit {
 public:
  CalcCredit() = default;
  void CalcCreditAnuitet(double credit_sum, double month_value, double rate);
  void CalcCreditDef(double credit_sum, double month_value, double rate);
  double GetMonthPayment();
  double GetTotalPayment();
  double GetOverPay();

 private:
  double month_paiment_{};
  double total_payment_{};
  double over_pay_{};
};
}  // namespace s21

#endif  // _SMARTCALCV2_SRC_APP_MODEL_CREDITMODEL_H_
