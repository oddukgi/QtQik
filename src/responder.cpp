#include <QApplication>
#include "header.h"
#include "responder.h"

#include <QRegExp>
#include <QStringList>
#include <QDebug>


#include <qhttpserver.h>
#include <qhttprequest.h>
#include <qhttpresponse.h>

Responder::Responder(QHttpRequest *req, QHttpResponse *resp)
    : m_req(req)
    , m_resp(resp)
{
//    QString temp = req->path();
    qDebug() << req->path();
    QRegExp exp("^/user/([a-z]+$)");
//    if (exp.indexIn(req->path()) == -1)
//    {
//        resp->writeHead(403);
////        resp->write(QByteArray(&temp));
//        resp->end(QByteArray("You aren't allowed here!"));
//        /// @todo There should be a way to tell request to stop streaming data
//        return;
//    }

    resp->setHeader("Content-Type", "text/html");
//    resp->writeHead(200);

//    QString name = exp.capturedTexts()[1];
//    QString bodyStart = tr("<html><head><title>BodyData App</title></head><body><h1>Hello %1!</h1><p>").arg(name);
//    resp->write(bodyStart.toUtf8());

    connect(req, SIGNAL(data(const QByteArray&)), this, SLOT(accumulate(const QByteArray&)));
    connect(req, SIGNAL(end()), this, SLOT(reply()));
    connect(m_resp, SIGNAL(done()), this, SLOT(deleteLater()));
}

Responder::~Responder()
{
}

QString Responder::convDateTime()
{
    QDateTime v = QDateTime::currentDateTime();
    const QString sformat="yyyy-MM-dd hh:mm:ss";
    return QString("%1").arg(QDateTime::fromString(v.toString(),Qt::TextDate).toString(sformat));
}

#define DF_ESSREALTIME_SIZE      22
QString ESSRealTimeReadingsItem[DF_ESSREALTIME_SIZE][2] =
{
    {"mRID",     ""},                            // 0
    {"aliasName","getESSRealTimeReadings"},      // 1
    {"name",     "response"},                    // 2

    {"GridInVoltage",  "220"},      // 3
    {"GridOutVoltage", "0"},        // 4
    {"GridInPower",    "1000"},     // 5
    {"GridOutPower",   "0"},        // 6
    {"GridInCurrent",  "50"},       // 7
    {"GridOutCurrent", "0"},        // 8

    {"LoadPower",   "3000"},        // 9
    {"LoadCurrent", "15"},          // 10
    {"LoadVoltage", "220"},         // 11

    {"AmountPower",   "3000"},      // 12
    {"AmountCurrent", "10"},        // 13
    {"AmountVoltage", "300"},       // 14

    {"DisChargeVoltageValue", "200"}, // 15
    {"ChargeVoltageValue",    "300"}, // 16
    {"DisChargePowerValue",   "400"}, // 17
    {"ChargePowerValue",      "500"}, // 18
    {"DisChargeCurrentValue", "10"},  // 19
    {"ChargeCurrentValue",    "20"},  // 20

    {"TimeStamp", "" }                 // 21
};
QString Responder::respESSRealTimeReadings(QString mRID)
{
    QDomDocument respDoc;
    QDomElement tag;
    QDomText t;

//    QDomNode header = respDoc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"utf-8\"");
//    respDoc.appendChild(header);
    QDomElement respRoot = respDoc.createElement("ESSRealTimeReadings");
    respDoc.appendChild(respRoot);

    ESSRealTimeReadingsItem[0][1] = mRID;
    ESSRealTimeReadingsItem[21][1]= convDateTime();

    for(int i=0; i<DF_ESSREALTIME_SIZE; i++)
    {
        tag = respDoc.createElement(ESSRealTimeReadingsItem[i][0]);
        t = respDoc.createTextNode(ESSRealTimeReadingsItem[i][1]);
        tag.appendChild(t);
        respRoot.appendChild(tag);
    }
    return respDoc.toString();
}

