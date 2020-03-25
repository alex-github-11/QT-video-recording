#include "camera.h"
#include "ui_camera.h"

Camera::Camera(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Camera)
{
    ui->setupUi(this);

    m_roiTop = 136;
    m_roiLeft = 73;
    m_roiRight = 551;
    m_roiBottom = 362;

    m_skin = true;

    //计时器
    m_timer1 = new QTimer(this);
    m_timer2 = new QTimer(this);

    m_enterImgLabel = new MyLabel;
    m_outImgLabel = new MyLabel;

    /****** 函数调用 ******/
    setDaySkin();
    setButtonTip();
    setWindowSize();

    initRoiLine();
    initParkingNumber();
    initEnterTabViewColumnTitle();
    initOutTabViewColumnTitle();

    showSumCarNumber();
    showUsedCarNumber();
    showRemainCarNumber();

    //信号与槽
    connect(ui->changeSkin, SIGNAL(clicked(bool)), this, SLOT(changeSkin()));

    connect(m_timer1, SIGNAL(timeout()), this, SLOT(readEnterFrame()));
    connect(m_timer2, SIGNAL(timeout()), this, SLOT(readOutFrame()));

    connect(ui->open_enter_cam, SIGNAL(clicked()), this, SLOT(openEnterCamera()));
    connect(ui->open_out_cam, SIGNAL(clicked()), this, SLOT(openOutCamera()));

    connect(ui->close_enter_cam, SIGNAL(clicked()), this, SLOT(closeEnterCamera()));
    connect(ui->close_out_cam, SIGNAL(clicked()), this, SLOT(closeOutCamera()));

    connect(ui->min_pushButton, SIGNAL(clicked()), this, SLOT(minimizedWindow()));
    connect(ui->close_pushButton, SIGNAL(clicked()), this, SLOT(closeWindow()));

    connect(ui->roi_top_plus, SIGNAL(clicked()), this, SLOT(roiTopLinePlus()));
    connect(ui->roi_top_subtract, SIGNAL(clicked()), this, SLOT(roiTopLineSubtract()));

    connect(ui->roi_bottom_plus, SIGNAL(clicked()), this, SLOT(roiBottomLinePlus()));
    connect(ui->roi_bottom_subtract, SIGNAL(clicked()), this, SLOT(roiBottomLineSubtract()));

    connect(ui->roi_left_plus, SIGNAL(clicked()), this, SLOT(roiLeftLinePlus()));
    connect(ui->roi_left_subtract, SIGNAL(clicked()), this, SLOT(roiLeftLineSubtract()));

    connect(ui->roi_right_plus, SIGNAL(clicked()), this, SLOT(roiRightLinePlus()));
    connect(ui->roi_right_subtract, SIGNAL(clicked()), this, SLOT(roiRightLineSubtract()));
}

/*************************** 窗口样式设置 *******************************/
//设置窗口大小
void Camera::setWindowSize()
{
    //窗口大小设置
    this->setMaximumSize(1800, 900);
    this->setMinimumSize(1800, 900);
    this->setWindowFlags(Qt::FramelessWindowHint);  //去掉标题栏
}

//设置TabView的样式
void Camera::setTabViewStyle()
{
    //左上角添加“序号”
    QAbstractButton *btn = ui->enter_info_View->findChild<QAbstractButton*>();
    QAbstractButton *btn1 = ui->out_info_View->findChild<QAbstractButton*>();

    if (btn && btn1)
    {
        btn->setText(QStringLiteral("序号"));
        btn1->setText(QStringLiteral("序号"));

        btn->installEventFilter(this);  /*注册事件 CPersonMng::eventFilter*/
        btn1->installEventFilter(this);

        QStyleOptionHeader opt, opt1;
        opt.text = btn->text();
        opt1.text = btn->text();

        QSize s = (btn->style()->sizeFromContents(QStyle::CT_HeaderSection, &opt, QSize(), btn).expandedTo(QApplication::globalStrut()));
        QSize s1 = (btn1->style()->sizeFromContents(QStyle::CT_HeaderSection, &opt1, QSize(), btn1).expandedTo(QApplication::globalStrut()));

        if (s.isValid() && s1.isValid())
        {
            ui->enter_info_View->verticalHeader()->setMinimumWidth(s.width());
            ui->out_info_View->verticalHeader()->setMinimumWidth(s1.width());
        }
    }

    ui->enter_info_View->horizontalHeader()->setObjectName("hHeader");  //水平表头object
    ui->enter_info_View->verticalHeader()->setObjectName("vHeader");    //垂直表头object

    ui->out_info_View->horizontalHeader()->setObjectName("hHeader");    //水平表头object
    ui->out_info_View->verticalHeader()->setObjectName("vHeader");      //垂直表头object

    m_tabViewStyle = "QHeaderView#hHeader::section {\
            background-color: rgb(0, 191, 255); \
            color: white;   \
            font: 75 16pt 华文行楷;  \
            height:40;  \
        }"
            "QHeaderView#vHeader::section {\
            background-color: rgb(0, 191, 255);  \
            color: white;   \
            font: 75 14pt 华文行楷; \
            height: 40;  \
            width: 48; \
        }"
            "QTableView{background-color: rgb(191, 239, 255);   \
             alternate-background-color: rgb(250, 250, 115);    \
             selection-color: white;    \
             selection-background-color: rgb(77, 77, 77);  \
        }"
             "QTableView {\
             font: 75 13pt 宋体;     \
             color: black;                         /*表格内文字颜色*/ \
             gridline-color: black;                /*表格内框颜色*/  \
             selection-color: rgb(192, 14, 235);                 /*选中区域的文字颜色*/   \
             selection-background-color: white;    /*选中区域的背景色*/    \
             border: 2px groove gray;   \
        }"
             "QTableView QTableCornerButton::section{\
             background-color: rgb(0, 191, 255);   \
             font: 75 16pt 华文行楷; \
             color: white;   \
             height: 40; \
        }";

    //间隔行颜色相同生效
    ui->enter_info_View->setAlternatingRowColors(true);
    ui->out_info_View->setAlternatingRowColors(true);

    //TabView样式设置
    ui->enter_info_View->setStyleSheet(m_tabViewStyle);
    ui->out_info_View->setStyleSheet(m_tabViewStyle);
}

