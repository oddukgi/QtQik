#include "serialform.h"
#include "ui_serialform.h"

MODBUS_PACKET mRxPacket;
MODBUS_PACKET mTxPacket;

MAIN_INFO g_MAIN_INFO;
MAIN_CONTROL g_MAIN_CONTROL;

bool g_time_write_enable;
bool g_schedule_write_enable;
bool g_dr_write_enable;

SerialForm::SerialForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SerialForm)
{
    ui->setupUi(this);

    serial = new QSerialPort(this);

    // powerson add
    openSerialPort();

    // error
    connect(serial, SIGNAL(error(QSerialPort::SerialPortError)), this, SLOT(handleError(QSerialPort::SerialPortError)));

    // read data
    connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));

    // write data
//    connect(console, SIGNAL(getData(QByteArray)), this, SLOT(writeData(QByteArray)));

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(doYourThing()));
    timer->start(317);
}

SerialForm::~SerialForm()
{
    delete ui;
}

void SerialForm::openSerialPort()
{
    serial->setPortName(SERIALPORT_TYPE);
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    if (serial->open(QIODevice::ReadWrite))
    {
    }
    else
    {
        QMessageBox::critical(this, tr("Error"), serial->errorString());
//        ui->statusBar->showMessage(tr("Open error"));
    }
}

void SerialForm::closeSerialPort()
{
    if (serial->isOpen())
        serial->close();
//    console->setEnabled(false);
//    ui->actionConnect->setEnabled(true);
//    ui->actionDisconnect->setEnabled(false);
//    ui->actionConfigure->setEnabled(true);
//    ui->statusBar->showMessage(tr("Disconnected"));
}

void SerialForm::about()
{
    QMessageBox::about(this, tr("About "), tr("test"));
}

u_int16_t	 ModBusCRC_Table[256]=
{
    0x0000, 0xC1C0, 0x81C1, 0x4001, 0x01C3, 0xC003, 0x8002, 0x41C2,
    0x01C6, 0xC006, 0x8007, 0x41C7, 0x0005, 0xC1C5, 0x81C4,	0x4004,
    0x01CC, 0xC00C, 0x800D, 0x41CD, 0x000F, 0xC1CF, 0x81CE, 0x400E,
    0x000A, 0xC1CA, 0x81CB, 0x400B, 0x01C9, 0xC009,	0x8008, 0x41C8,
    0x01D8, 0xC018, 0x8019, 0x41D9, 0x001B, 0xC1DB, 0x81DA, 0x401A,
    0x001E, 0xC1DE, 0x81DF, 0x401F, 0x01DD,	0xC01D, 0x801C, 0x41DC,
    0x0014, 0xC1D4, 0x81D5, 0x4015, 0x01D7, 0xC017, 0x8016, 0x41D6,
    0x01D2, 0xC012, 0x8013, 0x41D3,	0x0011, 0xC1D1, 0x81D0, 0x4010,
    0x01F0, 0xC030, 0x8031, 0x41F1, 0x0033, 0xC1F3, 0x81F2, 0x4032,
    0x0036, 0xC1F6, 0x81F7,	0x4037, 0x01F5, 0xC035, 0x8034, 0x41F4,
    0x003C, 0xC1FC, 0x81FD, 0x403D, 0x01FF, 0xC03F, 0x803E, 0x41FE,
    0x01FA, 0xC03A,	0x803B, 0x41FB, 0x0039, 0xC1F9, 0x81F8, 0x4038,
    0x0028, 0xC1E8, 0x81E9, 0x4029, 0x01EB, 0xC02B, 0x802A, 0x41EA,
    0x01EE,	0xC02E, 0x802F, 0x41EF, 0x002D, 0xC1ED, 0x81EC, 0x402C,
    0x01E4, 0xC024, 0x8025, 0x41E5, 0x0027, 0xC1E7, 0x81E6, 0x4026,
    0x0022, 0xC1E2, 0x81E3, 0x4023, 0x01E1, 0xC021, 0x8020, 0x41E0,
    0x01A0, 0xC060, 0x8061, 0x41A1, 0x0063, 0xC1A3, 0x81A2,	0x4062,
    0x0066, 0xC1A6, 0x81A7, 0x4067, 0x01A5, 0xC065, 0x8064, 0x41A4,
    0x006C, 0xC1AC, 0x81AD, 0x406D, 0x01AF, 0xC06F,	0x806E, 0x41AE,
    0x01AA, 0xC06A, 0x806B, 0x41AB, 0x0069, 0xC1A9, 0x81A8, 0x4068,
    0x0078, 0xC1B8, 0x81B9, 0x4079, 0x01BB,	0xC07B, 0x807A, 0x41BA,
    0x01BE, 0xC07E, 0x807F, 0x41BF, 0x007D, 0xC1BD, 0x81BC, 0x407C,
    0x01B4, 0xC074, 0x8075, 0x41B5,	0x0077, 0xC1B7, 0x81B6, 0x4076,
    0x0072, 0xC1B2, 0x81B3, 0x4073, 0x01B1, 0xC071, 0x8070, 0x41B0,
    0x0050, 0xC190, 0x8191,	0x4051, 0x0193, 0xC053, 0x8052, 0x4192,
    0x0196, 0xC056, 0x8057, 0x4197, 0x0055, 0xC195, 0x8194, 0x4054,
    0x019C, 0xC05C,	0x805D, 0x419D, 0x005F, 0xC19F, 0x819E, 0x405E,
    0x005A, 0xC19A, 0x819B, 0x405B, 0x0199, 0xC059, 0x8058, 0x4198,
    0x0188,	0xC048, 0x8049, 0x4189, 0x004B, 0xC18B, 0x818A, 0x404A,
    0x004E, 0xC18E, 0x818F, 0x404F, 0x018D, 0xC04D, 0x804C, 0x418C,
    0x0044, 0xC184, 0x8185, 0x4045, 0x0187, 0xC047, 0x8046, 0x4186,
    0x0182, 0xC042, 0x8043, 0x4183, 0x0041, 0xC181, 0x8180,	0x4040
};

