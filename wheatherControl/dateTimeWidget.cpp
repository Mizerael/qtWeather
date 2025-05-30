#include "dateTimeWidget.h"
#include "qboxlayout.h"
#include "qnamespace.h"
#include "qpushbutton.h"

dateTimeWidget::dateTimeWidget(QWidget *parent) : QGroupBox(parent) {

  this->setTitle("Дата/Время");
  this->setStyleSheet("QGroupBox {"
                      "  border: 2px solid #647d89;"
                      "  background-color: #394955;"
                      "  font: 22px 'Roboto';"
                      "  margin-top: 20px;"
                      "}"
                      "QGroupBox::title {"
                      "  subcontrol-origin: margin;"
                      "  subcontrol-position: top center;"
                      "  padding: 0 10px;"
                      "}");

  QFont font("Roboto", 22);
  this->setFont(font);

  this->date_label = new QLabel("Дата");
  this->date_label->setFont(font);
  this->date_label->setAlignment(Qt::AlignCenter);

  this->date_spin = new QSpinBox();
  this->date_spin->setRange(0, 100);
  this->date_spin->setSingleStep(1);
  this->date_spin->setFont(font);

  QHBoxLayout *date_layout = new QHBoxLayout();
  date_layout->addWidget(this->date_label);
  date_layout->addWidget(this->date_spin);

  this->time_label = new QLabel("Температура, C");
  this->time_label->setFont(font);
  this->time_label->setAlignment(Qt::AlignCenter);

  this->time_spin = new QSpinBox();
  this->time_spin->setRange(-100, 100);
  this->time_spin->setSingleStep(1);
  this->time_spin->setFont(font);

  QHBoxLayout *time_layout = new QHBoxLayout();
  time_layout->addWidget(this->time_label);
  time_layout->addWidget(this->time_spin);

  this->send_button = new QPushButton("Задать");
  this->send_button->setMaximumSize(this->width() / 2, 50);
  this->send_button->setMinimumSize(60, 40);
  QHBoxLayout *buttons = new QHBoxLayout;
  buttons->addStretch();
  buttons->addWidget(this->send_button, Qt::AlignRight);

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addLayout(date_layout);
  layout->addLayout(time_layout);
  layout->addLayout(buttons);
  this->setLayout(layout);
};