//白天模式皮肤
void Camera::setDaySkin()
{
    //设置背景颜色
    this->setStyleSheet("background: rgb(239, 239, 239)");

    ui->changeSkin->setStyleSheet("QPushButton{background-color: transparent; \
                                  background-image: url(:/Resource/sun.png);\
                                  }     \
                                  QPushButton:hover{ \
                                  background-image: url(:/Resource/moon.png);\
                                  } ");

    //TabView样式设置
    setTabViewStyle();

/**************** Roi按钮样式 ******************/
    m_up = "QPushButton{background: transparent; \
            background-image: url(:/Resource/Bup1.png); \
            } \
            QPushButton:hover{ \
            background-image: url(:/Resource/Yup1.png); \
            } \
            QPushButton:pressed{ \
            background-image: url(:/Resource/Gup1.png); \
            }";

    m_up1 = "QPushButton{background: transparent;\
            background-image: url(:/Resource/Yup1.png);\
            }\
            QPushButton:hover{\
            background-image: url(:/Resource/Bup1.png);\
            } \
            QPushButton:pressed{\
            background-image: url(:/Resource/Gup1.png);\
            }";

    m_down = "QPushButton{background: transparent;\
            background-image: url(:/Resource/Ydown1.png);\
            }\
            QPushButton:hover{\
            background-image: url(:/Resource/Bdown1.png);\
            } \
            QPushButton:pressed{\
            background-image: url(:/Resource/Gdown1.png);\
            }";

    m_down1 = "QPushButton{background: transparent;\
            background-image: url(:/Resource/Bdown1.png);\
            }\
            QPushButton:hover{\
            background-image: url(:/Resource/Ydown1.png);\
            } \
            QPushButton:pressed{\
            background-image: url(:/Resource/Gdown1.png);\
            }";

    m_left = "QPushButton{background: transparent;\
            background-image: url(:/Resource/Bleft1.png);\
            }\
            QPushButton:hover{\
            background-image: url(:/Resource/Yleft1.png);\
            } \
            QPushButton:pressed{\
            background-image: url(:/Resource/Gleft1.png);\
            }";

    m_left1 = "QPushButton{background: transparent;\
            background-image: url(:/Resource/Yleft1.png);\
            }\
            QPushButton:hover{\
            background-image: url(:/Resource/Bleft1.png);\
            } \
            QPushButton:pressed{\
            background-image: url(:/Resource/Gleft1.png);\
            }";

    m_right = "QPushButton{background: transparent; \
            background-image: url(:/Resource/Yright1.png);\
            }\
            QPushButton:hover{\
            background-image: url(:/Resource/Bright1.png);\
            } \
            QPushButton:pressed{\
            background-image: url(:/Resource/Gright1.png);\
            }";

    m_right1 = "QPushButton{background: transparent; \
            background-image: url(:/Resource/Bright1.png); \
            } \
            QPushButton:hover{ \
            background-image: url(:/Resource/Yright1.png); \
            } \
            QPushButton:pressed{ \
            background-image: url(:/Resource/Gright1.png); \
            }";

    ui->roi_top_plus->setStyleSheet(m_up);
    ui->roi_top_subtract->setStyleSheet(m_down);
    ui->roi_bottom_plus->setStyleSheet(m_down1);
    ui->roi_bottom_subtract->setStyleSheet(m_up1);
    ui->roi_left_plus->setStyleSheet(m_left);
    ui->roi_left_subtract->setStyleSheet(m_right);
    ui->roi_right_plus->setStyleSheet(m_right1);
    ui->roi_right_subtract->setStyleSheet(m_left1);

/****************************** LcdNumStyle *********************/;
    ui->sum_car_num->setSegmentStyle(QLCDNumber::Flat);
    ui->sum_car_num->setStyleSheet("font: bold; "
                                   "font-size: 30px; "
                                   "color: rgb(241, 70, 62); "
                                   "background-color: blue");  //背景、字体颜色设置

    ui->used_car_num->setSegmentStyle(QLCDNumber::Flat);
    ui->used_car_num->setStyleSheet("font: bold; "
                                    "font-size: 30px; "
                                    "color: rgb(241, 70, 62); "
                                    "background-color: blue");  //背景、字体颜色设置

    ui->remain_car_num->setSegmentStyle(QLCDNumber::Flat);
    ui->remain_car_num->setStyleSheet("font: bold; "
                                      "font-size: 30px; "
                                      "color: rgb(241, 70, 62); "
                                      "background-color: blue");  //背景、字体颜色设置

/********************** label、pushbutton样式 **********************/
    //label样式变量
    m_labelStyle = "border-radius: 14px; "
                  "color: rgb(0, 160, 255); "
                  "background-color: rgb(250, 250, 250); "
                  "font: bold 21pt 华文行楷; "
                  "border: 2px solid white"; //rgb(0, 191, 255)

    m_labelStyle1 = "border-radius: 14px; "
                   "color: rgb(0, 191, 255); "
                   "background-color: rgb(250, 250, 250); "
                   "font: 20pt 黑体; "
                   "border: 2px solid white";

    m_outImgLabel->setStyleSheet("border: 14px groove rgb(0, 191, 255)");          //出场视频显示label
    m_enterImgLabel->setStyleSheet("border: 14px groove rgb(0, 191, 255)");        //进场视频显示label

    ui->enter_recongnition_label->setStyleSheet(m_labelStyle);           //入场识别结果标题label
    ui->out_recongnition_label->setStyleSheet(m_labelStyle);             //出场识别结果标题label

    ui->sum_car_label->setStyleSheet(m_labelStyle);                      //总车位label
    ui->used_car_label->setStyleSheet(m_labelStyle);                     //已用车位label
    ui->remain_car_label->setStyleSheet(m_labelStyle);                   //剩余车位label

    ui->enter_record_title->setStyleSheet(m_labelStyle);                 //入场记录标题label
    ui->out_record_title->setStyleSheet(m_labelStyle);                   //出场记录标题label

    ui->enter_plate_number->setStyleSheet(m_labelStyle1);                //入场车牌显示label
    ui->out_plate_number->setStyleSheet(m_labelStyle1);                  //出场车牌显示label

    ui->enter_recongnition_lb->setStyleSheet("border: 10px groove rgb(0, 191, 255); "
                                             "border-radius: 10px");  //入场识别结果图片显示label  padding:2px 4px
    ui->out_recongnition_lb->setStyleSheet("border: 10px groove rgb(0, 191, 255); "
                                           "border-radius: 10px");    //出场识别结果图片显示label

/******************************* 按钮样式设计 *****************************************/
    m_openCamPbStyle = "QPushButton{background-color: transparent; \
            background-image: url(:/Resource/start2.png); \
            }  \
            QPushButton:hover{ \
            background-image: url(:/Resource/start1.png); \
            } \
            QPushButton:pressed{ \
            background-image: url(:/Resource/start3.png); \
            }";

    m_closeCamPbStyle = "QPushButton{background-color: transparent; \
            background-image: url(:/Resource/stop1.png); \
            }  \
            QPushButton:hover{ \
            background-image: url(:/Resource/stop2.png); \
            } \
            QPushButton:pressed{ \
            background-image: url(:/Resource/stop3.png); \
            }";

    m_openCam1PbPushed = "QPushButton{background-color: transparent; \
            background-image: url(:/Resource/start3.png); \
            }";

    m_closeCam1PbPushed = "QPushButton{background-color: transparent; \
            background-image: url(:/Resource/stop3.png); \
            }";

    m_openCam2PbPushed = "QPushButton{background-color: transparent; \
            background-image: url(:/Resource/start3.png); \
            }";

    m_closeCam2PbPushed = "QPushButton{background-color: transparent; \
            background-image: url(:/Resource/stop3.png); \
            }";

    ui->open_enter_cam->setStyleSheet(m_openCamPbStyle);       //入场打开摄像头1按钮样式
    ui->close_enter_cam->setStyleSheet(m_closeCamPbStyle);     //入场关闭摄像头1按钮样式
    ui->open_out_cam->setStyleSheet(m_openCamPbStyle);         //出场打开摄像头2按钮样式
    ui->close_out_cam->setStyleSheet(m_closeCamPbStyle);       //出场关闭摄像头2按钮样式

    if (m_cam1Open)
    {
        ui->open_enter_cam->setStyleSheet(m_openCam1PbPushed);     //入场打开摄像头1按钮样式
        ui->close_enter_cam->setStyleSheet(m_closeCamPbStyle);     //入场关闭摄像头1按钮样式
    }
    if (!m_cam1Open)
    {
        ui->open_enter_cam->setStyleSheet(m_openCamPbStyle);       //入场打开摄像头1按钮样式
        ui->close_enter_cam->setStyleSheet(m_closeCam1PbPushed);   //入场关闭摄像头1按钮样式
    }

    if (m_cam2Open)
    {
        ui->open_out_cam->setStyleSheet(m_openCam2PbPushed);      //出场打开摄像头2按钮样式
        ui->close_out_cam->setStyleSheet(m_closeCamPbStyle);      //出场关闭摄像头2按钮样式
    }
    if (!m_cam2Open)
    {
        ui->open_out_cam->setStyleSheet(m_openCamPbStyle);         //出场打开摄像头2按钮样式
        ui->close_out_cam->setStyleSheet(m_closeCam2PbPushed);     //出场关闭摄像头2按钮样式
    }
}