#define DF_CUMULATIVEDATA_SIZE      11
QString CumulativeDataItem[DF_CUMULATIVEDATA_SIZE][2] =
{
    {"mRID",     ""},                            // 0
    {"aliasName","getESSCumulativeDataReadings"},// 1
    {"name",     "response"},                    // 2

    {"GridCumulativeChargeValue",    "1000"},    // 3
    {"GridCumulativeDisChargeValue", "2000"},    // 4
    {"BatteryCumulativeChargeValue", "3000"},    // 5
    {"BatteryCumulativeDisChargeValue", "4000"}, // 6
    {"PVCumulativePowerAmountValue", "5000"},    // 7
    {"LoadCumulativePowerValue",     "6000"},    // 8
    {"period",   "15"},                          // 9
    {"TimeStamp", "" }                          // 10
};
//QString Responder::respCumulativeData(QDomDocument *p_respDoc, QDomElement *p_respRoot)
QString Responder::respCumulativeData(QString mRID)
{
    QDomDocument respDoc;
    QDomElement tag;
    QDomText t;

//    QDomNode header = respDoc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"utf-8\"");
//    respDoc.appendChild(header);
    QDomElement respRoot = respDoc.createElement("ESSCumulativeDataReadings");
    respDoc.appendChild(respRoot);

    CumulativeDataItem[0][1] = mRID;
    CumulativeDataItem[10][1]= convDateTime();

    for(int i=0; i<DF_CUMULATIVEDATA_SIZE; i++)
    {
        tag = respDoc.createElement(CumulativeDataItem[i][0]);
        t = respDoc.createTextNode(CumulativeDataItem[i][1]);
        tag.appendChild(t);
        respRoot.appendChild(tag);
    }

    return respDoc.toString();
}

#define DF_EESUNIT_SIZE 18
QString EesUintItem[DF_EESUNIT_SIZE][2] =
{
    {"mRID",                ""},      // 0
    {"aliasName",           "getEesUnit"},   // 1
    {"name",                "response"},   // 2

    {"BalancingStatus",     "1"},     // 3
    {"BMSStatus",           "1"},     // 4
    {"bypassMCCBStatus",    "1"},     // 5
    {"ChargingStatus",      "1"},     // 6
    {"DemandResponseStatus","1"},     // 7
    {"ESSTemp",             "250"},   // 8
    {"ESSVersion",          "1"},     // 9
    {"BatterySOC",          "50"},    // 10
    {"GridMCCBStatus",      "1"},     // 11
    {"LoadMCCBStatus",      "1"},     // 12
    {"OperationStatus",     "1"},     // 13
    {"PCSStatus",           "1"},     // 14
    {"PVMCCBStatus",        "1"},     // 15
    {"SchedulingStatus",    "1"},     // 16
    {"TimeStamp"            "" }      // 17
};
QString Responder::respEesUnit(QString mRID)
{
    QDomDocument respDoc;
    QDomElement tag;
    QDomText t;

//    QDomNode header = respDoc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"utf-8\"");
//    respDoc.appendChild(header);
    QDomElement respRoot = respDoc.createElement("getEesUnit");
    respDoc.appendChild(respRoot);

    EesUintItem[0][1] = mRID;
    EesUintItem[17][1]= convDateTime();

    for(int i=0; i<DF_EESUNIT_SIZE; i++)
    {
        tag = respDoc.createElement(EesUintItem[i][0]);
        t = respDoc.createTextNode(EesUintItem[i][1]);
        tag.appendChild(t);
        respRoot.appendChild(tag);
    }

    return respDoc.toString();
}

