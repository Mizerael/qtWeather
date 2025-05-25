#include "weatherWidget.h"
#include "circularBar.h"
#include "qboxlayout.h"
#include "qcontainerfwd.h"
#include "qgroupbox.h"
#include "qobject.h"
#include "qwidget.h"
wheatherWidget::wheatherWidget(const QString &label, QString units,
                               QWidget *parent)
    : QGroupBox(label, parent) {
  this->label = label;
  this->units = units;
  this->circular_bar = new circularBar();
  this->setMinimumSize(200, 200);
  this->setTitle(QString::asprintf("%s,%s", this->label.toUtf8().constData(),
                                   this->units.toUtf8().constData()));
  this->setStyleSheet("QGroupBox {"
                      "  border: 2px solid #647d89;"
                      "  background-color: #394955;"
                      "  font: 22px 'Roboto';"
                      "  margin-top: 20px;"
                      "}"
                      "QGroupBox::title {"
                      "  subcontrol-origin: margin;"
                      "  subcontrol-position: top center;"
                      "  padding: 0 10px;"
                      "}");
  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(this->circular_bar);
  this->setLayout(layout);
};

void wheatherWidget::update_circular_state(int val) {
  this->circular_bar->set_value(val);
};

void wheatherWidget::update_circular_min(int val) {
  this->circular_bar->set_min(val);
};

void wheatherWidget::update_circular_max(int val) {
  this->circular_bar->set_max(val);
};