//夜晚模式皮肤
void Camera::setNightSkin()
{
    //窗口大小设置
    this->setStyleSheet("background: rgb(65, 65, 65)");    //窗口背景颜色设置 #4D4D4D

    ui->changeSkin->setStyleSheet("QPushButton{background-color: transparent; \
                                  background-image: url(:/Resource/moon.png);\
                                  }     \
                                  QPushButton:hover{ \
                                  background-image: url(:/Resource/sun.png);\
                                  } ");

/****************************** TabView样式变量 ************************/
    m_tabViewStyle = "QHeaderView#hHeader::section {\
            background-color: transparent; \
            color: rgb(0, 255, 255);   \
            font: 75 16pt 华文行楷;  \
            height:40;  \
        }"
            "QHeaderView#vHeader::section {\
            background-color: transparent;  \
            color: rgb(0, 255, 255);   \
            font: 75 14pt 华文行楷; \
            height: 40;  \
            width: 48; \
        }"
            "QTableView{background-color: rgb(65, 65, 65);   \
             alternate-background-color: rgb(65, 65, 65);    \
             selection-color: white;    \
             selection-background-color: rgb(0, 191, 255);  \
        }"
             "QTableView {\
             font: bold 75 13pt 黑体;     \
             color: rgb(0, 255, 255);                         /*表格内文字颜色*/ \
             gridline-color: rgb(0, 255, 127);                /*表格内框颜色*/  \
             selection-color: rgb(192, 14, 235);                 /*选中区域的文字颜色*/   \
             selection-background-color: white;    /*选中区域的背景色*/    \
             border: 2px groove rgb(0, 255, 127);   \
        }"
             "QTableView QTableCornerButton::section{\
             background-color: rgb(65, 65, 65);   \
             font: 75 16pt 华文行楷; \
             color: rgb(85, 255, 255);   \
             height: 40; \
        }";

    //间隔行颜色相同生效
    ui->enter_info_View->setAlternatingRowColors(true);
    ui->out_info_View->setAlternatingRowColors(true);

    //TabView样式设置
    ui->enter_info_View->setStyleSheet(m_tabViewStyle);
    ui->out_info_View->setStyleSheet(m_tabViewStyle);

    //LCD样式
    ui->sum_car_num->setStyleSheet("font: bold; "
                                   "font-size: 30px; "
                                   "color: rgb(255, 0, 255); "
                                   "background-color: rgb(65, 65, 65)");  //背景、字体颜色设置

    ui->used_car_num->setStyleSheet("font: bold; "
                                    "font-size: 30px; "
                                    "color: rgb(255, 0, 255); "
                                    "background-color: rgb(65, 65, 65)");  //背景、字体颜色设置

    ui->remain_car_num->setStyleSheet("font: bold; "
                                      "font-size: 30px; "
                                      "color: rgb(255, 0, 255); "
                                      "background-color: rgb(65, 65, 65)");  //背景、字体颜色设置

/************************** label样式变量 ************************/
    m_labelStyle = "border-radius: 14px; "
                  "color: rgb(0, 255, 255); "
                  "background-color: transparent; "
                  "font: bold 21pt 华文行楷; "
                  "border: 2px solid rgb(0, 255, 127)";

    m_labelStyle1 = "border-radius: 14px; "
                   "color: rgb(0, 255, 255); "
                   "background-color: transparent; "
                   "font: 20pt 黑体; "
                   "border: 2px solid rgb(0, 255, 127)";

    m_enterImgLabel->setStyleSheet("border: 14px groove rgb(0, 191, 255)");        //进场视频显示label
    m_outImgLabel->setStyleSheet("border: 14px groove rgb(0, 191, 255)");          //出场视频显示label

    ui->enter_recongnition_label->setStyleSheet(m_labelStyle);           //入场识别结果标题label
    ui->out_recongnition_label->setStyleSheet(m_labelStyle);             //出场识别结果标题label

    ui->sum_car_label->setStyleSheet(m_labelStyle);                      //总车位label
    ui->used_car_label->setStyleSheet(m_labelStyle);                     //已用车位label
    ui->remain_car_label->setStyleSheet(m_labelStyle);                   //剩余车位label

    ui->enter_record_title->setStyleSheet(m_labelStyle);                 //入场记录标题label
    ui->out_record_title->setStyleSheet(m_labelStyle);                   //出场记录标题label

    ui->enter_plate_number->setStyleSheet(m_labelStyle1);                //入场车牌显示label
    ui->out_plate_number->setStyleSheet(m_labelStyle1);                  //出场车牌显示label

    ui->enter_recongnition_lb->setStyleSheet("border: 10px groove rgb(0, 191, 255); "
                                             "border-radius: 10px");  //入场识别结果图片显示label
    ui->out_recongnition_lb->setStyleSheet("border: 10px groove rgb(0, 191, 255); "
                                           "border-radius: 10px");    //出场识别结果图片显示label


/******************************* 按钮样式设计 *****************************************/
    m_openCamPbStyle = "QPushButton{background-color: transparent; \
            background-image: url(:/Resource/bStart.png); \
            }  \
            QPushButton:hover{ \
            background-image: url(:/Resource/rStart.png); \
            } \
            QPushButton:pressed{ \
            background-image: url(:/Resource/gStart.png); \
            }";

    m_closeCamPbStyle = "QPushButton{background-color: transparent; \
            background-image: url(:/Resource/rPause.png); \
            }  \
            QPushButton:hover{ \
            background-image: url(:/Resource/bPause.png); \
            } \
            QPushButton:pressed{ \
            background-image: url(:/Resource/gPause.png); \
            }";

    m_openCam1PbPushed = "QPushButton{background-color: transparent; \
            background-image: url(:/Resource/gStart.png); \
            }";

    m_closeCam1PbPushed = "QPushButton{background-color: transparent; \
            background-image: url(:/Resource/gPause.png); \
            }";

    m_openCam2PbPushed = "QPushButton{background-color: transparent; \
            background-image: url(:/Resource/gStart.png); \
            }";

    m_closeCam2PbPushed = "QPushButton{background-color: transparent; \
        background-image: url(:/Resource/gPause.png); \
        }";

    if (m_cam1Open)
    {
        ui->open_enter_cam->setStyleSheet(m_openCam1PbPushed);     //入场打开摄像头1按钮样式
        ui->close_enter_cam->setStyleSheet(m_closeCamPbStyle);     //入场关闭摄像头1按钮样式
    }
    if (!m_cam1Open)
    {
        ui->open_enter_cam->setStyleSheet(m_openCamPbStyle);       //入场打开摄像头1按钮样式
        ui->close_enter_cam->setStyleSheet(m_closeCam1PbPushed);   //入场关闭摄像头1按钮样式
    }

    if (m_cam2Open)
    {
        ui->open_out_cam->setStyleSheet(m_openCam2PbPushed);      //出场打开摄像头2按钮样式
        ui->close_out_cam->setStyleSheet(m_closeCamPbStyle);      //出场关闭摄像头2按钮样式
    }
    if (!m_cam2Open)
    {
        ui->open_out_cam->setStyleSheet(m_openCamPbStyle);         //出场打开摄像头2按钮样式
        ui->close_out_cam->setStyleSheet(m_closeCam2PbPushed);     //出场关闭摄像头2按钮样式
    }

    //ROI按钮样式
    m_up = "QPushButton{background: transparent; \
            background-image: url(:/Resource/bUp.png); \
            } \
            QPushButton:hover{ \
            background-image: url(:/Resource/yUp.png); \
            } \
            QPushButton:pressed{ \
            background-image: url(:/Resource/gUp.png); \
            }";

    m_up1 = "QPushButton{background: transparent;\
            background-image: url(:/Resource/yUp.png);\
            }\
            QPushButton:hover{\
            background-image: url(:/Resource/bUp.png);\
            } \
            QPushButton:pressed{\
            background-image: url(:/Resource/gUp.png);\
            }";

    m_down = "QPushButton{background: transparent;\
            background-image: url(:/Resource/yDown.png);\
            }\
            QPushButton:hover{\
            background-image: url(:/Resource/bDown.png);\
            } \
            QPushButton:pressed{\
            background-image: url(:/Resource/gDown.png);\
            }";

    m_down1 = "QPushButton{background: transparent;\
            background-image: url(:/Resource/bDown.png);\
            }\
            QPushButton:hover{\
            background-image: url(:/Resource/yDown.png);\
            } \
            QPushButton:pressed{\
            background-image: url(:/Resource/gDown.png);\
            }";

    m_left = "QPushButton{background: transparent;\
            background-image: url(:/Resource/bLeft.png);\
            }\
            QPushButton:hover{\
            background-image: url(:/Resource/yLeft.png);\
            } \
            QPushButton:pressed{\
            background-image: url(:/Resource/gLeft.png);\
            }";

    m_left1 = "QPushButton{background: transparent;\
            background-image: url(:/Resource/yLeft.png);\
            }\
            QPushButton:hover{\
            background-image: url(:/Resource/bLeft.png);\
            } \
            QPushButton:pressed{\
            background-image: url(:/Resource/gLeft.png);\
            }";

    m_right = "QPushButton{background: transparent; \
            background-image: url(:/Resource/yRight.png);\
            }\
            QPushButton:hover{\
            background-image: url(:/Resource/bRight.png);\
            } \
            QPushButton:pressed{\
            background-image: url(:/Resource/gRight.png);\
            }";

    m_right1 = "QPushButton{background: transparent; \
            background-image: url(:/Resource/bRight.png); \
            } \
            QPushButton:hover{ \
            background-image: url(:/Resource/yRight.png); \
            } \
            QPushButton:pressed{ \
            background-image: url(:/Resource/gRight.png); \
            }";

    ui->roi_top_plus->setStyleSheet(m_up);
    ui->roi_top_subtract->setStyleSheet(m_down);
    ui->roi_bottom_plus->setStyleSheet(m_down1);
    ui->roi_bottom_subtract->setStyleSheet(m_up1);
    ui->roi_left_plus->setStyleSheet(m_left);
    ui->roi_left_subtract->setStyleSheet(m_right);
    ui->roi_right_plus->setStyleSheet(m_right1);
    ui->roi_right_subtract->setStyleSheet(m_left1);
}

