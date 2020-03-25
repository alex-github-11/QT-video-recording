#ifndef CAMERA_H
#define CAMERA_H

#include <QDebug>
#include <QImage>
#include <QTimer>
#include <QPixmap>
#include <QDateTime>
#include <QTextCodec>
#include <QMainWindow>
#include <QStylePainter>
#include <QStandardItemModel>

#include "login.h"
#include "mylabel.h"

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

namespace Ui {
class Camera;
}

class Camera : public QMainWindow
{
    Q_OBJECT

public:
    explicit Camera(QWidget *parent = 0);
    ~Camera();

    void setWindowSize();               //设置窗口大小
    void setTabViewStyle();             //设置两个TabView样式
    void setButtonTip();                //设置按钮提示信息

    void showSumCarNumber();            //显示总车位数量
    void showUsedCarNumber();           //显示已用车位数量
    void showRemainCarNumber();         //显示剩余车位数量

    void initRoiLine();                 //初始化ROI1的四条边
    void initParkingNumber();           //初始化停车位的数量
    void initEnterTabViewColumnTitle(); //初始化进场信息列表的各列标题
    void initOutTabViewColumnTitle();   //初始化出场信息列表的各列标题

    bool eventFilter(QObject* o, QEvent* e); //事件过滤器

    QString getDateTime();                   //获取时间
    QImage mat2QImage(cv::Mat cvImg);        //Mat->QImage的转化
    QImage scaleImage2Label(QImage qImage, MyLabel *qLabel);    //图片使用label大小

protected:
    void mousePressEvent(QMouseEvent *e);     //鼠标点击
    void mouseMoveEvent(QMouseEvent *e);      //鼠标移动
    void mouseReleaseEvent(QMouseEvent *e);   //鼠标释放

private slots:
    void changeSkin();         //切换皮肤
    void setDaySkin();         //白天模式皮肤
    void setNightSkin();       //夜晚模式皮肤

    void closeWindow();        //关闭窗口
    void minimizedWindow();    //最小化窗口

    void readOutFrame();       //出场摄像头读取图像
    void openOutCamera();      //打开出场摄像头
    void closeOutCamera();     //关闭出场摄像头

    void readEnterFrame();     //进场摄像头读取图像
    void openEnterCamera();    //打开进场摄像头
    void closeEnterCamera();   //关闭进场摄像头          

    //调整ROI的四条边
    void roiTopLinePlus();
    void roiBottomLinePlus();
    void roiLeftLinePlus();
    void roiRightLinePlus();

    void roiTopLineSubtract();
    void roiBottomLineSubtract();
    void roiLeftLineSubtract();
    void roiRightLineSubtract();

private:
    Ui::Camera *ui;

    QPoint m_last;
    QImage m_image; //一张图像

    //一帧图像
    cv::Mat m_frame1;
    cv::Mat m_frame2;

    bool m_skin;     //记录是否切换皮肤
    bool m_cam1Open; //记录Cmaera1是否打开
    bool m_cam2Open; //记录Cmaera2是否打开

    //ROI1的四条边
    int m_roiTop;
    int m_roiLeft;
    int m_roiRight;
    int m_roiBottom;

    int m_sumParkingNum;        //总车位数量
    int m_usedParkingNum;       //已用车位数量
    int m_remainParkingNum;     //剩余车位数量

    /*定时器，用于定时取帧，隔一段时间获取图像*/
    QTimer *m_timer1;
    QTimer *m_timer2;

    MyLabel *m_enterImgLabel;      //显示入场图像的label
    MyLabel *m_outImgLabel;        //显示出场图像的label

    //label样式
    QString m_labelStyle;
    QString m_labelStyle1;

    QString m_tabViewStyle;        //tabViewStyle的样式变量

    /*调整ROI的四条边的按钮的样式变量*/
    QString m_up;
    QString m_up1;
    QString m_down;
    QString m_down1;
    QString m_left;
    QString m_left1;
    QString m_right;
    QString m_right1;

    QString m_openCamPbStyle;      //开启摄像头按钮的样式变量
    QString m_closeCamPbStyle;     //关闭摄像头按钮的样式变量
    QString m_openCam1PbPushed;    //当摄像头1打开时开启按钮的样式变量
    QString m_closeCam1PbPushed;   //当摄像头1打开时关闭按钮的样式变量
    QString m_openCam2PbPushed;    //当摄像头2打开时开启按钮的样式变量
    QString m_closeCam2PbPushed;   //当摄像头2打开时关闭按钮的样式变量

    //TableView的model
    QStandardItemModel *m_enterModel;
    QStandardItemModel *m_outModel;

    //一个获取视频的抽象接口结构
    cv::VideoCapture m_capture1;
    cv::VideoCapture m_capture2;
};

#endif // CAMERA_H
