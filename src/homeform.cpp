#include <QApplication>
#include "header.h"

/*!
    Default constructor with \a parent as the default argument
*/
HomeForm::HomeForm(QWidget *parent) : QWidget(parent), ui(new Ui::HomeForm)
{
    ui->setupUi(this);

    sourceQImage = QImage(IMGSOURCE_HOME);

    //Put Background Image
    ui->Img_Label->setGeometry(0,0,1024,660);

    QPixmap drawPixmap = QPixmap::fromImage(sourceQImage);

    // source image
    ui->Img_Label->setPixmap(drawPixmap.scaled(ui->Img_Label->size()));

//    // powerson toDo:?????? i think this delegate is no need more..
//    ListviewDelegate *m_listdelegate;
//    m_listdelegate = new ListviewDelegate();

    // initialization
    homeform_update();

    // serial 통신 start
    SerialForm *serialform = new SerialForm(this);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(homeform_update()));
    timer->start(1357);
}

/*!
    Default destructor
*/
HomeForm::~HomeForm()
{
    delete ui;
}

void HomeForm::image_set(QString filename, int x, int y)
{
    QImage *Img = new QImage();         //이미지를 로드하기 위한 QImage 선언
    QPixmap *buffer = new QPixmap();    //버퍼로 사용할 QPixmap 선언
    if(Img->load(filename))             //이미지를 로드한다.
    {
        *buffer = QPixmap::fromImage(*Img);   //이미지를 버퍼에 옮긴다.
        *buffer = buffer->scaled(Img->width(),Img->height()); //이미지 사이즈 조절
    }
    else // 이미지 로드 실패
    {
        QMessageBox::about(0, QString("Image load Error"),
                       filename);
    }
    QLabel *lbView = new QLabel(this);  //이미지를 화면에 출력할 QLabel 선언
    lbView->setPixmap(*buffer);         //버퍼에 있는 이미지를 QLabel에 출력
    lbView->resize(buffer->width(), buffer->height()); //QLabel의 크기를 이미지 사이즈에 맞추어 조절한다.
    lbView->move(x, y);                 //QLabel위치 조정
    lbView->show();                     //QLabel 를 보여준다.
}

