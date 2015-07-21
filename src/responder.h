#ifndef RESPONDER_H
#define RESPONDER_H

#include <QApplication>
#include "header.h"
#include "qhttpserverfwd.h"

#include <QObject>
#include <QScopedPointer>
#include <QtXml>

class Responder : public QObject
{
    Q_OBJECT

public:
    Responder(QHttpRequest *req, QHttpResponse *resp);
    ~Responder();
//    QString respCumlativeData(QDomDocument *p_respDoc, QDomElement *p_respRoot);
    QString respESSRealTimeReadings(QString rootTagName);
    QString respCumulativeData(QString rootTagName);
    QString respEesUnit(QString rootTagName);

    QString respPCSFaultMessage(QString rootTagName);
    QString respBatteryFaultMessage(QString rootTagName);
    QString respPCSOperationStatus(QString rootTagName);
    QString respDRMessage(QString rootTagName, QString mEventID);

    QString convDateTime();

signals:
    void done();

private slots:
    void accumulate(const QByteArray &data);
    void reply();

private:
    QScopedPointer<QHttpRequest> m_req;
    QHttpResponse *m_resp;
    int resp_type;
};

#endif // RESPONDER_H
