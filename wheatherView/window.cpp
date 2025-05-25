#include "window.h"
#include "qboxlayout.h"
#include "qdatetime.h"
#include "qevent.h"
#include "qfont.h"
#include "qlabel.h"
#include "qlocale.h"
#include "qmessagebox.h"
#include "qnamespace.h"
#include "qpushbutton.h"
#include "qtimer.h"
#include "qwidget.h"
#include "weatherWidget.h"

mainWindow::mainWindow(QWidget *parent) : QWidget(parent) {

  this->setWindowTitle("Метеоданные");
  this->setStyleSheet("background-color : #394955; color: #d4d4d4;");

  QFont font("Roboto", 22);
  QDateTime that_moment = QDateTime::currentDateTime();

  this->setFont(font);

  this->date = new QLabel(that_moment.toString("dd.MM.yyyy"));
  this->date->setAlignment(Qt::AlignCenter);

  this->time = new QLabel(that_moment.toString("hh:mm:ss"));
  this->time->setAlignment(Qt::AlignCenter);

  this->location = new QLabel("Санкт-Петербург");
  this->location->setAlignment(Qt::AlignCenter);

  this->journal = new QPushButton("Журнал");
  this->journal->setStyleSheet("border: 2px solid #d4d4d4;");

  QHBoxLayout *top_layout = new QHBoxLayout;
  top_layout->addWidget(this->date);
  top_layout->addWidget(this->time);
  top_layout->addWidget(this->location);

  this->humidity = new wheatherWidget("Влажность", "%");
  this->humidity->update_circular_min(0);
  this->humidity->update_circular_max(100);
  this->humidity->update_circular_state(50);

  this->pressure = new wheatherWidget("Давление", "мм");
  this->pressure->update_circular_min(600);
  this->pressure->update_circular_max(800);
  this->pressure->update_circular_state(760);

  this->temperature = new wheatherWidget("Температура", "C");

  this->temperature->update_circular_min(-50);
  this->temperature->update_circular_max(50);
  this->temperature->update_circular_state(20);

  QHBoxLayout *bars = new QHBoxLayout;
  bars->addWidget(this->humidity);
  bars->addWidget(this->pressure);
  bars->addWidget(this->temperature);

  QVBoxLayout *maybe_its_works_normaly = new QVBoxLayout;
  maybe_its_works_normaly->addLayout(bars);
  maybe_its_works_normaly->addLayout(top_layout);

  this->setLayout(maybe_its_works_normaly);
  this->resize(600, 400);

  this->connect(&this->timer, &QTimer::timeout, this, &mainWindow::update);
  this->timer.start(1000);
}

void mainWindow::closeEvent(QCloseEvent *event) {
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

void mainWindow::update() {

  QDateTime that_moment = QDateTime::currentDateTime();
  this->time->setText(that_moment.toString("hh:mm:ss"));
  this->date->setText(that_moment.toString("dd.MM.yyyy"));
};
