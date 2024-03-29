#ifndef TOSERVER_HH
#define TOSERVER_HH
#include "files.hh"
#include "FridgeState.h"
#include <QMainWindow>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QTimer>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QHostAddress>

#include <QNetworkInterface>
#include <QtNetwork>

#include <string.h>

class Server : public QWidget
{
  Q_OBJECT
public:
  explicit Server(QWidget *parent = nullptr);
  void sendStatusFridge(QString strStatus);
  void formBuyinglist();
  void sendBuyingProducts(QString strJsonProducts);
  void sendFileConnect();
  void sendInitFridge();
  void sendUID(QString);
public slots:
  void getResponseInit(QNetworkReply *reply);
  void getResponseUid(QNetworkReply *reply);
  void getResponseStatus(QNetworkReply *reply);
  void getResponseBuyingProducts(QNetworkReply *reply);
  void checkStatusFridge();
private:
  static QTimer *timerStatusFridge;
  static int timeStatusFridge;
  QString getMacAddress();
  QString getIpTun0();
  QString addInitToJson(QString, QString);
  QString urlInitFridge;
  QString urlSendingBuyProducts;
  QString urlSendStatusFridge;
  QString urlSendUid;
  QString checkResponseStatusUid(QString statusUid);
signals:
  void signalStatusUID(QString status);
};

#endif // TOSERVER_HH
