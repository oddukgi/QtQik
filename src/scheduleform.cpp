#include <QApplication>
#include <QString>
#include "header.h"

ScheduleForm::ScheduleForm(QWidget *parent) : QWidget(parent), ui(new Ui::ScheduleForm)
{
    ui->setupUi(this);

    // connect the signal for selection change
    connect(ui->pushButton_set, SIGNAL(pressed()), this, SLOT(scheduleform_update()));

    QTimer *timer1 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()), this, SLOT(main_time_update()));
    timer1->start(30000);

    QTimer *timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()), this, SLOT(check()));
    timer2->start(1000);

    main_time_update();
}

ScheduleForm::~ScheduleForm()
{
    delete ui;
}

void ScheduleForm::schedule_set_textbox_init()
{
    QString str_SetStartTime = QString("%1").arg(g_MAIN_INFO.schedule.num[0].StartTime);     // 1
    ui->textEdit_SetStartTime->setText(str_SetStartTime);

    QString str_SetStartTime_2 = QString("%1").arg(g_MAIN_INFO.schedule.num[1].StartTime);     // 2
    ui->textEdit_SetStartTime_2->setText(str_SetStartTime_2);

    QString str_SetStartTime_3 = QString("%1").arg(g_MAIN_INFO.schedule.num[2].StartTime);     // 3
    ui->textEdit_SetStartTime_3->setText(str_SetStartTime_3);

    QString str_SetStartTime_4 = QString("%1").arg(g_MAIN_INFO.schedule.num[3].StartTime);     // 4
    ui->textEdit_SetStartTime_4->setText(str_SetStartTime_4);

    QString str_SetStartTime_5 = QString("%1").arg(g_MAIN_INFO.schedule.num[4].StartTime);     // 5
    ui->textEdit_SetStartTime_5->setText(str_SetStartTime_5);

    QString str_SetStartTime_6 = QString("%1").arg(g_MAIN_INFO.schedule.num[5].StartTime);     // 6
    ui->textEdit_SetStartTime_6->setText(str_SetStartTime_6);

    QString str_SetStartTime_7 = QString("%1").arg(g_MAIN_INFO.schedule.num[6].StartTime);     // 7
    ui->textEdit_SetStartTime_7->setText(str_SetStartTime_7);

    QString str_SetStartTime_8 = QString("%1").arg(g_MAIN_INFO.schedule.num[7].StartTime);     // 8
    ui->textEdit_SetStartTime_8->setText(str_SetStartTime_8);

    QString str_SetStartTime_9 = QString("%1").arg(g_MAIN_INFO.schedule.num[8].StartTime);     // 9
    ui->textEdit_SetStartTime_9->setText(str_SetStartTime_9);

    QString str_SetStartTime_10 = QString("%1").arg(g_MAIN_INFO.schedule.num[9].StartTime);     // 10
    ui->textEdit_SetStartTime_10->setText(str_SetStartTime_10);

    QString str_SetStartTime_11 = QString("%1").arg(g_MAIN_INFO.schedule.num[10].StartTime);     // 11
    ui->textEdit_SetStartTime_11->setText(str_SetStartTime_11);

    QString str_SetStartTime_12 = QString("%1").arg(g_MAIN_INFO.schedule.num[11].StartTime);     // 12
    ui->textEdit_SetStartTime_12->setText(str_SetStartTime_12);

//    QString str_SetStartTime_13 = QString("%1").arg(g_MAIN_INFO.schedule.num[12].StartTime);     // 13
//    ui->textEdit_SetStartTime_13->setText(str_SetStartTime_13);

//    QString str_SetStartTime_14 = QString("%1").arg(g_MAIN_INFO.schedule.num[13].StartTime);     // 14
//    ui->textEdit_SetStartTime_14->setText(str_SetStartTime_14);

//    QString str_SetStartTime_15 = QString("%1").arg(g_MAIN_INFO.schedule.num[14].StartTime);     // 15
//    ui->textEdit_SetStartTime_15->setText(str_SetStartTime_15);

//    QString str_SetStartTime_16 = QString("%1").arg(g_MAIN_INFO.schedule.num[15].StartTime);     // 16
//    ui->textEdit_SetStartTime_16->setText(str_SetStartTime_16);

//    QString str_SetStartTime_17 = QString("%1").arg(g_MAIN_INFO.schedule.num[16].StartTime);     // 17
//    ui->textEdit_SetStartTime_17->setText(str_SetStartTime_17);

//    QString str_SetStartTime_18 = QString("%1").arg(g_MAIN_INFO.schedule.num[17].StartTime);     // 18
//    ui->textEdit_SetStartTime_18->setText(str_SetStartTime_18);

//    QString str_SetStartTime_19 = QString("%1").arg(g_MAIN_INFO.schedule.num[18].StartTime);     // 19
//    ui->textEdit_SetStartTime_19->setText(str_SetStartTime_19);

//    QString str_SetStartTime_20 = QString("%1").arg(g_MAIN_INFO.schedule.num[19].StartTime);     // 20
//    ui->textEdit_SetStartTime_20->setText(str_SetStartTime_20);

//    QString str_SetStartTime_21 = QString("%1").arg(g_MAIN_INFO.schedule.num[20].StartTime);     // 21
//    ui->textEdit_SetStartTime_21->setText(str_SetStartTime_21);

//    QString str_SetStartTime_22 = QString("%1").arg(g_MAIN_INFO.schedule.num[21].StartTime);     // 22
//    ui->textEdit_SetStartTime_22->setText(str_SetStartTime_22);

//    QString str_SetStartTime_23 = QString("%1").arg(g_MAIN_INFO.schedule.num[22].StartTime);     // 23
//    ui->textEdit_SetStartTime_23->setText(str_SetStartTime_23);

//    QString str_SetStartTime_24 = QString("%1").arg(g_MAIN_INFO.schedule.num[23].StartTime);     // 24
//    ui->textEdit_SetStartTime_24->setText(str_SetStartTime_24);

    QString str_SetPower = QString("%1").arg(g_MAIN_INFO.schedule.num[0].Power);
    ui->textEdit_SetPower->setText(str_SetPower);

    QString str_SetPower_2 = QString("%1").arg(g_MAIN_INFO.schedule.num[1].Power);
    ui->textEdit_SetPower_2->setText(str_SetPower_2);

    QString str_SetPower_3 = QString("%1").arg(g_MAIN_INFO.schedule.num[2].Power);
    ui->textEdit_SetPower_3->setText(str_SetPower_3);

    QString str_SetPower_4 = QString("%1").arg(g_MAIN_INFO.schedule.num[3].Power);
    ui->textEdit_SetPower_4->setText(str_SetPower_4);

    QString str_SetPower_5 = QString("%1").arg(g_MAIN_INFO.schedule.num[4].Power);
    ui->textEdit_SetPower_5->setText(str_SetPower_5);

    QString str_SetPower_6 = QString("%1").arg(g_MAIN_INFO.schedule.num[5].Power);
    ui->textEdit_SetPower_6->setText(str_SetPower_6);

    QString str_SetPower_7 = QString("%1").arg(g_MAIN_INFO.schedule.num[6].Power);
    ui->textEdit_SetPower_7->setText(str_SetPower_7);

    QString str_SetPower_8 = QString("%1").arg(g_MAIN_INFO.schedule.num[7].Power);
    ui->textEdit_SetPower_8->setText(str_SetPower_8);

    QString str_SetPower_9 = QString("%1").arg(g_MAIN_INFO.schedule.num[8].Power);
    ui->textEdit_SetPower_9->setText(str_SetPower_9);

    QString str_SetPower_10 = QString("%1").arg(g_MAIN_INFO.schedule.num[9].Power);
    ui->textEdit_SetPower_10->setText(str_SetPower_10);

    QString str_SetPower_11 = QString("%1").arg(g_MAIN_INFO.schedule.num[10].Power);
    ui->textEdit_SetPower_11->setText(str_SetPower_11);

    QString str_SetPower_12 = QString("%1").arg(g_MAIN_INFO.schedule.num[11].Power);
    ui->textEdit_SetPower_12->setText(str_SetPower_12);

//    QString str_SetPower_13 = QString("%1").arg(g_MAIN_INFO.schedule.num[12].Power);
//    ui->textEdit_SetPower_13->setText(str_SetPower_13);

//    QString str_SetPower_14 = QString("%1").arg(g_MAIN_INFO.schedule.num[13].Power);
//    ui->textEdit_SetPower_14->setText(str_SetPower_14);

//    QString str_SetPower_15 = QString("%1").arg(g_MAIN_INFO.schedule.num[14].Power);
//    ui->textEdit_SetPower_15->setText(str_SetPower_15);

//    QString str_SetPower_16 = QString("%1").arg(g_MAIN_INFO.schedule.num[15].Power);
//    ui->textEdit_SetPower_16->setText(str_SetPower_16);

//    QString str_SetPower_17 = QString("%1").arg(g_MAIN_INFO.schedule.num[16].Power);
//    ui->textEdit_SetPower_17->setText(str_SetPower_17);

//    QString str_SetPower_18 = QString("%1").arg(g_MAIN_INFO.schedule.num[17].Power);
//    ui->textEdit_SetPower_18->setText(str_SetPower_18);

//    QString str_SetPower_19 = QString("%1").arg(g_MAIN_INFO.schedule.num[18].Power);
//    ui->textEdit_SetPower_19->setText(str_SetPower_19);

//    QString str_SetPower_20 = QString("%1").arg(g_MAIN_INFO.schedule.num[19].Power);
//    ui->textEdit_SetPower_20->setText(str_SetPower_20);

//    QString str_SetPower_21 = QString("%1").arg(g_MAIN_INFO.schedule.num[20].Power);
//    ui->textEdit_SetPower_21->setText(str_SetPower_21);

//    QString str_SetPower_22 = QString("%1").arg(g_MAIN_INFO.schedule.num[21].Power);
//    ui->textEdit_SetPower_22->setText(str_SetPower_22);

//    QString str_SetPower_23 = QString("%1").arg(g_MAIN_INFO.schedule.num[22].Power);
//    ui->textEdit_SetPower_23->setText(str_SetPower_23);

//    QString str_SetPower_24 = QString("%1").arg(g_MAIN_INFO.schedule.num[23].Power);
//    ui->textEdit_SetPower_24->setText(str_SetPower_24);

    QString str_SetDirectionMode = QString("%1").arg(g_MAIN_INFO.schedule.num[0].DirectionMode);
    ui->textEdit_SetDirection->setText(str_SetDirectionMode);

    QString str_SetDirectionMode_2 = QString("%1").arg(g_MAIN_INFO.schedule.num[1].DirectionMode);
    ui->textEdit_SetDirection_2->setText(str_SetDirectionMode_2);

    QString str_SetDirectionMode_3 = QString("%1").arg(g_MAIN_INFO.schedule.num[2].DirectionMode);
    ui->textEdit_SetDirection_3->setText(str_SetDirectionMode_3);

    QString str_SetDirectionMode_4 = QString("%1").arg(g_MAIN_INFO.schedule.num[3].DirectionMode);
    ui->textEdit_SetDirection_4->setText(str_SetDirectionMode_4);

    QString str_SetDirectionMode_5 = QString("%1").arg(g_MAIN_INFO.schedule.num[4].DirectionMode);
    ui->textEdit_SetDirection_5->setText(str_SetDirectionMode_5);

    QString str_SetDirectionMode_6 = QString("%1").arg(g_MAIN_INFO.schedule.num[5].DirectionMode);
    ui->textEdit_SetDirection_6->setText(str_SetDirectionMode_6);

    QString str_SetDirectionMode_7 = QString("%1").arg(g_MAIN_INFO.schedule.num[6].DirectionMode);
    ui->textEdit_SetDirection_7->setText(str_SetDirectionMode_7);

    QString str_SetDirectionMode_8 = QString("%1").arg(g_MAIN_INFO.schedule.num[7].DirectionMode);
    ui->textEdit_SetDirection_8->setText(str_SetDirectionMode_8);

    QString str_SetDirectionMode_9 = QString("%1").arg(g_MAIN_INFO.schedule.num[8].DirectionMode);
    ui->textEdit_SetDirection_9->setText(str_SetDirectionMode_9);

    QString str_SetDirectionMode_10 = QString("%1").arg(g_MAIN_INFO.schedule.num[9].DirectionMode);
    ui->textEdit_SetDirection_10->setText(str_SetDirectionMode_10);

    QString str_SetDirectionMode_11 = QString("%1").arg(g_MAIN_INFO.schedule.num[10].DirectionMode);
    ui->textEdit_SetDirection_11->setText(str_SetDirectionMode_11);

    QString str_SetDirectionMode_12 = QString("%1").arg(g_MAIN_INFO.schedule.num[11].DirectionMode);
    ui->textEdit_SetDirection_12->setText(str_SetDirectionMode_12);

//    QString str_SetDirectionMode_13 = QString("%1").arg(g_MAIN_INFO.schedule.num[12].DirectionMode);
//    ui->textEdit_SetDirection_13->setText(str_SetDirectionMode_13);

//    QString str_SetDirectionMode_14 = QString("%1").arg(g_MAIN_INFO.schedule.num[13].DirectionMode);
//    ui->textEdit_SetDirection_14->setText(str_SetDirectionMode_14);

//    QString str_SetDirectionMode_15 = QString("%1").arg(g_MAIN_INFO.schedule.num[14].DirectionMode);
//    ui->textEdit_SetDirection_15->setText(str_SetDirectionMode_15);

//    QString str_SetDirectionMode_16 = QString("%1").arg(g_MAIN_INFO.schedule.num[15].DirectionMode);
//    ui->textEdit_SetDirection_16->setText(str_SetDirectionMode_16);

//    QString str_SetDirectionMode_17 = QString("%1").arg(g_MAIN_INFO.schedule.num[16].DirectionMode);
//    ui->textEdit_SetDirection_17->setText(str_SetDirectionMode_17);

//    QString str_SetDirectionMode_18 = QString("%1").arg(g_MAIN_INFO.schedule.num[17].DirectionMode);
//    ui->textEdit_SetDirection_18->setText(str_SetDirectionMode_18);

//    QString str_SetDirectionMode_19 = QString("%1").arg(g_MAIN_INFO.schedule.num[18].DirectionMode);
//    ui->textEdit_SetDirection_19->setText(str_SetDirectionMode_19);

//    QString str_SetDirectionMode_20 = QString("%1").arg(g_MAIN_INFO.schedule.num[19].DirectionMode);
//    ui->textEdit_SetDirection_20->setText(str_SetDirectionMode_20);

//    QString str_SetDirectionMode_21 = QString("%1").arg(g_MAIN_INFO.schedule.num[20].DirectionMode);
//    ui->textEdit_SetDirection_21->setText(str_SetDirectionMode_21);

//    QString str_SetDirectionMode_22 = QString("%1").arg(g_MAIN_INFO.schedule.num[21].DirectionMode);
//    ui->textEdit_SetDirection_22->setText(str_SetDirectionMode_22);

//    QString str_SetDirectionMode_23 = QString("%1").arg(g_MAIN_INFO.schedule.num[22].DirectionMode);
//    ui->textEdit_SetDirection_23->setText(str_SetDirectionMode_23);

//    QString str_SetDirectionMode_24 = QString("%1").arg(g_MAIN_INFO.schedule.num[23].DirectionMode);
//    ui->textEdit_SetDirection_24->setText(str_SetDirectionMode_24);
}

