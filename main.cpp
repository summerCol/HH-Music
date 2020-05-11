#include <QApplication>
#include "musicmainwindow.h"
#include "bottomwidget.h"
#include "leftwidget.h"



int main(int argc, char** argv)
{
    QApplication a(argc, argv);

    MusicMainWindow musicMainWindow;
    musicMainWindow.show();
//    BottomWidget btw;
//    btw.show();
//    LeftWidget leftWidget;
//    leftWidget.show();

    return a.exec();  //开启应用事件循环
}
