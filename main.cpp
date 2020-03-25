#include "camera.h"
#include "login.h"

#include <QApplication>
#include <QPushButton>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Camera w;
    Login login;

    if (login.exec() == QDialog::Accepted)
    {
        w.show();
        w.move ((QApplication::desktop()->width() - w.width())/2,
                (QApplication::desktop()->height() - w.height())/2);    //¥∞ø⁄æ”÷–œ‘ æ

        return a.exec();
    }
    else
        return 0;
}