void ScheduleForm::main_time_update()
{
    g_time_write_enable = true;

    int year = QString("%1").arg(QDateTime::fromString( QDateTime::currentDateTime().toString(), Qt::TextDate ).toString("yyyy")).toInt();
    int month = QString("%1").arg(QDateTime::fromString( QDateTime::currentDateTime().toString(), Qt::TextDate ).toString("MM")).toInt();
    int day = QString("%1").arg(QDateTime::fromString( QDateTime::currentDateTime().toString(), Qt::TextDate ).toString("dd")).toInt();
    int hour = QString("%1").arg(QDateTime::fromString( QDateTime::currentDateTime().toString(), Qt::TextDate ).toString("hh")).toInt();
    int minute = QString("%1").arg(QDateTime::fromString( QDateTime::currentDateTime().toString(), Qt::TextDate ).toString("mm")).toInt();
    int second = QString("%1").arg(QDateTime::fromString( QDateTime::currentDateTime().toString(), Qt::TextDate ).toString("ss")).toInt();
    g_MAIN_CONTROL.time.Year = (int16_t)year;
    g_MAIN_CONTROL.time.Month = (int16_t)month;
    g_MAIN_CONTROL.time.Day = (int16_t)day;
    g_MAIN_CONTROL.time.Hour = (int16_t)hour;
    g_MAIN_CONTROL.time.Minute = (int16_t)minute;
    g_MAIN_CONTROL.time.Sec = (int16_t)second;
}

