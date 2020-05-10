#include <QApplication>
#include "musicmainwindow.h"
#include "bottomwidget.h"



int main(int argc, char** argv)
{
    QApplication a(argc, argv);

//    MusicMainWindow musicMainWindow;
//    musicMainWindow.show();
    BottomWidget btw;
    btw.show();

    return a.exec();  //开启应用事件循环
}
