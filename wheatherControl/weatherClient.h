#ifndef WEATHERCLIENT_H
#define WEATHERCLIENT_H
#include "qobject.h"
#include "qtmetamacros.h"
#include "qurl.h"
#include "qwebsocket.h"

class weatherClient : public QObject {
  Q_OBJECT
public:
  explicit weatherClient(const QUrl &url, QObject *parent = nullptr);

  void sendParameters(int humidity, int temperature, int pressure);

signals:
  void connectionLost();
  void connectionRestored();

private slots:
  void onConnected();
  void onDisconnected();

private:
  QWebSocket m_webSocket;
  QUrl m_url;
};
#endif // !WEATHERCLIENT_H
