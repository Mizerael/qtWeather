#include "weatherServer.h"
#include "qjsondocument.h"
#include "qjsonobject.h"
#include "qobject.h"
#include "qtmetamacros.h"
#include "qwebsocket.h"
weatherServer::weatherServer(int port, QObject *parent) : QObject(parent) {
  m_server = new QWebSocketServer(QStringLiteral("Weather Server"),
                                  QWebSocketServer::NonSecureMode, this);
  if (m_server->listen(QHostAddress::LocalHost, port)) {
    connect(m_server, &QWebSocketServer::newConnection, this,
            &weatherServer::new_connection);
  }
}

void weatherServer::new_connection() {
  m_clientSocket = m_server->nextPendingConnection();
  connect(m_clientSocket, &QWebSocket::textMessageReceived, this,
          &weatherServer::new_message);
  connect(m_clientSocket, &QWebSocket::disconnected, this,
          &weatherServer::socket_disconnet);
  emit connetction_restore();
}

void weatherServer::new_message(QString message) {
  QJsonDocument doc = QJsonDocument::fromJson(message.toUtf8());
  if (doc.isObject()) {
    QJsonObject j_obj = doc.object();
    if (j_obj.value("type") == "params") {
      int humidity = j_obj.value("humidity").toInt();
      int temperature = j_obj.value("temperature").toInt();
      int pressure = j_obj.value("pressure").toInt();
      emit parametrs_update(humidity, temperature, pressure);
    } else if (j_obj.value("type") == "date") {
      QString date = j_obj.value("date").toString();

      QString time = j_obj.value("time").toString();
      emit date_update(date, time);
    }
  }
}

void weatherServer::socket_disconnet() {
  emit connection_lost();
  m_clientSocket->deleteLater();
  m_clientSocket = nullptr;
}
