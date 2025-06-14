#include "window.h"
#include "datasource.h"
#include "dateTimeWidget.h"
#include "locationWidget.h"
#include "qabstractbutton.h"
#include "qboxlayout.h"
#include "qevent.h"
#include "qmessagebox.h"
#include "qpushbutton.h"
#include "qurl.h"
#include "qwidget.h"
#include "settingsWidget.h"
#include "weatherClient.h"

controlWindow::controlWindow(QWidget *parent) : QWidget(parent) {
  this->setWindowTitle("Управление метеоданными");
  this->setStyleSheet("background-color : #394955; color: #d4d4d4;");

  this->data_source = new dataSourceWidget();
  this->settings_widget = new settingsWidget();
  this->datetime_widget = new dateTimeWidget();
  this->location_widget = new locationWidget();

  QVBoxLayout *layout = new QVBoxLayout();

  layout->addWidget(this->data_source);
  layout->addWidget(this->settings_widget);
  layout->addWidget(this->datetime_widget);
  layout->addWidget(this->location_widget);

  this->setLayout(layout);

  this->client = new weatherClient(QUrl("ws://127.0.0.1:4269"), this);

  connect(this->settings_widget->send_button, &QPushButton::clicked, this,
          &controlWindow::send_settings);
  connect(this->datetime_widget->send_button, &QPushButton::clicked, this,
          &controlWindow::send_date);
  this->client->sendParameters(this->settings_widget->get_humidity(),
                               this->settings_widget->get_temperature(),
                               this->settings_widget->get_pressure());
};

void controlWindow::send_settings() {
  this->client->sendParameters(this->settings_widget->get_humidity(),
                               this->settings_widget->get_temperature(),
                               this->settings_widget->get_pressure());
};

void controlWindow::send_date() {
  this->client->sendParameters(this->datetime_widget->get_date(),
                               this->datetime_widget->get_time());
};
void controlWindow::closeEvent(QCloseEvent *event) {
  if (!this->is_exit) {
    QMessageBox msg_box(this);
    msg_box.setWindowTitle("Подтвердите выход из приложения");
    msg_box.setText("Подтвердите выход из приложения");
    msg_box.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msg_box.setDefaultButton(QMessageBox::No);

    QAbstractButton *yes_button = msg_box.button(QMessageBox::Yes);
    QAbstractButton *no_button = msg_box.button(QMessageBox::No);

    yes_button->setText("Да");
    no_button->setText("Нет");

    int selected = msg_box.exec();
    if (selected == QMessageBox::Yes) {
      this->is_exit = true;
      this->client->connectionLost();
      event->accept();
    } else {
      event->ignore();
    }
  } else {
    event->accept();
  }
};
