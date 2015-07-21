#ifndef DEFINE_H
#define DEFINE_H

#include <QApplication>
#include "header.h"

// serialport
#define SERIALPORT_TYPE "/dev/ttyS0"
//#define SERIALPORT_TYPE "/dev/ttyUSB0"

// background
#define IMGSOURCE_HOME ":/res/bg_home.png"

// picture
#define IMGSOURCE_PICTURE_PV_0 ":/res/Picture_PV_0.jpg"
#define IMGSOURCE_PICTURE_PV_1 ":/res/Picture_PV_1.jpg"
#define IMGSOURCE_PICTURE_GRID_0 ":/res/Picture_Grid_0.jpg"
#define IMGSOURCE_PICTURE_GRID_1 ":/res/Picture_Grid_1.jpg"
#define IMGSOURCE_PICTURE_LOAD_0 ":/res/Picture_Load_0.jpg"
#define IMGSOURCE_PICTURE_LOAD_1 ":/res/Picture_Load_1.jpg"

// word
#define IMGSOURCE_WORD_PV_0 ":/res/Word_PV_1.jpg"
#define IMGSOURCE_WORD_PV_1 ":/res/Word_PV_1.jpg"
#define IMGSOURCE_WORD_GRID_0 ":/res/Word_Grid_1.jpg"
#define IMGSOURCE_WORD_GRID_1 ":/res/Word_Grid_1.jpg"
#define IMGSOURCE_WORD_LOAD_0 ":/res/Word_Load_1.jpg"
#define IMGSOURCE_WORD_LOAD_1 ":/res/Word_Load_1.jpg"

// arraw
#define IMGSOURCE_ARRAW_BETWEEN_PV_AND_BATTERY_0 ":/res/Arraw_between_pv_and_battery_0.jpg"
#define IMGSOURCE_ARRAW_BETWEEN_PV_AND_BATTERY_1 ":/res/Arraw_between_pv_and_battery_1.jpg"
#define IMGSOURCE_ARRAW_BETWEEN_BATTERY_AND_GRID_0 ":/res/Arraw_between_battery_and_grid_0.jpg"
#define IMGSOURCE_ARRAW_BETWEEN_BATTERY_AND_GRID_1 ":/res/Arraw_between_battery_and_grid_1.jpg"
#define IMGSOURCE_ARRAW_BETWEEN_BATTERY_AND_GRID_2 ":/res/Arraw_between_battery_and_grid_2.jpg"
#define IMGSOURCE_ARRAW_BETWEEN_BATTERY_AND_LOAD_0 ":/res/Arraw_between_battery_and_load_0.jpg"
#define IMGSOURCE_ARRAW_BETWEEN_BATTERY_AND_LOAD_1 ":/res/Arraw_between_battery_and_load_1.jpg"
#define IMGSOURCE_ARRAW_BETWEEN_GRID_AND_LOAD_0 ":/res/Arraw_between_grid_and_load_0.jpg"
#define IMGSOURCE_ARRAW_BETWEEN_GRID_AND_LOAD_1 ":/res/Arraw_between_grid_and_load_1.jpg"

#define s8 int8_t
#define u8 u_int8_t
#define s16 int16_t
#define u16 u_int16_t
#define s32 int32_t
#define u32 u_int32_t

typedef union
{
    u8 bit8[2];
    u16 data;
}DATA16;

typedef union
{
    s8 bit8[2];
    s16 data;
}DATA16_S;

typedef union
{
    u8 bit8[4];
    u16 bit16[2];
    u32 data;
}DATA32;

typedef union
{
    s8 bit8[4];
    s16 bit16[2];
    s32 data;
}DATA32_S;

typedef	struct
{
    u32 mDelay;			// Powerson 추가: Master Version 전용
    u8 mID;
    u8 mFunctionCode;
    u8 mDataLength;

    DATA16	tAddress;
    DATA16	tQuantity;
    DATA16  tData[128]; // for Func( 0x10 )
    DATA16  tCrc;
}MODBUS_PACKET;

typedef union
{
    u16 pdata[20];
    struct
    {
        s16 PV_W;
        s16 PV_V;
        s16 PV_A;
        s16 Grid_In_W;
        s16 Grid_In_V;
        s16 Grid_In_A;
        s16 Grid_Out_W;
        s16 Grid_Out_V;
        s16 Grid_Out_A;
        s16 Bat_Chg_W;
        s16 Bat_Chg_V;
        s16 Bat_Chg_A;
        s16 Bat_Dch_W;
        s16 Bat_Dch_V;
        s16 Bat_Dch_A;
        s16 Load_W;
        s16 Load_V;
        s16 Load_A;
        s16 reserved[2];
    };
}ESS_REALTIME_READINGS;

