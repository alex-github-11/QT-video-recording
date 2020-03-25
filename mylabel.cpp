#include "mylabel.h"

MyLabel::MyLabel(QWidget *parent /*= 0*/ ) : QLabel(parent)
{

}

//鼠标按下
void MyLabel::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        m_isPressed = true;
        m_rectStartPoint = e->pos();
    }

    if (e->button() == Qt::RightButton)
    {
        m_rectStartPoint = m_rectEndPoint;
        update();
    }
}

//鼠标移动
void MyLabel::mouseMoveEvent(QMouseEvent *e)
{
    if (m_isPressed)
    {
        m_rectEndPoint = e->pos();
    }
}

//鼠标抬起
void MyLabel::mouseReleaseEvent(QMouseEvent *e)
{

}

//绘图
void MyLabel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);      //先调用父类的paintEvent为了显示'背景'!!!

    //画矩形
    QPainter painter(this);
    painter.setPen(QPen(Qt::green, 2));

    if (m_rectStartPoint != m_rectEndPoint)
    {
        painter.drawRect(QRect(m_rectStartPoint, m_rectEndPoint));
    }
}

//
MyLabel::~MyLabel()
{

}
