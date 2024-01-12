#ifndef _SMARTCALCV2_SRC_APP_VIEW_DEBIT_H_
#define _SMARTCALCV2_SRC_APP_VIEW_DEBIT_H_

#include <QCloseEvent>
#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <QWidget>
#include <cmath>
#include <vector>

#include "../controller/debitcontroller.h"

namespace Ui {
class Debit;
}

class Debit : public QMainWindow {
  Q_OBJECT

 public:
  explicit Debit(s21::ControllerDebit *debit_controller,
                 QWidget *parent = nullptr);
  ~Debit();

 private:
  Ui::Debit *ui_;
  s21::ControllerDebit *debit_controller_;

 private slots:
  void on_BoxReplenish_currentTextChanged(const QString &arg1);
  QString PointPars(QString str);
  void on_Calculate_pressed();
  void on_DebitSumm_editingFinished();
  void on_Back_clicked();
  virtual void closeEvent(QCloseEvent *event);

 signals:
  void signal_debit_();
};

#endif  // _SMARTCALCV2_SRC_APP_VIEW_DEBIT_H_
