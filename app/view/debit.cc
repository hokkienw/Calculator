#include "debit.h"

#include "ui_debit.h"

Debit::Debit(s21::ControllerDebit *debit_controller, QWidget *parent)
    : QMainWindow(parent),
      ui_(new Ui::Debit),
      debit_controller_(debit_controller) {
  ui_->setupUi(this);
  ui_->lineEdit_replenish->hide();
}

Debit::~Debit() { delete ui_; }

QString Debit::PointPars(QString str) {
  if (str.size() > 0) {
    for (int i = 0; i < str.length(); i++) {
      if (str[i] == ',') {
        str[i] = '.';
      }
    }
  } else {
    str = "0";
  }
  return str;
}

void Debit::on_BoxReplenish_currentTextChanged(const QString &arg1) {
  if (arg1 == "Нет") {
    ui_->lineEdit_replenish->hide();
    ui_->lineEdit_replenish->setText("");
  } else {
    ui_->lineEdit_replenish->show();
  }
}

void Debit::on_Calculate_pressed() {
  s21::CalcDebit::input_param in;
  s21::CalcDebit::output_param out;
  in.sum = ui_->DebitSumm->text().toDouble();
  in.percent = PointPars(ui_->Percent->text()).toDouble();
  in.tax_percent = PointPars(ui_->KeyRate->text()).toDouble();
  in.term = ui_->Month_2->text().toInt();
  ui_->BoxCapitalization->currentText() == "Нет" ? in.type_capital = 1
                                                 : in.type_capital = 2;
  ui_->BoxPayout->currentText() == "Ежемесячно" ? in.type_pay = 1
                                                : in.type_pay = 2;
  in.add_sum = PointPars(ui_->lineEdit_replenish->text()).toDouble();

  if (in.sum < 0.01 || in.percent < 0 || in.percent > 100 ||
      in.tax_percent < 0 || in.tax_percent > 100 || in.term < 1 ||
      in.term > 600) {
    QMessageBox::about(this, "Error", "Please fill in correctly");
  } else {
    try {
      debit_controller_->CalculateDebit(in, out);
      if (out.interest_income >= 0 && out.total_sum >= 0) {
        ui_->MonthPay->setText(QString::number(out.total_sum, 'f', 2));
        ui_->Rate->setText(QString::number(out.interest_income, 'f', 2));
        ui_->Tax->setText(QString::number(out.tax_sum, 'f', 2));
      }
    } catch (...) {
      QMessageBox::about(this, "Error", "Please fill in correctly1");
    }
  }
}

void Debit::on_DebitSumm_editingFinished() {
  ui_->DebitSumm->setValidator(new QIntValidator(0, 2000000000, this));
  ui_->Month_2->setValidator(new QIntValidator(0, 2000000000, this));
  ui_->Percent->setValidator(new QDoubleValidator(0, 0, 5, this));
  ui_->KeyRate->setValidator(new QDoubleValidator(0, 0, 5, this));
  ui_->lineEdit_replenish->setValidator(
      new QDoubleValidator(-1000000000.0, 1000000000.0, 2, this));
}

void Debit::on_Back_clicked() { emit signal_debit_(); }

void Debit::closeEvent(QCloseEvent *event) {
  emit signal_debit_();
  event->accept();
}
