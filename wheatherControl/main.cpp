#include "qapplication.h"
#include "qmessagebox.h"
#include "qsharedmemory.h"
#include "window.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  QSharedMemory shared_mem("aboba");
  if (!shared_mem.create(1)) {
    QMessageBox::warning(nullptr, "Приложение уже запущено",
                         "Приложение уже запущено.");
  } else {
    controlWindow window;
    window.show();
    return app.exec();
  }
}