void Camera::setButtonTip()
{
    ui->min_pushButton->setToolTip(tr("最小化"));
    ui->close_pushButton->setToolTip(tr("关闭窗口"));
    ui->changeSkin->setToolTip(tr("白天/夜晚模式"));
    ui->open_enter_cam->setToolTip(tr("打开入场摄像头"));
    ui->open_out_cam->setToolTip(tr("打开出场摄像头"));
    ui->close_enter_cam->setToolTip(tr("关闭入场摄像头"));
    ui->close_out_cam->setToolTip(tr("关闭出场摄像头"));
}

/******************************** TabView初始化 ****************************/
//初始化进场信息列表标题
void Camera::initEnterTabViewColumnTitle()
{
    m_enterModel = new QStandardItemModel();

    //定义列标题
    m_enterModel->setHorizontalHeaderItem(0, new QStandardItem("车牌号"));
    m_enterModel->setHorizontalHeaderItem(1, new QStandardItem("入场时间"));
    m_enterModel->setHorizontalHeaderItem(2, new QStandardItem("车辆类型"));

    m_enterModel->setItem(0, 0, new QStandardItem("苏A 123456"));
    m_enterModel->setItem(1, 0, new QStandardItem("苏A 123456"));
    m_enterModel->setItem(2, 0, new QStandardItem("苏A 123456"));

    //将数据模型绑定控件
    ui->enter_info_View->setModel(m_enterModel);
}