u_int16_t CRC16_Modbus (u_int8_t*_buf, u_int32_t start, u_int32_t end, u_int16_t* table)
{
    u_int32_t cnt=0, mCRC=0xffff;
    for( cnt=start; cnt<end; cnt++)
    {
        mCRC = (u_int16_t)((mCRC << 8) ^ table[((mCRC >> 8) ^ _buf[cnt]) & 0x00FF]);
    }
    return mCRC;
}

void SerialForm::writeData(const QByteArray &data)
{
    serial->write(data);
}

void    ModBus_Receive_03 ()
{
    u_int16_t i;
    u_int16_t mAddress=0;
    u_int16_t mDataSize=0;

    if(mRxPacket.tQuantity.data == 0) // error
    {
        return;
    }

    mAddress = mRxPacket.tAddress.data;

    mDataSize = (int)sizeof(g_MAIN_INFO.pdata) / (int)sizeof(u16);

    if( (mAddress <= mDataSize) 	// Address 0 ~ 235 (236 quantity)
        && (mAddress + mRxPacket.tQuantity.data <= mDataSize+1)
        && (mRxPacket.tQuantity.data >= 1 && mRxPacket.tQuantity.data <= 123) )
    {
        // receive ok!
        for( i=0; i<mRxPacket.tQuantity.data; i++ )
        {
            g_MAIN_INFO.pdata[mAddress+i] = mRxPacket.tData[i].data;
        }
    }
}

void    ModBus_Receive_10 ()
{
    u_int16_t i;
    u_int16_t mAddress=0;

    if(mRxPacket.tQuantity.data == 0) // error
    {
        return;
    }

    mAddress = mRxPacket.tAddress.data;

    if( (mAddress >= 1000 && mAddress <= 1113) 	// 1000 ~ 1113 (114 quantity)
            && (mAddress + mRxPacket.tQuantity.data <= 114)
            && (mRxPacket.tQuantity.data >= 1 && mRxPacket.tQuantity.data <= 123) )
    {
        // receive ok!
        i=0;
    }
}


void SerialForm::readData()
{
    QByteArray rxdata;
    int i, j;
    u_int16_t rxcrc=0, calcrc=0;
    while (serial->waitForReadyRead(200))
        rxdata += serial->readAll();
    if( rxdata.length() > 0 )
    {
        for(i=0; i<rxdata.length(); i++)
        {
            if( rxdata[i] == 1 )    // modbus id success
            {
                calcrc = CRC16_Modbus((u_int8_t*)rxdata.data(), i, rxdata.length()-2, ModBusCRC_Table);
                rxcrc = ((rxdata[rxdata.length()-2] << 8 ) & 0xff00) | (rxdata[rxdata.length()-1] & 0x00ff);
                if( calcrc == rxcrc )
                {
                    mRxPacket.mID               = rxdata[i];
                    mRxPacket.mFunctionCode     = rxdata[i+1];
                    switch(mRxPacket.mFunctionCode)
                    {
                    case 0x03 :
                        mRxPacket.mDataLength 		= rxdata[i+2];
                        for(j=0; j<(mRxPacket.mDataLength/2); j++)
                        {
                            mRxPacket.tData[j].bit8[1] = rxdata[i+3+(j*2)]; // msb
                            mRxPacket.tData[j].bit8[0] = rxdata[i+4+(j*2)]; // lsb
                        }
                        mRxPacket.tQuantity.data = mRxPacket.mDataLength / 2;	// [중요]계산해야됨.
                        ModBus_Receive_03();
                        break;
                    case 0x10 :
                        mRxPacket.tAddress.bit8[1]  = rxdata[i+2];  	// msb
                        mRxPacket.tAddress.bit8[0]  = rxdata[i+3];  	// lsb
                        mRxPacket.tQuantity.bit8[1] = rxdata[i+4];  	// msb
                        mRxPacket.tQuantity.bit8[0] = rxdata[i+5];  	// lsb
                        ModBus_Receive_10();
                        break;
                    }
                }
                rxdata.clear();
            }
        }
    }
}