#define DF_PCSFAULT_SIZE 20
QString PCSFaultItem[DF_PCSFAULT_SIZE][2] =
{
    {"mRID",                ""},      // 0
    {"aliasName",           "getPCSFaultMessage"},   // 1
    {"name",                "response"},   // 2

    {"IPMFAULT",     "0"},     // 3
    {"SolarHoct",    "0"},     // 4
    {"BatteryHoct",  "0"},     // 5
    {"GridHoct",     "0"},     // 6
    {"BatteryHovt",  "0"},     // 7
    {"SolarHovt",    "0"},     // 8
    {"DCLinkHovt",   "0"},     // 9
    {"FANFault",     "0"},     // 10
    {"CANERR",       "0"},     // 11
    {"SolarSoct",    "0"},     // 12
    {"BatterySoct",  "0"},     // 13
    {"GridSoct",     "0"},     // 14
    {"DCLinkSovt",   "0"},     // 15
    {"OHTFault",     "0"},     // 16
    {"AntiFrequency","0"},     // 17
    {"AntiVoltage",  "0"},     // 18
    {"TimeStamp"     "" }      // 19
};
QString Responder::respPCSFaultMessage(QString mRID)
{
    QDomDocument respDoc;
    QDomElement tag;
    QDomText t;

    //    QDomNode header = respDoc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"utf-8\"");
    //    respDoc.appendChild(header);
    QDomElement respRoot = respDoc.createElement("getPCSFaultMessage");
    respDoc.appendChild(respRoot);

    PCSFaultItem[0][1] = mRID;
    PCSFaultItem[19][1]= convDateTime();

    for(int i=0; i<DF_PCSFAULT_SIZE; i++)
    {
        tag = respDoc.createElement(PCSFaultItem[i][0]);
        t = respDoc.createTextNode(PCSFaultItem[i][1]);
        tag.appendChild(t);
        respRoot.appendChild(tag);
    }

    return respDoc.toString();
}

#define DF_BATTERYFAULT_SIZE 13
QString BatteryFaultItem[DF_BATTERYFAULT_SIZE][2] =
{
    {"mRID",       ""},                     // 0
    {"aliasName",  "getBatteryFaultMessage"},   // 1
    {"name",       "response"},             // 2

    {"LTC3300CommFail",    "0"},  // 3
    {"CellsOverVoltage",   "0"},  // 4
    {"SecondOverVoltage",  "0"},  // 5
    {"BatteryOverVoltage", "0"},  // 6
    {"BatteryUnderVoltage","0"},  // 7
    {"BatteryOverCurrent", "0"},  // 8
    {"BatteryOverTemp",    "0"},  // 9
    {"BatteryLowTemp",     "0"},  // 10
    {"BatteryImbalance",   "0"},  // 11
    {"SlaveBMSCANSET",     "0"}  // 12
};
QString Responder::respBatteryFaultMessage(QString mRID)
{
    QDomDocument respDoc;
    QDomElement tag;
    QDomText t;

    //    QDomNode header = respDoc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"utf-8\"");
    //    respDoc.appendChild(header);
    QDomElement respRoot = respDoc.createElement("getBatteryFaultMessage");
    respDoc.appendChild(respRoot);

    BatteryFaultItem[0][1] = mRID;
//    BatteryFaultItem[17][1]= convDateTime();

    for(int i=0; i<DF_BATTERYFAULT_SIZE; i++)
    {
        tag = respDoc.createElement(BatteryFaultItem[i][0]);
        t = respDoc.createTextNode(BatteryFaultItem[i][1]);
        tag.appendChild(t);
        respRoot.appendChild(tag);
    }

    return respDoc.toString();
}

#define DF_PCSOPERATION_SIZE 13
QString PCSOperationStatusItem[DF_PCSOPERATION_SIZE][2] =
{
    {"mRID",       ""},                     // 0
    {"aliasName",  "getPCSOperationStatus"},// 1
    {"name",       "response"},             // 2

    {"DirectionMode",    "0"}      // 3
};
QString Responder::respPCSOperationStatus(QString mRID)
{
    QDomDocument respDoc;
    QDomElement tag;
    QDomText t;

    //    QDomNode header = respDoc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"utf-8\"");
    //    respDoc.appendChild(header);
    QDomElement respRoot = respDoc.createElement("getPCSOperationStatus");
    respDoc.appendChild(respRoot);

    PCSOperationStatusItem[0][1] = mRID;
//    PCSOperationStatusItem[17][1]= convDateTime();

    for(int i=0; i<DF_PCSOPERATION_SIZE; i++)
    {
        tag = respDoc.createElement(PCSOperationStatusItem[i][0]);
        t = respDoc.createTextNode(PCSOperationStatusItem[i][1]);
        tag.appendChild(t);
        respRoot.appendChild(tag);
    }

    return respDoc.toString();
}

