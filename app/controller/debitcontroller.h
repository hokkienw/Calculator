#ifndef _SMARTCALCV2_SRC_APP_CONTROLLER_DEBITCONTROLLER_H_
#define _SMARTCALCV2_SRC_APP_CONTROLLER_DEBITCONTROLLER_H_
#include "../model/debitmodel.h"

namespace s21 {
class ControllerDebit {
 public:
  explicit ControllerDebit(CalcDebit *dm) : dmodel_(dm) {}
  void CalculateDebit(s21::CalcDebit::input_param in,
                      s21::CalcDebit::output_param &out);

 private:
  s21::CalcDebit *dmodel_;
};
}  // namespace s21
#endif  //_SMARTCALCV2_SRC_APP_CONTROLLER_DEBITCONTROLLER_H_