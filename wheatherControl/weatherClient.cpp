#include "weatherClient.h"
#include "qjsondocument.h"
#include "qjsonobject.h"
#include "qobject.h"
weatherClient::weatherClient(const QUrl &url, QObject *parent)
    : QObject(parent), m_url(url) {
  connect(&m_webSocket, &QWebSocket::connected, this,
          &weatherClient::onConnected);
  connect(&m_webSocket, &QWebSocket::disconnected, this,
          &weatherClient::onDisconnected);
  m_webSocket.open(m_url);
}

void weatherClient::sendParameters(int humidity, int temperature,
                                   int pressure) {
  QJsonObject j_obj;
  j_obj["humidity"] = humidity;
  j_obj["temperature"] = temperature;
  j_obj["pressure"] = pressure;
  QJsonDocument doc(j_obj);
  m_webSocket.sendTextMessage(
      QString::fromUtf8(doc.toJson(QJsonDocument::Compact)));
}

void weatherClient::onConnected() { emit connectionRestored(); }

void weatherClient::onDisconnected() { emit connectionLost(); }