void HomeForm::listwidget_update()
{
    // PV
    ui->ListWidget_PV->setItemDelegate(new ListviewDelegate(ui->ListWidget_PV));
    QListWidgetItem *pv_item1 = new QListWidgetItem();
    QString pv_itemStr1 = QString("%1 W").arg(g_MAIN_INFO.realtime_data.PV_W);
    pv_item1->setText(pv_itemStr1);
    QListWidgetItem *pv_item2 = new QListWidgetItem();
    QString pv_itemStr2 = QString("%1 V").arg(g_MAIN_INFO.realtime_data.PV_V);
    pv_item2->setText(pv_itemStr2);
    QListWidgetItem *pv_item3 = new QListWidgetItem();
    QString pv_itemStr3 = QString("%1 A").arg(g_MAIN_INFO.realtime_data.PV_A);
    pv_item3->setText(pv_itemStr3);
    ui->ListWidget_PV->clear();
    ui->ListWidget_PV->setGeometry(120, 430, 105, 105);
    ui->ListWidget_PV->insertItem(0, pv_item1);
    ui->ListWidget_PV->insertItem(1, pv_item2);
    ui->ListWidget_PV->insertItem(2, pv_item3);

    // Battery
    ui->ListWidget_Battery->setItemDelegate(new ListviewDelegate(ui->ListWidget_Battery));
    QListWidgetItem *battery_item1 = new QListWidgetItem();
    QString battery_itemStr1 = QString("%1 W").arg(g_MAIN_INFO.realtime_data.Bat_Chg_W - g_MAIN_INFO.realtime_data.Bat_Dch_W);
    battery_item1->setText(battery_itemStr1);
    QListWidgetItem *battery_item2 = new QListWidgetItem();
    QString battery_itemStr2 = QString("%1 V").arg(g_MAIN_INFO.realtime_data.Bat_Chg_V - g_MAIN_INFO.realtime_data.Bat_Dch_V);
    battery_item2->setText(battery_itemStr2);
    QListWidgetItem *battery_item3 = new QListWidgetItem();
    QString battery_itemStr3 = QString("%1 A").arg(g_MAIN_INFO.realtime_data.Bat_Chg_A - g_MAIN_INFO.realtime_data.Bat_Dch_A);
    battery_item3->setText(battery_itemStr3);
    ui->ListWidget_Battery->clear();
    ui->ListWidget_Battery->setGeometry(450, 430, 105, 105);
    ui->ListWidget_Battery->insertItem(0, battery_item1);
    ui->ListWidget_Battery->insertItem(1, battery_item2);
    ui->ListWidget_Battery->insertItem(2, battery_item3);

    // Grid
    ui->ListWidget_Grid->setItemDelegate(new ListviewDelegate(ui->ListWidget_Grid));
    QListWidgetItem *grid_item1 = new QListWidgetItem();
    QString grid_itemStr1 = QString("%1 W").arg(g_MAIN_INFO.realtime_data.Grid_In_W - g_MAIN_INFO.realtime_data.Grid_Out_W);
    grid_item1->setText(grid_itemStr1);
    QListWidgetItem *grid_item2 = new QListWidgetItem();
    QString grid_itemStr2 = QString("%1 V").arg(g_MAIN_INFO.realtime_data.Grid_In_V - g_MAIN_INFO.realtime_data.Grid_Out_V);
    grid_item2->setText(grid_itemStr2);
    QListWidgetItem *grid_item3 = new QListWidgetItem();
    QString grid_itemStr3 = QString("%1 A").arg(g_MAIN_INFO.realtime_data.Grid_In_A - g_MAIN_INFO.realtime_data.Grid_Out_A);
    grid_item3->setText(grid_itemStr3);
    ui->ListWidget_Grid->clear();
    ui->ListWidget_Grid->setGeometry(850, 120, 105, 105);
    ui->ListWidget_Grid->insertItem(0, grid_item1);
    ui->ListWidget_Grid->insertItem(1, grid_item2);
    ui->ListWidget_Grid->insertItem(2, grid_item3);

    // Load
    ui->ListWidget_Load->setItemDelegate(new ListviewDelegate(ui->ListWidget_PV));
    QListWidgetItem *load_item1 = new QListWidgetItem();
    QString load_itemStr1 = QString("%1 W").arg(g_MAIN_INFO.realtime_data.Load_W);
    load_item1->setText(load_itemStr1);
    QListWidgetItem *load_item2 = new QListWidgetItem();
    QString load_itemStr2 = QString("%1 V").arg(g_MAIN_INFO.realtime_data.Load_V);
    load_item2->setText(load_itemStr2);
    QListWidgetItem *load_item3 = new QListWidgetItem();
    QString load_itemStr3 = QString("%1 A").arg(g_MAIN_INFO.realtime_data.Load_A);
    load_item3->setText(load_itemStr3);
    ui->ListWidget_Load->clear();
    ui->ListWidget_Load->setGeometry(850, 430, 105, 105);
    ui->ListWidget_Load->insertItem(0, load_item1);
    ui->ListWidget_Load->insertItem(1, load_item2);
    ui->ListWidget_Load->insertItem(2, load_item3);
}

