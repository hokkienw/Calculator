#include "creditcontroller.h"

namespace s21 {

void ControllerCredit::CalculateCreditAn(double credit_sum, double month_value,
                                         double rate) {
  cmodel_->CalcCreditAnuitet(credit_sum, month_value, rate);
}

void ControllerCredit::CalculateCreditDef(double credit_sum, double month_value,
                                          double rate) {
  cmodel_->CalcCreditDef(credit_sum, month_value, rate);
}

double ControllerCredit::GetMonthPayment() {
  return cmodel_->GetMonthPayment();
}

double ControllerCredit::GetTotalPayment() {
  return cmodel_->GetTotalPayment();
}

double ControllerCredit::GetOverPay() { return cmodel_->GetOverPay(); }

}  // namespace s21