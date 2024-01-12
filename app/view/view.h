#ifndef _SMARTCALCV2_SRC_APP_VIEW_VIEW_H_
#define _SMARTCALCV2_SRC_APP_VIEW_VIEW_H_

#include <QMainWindow>

#include "../controller/controller.h"
#include "credit.h"
#include "debit.h"
#include "plotview.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE

class View : public QMainWindow {
  Q_OBJECT

 public:
  explicit View(s21::Controller *controller,
                s21::ControllerCredit *credit_controller,
                s21::ControllerDebit *debit_controller, QWidget *parent = 0);
  ~View();

 public slots:
  void ShowHideCredit();
  void ShowHideDebit();
  void ShowHidePlot();

 private:
  Ui::View *ui_;
  s21::Controller *controller_;
  PlotView *plot_;
  Credit *credit_view_;
  Debit *debit_view_;

 private slots:
  void NumPressed();
  void MathButtonPressed();
  void EqualButtonPressed();
  void ClearButtonPressed();
  void ClearCButtonPressed();
  void CreditOpen();
  void DebitOpen();
  void ConnectButtons();
  void on_Plot_clicked();
  void on_RPN_clicked();
};
#endif  // _SMARTCALCV2_SRC_APP_VIEW_VIEW_H_
