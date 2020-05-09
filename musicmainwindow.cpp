#include "musicmainwindow.h"
#include <QVBoxLayout>

MusicMainWindow::MusicMainWindow(QWidget *parent) : QMainWindow(parent), m_play(false)
{
    setMinimumSize(1159, 863);

    auto centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);

    auto vBoxLayout = new QVBoxLayout(centralWidget);
    m_playBtn = new QPushButton(tr(""));
    m_playBtn->setFixedSize(48,48);
    m_playBtn->setStyleSheet("QPushButton{ border-image: url(:play.png);"
                                           "background: transparent; }" );
    vBoxLayout->addStretch(1);
    vBoxLayout->addWidget(m_playBtn);

    m_player = new QMediaPlayer;
    //connect(m_player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    m_player->setMedia(QUrl::fromLocalFile("D:\\ProjectCode\\HH-Music\\music\\玄觞 - 黯然销魂.mp3" ));
    m_player->setVolume(50);

    connect(m_playBtn, SIGNAL(clicked()), this, SLOT(play()));
}


void MusicMainWindow::play()
{
    if(m_play) //处于播放状态时点击展示暂停图片
    {
        m_player->play();
        m_playBtn->setStyleSheet("QPushButton{ border-image: url(:pause.png);"
                                               "background: transparent; }" );
    }
    else      //处于暂停状态时点击展示播放图片
    {
        m_player->pause();
        m_playBtn->setStyleSheet("QPushButton{ border-image: url(:play.png);"
                                               "background: transparent; }" );
    }


    m_play = !m_play;
}