void ScheduleForm::time_check()
{
    QDateTime v = QDateTime::currentDateTime();
    QString guiTime = QString("%1").arg(QDateTime::fromString(v.toString(),Qt::TextDate).toString("yyyy-MM-dd hh:mm:ss"));
    ui->textEdit_GUI_Time->setText(guiTime);

    ui->textEdit_Main_Time->setText(QString("%1-%2-%3 %4:%5:%6")
                                    .arg(g_MAIN_INFO.time.Year)
                                    .arg(g_MAIN_INFO.time.Month)
                                    .arg(g_MAIN_INFO.time.Day)
                                    .arg(g_MAIN_INFO.time.Hour)
                                    .arg(g_MAIN_INFO.time.Minute)
                                    .arg(g_MAIN_INFO.time.Sec));
}

void ScheduleForm::schedule_check()
{
    QString str_GetStartTime = QString("%1").arg(g_MAIN_INFO.schedule.num[0].StartTime);     // 1
    ui->textEdit_GetStartTime->setText(str_GetStartTime);

    QString str_GetStartTime_2 = QString("%1").arg(g_MAIN_INFO.schedule.num[1].StartTime);     // 2
    ui->textEdit_GetStartTime_2->setText(str_GetStartTime_2);

    QString str_GetStartTime_3 = QString("%1").arg(g_MAIN_INFO.schedule.num[2].StartTime);     // 3
    ui->textEdit_GetStartTime_3->setText(str_GetStartTime_3);

    QString str_GetStartTime_4 = QString("%1").arg(g_MAIN_INFO.schedule.num[3].StartTime);     // 4
    ui->textEdit_GetStartTime_4->setText(str_GetStartTime_4);

    QString str_GetStartTime_5 = QString("%1").arg(g_MAIN_INFO.schedule.num[4].StartTime);     // 5
    ui->textEdit_GetStartTime_5->setText(str_GetStartTime_5);

    QString str_GetStartTime_6 = QString("%1").arg(g_MAIN_INFO.schedule.num[5].StartTime);     // 6
    ui->textEdit_GetStartTime_6->setText(str_GetStartTime_6);

    QString str_GetStartTime_7 = QString("%1").arg(g_MAIN_INFO.schedule.num[6].StartTime);     // 7
    ui->textEdit_GetStartTime_7->setText(str_GetStartTime_7);

    QString str_GetStartTime_8 = QString("%1").arg(g_MAIN_INFO.schedule.num[7].StartTime);     // 8
    ui->textEdit_GetStartTime_8->setText(str_GetStartTime_8);

    QString str_GetStartTime_9 = QString("%1").arg(g_MAIN_INFO.schedule.num[8].StartTime);     // 9
    ui->textEdit_GetStartTime_9->setText(str_GetStartTime_9);

    QString str_GetStartTime_10 = QString("%1").arg(g_MAIN_INFO.schedule.num[9].StartTime);     // 10
    ui->textEdit_GetStartTime_10->setText(str_GetStartTime_10);

    QString str_GetStartTime_11 = QString("%1").arg(g_MAIN_INFO.schedule.num[10].StartTime);     // 11
    ui->textEdit_GetStartTime_11->setText(str_GetStartTime_11);

    QString str_GetStartTime_12 = QString("%1").arg(g_MAIN_INFO.schedule.num[11].StartTime);     // 12
    ui->textEdit_GetStartTime_12->setText(str_GetStartTime_12);

//    QString str_GetStartTime_13 = QString("%1").arg(g_MAIN_INFO.schedule.num[12].StartTime);     // 13
//    ui->textEdit_GetStartTime_13->setText(str_GetStartTime_13);

//    QString str_GetStartTime_14 = QString("%1").arg(g_MAIN_INFO.schedule.num[13].StartTime);     // 14
//    ui->textEdit_GetStartTime_14->setText(str_GetStartTime_14);

//    QString str_GetStartTime_15 = QString("%1").arg(g_MAIN_INFO.schedule.num[14].StartTime);     // 15
//    ui->textEdit_GetStartTime_15->setText(str_GetStartTime_15);

//    QString str_GetStartTime_16 = QString("%1").arg(g_MAIN_INFO.schedule.num[15].StartTime);     // 16
//    ui->textEdit_GetStartTime_16->setText(str_GetStartTime_16);

//    QString str_GetStartTime_17 = QString("%1").arg(g_MAIN_INFO.schedule.num[16].StartTime);     // 17
//    ui->textEdit_GetStartTime_17->setText(str_GetStartTime_17);

//    QString str_GetStartTime_18 = QString("%1").arg(g_MAIN_INFO.schedule.num[17].StartTime);     // 18
//    ui->textEdit_GetStartTime_18->setText(str_GetStartTime_18);

//    QString str_GetStartTime_19 = QString("%1").arg(g_MAIN_INFO.schedule.num[18].StartTime);     // 19
//    ui->textEdit_GetStartTime_19->setText(str_GetStartTime_19);

//    QString str_GetStartTime_20 = QString("%1").arg(g_MAIN_INFO.schedule.num[19].StartTime);     // 20
//    ui->textEdit_GetStartTime_20->setText(str_GetStartTime_20);

//    QString str_GetStartTime_21 = QString("%1").arg(g_MAIN_INFO.schedule.num[20].StartTime);     // 21
//    ui->textEdit_GetStartTime_21->setText(str_GetStartTime_21);

//    QString str_GetStartTime_22 = QString("%1").arg(g_MAIN_INFO.schedule.num[21].StartTime);     // 22
//    ui->textEdit_GetStartTime_22->setText(str_GetStartTime_22);

//    QString str_GetStartTime_23 = QString("%1").arg(g_MAIN_INFO.schedule.num[22].StartTime);     // 23
//    ui->textEdit_GetStartTime_23->setText(str_GetStartTime_23);

//    QString str_GetStartTime_24 = QString("%1").arg(g_MAIN_INFO.schedule.num[23].StartTime);     // 24
//    ui->textEdit_GetStartTime_24->setText(str_GetStartTime_24);

    QString str_GetPower = QString("%1").arg(g_MAIN_INFO.schedule.num[0].Power);
    ui->textEdit_GetPower->setText(str_GetPower);

    QString str_GetPower_2 = QString("%1").arg(g_MAIN_INFO.schedule.num[1].Power);
    ui->textEdit_GetPower_2->setText(str_GetPower_2);

    QString str_GetPower_3 = QString("%1").arg(g_MAIN_INFO.schedule.num[2].Power);
    ui->textEdit_GetPower_3->setText(str_GetPower_3);

    QString str_GetPower_4 = QString("%1").arg(g_MAIN_INFO.schedule.num[3].Power);
    ui->textEdit_GetPower_4->setText(str_GetPower_4);

    QString str_GetPower_5 = QString("%1").arg(g_MAIN_INFO.schedule.num[4].Power);
    ui->textEdit_GetPower_5->setText(str_GetPower_5);

    QString str_GetPower_6 = QString("%1").arg(g_MAIN_INFO.schedule.num[5].Power);
    ui->textEdit_GetPower_6->setText(str_GetPower_6);

    QString str_GetPower_7 = QString("%1").arg(g_MAIN_INFO.schedule.num[6].Power);
    ui->textEdit_GetPower_7->setText(str_GetPower_7);

    QString str_GetPower_8 = QString("%1").arg(g_MAIN_INFO.schedule.num[7].Power);
    ui->textEdit_GetPower_8->setText(str_GetPower_8);

    QString str_GetPower_9 = QString("%1").arg(g_MAIN_INFO.schedule.num[8].Power);
    ui->textEdit_GetPower_9->setText(str_GetPower_9);

    QString str_GetPower_10 = QString("%1").arg(g_MAIN_INFO.schedule.num[9].Power);
    ui->textEdit_GetPower_10->setText(str_GetPower_10);

    QString str_GetPower_11 = QString("%1").arg(g_MAIN_INFO.schedule.num[10].Power);
    ui->textEdit_GetPower_11->setText(str_GetPower_11);

    QString str_GetPower_12 = QString("%1").arg(g_MAIN_INFO.schedule.num[11].Power);
    ui->textEdit_GetPower_12->setText(str_GetPower_12);

//    QString str_GetPower_13 = QString("%1").arg(g_MAIN_INFO.schedule.num[12].Power);
//    ui->textEdit_GetPower_13->setText(str_GetPower_13);

//    QString str_GetPower_14 = QString("%1").arg(g_MAIN_INFO.schedule.num[13].Power);
//    ui->textEdit_GetPower_14->setText(str_GetPower_14);

//    QString str_GetPower_15 = QString("%1").arg(g_MAIN_INFO.schedule.num[14].Power);
//    ui->textEdit_GetPower_15->setText(str_GetPower_15);

//    QString str_GetPower_16 = QString("%1").arg(g_MAIN_INFO.schedule.num[15].Power);
//    ui->textEdit_GetPower_16->setText(str_GetPower_16);

//    QString str_GetPower_17 = QString("%1").arg(g_MAIN_INFO.schedule.num[16].Power);
//    ui->textEdit_GetPower_17->setText(str_GetPower_17);

//    QString str_GetPower_18 = QString("%1").arg(g_MAIN_INFO.schedule.num[17].Power);
//    ui->textEdit_GetPower_18->setText(str_GetPower_18);

//    QString str_GetPower_19 = QString("%1").arg(g_MAIN_INFO.schedule.num[18].Power);
//    ui->textEdit_GetPower_19->setText(str_GetPower_19);

//    QString str_GetPower_20 = QString("%1").arg(g_MAIN_INFO.schedule.num[19].Power);
//    ui->textEdit_GetPower_20->setText(str_GetPower_20);

//    QString str_GetPower_21 = QString("%1").arg(g_MAIN_INFO.schedule.num[20].Power);
//    ui->textEdit_GetPower_21->setText(str_GetPower_21);

//    QString str_GetPower_22 = QString("%1").arg(g_MAIN_INFO.schedule.num[21].Power);
//    ui->textEdit_GetPower_22->setText(str_GetPower_22);

//    QString str_GetPower_23 = QString("%1").arg(g_MAIN_INFO.schedule.num[22].Power);
//    ui->textEdit_GetPower_23->setText(str_GetPower_23);

//    QString str_GetPower_24 = QString("%1").arg(g_MAIN_INFO.schedule.num[23].Power);
//    ui->textEdit_GetPower_24->setText(str_GetPower_24);

    QString str_GetDirectionMode = QString("%1").arg(g_MAIN_INFO.schedule.num[0].DirectionMode);
    ui->textEdit_GetDirection->setText(str_GetDirectionMode);

    QString str_GetDirectionMode_2 = QString("%1").arg(g_MAIN_INFO.schedule.num[1].DirectionMode);
    ui->textEdit_GetDirection_2->setText(str_GetDirectionMode_2);

    QString str_GetDirectionMode_3 = QString("%1").arg(g_MAIN_INFO.schedule.num[2].DirectionMode);
    ui->textEdit_GetDirection_3->setText(str_GetDirectionMode_3);

    QString str_GetDirectionMode_4 = QString("%1").arg(g_MAIN_INFO.schedule.num[3].DirectionMode);
    ui->textEdit_GetDirection_4->setText(str_GetDirectionMode_4);

    QString str_GetDirectionMode_5 = QString("%1").arg(g_MAIN_INFO.schedule.num[4].DirectionMode);
    ui->textEdit_GetDirection_5->setText(str_GetDirectionMode_5);

    QString str_GetDirectionMode_6 = QString("%1").arg(g_MAIN_INFO.schedule.num[5].DirectionMode);
    ui->textEdit_GetDirection_6->setText(str_GetDirectionMode_6);

    QString str_GetDirectionMode_7 = QString("%1").arg(g_MAIN_INFO.schedule.num[6].DirectionMode);
    ui->textEdit_GetDirection_7->setText(str_GetDirectionMode_7);

    QString str_GetDirectionMode_8 = QString("%1").arg(g_MAIN_INFO.schedule.num[7].DirectionMode);
    ui->textEdit_GetDirection_8->setText(str_GetDirectionMode_8);

    QString str_GetDirectionMode_9 = QString("%1").arg(g_MAIN_INFO.schedule.num[8].DirectionMode);
    ui->textEdit_GetDirection_9->setText(str_GetDirectionMode_9);

    QString str_GetDirectionMode_10 = QString("%1").arg(g_MAIN_INFO.schedule.num[9].DirectionMode);
    ui->textEdit_GetDirection_10->setText(str_GetDirectionMode_10);

    QString str_GetDirectionMode_11 = QString("%1").arg(g_MAIN_INFO.schedule.num[10].DirectionMode);
    ui->textEdit_GetDirection_11->setText(str_GetDirectionMode_11);

    QString str_GetDirectionMode_12 = QString("%1").arg(g_MAIN_INFO.schedule.num[11].DirectionMode);
    ui->textEdit_GetDirection_12->setText(str_GetDirectionMode_12);

//    QString str_GetDirectionMode_13 = QString("%1").arg(g_MAIN_INFO.schedule.num[12].DirectionMode);
//    ui->textEdit_GetDirection_13->setText(str_GetDirectionMode_13);

//    QString str_GetDirectionMode_14 = QString("%1").arg(g_MAIN_INFO.schedule.num[13].DirectionMode);
//    ui->textEdit_GetDirection_14->setText(str_GetDirectionMode_14);

//    QString str_GetDirectionMode_15 = QString("%1").arg(g_MAIN_INFO.schedule.num[14].DirectionMode);
//    ui->textEdit_GetDirection_15->setText(str_GetDirectionMode_15);

//    QString str_GetDirectionMode_16 = QString("%1").arg(g_MAIN_INFO.schedule.num[15].DirectionMode);
//    ui->textEdit_GetDirection_16->setText(str_GetDirectionMode_16);

//    QString str_GetDirectionMode_17 = QString("%1").arg(g_MAIN_INFO.schedule.num[16].DirectionMode);
//    ui->textEdit_GetDirection_17->setText(str_GetDirectionMode_17);

//    QString str_GetDirectionMode_18 = QString("%1").arg(g_MAIN_INFO.schedule.num[17].DirectionMode);
//    ui->textEdit_GetDirection_18->setText(str_GetDirectionMode_18);

//    QString str_GetDirectionMode_19 = QString("%1").arg(g_MAIN_INFO.schedule.num[18].DirectionMode);
//    ui->textEdit_GetDirection_19->setText(str_GetDirectionMode_19);

//    QString str_GetDirectionMode_20 = QString("%1").arg(g_MAIN_INFO.schedule.num[19].DirectionMode);
//    ui->textEdit_GetDirection_20->setText(str_GetDirectionMode_20);

//    QString str_GetDirectionMode_21 = QString("%1").arg(g_MAIN_INFO.schedule.num[20].DirectionMode);
//    ui->textEdit_GetDirection_21->setText(str_GetDirectionMode_21);

//    QString str_GetDirectionMode_22 = QString("%1").arg(g_MAIN_INFO.schedule.num[21].DirectionMode);
//    ui->textEdit_GetDirection_22->setText(str_GetDirectionMode_22);

//    QString str_GetDirectionMode_23 = QString("%1").arg(g_MAIN_INFO.schedule.num[22].DirectionMode);
//    ui->textEdit_GetDirection_23->setText(str_GetDirectionMode_23);

//    QString str_GetDirectionMode_24 = QString("%1").arg(g_MAIN_INFO.schedule.num[23].DirectionMode);
//    ui->textEdit_GetDirection_24->setText(str_GetDirectionMode_24);
}

