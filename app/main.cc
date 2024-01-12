#include <QApplication>

#include "view/view.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::StandCalcModel model;
  s21::Controller controller(&model);
  s21::CalcCredit cmodel;
  s21::ControllerCredit credit_controller(&cmodel);
  s21::CalcDebit dmodel;
  s21::ControllerDebit debit_controller(&dmodel);
  View w(&controller, &credit_controller, &debit_controller);
  w.show();
  w.setWindowTitle("SmartCalc_v2.0");
  w.setFixedSize(561, 401);
  return a.exec();
}