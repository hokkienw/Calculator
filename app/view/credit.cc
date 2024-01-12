#include "credit.h"

#include "ui_credit.h"

Credit::Credit(s21::ControllerCredit *credit_controller, QWidget *parent)
    : QMainWindow(parent),
      ui_(new Ui::Credit),
      credit_controller_(credit_controller) {
  ui_->setupUi(this);
  ui_->MonthPay->setText(QString::number(0));
  ui_->TotalPay->setText(QString::number(0));
  ui_->OverPay->setText(QString::number(0));
  connect(ui_->Calculate, SIGNAL(released()), this, SLOT(Calc()));
}

Credit::~Credit() { delete ui_; }

void Credit::Calc() {
  double rate = (ui_->Percent->value() / 100) / 12;
  double month = ui_->Month->value();
  double credit_sum = ui_->CreditSumm->value();
  Qt::CheckState curState = ui_->checkBox->checkState();
  if (curState == Qt::CheckState::Unchecked) {
    credit_controller_->CalculateCreditAn(credit_sum, month, rate);
  } else {
    credit_controller_->CalculateCreditDef(credit_sum, month, rate);
  }
  ui_->MonthPay->setText(
      QString::number(credit_controller_->GetMonthPayment()));
  ui_->TotalPay->setText(
      QString::number(credit_controller_->GetTotalPayment()));
  ui_->OverPay->setText(QString::number(credit_controller_->GetOverPay()));
}

void Credit::on_Back_clicked() { emit signal_credit_(); }

void Credit::closeEvent(QCloseEvent *event) {
  emit signal_credit_();
  event->accept();
}
