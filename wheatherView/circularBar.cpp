#include "circularBar.h"
#include "qcontainerfwd.h"
#include "qevent.h"
#include "qicon.h"
#include "qnamespace.h"
#include "qobject.h"
#include "qpainter.h"
#include "qwidget.h"

circularBar::circularBar(int min, int max, QWidget *parent) : QWidget(parent) {
  this->min = min;
  this->max = max;
  this->delta = 0.0;
  this->value = INT_MIN;
  this->actual_color = &this->empty_color;
  this->text_color = &this->empty_color;

  this->setMinimumSize(60, 60);
}

void circularBar::set_min(int val) { this->min = val; }
void circularBar::set_max(int val) { this->max = val; }

void circularBar::set_value(int val) {
  if ((val > this->max) || (val < this->min)) {
    this->value = INT_MIN;
    this->delta = 0;
    this->actual_color = &this->empty_color;
    this->text_color = &this->empty_color;
  } else {
    this->value = val;
    this->delta = (this->value - this->min) * 1.0 / (max - min);
    this->text_color = &this->white;
    if (this->delta < 0.1) {
      this->actual_color = &this->low_color;
    } else if (this->delta > 0.9) {
      this->actual_color = &this->top_color;
    } else {
      this->actual_color = &this->mid_color;
    }
  }
  this->update();
}

void circularBar::paintEvent(QPaintEvent *) {
  QPainter paint(this);
  paint.setRenderHint(QPainter::Antialiasing);
  int line_width = 8;

  paint.fillRect(this->rect(), this->bg_color);

  int side =
      (this->width() < this->height() ? this->width() : this->height()) - 30;

  QRectF r((this->width() - side) / 2.0 + line_width,
           (this->height() - side) / 2.0 + line_width, side - 2 * line_width,
           side - 2 * line_width);

  QPen pen(this->empty_color, line_width);
  paint.setPen(pen);
  paint.drawArc(r, 0, 16 * 360);

  pen.setColor(*this->actual_color);
  paint.setPen(pen);
  int angle_span = static_cast<int>(16 * 360 * this->delta);
  paint.drawArc(r, 90 * 16, -angle_span);

  paint.setPen(*this->text_color);
  if (this->value == INT_MIN) {
    paint.drawText(this->rect(), Qt::AlignCenter, "---");
  } else {
    paint.drawText(this->rect(), Qt::AlignCenter, QString::number(this->value));
  }
}
