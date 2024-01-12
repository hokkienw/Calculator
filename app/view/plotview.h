#ifndef _SMARTCALCV2_SRC_APP_VIEW_PLOTVIEW_H_
#define _SMARTCALCV2_SRC_APP_VIEW_PLOTVIEW_H_

#include <QCloseEvent>
#include <QMainWindow>

#include "../model/qcustomplot.h"

namespace Ui {
class PlotView;
}

class PlotView : public QMainWindow {
  Q_OBJECT

 public:
  explicit PlotView(QWidget *parent = nullptr);
  void PlotGraph(std::pair<std::vector<double>, std::vector<double>> val,
                 double max_x, double max_y);
  ~PlotView();

 private slots:
  void on_Back_clicked();
  virtual void closeEvent(QCloseEvent *event);

 private:
  Ui::PlotView *ui_;

 signals:
  void signal_plot_();
};

#endif  // _SMARTCALCV2_SRC_APP_VIEW_PLOTVIEW_H_
