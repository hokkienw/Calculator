#ifndef _SMARTCALCV2_SRC_APP_CONTROLLER_CREDITCONTROLLER_H_
#define _SMARTCALCV2_SRC_APP_CONTROLLER_CREDITCONTROLLER_H_

#include "../model/creditmodel.h"

namespace s21 {

class ControllerCredit {
 public:
  explicit ControllerCredit(CalcCredit *cm) : cmodel_(cm) {}
  void CalculateCreditAn(double credit_sum, double month_value, double rate);
  void CalculateCreditDef(double credit_sum, double month_value, double rate);
  double GetMonthPayment();
  double GetOverPay();
  double GetTotalPayment();

 private:
  s21::CalcCredit *cmodel_;
};

}  // namespace s21

#endif  //_SMARTCALCV2_SRC_APP_CONTROLLER_CREDITCONTROLLER_H_