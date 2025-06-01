#include "settingsWidget.h"
#include "qboxlayout.h"
#include "qnamespace.h"
#include "qpushbutton.h"

settingsWidget::settingsWidget(QWidget *parent) : QGroupBox(parent) {
  this->setTitle("Параметры");
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

  this->humidity_label = new QLabel("Влажность, %");
  this->humidity_label->setFont(font);
  this->humidity_label->setAlignment(Qt::AlignCenter);

  this->humidity_spin = new QSpinBox();
  this->humidity_spin->setRange(0, 100);
  this->humidity_spin->setSingleStep(1);
  this->humidity_spin->setFont(font);

  QHBoxLayout *humidity_layout = new QHBoxLayout();
  humidity_layout->addWidget(this->humidity_label);
  humidity_layout->addWidget(this->humidity_spin);

  this->temperature_label = new QLabel("Температура, C");
  this->temperature_label->setFont(font);
  this->temperature_label->setAlignment(Qt::AlignCenter);

  this->temperature_spin = new QSpinBox();
  this->temperature_spin->setRange(-100, 100);
  this->temperature_spin->setSingleStep(1);
  this->temperature_spin->setFont(font);

  QHBoxLayout *temperature_layout = new QHBoxLayout();
  temperature_layout->addWidget(this->temperature_label);
  temperature_layout->addWidget(this->temperature_spin);

  this->pressure_label = new QLabel("Давление, мм рт ст");
  this->pressure_label->setFont(font);
  this->pressure_label->setAlignment(Qt::AlignCenter);

  this->pressure_spin = new QSpinBox();
  this->pressure_spin->setRange(0, 1000);
  this->pressure_spin->setSingleStep(1);
  this->pressure_spin->setFont(font);

  QHBoxLayout *pressure_layout = new QHBoxLayout();
  pressure_layout->addWidget(this->pressure_label);
  pressure_layout->addWidget(this->pressure_spin);

  this->send_button = new QPushButton("Задать");
  this->send_button->setMaximumSize(this->width() / 2, 50);
  this->send_button->setMinimumSize(60, 40);
  QHBoxLayout *buttons = new QHBoxLayout;
  buttons->addStretch();
  buttons->addWidget(this->send_button, Qt::AlignRight);

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addLayout(humidity_layout);
  layout->addLayout(temperature_layout);
  layout->addLayout(pressure_layout);
  layout->addLayout(buttons);
  this->setLayout(layout);
};

int settingsWidget::get_humidity() { return this->humidity_spin->value(); };
int settingsWidget::get_temperature() {
  return this->temperature_spin->value();
};
int settingsWidget::get_pressure() { return this->pressure_spin->value(); };