void SerialForm::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError)
    {
        QMessageBox::critical(this, tr("Critical Error"), serial->errorString());
        closeSerialPort();
    }
}

void SerialForm::doYourThing()
{
    u_int16_t idx=0, i;
    u_int8_t  pData[256];

    static u_int8_t cnt=0;

    mTxPacket.mID = 1;

    // command 우선순위가 status보다높게..
    if( g_time_write_enable == true )
    {
        g_time_write_enable = false;
        mTxPacket.mFunctionCode = 0x10;
        mTxPacket.tAddress.data = 1000;
        mTxPacket.tQuantity.data = 6;
        for( i=0; i<6; i++ )
        {
            mTxPacket.tData[i].data = g_MAIN_CONTROL.time.pdata[i];
        }
    }
    else if( g_schedule_write_enable == true )
    {
        g_schedule_write_enable = false;
        mTxPacket.mFunctionCode = 0x10;
        mTxPacket.tAddress.data = 1006;
        mTxPacket.tQuantity.data = 72;
        for( i=0; i<72; i++ )
        {
            mTxPacket.tData[i].data = g_MAIN_CONTROL.schedule.pdata[i];
        }
    }
    else if( g_dr_write_enable == true )
    {
        g_dr_write_enable = false;
        mTxPacket.mFunctionCode = 0x10;
        mTxPacket.tAddress.data = 1078;
        mTxPacket.tQuantity.data = 36;
        for( i=0; i<36; i++ )
        {
            mTxPacket.tData[i].data = g_MAIN_CONTROL.dr.pdata[i];
        }
    }
    else
    {
        // status
        if( cnt == 0 )
        {
            mTxPacket.mFunctionCode = 0x03;
            mTxPacket.tAddress.data = 0;
            mTxPacket.tQuantity.data = 118;
        }
        else if( cnt == 1 )
        {
            mTxPacket.mFunctionCode = 0x03;
            mTxPacket.tAddress.data = 118;
            mTxPacket.tQuantity.data = 118;
        }

        if( cnt++ >= 1 )
        {
            cnt = 0;
        }
    }

    mRxPacket.tAddress.data = mTxPacket.tAddress.data;
    mTxPacket.mDataLength = mTxPacket.tQuantity.data * 2;

    pData[idx++] = mTxPacket.mID;
    pData[idx++] = mTxPacket.mFunctionCode;

    switch(mTxPacket.mFunctionCode)
    {
    case    0x03:
        pData[idx++] = mTxPacket.tAddress.bit8[1];
        pData[idx++] = mTxPacket.tAddress.bit8[0];
        pData[idx++] = mTxPacket.tQuantity.bit8[1];
        pData[idx++] = mTxPacket.tQuantity.bit8[0];
        break;
    case    0x10:
        pData[idx++] = mTxPacket.tAddress.bit8[1];
        pData[idx++] = mTxPacket.tAddress.bit8[0];
        pData[idx++] = mTxPacket.tQuantity.bit8[1];
        pData[idx++] = mTxPacket.tQuantity.bit8[0];
        pData[idx++] = mTxPacket.mDataLength;
        for(i=0; i<mTxPacket.tQuantity.data; i++)
        {
            pData[idx++] = mTxPacket.tData[i].bit8[1];
            pData[idx++] = mTxPacket.tData[i].bit8[0];
        }
        break;
    }

    mTxPacket.tCrc.data = CRC16_Modbus( pData, 0, idx, (u_int16_t*)ModBusCRC_Table);	// [중요] dummy 없는 version

    pData[idx++] = mTxPacket.tCrc.bit8[1];
    pData[idx++] = mTxPacket.tCrc.bit8[0];

    QByteArray txdata = QByteArray::fromRawData((char*)&pData, sizeof(pData));

    serial->write(txdata, idx);
}
