#include "creditmodel.h"

namespace s21 {

void CalcCredit::CalcCreditAnuitet(double credit_sum, double month_value,
                                   double rate) {
  month_paiment_ = (credit_sum * rate * pow((1 + rate), month_value) /
                    (pow((1 + rate), month_value) - 1));
  total_payment_ = month_paiment_ * month_value;
  over_pay_ = total_payment_ - credit_sum;
}

void CalcCredit::CalcCreditDef(double credit_sum, double month_value,
                               double rate) {
  double const_payment_mounth = credit_sum / month_value;
  double credit_balance = credit_sum;
  month_paiment_ = 0;
  total_payment_ = 0;
  do {
    month_paiment_ = (const_payment_mounth + credit_balance * rate);
    total_payment_ += month_paiment_;
    credit_balance = credit_balance - const_payment_mounth;
  } while (fabs(credit_balance) > 1e-2);
  over_pay_ = total_payment_ - credit_sum;
}

double CalcCredit::GetMonthPayment() { return month_paiment_; }
double CalcCredit::GetTotalPayment() { return total_payment_; }
double CalcCredit::GetOverPay() { return over_pay_; }

}  // namespace s21
