#ifndef JOURNAL_H
#define JOURNAL_H

#include "qdatetime.h"
#include "qdialog.h"
#include "qlistwidget.h"
#include "qtmetamacros.h"

class journal : public QDialog {
  Q_OBJECT
public:
  explicit journal(QWidget *parent = 0);
  void add_event(const QString &text,
                 const QDateTime &date = QDateTime::currentDateTime());

private:
  QListWidget *story;
};
#endif // !JOURNAL_H
