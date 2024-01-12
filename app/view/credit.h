#ifndef _SMARTCALCV2_SRC_APP_VIEW_CREDIT_H_
#define _SMARTCALCV2_SRC_APP_VIEW_CREDIT_H_

#include <QCloseEvent>
#include <QMainWindow>

#include "../controller/creditcontroller.h"

namespace Ui {
class Credit;
}

class Credit : public QMainWindow {
  Q_OBJECT

 public:
  explicit Credit(s21::ControllerCredit *credit_controller,
                  QWidget *parent = nullptr);
  ~Credit();

 private:
  Ui::Credit *ui_;
  s21::ControllerCredit *credit_controller_;

 private slots:
  void Calc();
  void on_Back_clicked();
  virtual void closeEvent(QCloseEvent *event);

 signals:
  void signal_credit_();
};

#endif  // _SMARTCALCV2_SRC_APP_VIEW_CREDIT_H_
