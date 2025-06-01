#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include "qgroupbox.h"
#include "qlabel.h"
#include "qpushbutton.h"
#include "qspinbox.h"
#include "qtmetamacros.h"
#include "qwidget.h"

class settingsWidget : public QGroupBox {
  Q_OBJECT
public:
  explicit settingsWidget(QWidget *parent = 0);
  int get_humidity();
  int get_temperature();
  int get_pressure();
  QPushButton *send_button;

private:
  QLabel *humidity_label;
  QLabel *temperature_label;
  QLabel *pressure_label;
  QSpinBox *humidity_spin;
  QSpinBox *temperature_spin;
  QSpinBox *pressure_spin;
};

#endif // !SETTINGSWIDGET_H
