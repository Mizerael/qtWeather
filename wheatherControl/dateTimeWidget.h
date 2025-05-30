#ifndef DATETIMEWIDGET_H
#define DATETIMEWIDGET_H

#include "qgroupbox.h"
#include "qlabel.h"
#include "qpushbutton.h"
#include "qspinbox.h"
#include "qtmetamacros.h"
#include "qwidget.h"

class dateTimeWidget : public QGroupBox {
  Q_OBJECT
public:
  explicit dateTimeWidget(QWidget *parent = 0);

private:
  QLabel *date_label;
  QLabel *time_label;
  QSpinBox *date_spin;
  QSpinBox *time_spin;
  QPushButton *send_button;
};

#endif // !DATETIMEWIDGET_H
