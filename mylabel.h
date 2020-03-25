#ifndef MyLabel_H
#define MyLabel_H

#include <QLabel>
#include <QPoint>
#include <QPainter>
#include <QColor>
#include <QPaintEvent>
#include <QPen>
#include<QPainter>
#include <QWidget>

#include <QDebug>
#include <QMouseEvent>

class MyLabel : public QLabel
{
public:
    explicit MyLabel(QWidget *parent = 0);
    ~MyLabel();

    void paintEvent(QPaintEvent *event) ; //绘制矩形
    void mousePressEvent(QMouseEvent *e);   //鼠标按下
    void mouseMoveEvent(QMouseEvent *e);    //鼠标移动
    void mouseReleaseEvent(QMouseEvent *e); //鼠标抬起

private:
    bool m_isPressed;           //记录鼠标是否按下

    QPoint m_rectStartPoint;    //矩形起点
    QPoint m_rectEndPoint;      //矩形终点
};

#endif // MyLabel_H
