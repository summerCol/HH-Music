#ifndef MUSICMAINWINDOW_H
#define MUSICMAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QPushButton>
#include <QMediaPlayer>

class MusicMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MusicMainWindow(QWidget *parent = nullptr);

private:
    QPushButton* m_playBtn;
    QMediaPlayer* m_player;

signals:

public slots:
    void play();

};

#endif // MUSICMAINWINDOW_H
