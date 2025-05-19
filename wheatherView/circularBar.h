#ifndef CIRCULARBAR_H
#define CIRCULARBAR_H

#include "qevent.h"
#include "qobject.h"
#include "qtmetamacros.h"
#include "qwidget.h"

class circularBar : public QWidget {
  Q_OBJECT
public:
  explicit circularBar(QString label, QString units, QWidget *parent = 0);
  void set_value(double val);

protected:
  void paintEvent(QPaintEvent *event) override;

private:
  double value = .0f;
  QString label;
  QString units;
};

#endif // !CIRCULARBAR_H
