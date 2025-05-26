
#include "datasource.h"
#include "qboxlayout.h"
#include "qcombobox.h"
#include "qgroupbox.h"
#include "qlabel.h"
#include "qwidget.h"
dataSourceWidget::dataSourceWidget(QWidget *parent) : QGroupBox(parent) {
  this->setTitle("Источник данных");
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

  this->meteo_label = new QLabel("Источник метео");
  this->meteo_label->setAlignment(Qt::AlignCenter);
  this->meteo_label->setFont(font);

  this->meteo_list = new QComboBox();
  this->meteo_list->addItems({"Оператор", "Локальный файл", "Онлайн сервис"});

  this->time_label = new QLabel("Источник времени");
  this->time_label->setAlignment(Qt::AlignCenter);
  this->time_label->setFont(font);

  this->time_list = new QComboBox();
  this->time_list->addItems({"Оператор", "Локальный файл", "ПК"});

  QHBoxLayout *meteo_layout = new QHBoxLayout();
  meteo_layout->addWidget(this->meteo_label);
  meteo_layout->addWidget(this->meteo_list);

  QHBoxLayout *time_layout = new QHBoxLayout();
  time_layout->addWidget(this->time_label);
  time_layout->addWidget(this->time_list);

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addLayout(meteo_layout);
  layout->addLayout(time_layout);
  this->setLayout(layout);
}
