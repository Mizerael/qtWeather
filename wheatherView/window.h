#ifndef WINDOW_H
#define WINDOW_H

#include "qlabel.h"
#include "qpushbutton.h"
#include "qtimer.h"
#include "qtmetamacros.h"
#include "qwidget.h"
#include "weatherWidget.h"

class mainWindow : public QWidget {
  Q_OBJECT
public:
  explicit mainWindow(QWidget *parent = 0);

protected:
  void closeEvent(QCloseEvent *event) override;

private slots:
  void update();

private:
  wheatherWidget *humidity;
  wheatherWidget *pressure;
  wheatherWidget *temperature;
  QLabel *date;
  QLabel *time;
  QLabel *location;
  QPushButton *journal;
  QTimer timer;
  bool is_exit = false;
};

#endif // WINDOW_H