void HomeForm::picture_update()
{
    switch (g_MAIN_INFO.pcs_opeation_status.Picture_PV)
    {
    case 0:
        image_set(IMGSOURCE_PICTURE_PV_0, 63, 215);
        break;
    case 1:
        image_set(IMGSOURCE_PICTURE_PV_1, 60, 213);
        break;
    }

    switch (g_MAIN_INFO.pcs_opeation_status.Picture_Grid)
    {
    case 0:
        image_set(IMGSOURCE_PICTURE_GRID_0, 695, 90);
        break;
    case 1:
        image_set(IMGSOURCE_PICTURE_GRID_1, 697, 91);
        break;
    }

    switch (g_MAIN_INFO.pcs_opeation_status.Picture_Load)
    {
    case 0:
        image_set(IMGSOURCE_PICTURE_LOAD_0, 695, 400);
        break;
    case 1:
        image_set(IMGSOURCE_PICTURE_LOAD_1, 695, 400);
        break;
    }
}

void HomeForm::arraw_update()
{
    switch (g_MAIN_INFO.pcs_opeation_status.Arraw_PV_to_Battery)
    {
    case 0:
        image_set(IMGSOURCE_ARRAW_BETWEEN_PV_AND_BATTERY_0, 310, 300);
        break;
    case 1:
        image_set(IMGSOURCE_ARRAW_BETWEEN_PV_AND_BATTERY_1, 310, 300);
        break;
    }

    switch (g_MAIN_INFO.pcs_opeation_status.Arraw_Between_Battery_and_Grid)
    {
    case 0:
        image_set(IMGSOURCE_ARRAW_BETWEEN_BATTERY_AND_GRID_0, 595, 173);
        break;
    case 1:
        image_set(IMGSOURCE_ARRAW_BETWEEN_BATTERY_AND_GRID_1, 595, 173);
        break;
    case 2:
        image_set(IMGSOURCE_ARRAW_BETWEEN_BATTERY_AND_GRID_2, 595, 173);
        break;
    }

    switch (g_MAIN_INFO.pcs_opeation_status.Arraw_Battery_to_Load)
    {
    case 0:
        image_set(IMGSOURCE_ARRAW_BETWEEN_BATTERY_AND_LOAD_0, 599, 377);
        break;
    case 1:
        image_set(IMGSOURCE_ARRAW_BETWEEN_BATTERY_AND_LOAD_1, 599, 377);
        break;
    }

    switch (g_MAIN_INFO.pcs_opeation_status.Arraw_Grid_to_Load)
    {
    case 0:
        image_set(IMGSOURCE_ARRAW_BETWEEN_GRID_AND_LOAD_0, 758, 274);
        break;
    case 1:
        image_set(IMGSOURCE_ARRAW_BETWEEN_GRID_AND_LOAD_1, 758, 274);
        break;
    }
}

void HomeForm::word_update()
{
    switch (g_MAIN_INFO.pcs_opeation_status.Word_PV)
    {
    case 0:
        image_set(IMGSOURCE_WORD_PV_0, 163, 159);
        break;
    case 1:
        image_set(IMGSOURCE_WORD_PV_1, 163, 159);
        break;
    }

    switch (g_MAIN_INFO.pcs_opeation_status.Word_Grid)
    {
    case 0:
        image_set(IMGSOURCE_WORD_GRID_0, 738, 62);
        break;
    case 1:
        image_set(IMGSOURCE_WORD_GRID_1, 738, 62);
        break;
    }

    switch (g_MAIN_INFO.pcs_opeation_status.Word_Load)
    {
    case 0:
        image_set(IMGSOURCE_WORD_LOAD_0, 738, 372);
        break;
    case 1:
        image_set(IMGSOURCE_WORD_LOAD_1, 738, 372);
        break;
    }

    // Battery는 없음
}

