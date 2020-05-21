#ifndef MUSICMAINWINDOW_H
#define MUSICMAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QPushButton>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QMouseEvent>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "bottomwidget.h"
#include "leftwidget.h"
#include "upperwidget.h"
#include "volumewidget.h"

class MusicMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MusicMainWindow(QWidget *parent = nullptr);
    ~MusicMainWindow();

private:
    QMediaPlayer* m_player;
    QMediaPlaylist* m_playlist;
    QVideoWidget* m_videoWidget;
    BottomWidget* m_bottomWidget;
    LeftWidget* m_leftWidget;
    UpperWidget* m_upperWidget;
    VolumeWidget* m_volumeWidget;
    QHBoxLayout* hMainLayout;
    QVBoxLayout* vBoxLayout;
    bool m_play;
    bool m_isPress;
    bool m_showNormal;
    bool m_showVolumeWidget;
    QPoint m_pressPoint;

signals:

public slots:
    void play();
    void moveSlot(QPoint point);
    void showMaxNormal();
    void positionChanged(qint64 ms);
    void showVolumeWidget();
};

#endif // MUSICMAINWINDOW_H
