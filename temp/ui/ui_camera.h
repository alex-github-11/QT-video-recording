/********************************************************************************
** Form generated from reading UI file 'camera.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERA_H
#define UI_CAMERA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Camera
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_4;
    QFrame *video_frame;
    QGridLayout *gridLayout_8;
    QFrame *frame_2;
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *enter_Layout;
    QVBoxLayout *out_Layout;
    QFrame *pushbutton_frame;
    QPushButton *close_enter_cam;
    QPushButton *open_enter_cam;
    QPushButton *close_out_cam;
    QPushButton *open_out_cam;
    QPushButton *roi_top_plus;
    QPushButton *roi_top_subtract;
    QPushButton *roi_bottom_plus;
    QPushButton *roi_bottom_subtract;
    QPushButton *roi_left_plus;
    QPushButton *roi_left_subtract;
    QPushButton *roi_right_subtract;
    QPushButton *roi_right_plus;
    QFrame *info_frame;
    QGridLayout *gridLayout_12;
    QFrame *car_num_frame;
    QGridLayout *gridLayout_9;
    QHBoxLayout *horizontalLayout_3;
    QLabel *sum_car_label;
    QLCDNumber *sum_car_num;
    QLabel *used_car_label;
    QLCDNumber *used_car_num;
    QLabel *remain_car_label;
    QLCDNumber *remain_car_num;
    QFrame *recongnition_frame;
    QGridLayout *gridLayout_11;
    QVBoxLayout *verticalLayout_7;
    QLabel *enter_recongnition_lb;
    QLineEdit *enter_plate_number;
    QVBoxLayout *verticalLayout_8;
    QLabel *out_recongnition_lb;
    QLineEdit *out_plate_number;
    QLabel *enter_recongnition_label;
    QLabel *out_recongnition_label;
    QSpacerItem *verticalSpacer;
    QFrame *car_info_frame;
    QGridLayout *gridLayout_10;
    QGridLayout *gridLayout_6;
    QLabel *enter_record_title;
    QTableView *enter_info_View;
    QTableView *out_info_View;
    QLabel *out_record_title;
    QFrame *title_frame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *title_label;
    QFrame *frame;
    QPushButton *changeSkin;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *min_pushButton;
    QPushButton *close_pushButton;

    void setupUi(QMainWindow *Camera)
    {
        if (Camera->objectName().isEmpty())
            Camera->setObjectName(QStringLiteral("Camera"));
        Camera->resize(1418, 829);
        Camera->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(Camera);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral("border-color: rgb(255, 0, 0);"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, -1, 0, -1);
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(4);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        video_frame = new QFrame(centralWidget);
        video_frame->setObjectName(QStringLiteral("video_frame"));
        video_frame->setMaximumSize(QSize(16777215, 16777215));
        video_frame->setFrameShape(QFrame::Panel);
        video_frame->setFrameShadow(QFrame::Sunken);
        video_frame->setLineWidth(4);
        gridLayout_8 = new QGridLayout(video_frame);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(-1, -1, 5, -1);
        frame_2 = new QFrame(video_frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setMaximumSize(QSize(806, 16777215));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frame_2);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(2, 0, 1, 2);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        enter_Layout = new QVBoxLayout();
        enter_Layout->setSpacing(6);
        enter_Layout->setObjectName(QStringLiteral("enter_Layout"));

        verticalLayout_6->addLayout(enter_Layout);

        out_Layout = new QVBoxLayout();
        out_Layout->setSpacing(6);
        out_Layout->setObjectName(QStringLiteral("out_Layout"));

        verticalLayout_6->addLayout(out_Layout);


        horizontalLayout_6->addLayout(verticalLayout_6);


        gridLayout_7->addLayout(horizontalLayout_6, 0, 0, 1, 1);


        gridLayout_8->addWidget(frame_2, 0, 1, 1, 1);

        pushbutton_frame = new QFrame(video_frame);
        pushbutton_frame->setObjectName(QStringLiteral("pushbutton_frame"));
        pushbutton_frame->setMinimumSize(QSize(237, 0));
        pushbutton_frame->setMaximumSize(QSize(238, 16777215));
        pushbutton_frame->setFrameShape(QFrame::Panel);
        pushbutton_frame->setFrameShadow(QFrame::Sunken);
        pushbutton_frame->setLineWidth(3);
        close_enter_cam = new QPushButton(pushbutton_frame);
        close_enter_cam->setObjectName(QStringLiteral("close_enter_cam"));
        close_enter_cam->setGeometry(QRect(140, 100, 67, 67));
        close_enter_cam->setStyleSheet(QStringLiteral(""));
        open_enter_cam = new QPushButton(pushbutton_frame);
        open_enter_cam->setObjectName(QStringLiteral("open_enter_cam"));
        open_enter_cam->setGeometry(QRect(30, 100, 67, 67));
        open_enter_cam->setMinimumSize(QSize(0, 0));
        open_enter_cam->setStyleSheet(QLatin1String("QPushButton{background-color: transparent; \n"
"background-image: url(:/Resource/blueStart.png);\n"
"}  \n"
" \n"
"QPushButton:hover{ \n"
"background-image: url(:/Resource/redStart.png);\n"
"} \n"
"QPushButton:pressed{\n"
"background-image: url(:/Resource/start3.png);\n"
"}"));
        close_out_cam = new QPushButton(pushbutton_frame);
        close_out_cam->setObjectName(QStringLiteral("close_out_cam"));
        close_out_cam->setGeometry(QRect(140, 210, 67, 67));
        close_out_cam->setStyleSheet(QStringLiteral(""));
        open_out_cam = new QPushButton(pushbutton_frame);
        open_out_cam->setObjectName(QStringLiteral("open_out_cam"));
        open_out_cam->setGeometry(QRect(30, 210, 67, 67));
        open_out_cam->setStyleSheet(QStringLiteral(""));
        roi_top_plus = new QPushButton(pushbutton_frame);
        roi_top_plus->setObjectName(QStringLiteral("roi_top_plus"));
        roi_top_plus->setGeometry(QRect(90, 400, 59, 50));
        roi_top_plus->setStyleSheet(QStringLiteral(""));
        roi_top_plus->setFlat(false);
        roi_top_subtract = new QPushButton(pushbutton_frame);
        roi_top_subtract->setObjectName(QStringLiteral("roi_top_subtract"));
        roi_top_subtract->setGeometry(QRect(90, 450, 59, 50));
        roi_top_subtract->setStyleSheet(QStringLiteral(""));
        roi_bottom_plus = new QPushButton(pushbutton_frame);
        roi_bottom_plus->setObjectName(QStringLiteral("roi_bottom_plus"));
        roi_bottom_plus->setGeometry(QRect(90, 560, 59, 50));
        roi_bottom_plus->setStyleSheet(QStringLiteral(""));
        roi_bottom_subtract = new QPushButton(pushbutton_frame);
        roi_bottom_subtract->setObjectName(QStringLiteral("roi_bottom_subtract"));
        roi_bottom_subtract->setGeometry(QRect(90, 510, 59, 50));
        roi_bottom_subtract->setStyleSheet(QStringLiteral(""));
        roi_left_plus = new QPushButton(pushbutton_frame);
        roi_left_plus->setObjectName(QStringLiteral("roi_left_plus"));
        roi_left_plus->setGeometry(QRect(10, 480, 59, 50));
        roi_left_plus->setStyleSheet(QStringLiteral(""));
        roi_left_subtract = new QPushButton(pushbutton_frame);
        roi_left_subtract->setObjectName(QStringLiteral("roi_left_subtract"));
        roi_left_subtract->setGeometry(QRect(60, 480, 59, 50));
        roi_left_subtract->setStyleSheet(QStringLiteral(""));
        roi_right_subtract = new QPushButton(pushbutton_frame);
        roi_right_subtract->setObjectName(QStringLiteral("roi_right_subtract"));
        roi_right_subtract->setGeometry(QRect(120, 480, 59, 50));
        roi_right_subtract->setStyleSheet(QStringLiteral(""));
        roi_right_plus = new QPushButton(pushbutton_frame);
        roi_right_plus->setObjectName(QStringLiteral("roi_right_plus"));
        roi_right_plus->setGeometry(QRect(170, 480, 59, 50));
        roi_right_plus->setStyleSheet(QStringLiteral(""));

        gridLayout_8->addWidget(pushbutton_frame, 0, 0, 1, 1);


        gridLayout_4->addWidget(video_frame, 0, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout_4, 0, 0, 1, 1);

        info_frame = new QFrame(centralWidget);
        info_frame->setObjectName(QStringLiteral("info_frame"));
        info_frame->setMaximumSize(QSize(803, 16777215));
        info_frame->setFrameShape(QFrame::Panel);
        info_frame->setFrameShadow(QFrame::Sunken);
        info_frame->setLineWidth(4);
        gridLayout_12 = new QGridLayout(info_frame);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        car_num_frame = new QFrame(info_frame);
        car_num_frame->setObjectName(QStringLiteral("car_num_frame"));
        car_num_frame->setFrameShape(QFrame::Panel);
        car_num_frame->setFrameShadow(QFrame::Sunken);
        car_num_frame->setLineWidth(3);
        gridLayout_9 = new QGridLayout(car_num_frame);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        sum_car_label = new QLabel(car_num_frame);
        sum_car_label->setObjectName(QStringLiteral("sum_car_label"));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        sum_car_label->setFont(font);
        sum_car_label->setStyleSheet(QStringLiteral(""));

        horizontalLayout_3->addWidget(sum_car_label);

        sum_car_num = new QLCDNumber(car_num_frame);
        sum_car_num->setObjectName(QStringLiteral("sum_car_num"));
        sum_car_num->setStyleSheet(QStringLiteral(""));
        sum_car_num->setFrameShape(QFrame::Box);
        sum_car_num->setFrameShadow(QFrame::Raised);

        horizontalLayout_3->addWidget(sum_car_num);

        used_car_label = new QLabel(car_num_frame);
        used_car_label->setObjectName(QStringLiteral("used_car_label"));
        used_car_label->setFont(font);
        used_car_label->setStyleSheet(QStringLiteral(""));

        horizontalLayout_3->addWidget(used_car_label);

        used_car_num = new QLCDNumber(car_num_frame);
        used_car_num->setObjectName(QStringLiteral("used_car_num"));
        used_car_num->setStyleSheet(QStringLiteral(""));

        horizontalLayout_3->addWidget(used_car_num);

        remain_car_label = new QLabel(car_num_frame);
        remain_car_label->setObjectName(QStringLiteral("remain_car_label"));
        remain_car_label->setFont(font);
        remain_car_label->setStyleSheet(QStringLiteral(""));

        horizontalLayout_3->addWidget(remain_car_label);

        remain_car_num = new QLCDNumber(car_num_frame);
        remain_car_num->setObjectName(QStringLiteral("remain_car_num"));
        remain_car_num->setStyleSheet(QStringLiteral(""));

        horizontalLayout_3->addWidget(remain_car_num);


        gridLayout_9->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        gridLayout_12->addWidget(car_num_frame, 0, 0, 1, 1);

        recongnition_frame = new QFrame(info_frame);
        recongnition_frame->setObjectName(QStringLiteral("recongnition_frame"));
        recongnition_frame->setFrameShape(QFrame::Panel);
        recongnition_frame->setFrameShadow(QFrame::Sunken);
        recongnition_frame->setLineWidth(4);
        gridLayout_11 = new QGridLayout(recongnition_frame);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        enter_recongnition_lb = new QLabel(recongnition_frame);
        enter_recongnition_lb->setObjectName(QStringLiteral("enter_recongnition_lb"));
        enter_recongnition_lb->setMaximumSize(QSize(16777215, 16777095));

        verticalLayout_7->addWidget(enter_recongnition_lb);

        enter_plate_number = new QLineEdit(recongnition_frame);
        enter_plate_number->setObjectName(QStringLiteral("enter_plate_number"));
        enter_plate_number->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        enter_plate_number->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(enter_plate_number);


        gridLayout_11->addLayout(verticalLayout_7, 1, 0, 1, 1);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        out_recongnition_lb = new QLabel(recongnition_frame);
        out_recongnition_lb->setObjectName(QStringLiteral("out_recongnition_lb"));
        out_recongnition_lb->setMaximumSize(QSize(16777215, 16777095));

        verticalLayout_8->addWidget(out_recongnition_lb);

        out_plate_number = new QLineEdit(recongnition_frame);
        out_plate_number->setObjectName(QStringLiteral("out_plate_number"));
        out_plate_number->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        out_plate_number->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(out_plate_number);


        gridLayout_11->addLayout(verticalLayout_8, 1, 2, 1, 1);

        enter_recongnition_label = new QLabel(recongnition_frame);
        enter_recongnition_label->setObjectName(QStringLiteral("enter_recongnition_label"));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        enter_recongnition_label->setFont(font1);
        enter_recongnition_label->setStyleSheet(QStringLiteral(""));
        enter_recongnition_label->setFrameShape(QFrame::NoFrame);
        enter_recongnition_label->setFrameShadow(QFrame::Plain);

        gridLayout_11->addWidget(enter_recongnition_label, 0, 0, 1, 1);

        out_recongnition_label = new QLabel(recongnition_frame);
        out_recongnition_label->setObjectName(QStringLiteral("out_recongnition_label"));
        out_recongnition_label->setFont(font1);
        out_recongnition_label->setStyleSheet(QStringLiteral(""));

        gridLayout_11->addWidget(out_recongnition_label, 0, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 101, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_11->addItem(verticalSpacer, 1, 1, 1, 1);


        gridLayout_12->addWidget(recongnition_frame, 1, 0, 1, 1);

        car_info_frame = new QFrame(info_frame);
        car_info_frame->setObjectName(QStringLiteral("car_info_frame"));
        car_info_frame->setFrameShape(QFrame::Panel);
        car_info_frame->setFrameShadow(QFrame::Sunken);
        car_info_frame->setLineWidth(4);
        gridLayout_10 = new QGridLayout(car_info_frame);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        enter_record_title = new QLabel(car_info_frame);
        enter_record_title->setObjectName(QStringLiteral("enter_record_title"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font2.setPointSize(16);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        enter_record_title->setFont(font2);
        enter_record_title->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));

        gridLayout_6->addWidget(enter_record_title, 0, 0, 1, 1);

        enter_info_View = new QTableView(car_info_frame);
        enter_info_View->setObjectName(QStringLiteral("enter_info_View"));
        enter_info_View->setFrameShape(QFrame::Panel);
        enter_info_View->setFrameShadow(QFrame::Raised);
        enter_info_View->setLineWidth(4);
        enter_info_View->setAutoScroll(true);
        enter_info_View->setShowGrid(true);
        enter_info_View->setCornerButtonEnabled(true);

        gridLayout_6->addWidget(enter_info_View, 1, 0, 1, 1);

        out_info_View = new QTableView(car_info_frame);
        out_info_View->setObjectName(QStringLiteral("out_info_View"));
        out_info_View->setFrameShape(QFrame::Panel);
        out_info_View->setFrameShadow(QFrame::Raised);
        out_info_View->setLineWidth(4);

        gridLayout_6->addWidget(out_info_View, 1, 1, 1, 1);

        out_record_title = new QLabel(car_info_frame);
        out_record_title->setObjectName(QStringLiteral("out_record_title"));
        out_record_title->setFont(font2);
        out_record_title->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));

        gridLayout_6->addWidget(out_record_title, 0, 1, 1, 1);


        gridLayout_10->addLayout(gridLayout_6, 0, 0, 1, 1);


        gridLayout_12->addWidget(car_info_frame, 2, 0, 1, 1);


        gridLayout_2->addWidget(info_frame, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 1, 0, 1, 1);

        title_frame = new QFrame(centralWidget);
        title_frame->setObjectName(QStringLiteral("title_frame"));
        title_frame->setFrameShape(QFrame::Panel);
        title_frame->setFrameShadow(QFrame::Sunken);
        title_frame->setLineWidth(3);
        horizontalLayout_2 = new QHBoxLayout(title_frame);
        horizontalLayout_2->setSpacing(1);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, 0, 5, 0);
        title_label = new QLabel(title_frame);
        title_label->setObjectName(QStringLiteral("title_label"));
        title_label->setStyleSheet(QString::fromUtf8("color: rgb(0, 191, 255);\n"
"font: 16pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";\n"
""));

        horizontalLayout_2->addWidget(title_label);

        frame = new QFrame(title_frame);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(100, 0));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        changeSkin = new QPushButton(frame);
        changeSkin->setObjectName(QStringLiteral("changeSkin"));
        changeSkin->setGeometry(QRect(20, 0, 32, 32));
        changeSkin->setMaximumSize(QSize(33, 32));
        changeSkin->setStyleSheet(QLatin1String("QPushButton{background-color: transparent; \n"
"background-image: url(:/Resource/sun.png);\n"
"}  \n"
"\n"
"QPushButton:hover{ \n"
"background-image: url(:/Resource/moon.png);\n"
"} "));

        horizontalLayout_2->addWidget(frame);

        horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        min_pushButton = new QPushButton(title_frame);
        min_pushButton->setObjectName(QStringLiteral("min_pushButton"));
        min_pushButton->setMinimumSize(QSize(36, 33));
        min_pushButton->setMaximumSize(QSize(36, 33));
        min_pushButton->setStyleSheet(QLatin1String("QPushButton{background-color: transparent; \n"
"background-image: url(:/Resource/bMini.png);\n"
"}  \n"
" \n"
"QPushButton:hover{ \n"
"background-image: url(:/Resource/Rmini.png);\n"
"} \n"
"\n"
"QPushButton:pressed{\n"
"background-image: url(:/Resource/gMini.png);\n"
"}"));
        min_pushButton->setFlat(false);

        horizontalLayout_2->addWidget(min_pushButton);

        close_pushButton = new QPushButton(title_frame);
        close_pushButton->setObjectName(QStringLiteral("close_pushButton"));
        close_pushButton->setMinimumSize(QSize(36, 33));
        close_pushButton->setMaximumSize(QSize(36, 33));
        close_pushButton->setStyleSheet(QLatin1String("QPushButton{background-color: transparent; \n"
"background-image: url(:/Resource/bClose.png);\n"
"}  \n"
" \n"
"QPushButton:hover{ \n"
"background-image: url(:/Resource/Rclose.png);\n"
"} \n"
"QPushButton:pressed{\n"
"background-image: url(:/Resource/gClose.png);\n"
"}"));

        horizontalLayout_2->addWidget(close_pushButton);


        gridLayout->addWidget(title_frame, 0, 0, 1, 1);

        Camera->setCentralWidget(centralWidget);

        retranslateUi(Camera);

        QMetaObject::connectSlotsByName(Camera);
    } // setupUi

    void retranslateUi(QMainWindow *Camera)
    {
        Camera->setWindowTitle(QApplication::translate("Camera", "Camera", Q_NULLPTR));
        close_enter_cam->setText(QString());
        open_enter_cam->setText(QString());
        close_out_cam->setText(QString());
        open_out_cam->setText(QString());
        roi_top_plus->setText(QString());
        roi_top_subtract->setText(QString());
        roi_bottom_plus->setText(QString());
        roi_bottom_subtract->setText(QString());
        roi_left_plus->setText(QString());
        roi_left_subtract->setText(QString());
        roi_right_subtract->setText(QString());
        roi_right_plus->setText(QString());
        sum_car_label->setText(QApplication::translate("Camera", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600;\">\346\200\273 \350\275\246 \344\275\215</span></p></body></html>", Q_NULLPTR));
        used_car_label->setText(QApplication::translate("Camera", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600;\">\345\267\262\347\224\250\350\275\246\344\275\215</span></p></body></html>", Q_NULLPTR));
        remain_car_label->setText(QApplication::translate("Camera", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600;\">\345\211\251\344\275\231\350\275\246\344\275\215</span></p></body></html>", Q_NULLPTR));
        enter_recongnition_lb->setText(QString());
        enter_plate_number->setText(QApplication::translate("Camera", " Anihio123", Q_NULLPTR));
        out_recongnition_lb->setText(QString());
        out_plate_number->setText(QApplication::translate("Camera", " Anihio123", Q_NULLPTR));
        enter_recongnition_label->setText(QApplication::translate("Camera", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\345\205\245 \345\234\272 \350\257\206 \345\210\253 \347\273\223 \346\236\234</span></p></body></html>", Q_NULLPTR));
        out_recongnition_label->setText(QApplication::translate("Camera", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\345\207\272 \345\234\272 \350\257\206 \345\210\253 \347\273\223 \346\236\234</span></p></body></html>", Q_NULLPTR));
        enter_record_title->setText(QApplication::translate("Camera", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\345\205\245 \345\234\272 \344\277\241 \346\201\257 \350\256\260 \345\275\225</span></p></body></html>", Q_NULLPTR));
        out_record_title->setText(QApplication::translate("Camera", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\345\207\272 \345\234\272 \344\277\241 \346\201\257 \350\256\260 \345\275\225</span></p></body></html>", Q_NULLPTR));
        title_label->setText(QApplication::translate("Camera", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600;\">\350\275\246\347\211\214\350\275\246\350\276\206\346\231\272\350\203\275\350\257\206\345\210\253\347\256\241\347\220\206\347\263\273\347\273\237</span></p></body></html>", Q_NULLPTR));
        changeSkin->setText(QString());
        min_pushButton->setText(QString());
        close_pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Camera: public Ui_Camera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERA_H
