#ifndef WEATHERSERVER_H
#define WEATHERSERVER_H

#include "qobject.h"
#include "qtmetamacros.h"
#include "qwebsocket.h"
#include "qwebsocketserver.h"

class weatherServer : public QObject {
  Q_OBJECT
public:
  explicit weatherServer(int port = 4269, QObject *parent = 0);
signals:
  void parametrs_update(int humidiry, int temperature, int pressure);
  void date_update(QString date, QString time);
  void connection_lost();
  void connetction_restore();
private slots:
  void new_connection();
  void new_message(QString mess);
  void socket_disconnet();

private:
  QWebSocketServer *m_server;
  QWebSocket *m_clientSocket = 0;
};

#endif // WEATHERSERVER_H
