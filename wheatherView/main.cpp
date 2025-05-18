#include <QApplication>
#include <QPushButton>

int main (int argc, char *argv[]) {
  QApplication app(argc, argv);
  
  QPushButton butt ("hello");
  butt.show();

  return app.exec();
}
