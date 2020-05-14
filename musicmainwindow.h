#ifndef MUSICMAINWINDOW_H
#define MUSICMAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QPushButton>
#include <QMediaPlayer>
#include <QMouseEvent>
#include "bottomwidget.h"
#include "leftwidget.h"
#include "upperwidget.h"

class MusicMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MusicMainWindow(QWidget *parent = nullptr);

protected:
//    void mousePressEvent(QMouseEvent *event);
//    void mouseReleaseEvent(QMouseEvent *event);
//    void mouseMoveEvent(QMouseEvent *event);

private:
    QMediaPlayer* m_player;
    BottomWidget* m_bottomWidget;
    LeftWidget* m_leftWidget;
    UpperWidget* m_upperWidget;
    bool m_play;
    bool m_isPress;
    QPoint m_pressPoint;

signals:

public slots:
    void play();
    void moveSlot(QPoint point);

};

#endif // MUSICMAINWINDOW_H
