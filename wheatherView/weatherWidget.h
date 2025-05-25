#ifndef WHEATHERWIDGET_H
#define WHEATHERWIDGET_H

#include "circularBar.h"
#include "qgroupbox.h"
#include "qobject.h"
#include "qtmetamacros.h"
#include "qwidget.h"
class wheatherWidget : public QGroupBox {
  Q_OBJECT
public:
  explicit wheatherWidget(const QString &label, QString units,
                          QWidget *parent = 0);
  void update_circular_state(int val);
  void update_circular_min(int val);
  void update_circular_max(int val);

private:
  circularBar *circular_bar;
  QString label;
  QString units;
};

#endif // !WHEATHERWIDGET_H