//初始化出场信息列表标题
void Camera::initOutTabViewColumnTitle()
{
    m_outModel = new QStandardItemModel();

    //定义列标题
    m_outModel->setHorizontalHeaderItem(0, new QStandardItem("车牌号"));
    m_outModel->setHorizontalHeaderItem(1, new QStandardItem("出场时间"));
    m_outModel->setHorizontalHeaderItem(2, new QStandardItem("停留时间"));
    m_outModel->setHorizontalHeaderItem(3, new QStandardItem("收费金额"));

    //行数据 0 行,0 列
    m_outModel->setItem(0, 0, new QStandardItem("苏A 123456"));
    m_outModel->setItem(1, 0, new QStandardItem("苏A 123456"));
    m_outModel->setItem(2, 0, new QStandardItem("苏A 123456"));

    //将数据模型绑定控件
    ui->out_info_View->setModel(m_outModel);
}

//事件过滤器
bool Camera::eventFilter(QObject* o, QEvent* e)
{
    if (e->type() == QEvent::Paint)
    {
        QAbstractButton *btn = qobject_cast<QAbstractButton*>(o);
        QAbstractButton *btn1 = qobject_cast<QAbstractButton*>(o);
        if (btn && btn1)
        {
            // paint by hand (borrowed from QTableCornerButton)

            QStyleOptionHeader opt, opt1;
            opt.init(btn);
            opt1.init(btn1);

            QStyle::State state = QStyle::State_None;
            if (btn->isEnabled() && btn1->isEnabled())
                state |= QStyle::State_Enabled;
            if (btn->isActiveWindow() && btn1->isActiveWindow())
                state |= QStyle::State_Active;
            if (btn->isDown() && btn1->isDown())
                state |= QStyle::State_Sunken;

            opt.state = state;
            opt1.state = state;

            opt.rect = btn->rect();
            opt1.rect = btn->rect();

            opt.text = btn->text(); // this line is the only difference to QTableCornerButton
            opt1.text = btn->text();

            opt.position = QStyleOptionHeader::OnlyOneSection;
            opt1.position = QStyleOptionHeader::OnlyOneSection;

            QStylePainter painter(btn);
            QStylePainter painter1(btn1);

            painter.drawControl(QStyle::CE_Header, opt);
            painter1.drawControl(QStyle::CE_Header, opt1);

            return true; // eat event

        }
    }
    return false;
}

