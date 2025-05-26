#ifndef CONTROLWINDOW_H
#define CONTROLWINDOW_H

#include "datasource.h"
#include "qtmetamacros.h"
#include "qwidget.h"
#include "settingsWidget.h"
class controlWindow : public QWidget {
  Q_OBJECT
public:
  explicit controlWindow(QWidget *parent = 0);

protected:
  void closeEvent(QCloseEvent *event) override;

private slots:
  // void update();
private:
  bool is_exit = false;
  dataSourceWidget *data_source;
  settingsWidget *settings_widget;
};
#endif // !CONTROLWINDOW_H
