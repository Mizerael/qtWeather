#ifndef DATETIMEWIDGET_H
#define DATETIMEWIDGET_H

#include "qcontainerfwd.h"
#include "qdatetimeedit.h"
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
  QPushButton *send_button;
  QString get_date();
  QString get_time();

private:
  QLabel *date_label;
  QLabel *time_label;
  QDateEdit *date_spin;
  QTimeEdit *time_spin;
};

#endif // !DATETIMEWIDGET_H