#define DF_DRMESSAGE_SIZE 9
QString DRMessageItem[DF_DRMESSAGE_SIZE][2] =
{
    {"mRID",       ""},            // 0
    {"aliasName",  "getDRMessage"},// 1
    {"name",       "response"},    // 2

    {"EventID",     ""},      // 3
    {"StartTime",   ""},      // 4
    {"Duration",    "10"},    // 5
    {"ReduceEnergy","0"},     // 6
    {"Status",      "0"},     // 7
    {"ESSStatus",   "0"}     // 8
};
QString Responder::respDRMessage(QString mRID, QString mEventID)
{
    QDomDocument respDoc;
    QDomElement tag;
    QDomText t;

    //    QDomNode header = respDoc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"utf-8\"");
    //    respDoc.appendChild(header);
    QDomElement respRoot = respDoc.createElement("getDRMessage");
    respDoc.appendChild(respRoot);

    DRMessageItem[0][1] = mRID;
    DRMessageItem[3][1] = mEventID;
    DRMessageItem[4][1] = convDateTime();

    for(int i=0; i<DF_DRMESSAGE_SIZE; i++)
    {
        tag = respDoc.createElement(DRMessageItem[i][0]);
        t = respDoc.createTextNode(DRMessageItem[i][1]);
        tag.appendChild(t);
        respRoot.appendChild(tag);
    }

    return respDoc.toString();
}

void Responder::accumulate(const QByteArray &data)
{
    QString response;
    QByteArray baReply;

    QString mRID, mEventID;
    QString payload = QString(data);
    qDebug() << payload;

    QDomDocument document;
    if( !document.setContent( data ) )
    {
      qDebug( "Failed to parse the file into a DOM tree." );
      return ;
    }
    QDomElement root = document.documentElement();

    qDebug() << "root= " << root.tagName() << "type= " << root.nodeType();

    QDomNode node = root.firstChild();
    while(!node.isNull())
    {
        QDomElement e = node.toElement();
        if(!e.isNull())
        {
            qDebug() << "tag="<< e.tagName() << ", text="<< e.text();
            // to do
            if(e.tagName() == "mRID")
                mRID = e.text();
            else if(e.tagName() == "EventID")
                mEventID = e.text();
            else if(e.tagName() == "name")
            {
                if(e.text() == "notification") {
                    resp_type = 100;
                    return;
                }
            }
        }
        node = node.nextSibling();
    }

    m_resp->writeHead(200);

    if(root.tagName() == "getESSRealTimeReadings")
    {
        response = respESSRealTimeReadings(mRID);
    }
    else if(root.tagName() == "getESSCumulativeDataReadings")
    {
        response = respCumulativeData(mRID);
    }
    else if(root.tagName() == "getEesUnit")
    {
        response = respEesUnit(mRID);
    }
    else if(root.tagName() == "getPCSFaultMessage")
    {
        response = respPCSFaultMessage(mRID);
    }
    else if(root.tagName() == "getBatteryFaultMessage")
    {
        response = respBatteryFaultMessage(mRID);
    }
    else if(root.tagName() == "getPCSOperationStatus")
    {
        response = respPCSOperationStatus(mRID);
    }
    else if(root.tagName() == "getDRMessage")
    {
        response = respDRMessage(mRID, mEventID);
    }

    baReply = response.toStdString().c_str();
    m_resp->write(baReply);
}

void Responder::reply()
{
    if(resp_type == 100)
        m_resp->writeHead(403);

    m_resp->end(QByteArray("\r\n\r\n\r\n"));
}

