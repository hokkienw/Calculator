#include "debitmodel.h"

namespace s21 {

void CalcDebit::DepositCalc(input_param in, output_param& out) {
  if ((in.type_capital == 2) || (in.type_capital == 1 && in.type_pay == 1)) {
    out.interest_income = 0;
    for (int i = 0; i < in.term; i++) {
      in.sum = in.sum + in.add_sum;
      if (in.sum < 0) {
        throw "not enouth money";
      }
      double monthly_percent = in.sum * in.percent / 1200;
      out.interest_income = out.interest_income + monthly_percent;
      if (in.type_pay == 2) {
        in.sum = in.sum + monthly_percent;
      }
    }
    out.interest_income = std::round(out.interest_income * 100) / 100.0;
    out.total_sum = std::round((in.sum + out.interest_income) * 100) / 100.0;
    out.tax_sum =
        std::round((out.interest_income * in.tax_percent / 100) * 100) / 100.0;
  } else if (in.type_capital == 1 && in.type_pay == 2) {
    out.interest_income = 0;
    double monthly_percent = 0;
    for (int i = 0; i < in.term; i++) {
      in.sum = in.sum + in.add_sum + monthly_percent;
      if (in.sum < 0) {
        throw "not enouth money";
      }
      monthly_percent = in.sum * in.percent / 1200;
      out.interest_income = out.interest_income + monthly_percent;
    }
    out.interest_income = std::round(out.interest_income * 100) / 100.0;
    out.total_sum = std::round((in.sum + monthly_percent) * 100) / 100.0;
    out.tax_sum =
        std::round((out.interest_income * in.tax_percent / 100) * 100) / 100.0;
    ;
  }
}
}  // namespace s21