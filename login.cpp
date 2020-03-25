#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    initWindowStyle();

    //信号与槽
    connect(ui->close_bt, SIGNAL(clicked(bool)), this, SLOT(closeWindow()));
    connect(ui->mini_bt, SIGNAL(clicked(bool)), this, SLOT(miniWindow()));
    connect(ui->login_bt, SIGNAL(clicked(bool)), this, SLOT(loginSystem()));
}

//关闭窗口
void Login::closeWindow()
{
    this->close();
}

//最小化窗口
void Login::miniWindow()
{
    this->showMinimized();
}

//登录系统
void Login::loginSystem()
{
    if(ui->autoLogin->isChecked() == true)
    {
        ui->userLineEdit->setText("user");
        ui->pwLineEdit->setText("123456");
        accept();
    }
    else
    {
        // 判断用户名和密码是否正确，如果错误则弹出警告对话框
        //trimmed()函数可以去除字符串前后的空白字符
        if(ui->userLineEdit->text().trimmed() == tr("user") &&
                ui->pwLineEdit->text() == tr("123456"))
        {
            accept();
        }
        else
        {
            QMessageBox::warning(this, tr("警告！"),
                                 tr("用户名或密码错误！"),
                                 QMessageBox::Yes);
        }

        // 清空内容并定位光标
        ui->userLineEdit->clear();
        ui->pwLineEdit->clear();
        ui->userLineEdit->setFocus();
    }
}

//恢复鼠标按压功能
void Login::mousePressEvent(QMouseEvent *e)
{
    m_last = e->globalPos();
}

//恢复鼠标按下后移动功能
void Login::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX() - m_last.x();
    int dy = e->globalY() - m_last.y();
    m_last = e->globalPos();
    move(x() + dx, y() + dy);
}

//恢复鼠标释放功能
void Login::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - m_last.x();
    int dy = e->globalY() - m_last.y();
    move(x() + dx, y() + dy);
}

//登陆界面样式初始化
void Login::initWindowStyle()
{
    this->setFixedSize(454, 668);
    //取消边框及标题栏
    this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);

    //星号输入密码
    ui->pwLineEdit->setEchoMode(QLineEdit::Password);

    //暗注释（设置提示文字）
    ui->pwLineEdit->setStyleSheet("background-color: transparent; "
                                  "color: rgb(0, 255, 255);"
                                  "font: bold 19px 黑体;");
    ui->userLineEdit->setStyleSheet("background-color: transparent; "
                                    "color: rgb(0, 255, 255);"
                                    "font: bold 19px 黑体");

    ui->pwLineEdit->setPlaceholderText(QStringLiteral("密码"));
    ui->userLineEdit->setPlaceholderText(QStringLiteral("用户名"));

    //设置背景
    setAutoFillBackground(true);
    QPalette palette = this->palette();
    palette.setBrush(backgroundRole(), QPixmap("bgi/411.png"));
    this->setPalette(palette);
}

Login::~Login()
{
    delete ui;
}
