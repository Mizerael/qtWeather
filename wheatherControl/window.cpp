#include "window.h"
#include "datasource.h"
#include "qabstractbutton.h"
#include "qboxlayout.h"
#include "qevent.h"
#include "qmessagebox.h"
#include "qwidget.h"
#include "settingsWidget.h"

controlWindow::controlWindow(QWidget *parent) : QWidget(parent) {
  this->setWindowTitle("Управление метеоданными");
  this->setStyleSheet("background-color : #394955; color: #d4d4d4;");

  this->data_source = new dataSourceWidget();
  this->settings_widget = new settingsWidget();

  QVBoxLayout *layout = new QVBoxLayout();

  layout->addWidget(this->data_source);
  layout->addWidget(this->settings_widget);

  this->setLayout(layout);
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
      event->accept();
    } else {
      event->ignore();
    }
  } else {
    event->accept();
  }
};
