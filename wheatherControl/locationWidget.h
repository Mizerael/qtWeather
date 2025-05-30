#ifndef LOCATIONWIDGET_H
#define LOCATIONWIDGET_H

#include "qcombobox.h"
#include "qcontainerfwd.h"
#include "qgroupbox.h"
#include "qlabel.h"
#include "qtmetamacros.h"
#include "qwidget.h"

class locationWidget : public QGroupBox {
  Q_OBJECT
public:
  explicit locationWidget(QWidget *parent = 0);
private slots:
  // void send_data();

private:
  QComboBox *location_list;
  QLabel *location_label;
};

#endif // !LOCATIONWIDGET_H
