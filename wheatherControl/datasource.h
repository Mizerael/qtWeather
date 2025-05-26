#ifndef DATASOURCE_H
#define DATASOURCE_H

#include "qcombobox.h"
#include "qcontainerfwd.h"
#include "qgroupbox.h"
#include "qlabel.h"
#include "qtmetamacros.h"
#include "qwidget.h"

class dataSourceWidget : public QGroupBox {
  Q_OBJECT
public:
  explicit dataSourceWidget(QWidget *parent = 0);
private slots:
  // void send_data();

private:
  QComboBox *meteo_list;
  QLabel *meteo_label;
  QComboBox *time_list;
  QLabel *time_label;
};

#endif // !DATASOURCE_H
