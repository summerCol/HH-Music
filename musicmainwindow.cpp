#include "musicmainwindow.h"
#include <QVBoxLayout>

MusicMainWindow::MusicMainWindow(QWidget *parent) : QMainWindow(parent)
{
    setMinimumSize(1159, 863);

    auto centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);

    auto vBoxLayout = new QVBoxLayout(centralWidget);
    m_playBtn = new QPushButton(tr("播放"));
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
    m_player->play();
}
