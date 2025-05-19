#include "window.h"
#include "qevent.h"
#include "qmessagebox.h"
#include "qwidget.h"

mainWindow::mainWindow(QWidget *parent) : QWidget(parent) {
  setWindowTitle("Метеоданные");
  setStyleSheet("background-color : #394955; color: #d4d4d4;");
}

void mainWindow::closeEvent(QCloseEvent *event) {
  if (!this->is_exit) {
    QMessageBox msg_box(this);
    msg_box.setWindowTitle("Подтвердите выход из приложения");
    msg_box.setText("Подтвердите выход из приложения");
    msg_box.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msg_box.setDefaultButton(QMessageBox::No);
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
  this->time->setText("aboba");
  this->date->setText("abooba");
};
