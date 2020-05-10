#ifndef MUSICMAINWINDOW_H
#define MUSICMAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QPushButton>
#include <QMediaPlayer>
#include "bottomwidget.h"

class MusicMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MusicMainWindow(QWidget *parent = nullptr);

private:
    QMediaPlayer* m_player;
    BottomWidget* m_bottomWidget;
    bool m_play;

signals:

public slots:
    void play();

};

#endif // MUSICMAINWINDOW_H
