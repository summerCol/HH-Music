#include <QApplication>
#include "musicmainwindow.h"



int main(int argc, char** argv)
{
    QApplication a(argc, argv);

    MusicMainWindow musicMainWindow;
    musicMainWindow.show();

    return a.exec();  //开启应用事件循环
}
