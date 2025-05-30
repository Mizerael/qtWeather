#include "locationWidget.h"
#include "qboxlayout.h"
#include "qcombobox.h"
#include "qgroupbox.h"
#include "qlabel.h"
#include "qwidget.h"
locationWidget::locationWidget(QWidget *parent) : QGroupBox(parent) {
  this->setTitle("Местоположение");
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

  this->location_label = new QLabel("Источник метео");
  this->location_label->setAlignment(Qt::AlignCenter);
  this->location_label->setFont(font);

  this->location_list = new QComboBox();
  this->location_list->addItems({"Саратов", "Санкт-Петербург"});

  QHBoxLayout *location_layout = new QHBoxLayout();
  location_layout->addWidget(this->location_label);
  location_layout->addWidget(this->location_list);

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addLayout(location_layout);
  this->setLayout(layout);
}
