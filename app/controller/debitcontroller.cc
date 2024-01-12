#include "debitcontroller.h"

namespace s21 {

void ControllerDebit::CalculateDebit(s21::CalcDebit::input_param in,
                                     s21::CalcDebit::output_param &out) {
  dmodel_->DepositCalc(in, out);
}
}  // namespace s21