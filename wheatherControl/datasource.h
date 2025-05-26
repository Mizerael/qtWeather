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

private:
  QComboBox *meteo_list;
  QLabel *meteo_label;
  QComboBox *time_list;
  QLabel *time_label;

  QString *selected_meteo;
  QString *selected_time;
};

#endif // !DATASOURCE_H