/******************************* 获取系统时间 ********************************/
QString Camera::getDateTime()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss ");

    return str;
}

//初始化停车位的数量
void Camera::initParkingNumber()
{
    m_sumParkingNum = 1000;         //总车位数量
    m_usedParkingNum = 0;           //已用车位数量
    m_remainParkingNum = 1000;      //剩余车位数量
}


/********************************** 摄像头控制 ********************************/
//打开进场摄像头
void Camera::openEnterCamera()
{
    m_capture1.open(0);
    //m_capture1.open("rtsp://admin:guit123456789@192.168.10.64:554/H.264/ch1/main/av_stream");

    if(m_capture1.isOpened())
    {
        qDebug() << "camera0 is opened";
    }

    m_timer1->start(20);
    m_cam1Open = true;

    ui->open_enter_cam->setStyleSheet(m_openCam1PbPushed);
    ui->close_enter_cam->setStyleSheet(m_closeCamPbStyle);
}

//打开出场摄像头
void Camera::openOutCamera()
{
    m_capture2.open(0);

    if(m_capture2.isOpened())
    {
        qDebug() << "camera1 is opened";
    }

    m_timer2->start(30);

    m_cam2Open = true;

    ui->open_out_cam->setStyleSheet(m_openCam2PbPushed);
    ui->close_out_cam->setStyleSheet(m_closeCamPbStyle);
}

