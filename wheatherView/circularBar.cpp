#include "circularBar.h"
#include "qevent.h"
#include "qicon.h"
#include "qnamespace.h"
#include "qobject.h"
#include "qpainter.h"
#include "qwidget.h"

circularBar::circularBar(QString label, QString units, QWidget *parent)
    : QWidget(parent) {
  this->label = label;
  this->units = units;
  this->setMinimumSize(140, 140);
}

void circularBar::set_value(double val) {
  this->value = val;
  this->update();
}

void circularBar::paintEvent(QPaintEvent *) {
  QPainter paint(this);
  paint.setRenderHint(QPainter::Antialiasing);
  int line_width = 8;

  QColor bg_color("#394955");
  QColor fg_color("#d4d4d4");
  paint.fillRect(this->rect(), bg_color);

  int side =
      (this->width() < this->height() ? this->width() : this->height()) - 30;

  QRectF r((this->width() - side) / 2.0 + line_width,
           (this->height() - side) / 2.0 + line_width, side - 2 * line_width,
           side - 2 * line_width);

  QPen pen(QColor(80, 80, 80), line_width);
  paint.setPen(pen);
  paint.drawArc(r, 0, 16 * 360);

  pen.setColor(fg_color);
  paint.setPen(pen);
  int angle_span = static_cast<int>(16 * 360 * this->value);
  paint.drawArc(r, 90 * 16, -angle_span);

  QRectF label_rect = r.adjusted(0, side * 0.08, 0, -side * 0.75);
  paint.setPen(fg_color);
  paint.drawText(label_rect, Qt::AlignHCenter | Qt::AlignTop, this->label);

  QString val_str = QString::number(int(this->value * 100)) + " " + this->units;
  paint.drawText(this->rect(), Qt::AlignCenter, val_str);
}
