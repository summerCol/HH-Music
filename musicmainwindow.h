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
#include <QMenu>
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
    QMenu* m_modeMenu;
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
    void showVolumeWidget(QPoint pos);
    void setPlayerPosition();
    void showMenu();

protected:
    bool eventFilter(QObject* obj, QEvent* ev);

private:
    void createMenu();
};

#endif // MUSICMAINWINDOW_H