//入场摄像头读取图像
void Camera::readEnterFrame()
{
    m_capture1 >> m_frame1;
    QImage Image = mat2QImage(m_frame1);

    std::string str = getDateTime().toStdString();  //QString类型转String类型
    cv::putText(m_frame1, str, Point(30, 110), 2, 1, Scalar(255, 0, 0), 4, 8);  //绘制时间

    QImage scaleImage = scaleImage2Label(Image, m_enterImgLabel);   // QImage适应QLabel

    ui->enter_Layout->addWidget(m_enterImgLabel);
    m_enterImgLabel->setPixmap(QPixmap::fromImage(scaleImage));
    m_enterImgLabel->setAlignment(Qt::AlignCenter);

    //绘制框
//    if (m_enterImgLabel->m_rectStartPoint.x())
//    {
//        cv::rectangle(m_frame1,
//                      cvPoint(m_enterImgLabel->m_rectStartPoint.x(), m_enterImgLabel->m_rectStartPoint.y()),
//                      cvPoint(m_enterImgLabel->m_rectEndPoint.x(), m_enterImgLabel->m_rectEndPoint.y()),
//                      cvScalar(0, 0, 255),
//                      2,
//                      1,
//                      0);
//    }
}

//出场摄像头读取图像
void Camera::readOutFrame()
{
    m_capture2 >> m_frame2;
    QImage Image = mat2QImage(m_frame2);
    cv::line(m_frame2, cvPoint(136, 73), cvPoint(551, 362), cvScalar(0, 0, 255), 2);

    QImage scaleImage = scaleImage2Label(Image, m_outImgLabel);   // QImage适应QLabel
    ui->out_Layout->addWidget(m_outImgLabel);
    m_outImgLabel->setPixmap(QPixmap::fromImage(scaleImage));
    m_outImgLabel->setAlignment(Qt::AlignCenter);
}

//关闭进场摄像头
void Camera::closeEnterCamera()
{
    m_cam1Open = false;
    m_timer1->stop();                             //停止计时
    m_capture1.release();                         //关闭摄像头

    m_enterImgLabel->setPixmap(QPixmap());        //释放内存，关闭画面

    ui->open_enter_cam->setStyleSheet(m_openCamPbStyle);
    ui->close_enter_cam->setStyleSheet(m_closeCam1PbPushed);

    qDebug() << "Camera0 is closed!";
}

//关闭出场摄像头
void Camera::closeOutCamera()
{
    m_cam2Open = false;
    m_timer2->stop();                             //停止计时
    m_capture2.release();                         //关闭摄像头

    m_outImgLabel->setPixmap(QPixmap());          //释放内存，关闭画面

    ui->close_out_cam->setStyleSheet(m_closeCam2PbPushed);
    ui->open_out_cam->setStyleSheet(m_openCamPbStyle);

    qDebug() << "Camera1 is closed!";
}