void HomeForm::simulation_data_cal()
{
    static int simulation_data_cal_select=0;
    switch( simulation_data_cal_select )
    {
    case 0:	// PV to Load (with Battery charge)
        g_MAIN_INFO.pcs_opeation_status.DirectionMode = 0;
        g_MAIN_INFO.pcs_opeation_status.Word_PV = 1;
        g_MAIN_INFO.pcs_opeation_status.Word_Battery = 1;
        g_MAIN_INFO.pcs_opeation_status.Word_Grid = 1;
        g_MAIN_INFO.pcs_opeation_status.Word_Load = 1;
        g_MAIN_INFO.pcs_opeation_status.Picture_PV = 1;
        g_MAIN_INFO.pcs_opeation_status.Picture_Grid = 0;
        g_MAIN_INFO.pcs_opeation_status.Picture_Load = 1;
        g_MAIN_INFO.pcs_opeation_status.Arraw_PV_to_Battery = 1;
        g_MAIN_INFO.pcs_opeation_status.Arraw_Between_Battery_and_Grid = 0;
        g_MAIN_INFO.pcs_opeation_status.Arraw_Battery_to_Load = 1;
        g_MAIN_INFO.pcs_opeation_status.Arraw_Grid_to_Load = 0;
        g_MAIN_INFO.realtime_data.PV_W = 2000;						// 2000W
        g_MAIN_INFO.realtime_data.PV_V = 150;							// 150V
        g_MAIN_INFO.realtime_data.PV_A = 133;							// 13.3A
        g_MAIN_INFO.realtime_data.Grid_In_W = 0;
        g_MAIN_INFO.realtime_data.Grid_In_V = 0;
        g_MAIN_INFO.realtime_data.Grid_In_A = 0;
        g_MAIN_INFO.realtime_data.Grid_Out_W = 0;
        g_MAIN_INFO.realtime_data.Grid_Out_V = 0;
        g_MAIN_INFO.realtime_data.Grid_Out_A = 0;
        g_MAIN_INFO.realtime_data.Bat_Chg_W = 500;					// 500W
        g_MAIN_INFO.realtime_data.Bat_Chg_V = 144;					// 144V
        g_MAIN_INFO.realtime_data.Bat_Chg_A = 35;						// 3.5A
        g_MAIN_INFO.realtime_data.Bat_Dch_W = 0;
        g_MAIN_INFO.realtime_data.Bat_Dch_V = 0;
        g_MAIN_INFO.realtime_data.Bat_Dch_A = 0;
        g_MAIN_INFO.realtime_data.Load_W = 1500;						// 1500W
        g_MAIN_INFO.realtime_data.Load_V = 220;						// 220V
        g_MAIN_INFO.realtime_data.Load_A = 68;						// 6.8A
        break;
    case 1:	// Grid to Load (with PV)
        g_MAIN_INFO.pcs_opeation_status.DirectionMode = 1;
        g_MAIN_INFO.pcs_opeation_status.Word_PV = 1;
        g_MAIN_INFO.pcs_opeation_status.Word_Battery = 1;
        g_MAIN_INFO.pcs_opeation_status.Word_Grid = 1;
        g_MAIN_INFO.pcs_opeation_status.Word_Load = 1;
        g_MAIN_INFO.pcs_opeation_status.Picture_PV = 0;				// or 1, 낮과 밤 고려할 것.
        g_MAIN_INFO.pcs_opeation_status.Picture_Grid = 1;
        g_MAIN_INFO.pcs_opeation_status.Picture_Load = 1;
        g_MAIN_INFO.pcs_opeation_status.Arraw_PV_to_Battery = 0;		// or 1, 낮과 밤 고려할 것.
        g_MAIN_INFO.pcs_opeation_status.Arraw_Between_Battery_and_Grid = 0;
        g_MAIN_INFO.pcs_opeation_status.Arraw_Battery_to_Load = 0;
        g_MAIN_INFO.pcs_opeation_status.Arraw_Grid_to_Load = 1;
        g_MAIN_INFO.realtime_data.PV_W = 0;							// 낮에는 pv 들어오므로 변경
        g_MAIN_INFO.realtime_data.PV_V = 0;							// 낮에는 pv 들어오므로 변경
        g_MAIN_INFO.realtime_data.PV_A = 0;							// 낮에는 pv 들어오므로 변경
        g_MAIN_INFO.realtime_data.Grid_In_W = 1000;					// 1000W (PV가 늘어나면 grid는 줄어들게)
        g_MAIN_INFO.realtime_data.Grid_In_V = 220;					// 220V (PV가 늘어나면 grid는 줄어들게)
        g_MAIN_INFO.realtime_data.Grid_In_A = 45;						// 4.5A (PV가 늘어나면 grid는 줄어들게)
        g_MAIN_INFO.realtime_data.Grid_Out_W = 0;
        g_MAIN_INFO.realtime_data.Grid_Out_V = 0;
        g_MAIN_INFO.realtime_data.Grid_Out_A = 0;
        g_MAIN_INFO.realtime_data.Bat_Chg_W = 0;
        g_MAIN_INFO.realtime_data.Bat_Chg_V = 0;
        g_MAIN_INFO.realtime_data.Bat_Chg_A = 0;
        g_MAIN_INFO.realtime_data.Bat_Dch_W = 0;
        g_MAIN_INFO.realtime_data.Bat_Dch_V = 0;
        g_MAIN_INFO.realtime_data.Bat_Dch_A = 0;
        g_MAIN_INFO.realtime_data.Load_W = 1000;
        g_MAIN_INFO.realtime_data.Load_V = 220;
        g_MAIN_INFO.realtime_data.Load_A = 45;
        break;
    case 2: // Battery to Load (with PV)
        g_MAIN_INFO.pcs_opeation_status.DirectionMode = 2;
        g_MAIN_INFO.pcs_opeation_status.Word_PV = 1;
        g_MAIN_INFO.pcs_opeation_status.Word_Battery = 1;
        g_MAIN_INFO.pcs_opeation_status.Word_Grid = 1;
        g_MAIN_INFO.pcs_opeation_status.Word_Load = 1;
        g_MAIN_INFO.pcs_opeation_status.Picture_PV = 0;	// or 1, 낮과 밤 고려할 것.
        g_MAIN_INFO.pcs_opeation_status.Picture_Grid = 0;
        g_MAIN_INFO.pcs_opeation_status.Picture_Load = 1;
        g_MAIN_INFO.pcs_opeation_status.Arraw_PV_to_Battery = 0;	// or 1, 낮과 밤 고려할 것.
        g_MAIN_INFO.pcs_opeation_status.Arraw_Between_Battery_and_Grid = 0;
        g_MAIN_INFO.pcs_opeation_status.Arraw_Battery_to_Load = 1;
        g_MAIN_INFO.pcs_opeation_status.Arraw_Grid_to_Load = 0;
        g_MAIN_INFO.realtime_data.PV_W = 0;							// 낮에는 pv 들어오므로 변경
        g_MAIN_INFO.realtime_data.PV_V = 0;							// 낮에는 pv 들어오므로 변경
        g_MAIN_INFO.realtime_data.PV_A = 0;							// 낮에는 pv 들어오므로 변경
        g_MAIN_INFO.realtime_data.Grid_In_W = 0;
        g_MAIN_INFO.realtime_data.Grid_In_V = 0;
        g_MAIN_INFO.realtime_data.Grid_In_A = 0;
        g_MAIN_INFO.realtime_data.Grid_Out_W = 0;
        g_MAIN_INFO.realtime_data.Grid_Out_V = 0;
        g_MAIN_INFO.realtime_data.Grid_Out_A = 0;
        g_MAIN_INFO.realtime_data.Bat_Chg_W = 0;
        g_MAIN_INFO.realtime_data.Bat_Chg_V = 0;
        g_MAIN_INFO.realtime_data.Bat_Chg_A = 0;
        g_MAIN_INFO.realtime_data.Bat_Dch_W = 1000;					// 1000W (PV가 늘어나면 battery dch는 줄어들게)
        g_MAIN_INFO.realtime_data.Bat_Dch_V = 50;						// 50V (PV가 늘어나면 battery dch는 줄어들게)
        g_MAIN_INFO.realtime_data.Bat_Dch_A = 20;						// 20A (PV가 늘어나면 battery dch는 줄어들게)
        g_MAIN_INFO.realtime_data.Load_W = 1000;						// 1000W
        g_MAIN_INFO.realtime_data.Load_V = 220;						// 220V
        g_MAIN_INFO.realtime_data.Load_A = 45;						// 4.5A
        break;
    case 3:	// Grid to Battery (with PV)
        g_MAIN_INFO.pcs_opeation_status.DirectionMode = 3;
        g_MAIN_INFO.pcs_opeation_status.Word_PV = 1;
        g_MAIN_INFO.pcs_opeation_status.Word_Battery = 1;
        g_MAIN_INFO.pcs_opeation_status.Word_Grid = 1;
        g_MAIN_INFO.pcs_opeation_status.Word_Load = 1;
        g_MAIN_INFO.pcs_opeation_status.Picture_PV = 0;				// or 1, 낮과 밤 고려할 것.
        g_MAIN_INFO.pcs_opeation_status.Picture_Grid = 1;
        g_MAIN_INFO.pcs_opeation_status.Picture_Load = 1;
        g_MAIN_INFO.pcs_opeation_status.Arraw_PV_to_Battery = 0;		// or 1, 낮과 밤 고려할 것.
        g_MAIN_INFO.pcs_opeation_status.Arraw_Between_Battery_and_Grid = 1;
        g_MAIN_INFO.pcs_opeation_status.Arraw_Battery_to_Load = 0;
        g_MAIN_INFO.pcs_opeation_status.Arraw_Grid_to_Load = 1;
        g_MAIN_INFO.realtime_data.PV_W = 0;							// 낮에는 pv 들어오므로 변경
        g_MAIN_INFO.realtime_data.PV_V = 0;							// 낮에는 pv 들어오므로 변경
        g_MAIN_INFO.realtime_data.PV_A = 0;							// 낮에는 pv 들어오므로 변경
        g_MAIN_INFO.realtime_data.Grid_In_W = 2000;					// 2000W (PV가 늘어나면 grid in은 줄어들게)
        g_MAIN_INFO.realtime_data.Grid_In_V = 220;					// 220V (PV가 늘어나면 grid in은 줄어들게)
        g_MAIN_INFO.realtime_data.Grid_In_A = 91;						// 9.1A (PV가 늘어나면 grid in은 줄어들게)
        g_MAIN_INFO.realtime_data.Grid_Out_W = 0;
        g_MAIN_INFO.realtime_data.Grid_Out_V = 0;
        g_MAIN_INFO.realtime_data.Grid_Out_A = 0;
        g_MAIN_INFO.realtime_data.Bat_Chg_W = 1000;					// 1000W (PV가 늘어나면 battery chg는 줄어들게)
        g_MAIN_INFO.realtime_data.Bat_Chg_V = 50;						// 50V (PV가 늘어나면 battery chg는 줄어들게)
        g_MAIN_INFO.realtime_data.Bat_Chg_A = 20;						// 2.0A (PV가 늘어나면 battery chg는 줄어들게)
        g_MAIN_INFO.realtime_data.Bat_Dch_W = 0;
        g_MAIN_INFO.realtime_data.Bat_Dch_V = 0;
        g_MAIN_INFO.realtime_data.Bat_Dch_A = 0;
        g_MAIN_INFO.realtime_data.Load_W = 1000;						// 1000W
        g_MAIN_INFO.realtime_data.Load_V = 220;						// 220V
        g_MAIN_INFO.realtime_data.Load_A = 45;						// 4.5A
        break;
    }
    // imsi test
    if( simulation_data_cal_select++ >= 3)
    {
        simulation_data_cal_select=0;
    }
}

void HomeForm::homeform_update()
{
    listwidget_update();
    picture_update();
    arraw_update();
    word_update();
//    simulation_data_cal();
}
