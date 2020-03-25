#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QString>
#include <QMouseEvent>
#include <QMessageBox>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

    void initWindowStyle();

protected:
    void mousePressEvent(QMouseEvent *e);   //恢复鼠标按压功能
    void mouseMoveEvent(QMouseEvent *e);    //恢复鼠标按下后移动功能
    void mouseReleaseEvent(QMouseEvent *e); //恢复鼠标释放功能

private slots:
    void closeWindow();   //关闭窗口
    void miniWindow();    //最小化窗口
    void loginSystem();   //登录系统

private:
    Ui::Login *ui;

    QPoint m_last;
    QString m_passWord;
};

#endif // LOGIN_H