/************************* 车位显示 ***************************/
//总车位数量显示
void Camera::showSumCarNumber()
{
    ui->sum_car_num->setDigitCount(4);          //显示位数
    ui->sum_car_num->setDecMode();              //设置进制
    ui->sum_car_num->display(m_sumParkingNum);   //显示
}

//已用车位数量显示
void Camera::showUsedCarNumber()
{
    ui->used_car_num->setDigitCount(4);
    ui->used_car_num->setDecMode();
    ui->used_car_num->display(m_usedParkingNum);
}

//剩余车位数量显示
void Camera::showRemainCarNumber()
{
    ui->remain_car_num->setDigitCount(4);
    ui->remain_car_num->setDecMode();
    ui->remain_car_num->display(m_remainParkingNum);
}


/***************************** 鼠标事件 *****************************/
//鼠标点击
void Camera::mousePressEvent(QMouseEvent *e)
{
    m_last = e->globalPos();
}

//鼠标移动
void Camera::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX() - m_last.x();
    int dy = e->globalY() - m_last.y();
    m_last = e->globalPos();
    move(x()+dx, y()+dy);
}

//鼠标释放
void Camera::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - m_last.x();
    int dy = e->globalY() - m_last.y();
    move(x()+dx, y()+dy);
}


/********************* 窗口控制函数 **************************/

//最小化窗口
void Camera::minimizedWindow()
{
    this->showMinimized();
}

//关闭窗口
void Camera::closeWindow()
{
    this->close();
}

//切换皮肤
void Camera::changeSkin()
{
    if (m_skin)
    {
        setNightSkin();
        m_skin = false;
    }
    else
    {
        setDaySkin();
        m_skin = true;
    }
}

/********************************* 图片格式 *************************************/
//Mat->QImage
QImage Camera::mat2QImage(cv::Mat cvImg)
{
    QImage qImg;

    if (cvImg.channels() == 3)                             //3 channels color image
    {
        cv::cvtColor(cvImg, cvImg, CV_BGR2RGB);
        qImg = QImage((const unsigned char*)(cvImg.data),
                      cvImg.cols, cvImg.rows,
                      cvImg.cols*cvImg.channels(),
                      QImage::Format_RGB888);
    }

    else if (cvImg.channels() == 1)                    //grayscale image
    {
        qImg = QImage((const unsigned char*)(cvImg.data),
                      cvImg.cols, cvImg.rows,
                      cvImg.cols*cvImg.channels(),
                      QImage::Format_Indexed8);
    }

    else
    {
        qImg = QImage((const unsigned char*)(cvImg.data),
                      cvImg.cols, cvImg.rows,
                      cvImg.cols*cvImg.channels(),
                      QImage::Format_RGB888);
    }

    return qImg;
}

//图片适应label大小
QImage Camera::scaleImage2Label(QImage qImage, MyLabel *qLabel)
{
    QImage qScaledImage;
    QSize qImageSize = qImage.size();
    QSize qLabelSize = qLabel->size();

    double dWidthRatio = 1.0 * qImageSize.width() / qLabelSize.width();
    double dHeightRatio = 1.0 * qImageSize.height() / qLabelSize.height();
    if (dWidthRatio>dHeightRatio)
    {
        qScaledImage = qImage.scaledToWidth(qLabelSize.width());
    } else {
        qScaledImage = qImage.scaledToHeight(qLabelSize.height());
    }

    return qScaledImage;
}

/************************* ROI区域调整 ******************************/
//初始化ROI的四条边
void Camera::initRoiLine()
{
    m_roiTop = 136;
    m_roiLeft = 73;
    m_roiRight = 551;
    m_roiBottom = 362;
}

//加
void Camera::roiTopLinePlus()
{
    m_roiTop -= 5;
}

void Camera::roiBottomLinePlus()
{
    m_roiBottom += 5;
}

void Camera::roiLeftLinePlus()
{
    m_roiLeft -= 5;
}

void Camera::roiRightLinePlus()
{
    m_roiRight += 5;
}

//减
void Camera::roiTopLineSubtract()
{
    m_roiTop += 5;
}

void Camera::roiBottomLineSubtract()
{
    m_roiBottom -= 5;
}

void Camera::roiLeftLineSubtract()
{
    m_roiLeft += 5;
}

void Camera::roiRightLineSubtract()
{
    m_roiRight -= 5;
}

//析构
Camera::~Camera()
{
    delete ui;

    delete m_timer1;
    m_timer1 = NULL;

    delete m_timer2;
    m_timer2 = NULL;

    delete m_enterModel;
    m_enterModel = NULL;

    delete m_outModel;
    m_outModel = NULL;

    delete m_enterImgLabel;
    m_enterImgLabel = NULL;

    delete m_outImgLabel;
    m_outImgLabel = NULL;
}
