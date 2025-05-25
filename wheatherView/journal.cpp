
#include "journal.h"
#include "qboxlayout.h"
#include "qnamespace.h"
#include "qpushbutton.h"
#include "qwidget.h"
journal::journal(QWidget *parent) : QDialog(parent) {
  this->setWindowTitle("Журнал");
  this->setMinimumSize(300, 400);
  this->setFont(QFont("Roboto", 14));

  this->story = new QListWidget(this);
  QPushButton *closeBtn = new QPushButton("Закрыть", this);

  QVBoxLayout *layout = new QVBoxLayout(this);
  layout->addWidget(this->story);
  layout->addWidget(closeBtn, 0, Qt::AlignCenter);

  connect(closeBtn, &QPushButton::clicked, this, &QDialog::accept);
};

void journal::add_event(const QString &text, const QDateTime &date) {
  QString line =
      QString("[%1] %2").arg(date.toString("dd.MM.yyyy hh:mm:ss"), text);
  this->story->addItem(line);
}