void ScheduleForm::dr_check()
{
    // toDo: 나중에 dr 들어왔을 때만 g_dr_write_enable = true되도록 처리할 것.
    //g_dr_write_enable = true;
}

void ScheduleForm::check()
{
    static bool init_flag = false;
    static int init_cnt = 0;
    if( init_flag == false )
    {
        if( init_cnt++ >= 1 )
        {
            init_cnt = 0;
            init_flag = true;
            schedule_set_textbox_init();
        }
    }
    time_check();
    schedule_check();
    dr_check();
}

void ScheduleForm::on_pushButton_set_clicked()
{
    bool ok;

    g_schedule_write_enable = true;

    QString *str_SetStartTime = new QString();
    *str_SetStartTime = ui->textEdit_SetStartTime->toPlainText();
    g_MAIN_CONTROL.schedule.num[0].StartTime = str_SetStartTime->toInt(&ok, 10);

    QString *str_SetStartTime_2 = new QString();
    *str_SetStartTime_2 = ui->textEdit_SetStartTime_2->toPlainText();
    g_MAIN_CONTROL.schedule.num[1].StartTime = str_SetStartTime_2->toInt(&ok, 10);

    QString *str_SetStartTime_3 = new QString();
    *str_SetStartTime_3 = ui->textEdit_SetStartTime_3->toPlainText();
    g_MAIN_CONTROL.schedule.num[2].StartTime = str_SetStartTime_3->toInt(&ok, 10);

    QString *str_SetStartTime_4 = new QString();
    *str_SetStartTime_4 = ui->textEdit_SetStartTime_4->toPlainText();
    g_MAIN_CONTROL.schedule.num[3].StartTime = str_SetStartTime_4->toInt(&ok, 10);

    QString *str_SetStartTime_5 = new QString();
    *str_SetStartTime_5 = ui->textEdit_SetStartTime_5->toPlainText();
    g_MAIN_CONTROL.schedule.num[4].StartTime = str_SetStartTime_5->toInt(&ok, 10);

    QString *str_SetStartTime_6 = new QString();
    *str_SetStartTime_6 = ui->textEdit_SetStartTime_6->toPlainText();
    g_MAIN_CONTROL.schedule.num[5].StartTime = str_SetStartTime_6->toInt(&ok, 10);

    QString *str_SetStartTime_7 = new QString();
    *str_SetStartTime_7 = ui->textEdit_SetStartTime_7->toPlainText();
    g_MAIN_CONTROL.schedule.num[6].StartTime = str_SetStartTime_7->toInt(&ok, 10);

    QString *str_SetStartTime_8 = new QString();
    *str_SetStartTime_8 = ui->textEdit_SetStartTime_8->toPlainText();
    g_MAIN_CONTROL.schedule.num[7].StartTime = str_SetStartTime_8->toInt(&ok, 10);

    QString *str_SetStartTime_9 = new QString();
    *str_SetStartTime_9 = ui->textEdit_SetStartTime_9->toPlainText();
    g_MAIN_CONTROL.schedule.num[8].StartTime = str_SetStartTime_9->toInt(&ok, 10);

    QString *str_SetStartTime_10 = new QString();
    *str_SetStartTime_10 = ui->textEdit_SetStartTime_10->toPlainText();
    g_MAIN_CONTROL.schedule.num[9].StartTime = str_SetStartTime_10->toInt(&ok, 10);

    QString *str_SetStartTime_11 = new QString();
    *str_SetStartTime_11 = ui->textEdit_SetStartTime_11->toPlainText();
    g_MAIN_CONTROL.schedule.num[10].StartTime = str_SetStartTime_11->toInt(&ok, 10);

    QString *str_SetStartTime_12 = new QString();
    *str_SetStartTime_12 = ui->textEdit_SetStartTime_12->toPlainText();
    g_MAIN_CONTROL.schedule.num[11].StartTime = str_SetStartTime_12->toInt(&ok, 10);

//    QString *str_SetStartTime_13 = new QString();
//    *str_SetStartTime_13 = ui->textEdit_SetStartTime_13->toPlainText();
//    g_MAIN_CONTROL.schedule.num[12].StartTime = str_SetStartTime_13->toInt(&ok, 10);

//    QString *str_SetStartTime_14 = new QString();
//    *str_SetStartTime_14 = ui->textEdit_SetStartTime_14->toPlainText();
//    g_MAIN_CONTROL.schedule.num[13].StartTime = str_SetStartTime_14->toInt(&ok, 10);

//    QString *str_SetStartTime_15 = new QString();
//    *str_SetStartTime_15 = ui->textEdit_SetStartTime_15->toPlainText();
//    g_MAIN_CONTROL.schedule.num[14].StartTime = str_SetStartTime_15->toInt(&ok, 10);

//    QString *str_SetStartTime_16 = new QString();
//    *str_SetStartTime_16 = ui->textEdit_SetStartTime_16->toPlainText();
//    g_MAIN_CONTROL.schedule.num[15].StartTime = str_SetStartTime_16->toInt(&ok, 10);

//    QString *str_SetStartTime_17 = new QString();
//    *str_SetStartTime_17 = ui->textEdit_SetStartTime_17->toPlainText();
//    g_MAIN_CONTROL.schedule.num[16].StartTime = str_SetStartTime_17->toInt(&ok, 10);

//    QString *str_SetStartTime_18 = new QString();
//    *str_SetStartTime_18 = ui->textEdit_SetStartTime_18->toPlainText();
//    g_MAIN_CONTROL.schedule.num[17].StartTime = str_SetStartTime_18->toInt(&ok, 10);

//    QString *str_SetStartTime_19 = new QString();
//    *str_SetStartTime_19 = ui->textEdit_SetStartTime_19->toPlainText();
//    g_MAIN_CONTROL.schedule.num[18].StartTime = str_SetStartTime_19->toInt(&ok, 10);

//    QString *str_SetStartTime_20 = new QString();
//    *str_SetStartTime_20 = ui->textEdit_SetStartTime_20->toPlainText();
//    g_MAIN_CONTROL.schedule.num[19].StartTime = str_SetStartTime_20->toInt(&ok, 10);

//    QString *str_SetStartTime_21 = new QString();
//    *str_SetStartTime_21 = ui->textEdit_SetStartTime_21->toPlainText();
//    g_MAIN_CONTROL.schedule.num[20].StartTime = str_SetStartTime_21->toInt(&ok, 10);

//    QString *str_SetStartTime_22 = new QString();
//    *str_SetStartTime_22 = ui->textEdit_SetStartTime_22->toPlainText();
//    g_MAIN_CONTROL.schedule.num[21].StartTime = str_SetStartTime_22->toInt(&ok, 10);

//    QString *str_SetStartTime_23 = new QString();
//    *str_SetStartTime_23 = ui->textEdit_SetStartTime_23->toPlainText();
//    g_MAIN_CONTROL.schedule.num[22].StartTime = str_SetStartTime_23->toInt(&ok, 10);

//    QString *str_SetStartTime_24 = new QString();
//    *str_SetStartTime_24 = ui->textEdit_SetStartTime_24->toPlainText();
//    g_MAIN_CONTROL.schedule.num[23].StartTime = str_SetStartTime_24->toInt(&ok, 10);

    QString *str_SetPower = new QString();
    *str_SetPower = ui->textEdit_SetPower->toPlainText();
    g_MAIN_CONTROL.schedule.num[0].Power = str_SetPower->toInt(&ok, 10);

    QString *str_SetPower_2 = new QString();
    *str_SetPower_2 = ui->textEdit_SetPower_2->toPlainText();
    g_MAIN_CONTROL.schedule.num[1].Power = str_SetPower_2->toInt(&ok, 10);

    QString *str_SetPower_3 = new QString();
    *str_SetPower_3 = ui->textEdit_SetPower_3->toPlainText();
    g_MAIN_CONTROL.schedule.num[2].Power = str_SetPower_3->toInt(&ok, 10);

    QString *str_SetPower_4 = new QString();
    *str_SetPower_4 = ui->textEdit_SetPower_4->toPlainText();
    g_MAIN_CONTROL.schedule.num[3].Power = str_SetPower_4->toInt(&ok, 10);

    QString *str_SetPower_5 = new QString();
    *str_SetPower_5 = ui->textEdit_SetPower_5->toPlainText();
    g_MAIN_CONTROL.schedule.num[4].Power = str_SetPower_5->toInt(&ok, 10);

    QString *str_SetPower_6 = new QString();
    *str_SetPower_6 = ui->textEdit_SetPower_6->toPlainText();
    g_MAIN_CONTROL.schedule.num[5].Power = str_SetPower_6->toInt(&ok, 10);

    QString *str_SetPower_7 = new QString();
    *str_SetPower_7 = ui->textEdit_SetPower_7->toPlainText();
    g_MAIN_CONTROL.schedule.num[6].Power = str_SetPower_7->toInt(&ok, 10);

    QString *str_SetPower_8 = new QString();
    *str_SetPower_8 = ui->textEdit_SetPower_8->toPlainText();
    g_MAIN_CONTROL.schedule.num[7].Power = str_SetPower_8->toInt(&ok, 10);

    QString *str_SetPower_9 = new QString();
    *str_SetPower_9 = ui->textEdit_SetPower_9->toPlainText();
    g_MAIN_CONTROL.schedule.num[8].Power = str_SetPower_9->toInt(&ok, 10);

    QString *str_SetPower_10 = new QString();
    *str_SetPower_10 = ui->textEdit_SetPower_10->toPlainText();
    g_MAIN_CONTROL.schedule.num[9].Power = str_SetPower_10->toInt(&ok, 10);

    QString *str_SetPower_11 = new QString();
    *str_SetPower_11 = ui->textEdit_SetPower_11->toPlainText();
    g_MAIN_CONTROL.schedule.num[10].Power = str_SetPower_11->toInt(&ok, 10);

    QString *str_SetPower_12 = new QString();
    *str_SetPower_12 = ui->textEdit_SetPower_12->toPlainText();
    g_MAIN_CONTROL.schedule.num[11].Power = str_SetPower_12->toInt(&ok, 10);

//    QString *str_SetPower_13 = new QString();
//    *str_SetPower_13 = ui->textEdit_SetPower_13->toPlainText();
//    g_MAIN_CONTROL.schedule.num[12].Power = str_SetPower_13->toInt(&ok, 10);

//    QString *str_SetPower_14 = new QString();
//    *str_SetPower_14 = ui->textEdit_SetPower_14->toPlainText();
//    g_MAIN_CONTROL.schedule.num[13].Power = str_SetPower_14->toInt(&ok, 10);

//    QString *str_SetPower_15 = new QString();
//    *str_SetPower_15 = ui->textEdit_SetPower_15->toPlainText();
//    g_MAIN_CONTROL.schedule.num[14].Power = str_SetPower_15->toInt(&ok, 10);

//    QString *str_SetPower_16 = new QString();
//    *str_SetPower_16 = ui->textEdit_SetPower_16->toPlainText();
//    g_MAIN_CONTROL.schedule.num[15].Power = str_SetPower_16->toInt(&ok, 10);

//    QString *str_SetPower_17 = new QString();
//    *str_SetPower_17 = ui->textEdit_SetPower_17->toPlainText();
//    g_MAIN_CONTROL.schedule.num[16].Power = str_SetPower_17->toInt(&ok, 10);

//    QString *str_SetPower_18 = new QString();
//    *str_SetPower_18 = ui->textEdit_SetPower_18->toPlainText();
//    g_MAIN_CONTROL.schedule.num[17].Power = str_SetPower_18->toInt(&ok, 10);

//    QString *str_SetPower_19 = new QString();
//    *str_SetPower_19 = ui->textEdit_SetPower_19->toPlainText();
//    g_MAIN_CONTROL.schedule.num[18].Power = str_SetPower_19->toInt(&ok, 10);

//    QString *str_SetPower_20 = new QString();
//    *str_SetPower_20 = ui->textEdit_SetPower_20->toPlainText();
//    g_MAIN_CONTROL.schedule.num[19].Power = str_SetPower_20->toInt(&ok, 10);

//    QString *str_SetPower_21 = new QString();
//    *str_SetPower_21 = ui->textEdit_SetPower_21->toPlainText();
//    g_MAIN_CONTROL.schedule.num[20].Power = str_SetPower_21->toInt(&ok, 10);

//    QString *str_SetPower_22 = new QString();
//    *str_SetPower_22 = ui->textEdit_SetPower_22->toPlainText();
//    g_MAIN_CONTROL.schedule.num[21].Power = str_SetPower_22->toInt(&ok, 10);

//    QString *str_SetPower_23 = new QString();
//    *str_SetPower_23 = ui->textEdit_SetPower_23->toPlainText();
//    g_MAIN_CONTROL.schedule.num[22].Power = str_SetPower_23->toInt(&ok, 10);

//    QString *str_SetPower_24 = new QString();
//    *str_SetPower_24 = ui->textEdit_SetPower_24->toPlainText();
//    g_MAIN_CONTROL.schedule.num[23].Power = str_SetPower_24->toInt(&ok, 10);

    QString *str_SetDirectionMode = new QString();
    *str_SetDirectionMode = ui->textEdit_SetDirection->toPlainText();
    g_MAIN_CONTROL.schedule.num[0].DirectionMode = str_SetDirectionMode->toInt(&ok, 10);

    QString *str_SetDirectionMode_2 = new QString();
    *str_SetDirectionMode_2 = ui->textEdit_SetDirection_2->toPlainText();
    g_MAIN_CONTROL.schedule.num[1].DirectionMode = str_SetDirectionMode_2->toInt(&ok, 10);

    QString *str_SetDirectionMode_3 = new QString();
    *str_SetDirectionMode_3 = ui->textEdit_SetDirection_3->toPlainText();
    g_MAIN_CONTROL.schedule.num[2].DirectionMode = str_SetDirectionMode_3->toInt(&ok, 10);

    QString *str_SetDirectionMode_4 = new QString();
    *str_SetDirectionMode_4 = ui->textEdit_SetDirection_4->toPlainText();
    g_MAIN_CONTROL.schedule.num[3].DirectionMode = str_SetDirectionMode_4->toInt(&ok, 10);

    QString *str_SetDirectionMode_5 = new QString();
    *str_SetDirectionMode_5 = ui->textEdit_SetDirection_5->toPlainText();
    g_MAIN_CONTROL.schedule.num[4].DirectionMode = str_SetDirectionMode_5->toInt(&ok, 10);

    QString *str_SetDirectionMode_6 = new QString();
    *str_SetDirectionMode_6 = ui->textEdit_SetDirection_6->toPlainText();
    g_MAIN_CONTROL.schedule.num[5].DirectionMode = str_SetDirectionMode_6->toInt(&ok, 10);

    QString *str_SetDirectionMode_7 = new QString();
    *str_SetDirectionMode_7 = ui->textEdit_SetDirection_7->toPlainText();
    g_MAIN_CONTROL.schedule.num[6].DirectionMode = str_SetDirectionMode_7->toInt(&ok, 10);

    QString *str_SetDirectionMode_8 = new QString();
    *str_SetDirectionMode_8 = ui->textEdit_SetDirection_8->toPlainText();
    g_MAIN_CONTROL.schedule.num[7].DirectionMode = str_SetDirectionMode_8->toInt(&ok, 10);

    QString *str_SetDirectionMode_9 = new QString();
    *str_SetDirectionMode_9 = ui->textEdit_SetDirection_9->toPlainText();
    g_MAIN_CONTROL.schedule.num[8].DirectionMode = str_SetDirectionMode_9->toInt(&ok, 10);

    QString *str_SetDirectionMode_10 = new QString();
    *str_SetDirectionMode_10 = ui->textEdit_SetDirection_10->toPlainText();
    g_MAIN_CONTROL.schedule.num[9].DirectionMode = str_SetDirectionMode_10->toInt(&ok, 10);

    QString *str_SetDirectionMode_11 = new QString();
    *str_SetDirectionMode_11 = ui->textEdit_SetDirection_11->toPlainText();
    g_MAIN_CONTROL.schedule.num[10].DirectionMode = str_SetDirectionMode_11->toInt(&ok, 10);

    QString *str_SetDirectionMode_12 = new QString();
    *str_SetDirectionMode_12 = ui->textEdit_SetDirection_12->toPlainText();
    g_MAIN_CONTROL.schedule.num[11].DirectionMode = str_SetDirectionMode_12->toInt(&ok, 10);

//    QString *str_SetDirectionMode_13 = new QString();
//    *str_SetDirectionMode_13 = ui->textEdit_SetDirection_13->toPlainText();
//    g_MAIN_CONTROL.schedule.num[12].DirectionMode = str_SetDirectionMode_13->toInt(&ok, 10);

//    QString *str_SetDirectionMode_14 = new QString();
//    *str_SetDirectionMode_14 = ui->textEdit_SetDirection_14->toPlainText();
//    g_MAIN_CONTROL.schedule.num[13].DirectionMode = str_SetDirectionMode_14->toInt(&ok, 10);

//    QString *str_SetDirectionMode_15 = new QString();
//    *str_SetDirectionMode_15 = ui->textEdit_SetDirection_15->toPlainText();
//    g_MAIN_CONTROL.schedule.num[14].DirectionMode = str_SetDirectionMode_15->toInt(&ok, 10);

//    QString *str_SetDirectionMode_16 = new QString();
//    *str_SetDirectionMode_16 = ui->textEdit_SetDirection_16->toPlainText();
//    g_MAIN_CONTROL.schedule.num[15].DirectionMode = str_SetDirectionMode_16->toInt(&ok, 10);

//    QString *str_SetDirectionMode_17 = new QString();
//    *str_SetDirectionMode_17 = ui->textEdit_SetDirection_17->toPlainText();
//    g_MAIN_CONTROL.schedule.num[16].DirectionMode = str_SetDirectionMode_17->toInt(&ok, 10);

//    QString *str_SetDirectionMode_18 = new QString();
//    *str_SetDirectionMode_18 = ui->textEdit_SetDirection_18->toPlainText();
//    g_MAIN_CONTROL.schedule.num[17].DirectionMode = str_SetDirectionMode_18->toInt(&ok, 10);

//    QString *str_SetDirectionMode_19 = new QString();
//    *str_SetDirectionMode_19 = ui->textEdit_SetDirection_19->toPlainText();
//    g_MAIN_CONTROL.schedule.num[18].DirectionMode = str_SetDirectionMode_19->toInt(&ok, 10);

//    QString *str_SetDirectionMode_20 = new QString();
//    *str_SetDirectionMode_20 = ui->textEdit_SetDirection_20->toPlainText();
//    g_MAIN_CONTROL.schedule.num[19].DirectionMode = str_SetDirectionMode_20->toInt(&ok, 10);

//    QString *str_SetDirectionMode_21 = new QString();
//    *str_SetDirectionMode_21 = ui->textEdit_SetDirection_21->toPlainText();
//    g_MAIN_CONTROL.schedule.num[20].DirectionMode = str_SetDirectionMode_21->toInt(&ok, 10);

//    QString *str_SetDirectionMode_22 = new QString();
//    *str_SetDirectionMode_22 = ui->textEdit_SetDirection_22->toPlainText();
//    g_MAIN_CONTROL.schedule.num[21].DirectionMode = str_SetDirectionMode_22->toInt(&ok, 10);

//    QString *str_SetDirectionMode_23 = new QString();
//    *str_SetDirectionMode_23 = ui->textEdit_SetDirection_23->toPlainText();
//    g_MAIN_CONTROL.schedule.num[22].DirectionMode = str_SetDirectionMode_23->toInt(&ok, 10);

//    QString *str_SetDirectionMode_24 = new QString();
//    *str_SetDirectionMode_24 = ui->textEdit_SetDirection_24->toPlainText();
//    g_MAIN_CONTROL.schedule.num[23].DirectionMode = str_SetDirectionMode_24->toInt(&ok, 10);
}
