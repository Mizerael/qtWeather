#ifndef CIRCULARBAR_H
#define CIRCULARBAR_H

#include "qcolor.h"
#include "qevent.h"
#include "qobject.h"
#include "qtmetamacros.h"
#include "qwidget.h"

class circularBar : public QWidget {
  Q_OBJECT
public:
  explicit circularBar(int min = 0, int max = 1, QWidget *parent = 0);
  void set_min(int val);
  void set_max(int val);
  void set_value(int val);

protected:
  void paintEvent(QPaintEvent *event) override;

private:
  int value;
  int min;
  int max;
  double delta;
  QColor *actual_color;
  QColor *text_color;
  QColor white = QColor("#ffffff");
  QColor empty_color = QColor("#647d89");
  QColor low_color = QColor("#fff500");
  QColor mid_color = QColor("#64ff89");
  QColor top_color = QColor("#fff500");
  QColor bg_color = QColor("#394955");
};

#endif // !CIRCULARBAR_H
