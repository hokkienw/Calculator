#include "view.h"

#include "ui_view.h"

View::View(s21::Controller *controller,
           s21::ControllerCredit *credit_controller,
           s21::ControllerDebit *debit_controller, QWidget *parent)
    : QMainWindow(parent), ui_(new Ui::View), controller_(controller) {
  ui_->setupUi(this);

  QPushButton *numButtons[10];
  for (int i = 0; i < 10; ++i) {
    QString butName = "Button" + QString::number(i);
    numButtons[i] = View::findChild<QPushButton *>(butName);
    connect(numButtons[i], SIGNAL(released()), this, SLOT(NumPressed()));
  }
  ConnectButtons();

  credit_view_ = new Credit(credit_controller, this);
  connect(credit_view_, &Credit::signal_credit_, this, &View::ShowHideCredit);

  debit_view_ = new Debit(debit_controller, this);
  connect(debit_view_, &Debit::signal_debit_, this, &View::ShowHideDebit);

  plot_ = new PlotView(this);
  connect(plot_, &PlotView::signal_plot_, this, &View::ShowHidePlot);
}

View::~View() {
  delete ui_;
  delete credit_view_;
  delete debit_view_;
  delete plot_;
}

void View::NumPressed() {
  QPushButton *button = (QPushButton *)sender();
  QString but_val = button->text();
  QString display_val = ui_->Display->text();
  QString new_val = display_val + but_val;
  ui_->Display->setText(new_val);
}

void View::MathButtonPressed() {
  QString display_val = ui_->Display->text();
  QPushButton *button = (QPushButton *)sender();
  QString but_val = button->text();
  QString new_val = display_val + but_val + "(";
  ui_->Display->setText(new_val);
}

void View::ClearButtonPressed() { ui_->Display->setText(""); }
void View::ClearCButtonPressed() { ui_->Display->backspace(); }

void View::EqualButtonPressed() {
  std::string input = ui_->Display->text().toStdString();
  double x_val = ui_->buttonXVal->value();
  ui_->Display->setText(
      QString::fromUtf8(controller_->Calculate(input, x_val)));
}

void View::on_Plot_clicked() {
  bool error = false;
  std::string input = ui_->Display->text().toStdString();
  double max_x = ui_->buttonXMax->value();
  double max_y = ui_->buttonYMax->value();
  plot_->PlotGraph(controller_->GraphCalc(input, max_x, max_y, error), max_x,
                   max_y);
  if (!error) {
    plot_->show();
    plot_->setFixedSize(561, 401);
    this->hide();
  } else {
    ui_->Display->setText("Wrong Input");
  }
}

void View::on_RPN_clicked() {
  std::string input = ui_->Display->text().toStdString();
  double x_val = ui_->buttonXVal->value();
  ui_->Display->setText(
      QString::fromUtf8(controller_->GetRpnString(input, x_val)));
}

void View::CreditOpen() {
  this->hide();
  credit_view_->show();
  credit_view_->setWindowTitle("CreditCalculator");
  credit_view_->setFixedSize(561, 401);
}

void View::ShowHideCredit() {
  this->show();
  credit_view_->hide();
}

void View::DebitOpen() {
  this->hide();
  debit_view_->show();
  debit_view_->setWindowTitle("DebitCalculator");
  debit_view_->setFixedSize(561, 401);
}

void View::ShowHideDebit() {
  this->show();
  debit_view_->hide();
}

void View::ShowHidePlot() {
  this->show();
  plot_->hide();
}

void View::ConnectButtons() {
  connect(ui_->add, SIGNAL(released()), this, SLOT(NumPressed()));
  connect(ui_->div, SIGNAL(released()), this, SLOT(NumPressed()));
  connect(ui_->sub, SIGNAL(released()), this, SLOT(NumPressed()));
  connect(ui_->mul, SIGNAL(released()), this, SLOT(NumPressed()));
  connect(ui_->dot, SIGNAL(released()), this, SLOT(NumPressed()));
  connect(ui_->mod, SIGNAL(released()), this, SLOT(NumPressed()));
  connect(ui_->pow, SIGNAL(released()), this, SLOT(NumPressed()));
  connect(ui_->breket_l, SIGNAL(released()), this, SLOT(NumPressed()));
  connect(ui_->breket_r, SIGNAL(released()), this, SLOT(NumPressed()));
  connect(ui_->x, SIGNAL(released()), this, SLOT(NumPressed()));

  connect(ui_->sqrt, SIGNAL(released()), this, SLOT(MathButtonPressed()));
  connect(ui_->ln, SIGNAL(released()), this, SLOT(MathButtonPressed()));
  connect(ui_->log, SIGNAL(released()), this, SLOT(MathButtonPressed()));
  connect(ui_->sin, SIGNAL(released()), this, SLOT(MathButtonPressed()));
  connect(ui_->cos, SIGNAL(released()), this, SLOT(MathButtonPressed()));
  connect(ui_->tan, SIGNAL(released()), this, SLOT(MathButtonPressed()));
  connect(ui_->atan, SIGNAL(released()), this, SLOT(MathButtonPressed()));
  connect(ui_->asin, SIGNAL(released()), this, SLOT(MathButtonPressed()));
  connect(ui_->acos, SIGNAL(released()), this, SLOT(MathButtonPressed()));
  connect(ui_->ebut, SIGNAL(released()), this, SLOT(NumPressed()));
  connect(ui_->enegbut, SIGNAL(released()), this, SLOT(NumPressed()));
  connect(ui_->equal, SIGNAL(released()), this, SLOT(EqualButtonPressed()));

  connect(ui_->Credit, SIGNAL(released()), this, SLOT(CreditOpen()));
  connect(ui_->Debit, SIGNAL(released()), this, SLOT(DebitOpen()));

  connect(ui_->cbut, SIGNAL(released()), this, SLOT(ClearCButtonPressed()));
  connect(ui_->Clear, SIGNAL(released()), this, SLOT(ClearButtonPressed()));
}