typedef union
{
    u16 pdata[20];
    struct
    {
        s16 PV;
        s16 Grid_In;
        s16 Grid_Out;
        s16 Bat_Chg;
        s16 Bat_Dch;
        s16 Load;
        s16 reserved[14];
    };
}ESS_CUMLATIVE_READINGS;

typedef union
{
    u16 pdata[20];
    struct
    {
        s16 BalancingStatus;
        s16 BMSStatus;
        s16 bypassMCCBStatus;
        s16 ChargingStatus;
        s16 ESSTemp;
        s16 ESSVersion;
        s16 BatterySOC;
        s16 GridMCCBStatus;
        s16 LoadMCCBStatus;
        s16 OperationStatus;
        s16 PCSStatus;
        s16 PVMCCBStatus;
        s16 SchedulingStatus;
        s16 reserved[7];
    };
}ESS_STATUS_INFO;

typedef union
{
    u16 pdata[20];
    struct
    {
        s16 IPMFAULT;
        s16 SolarHoct;
        s16 BatteryHoct;
        s16 GridHoct;
        s16 BatteryHovt;
        s16 SolarHovt;
        s16 DCLinkHovt;
        s16 FANFault;
        s16 CANERR;
        s16 SolarSoct;
        s16 BatterySoct;
        s16 GridSoct;
        s16 DCLinkSovt;
        s16 OHTFault;
        s16 AntFrequency;
        s16 AntVoltage;
        s16 reserved[4];
    };
}PCS_FAULT_MESSAGE;

typedef union
{
    u16 pdata[20];
    struct
    {
        s16 LTC3300CommFail;
        s16 CellsOverVoltage;
        s16 SecondOverVoltage;
        s16 BatteryOverVoltage;
        s16 BatteryUnderVoltage;
        s16 BatteryOverCurrent;
        s16 BatteryOverTemp;
        s16 BatteryLowTemp;
        s16 BatteryImbalance;
        s16 SlaveBMSCANSET;
        s16 reserved[10];
    };
}BATTERY_FAULT_MESSAGE;

typedef union
{
    u16 pdata[20];
    struct
    {
        s16 DirectionMode;
        s16 Word_PV;
        s16 Word_Battery;
        s16 Word_Grid;
        s16 Word_Load;
        s16 Picture_PV;
        s16 Picture_Grid;
        s16 Picture_Load;
        s16 Arraw_PV_to_Battery;
        s16 Arraw_Between_Battery_and_Grid;
        s16 Arraw_Battery_to_Load;
        s16 Arraw_Grid_to_Load;
        s16 reserved[8];
    };
}PCS_OPERATIION_STATUS;

typedef union
{
    u16 pdata[72];
    struct
    {
        s16 StartTime;
        s16 DirectionMode;
        s16 Power;
    }num[24];
}SCHEDULE;

typedef union
{
    u16 pdata[6];
    struct
    {
        s16 Year;
        s16 Month;
        s16 Day;
        s16 Hour;
        s16 Minute;
        s16 Sec;
    };
}TIME;

typedef union
{
    u16 pdata[36];
    struct
    {
        s16 StartTime;
        s16 Duration;
        s16 ReduceEnergy;
    }num[12];
}DR;

typedef union	// 0 ~ 235 (236 quantity)
{
    u16 pdata[236];
    struct
    {
        ESS_REALTIME_READINGS realtime_data;		// 20
        ESS_CUMLATIVE_READINGS cumlative_data;		// 20
        ESS_STATUS_INFO status_info;				// 20
        PCS_FAULT_MESSAGE pcs_fault;				// 20
        BATTERY_FAULT_MESSAGE battery_fault; 		// 20
        PCS_OPERATIION_STATUS pcs_opeation_status;	// 20
        TIME time;									// 6
        SCHEDULE schedule;							// 72
        DR dr;										// 36
    };
}MAIN_INFO;

typedef union	// 0 ~ 113 (114 quantity)
{
    u16 pdata[114];
    struct
    {
        TIME time;									// 1000 ~ 1005 (6)
        SCHEDULE schedule;							// 1006 ~ 1077 (72)
        DR dr;										// 1078 ~ 1113 (36)
    };
}MAIN_CONTROL;

#endif // DEFINE_H
