#include "plotview.h"

#include "ui_plotview.h"

PlotView::PlotView(QWidget *parent)
    : QMainWindow(parent), ui_(new Ui::PlotView) {
  ui_->setupUi(this);
}

PlotView::~PlotView() { delete ui_; }

void PlotView::PlotGraph(
    std::pair<std::vector<double>, std::vector<double>> val, double max_x,
    double max_y) {
  ui_->widget->clearGraphs();
  QPen pen;
  pen.setColor(QColor(132, 38, 87));

  ui_->widget->xAxis->setRange(-max_x, max_x);
  ui_->widget->yAxis->setRange(-max_y, max_y);
  ui_->widget->addGraph()->setPen(pen);
  ui_->widget->graph(0)->addData(
      QVector<double>(val.first.begin(), val.first.end()),
      QVector<double>(val.second.begin(), val.second.end()));
  ui_->widget->setInteraction(QCP::iRangeZoom, true);
  ui_->widget->setInteraction(QCP::iRangeDrag, true);
  ui_->widget->setBackground(QColor(235, 234, 230));
  ui_->widget->replot();
}

void PlotView::on_Back_clicked() { emit signal_plot_(); }

void PlotView::closeEvent(QCloseEvent *event) {
  emit signal_plot_();
  event->accept();
}

