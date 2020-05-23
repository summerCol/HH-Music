#include "musicmainwindow.h"
#include <QDebug>
#include <QSpacerItem>

MusicMainWindow::MusicMainWindow(QWidget *parent) : QMainWindow(parent),
                                                    m_play(false), m_isPress(false),
                                                    m_showNormal(true), m_showVolumeWidget(false),
                                                    m_pressPoint(QPoint(0, 0))
{
    setMinimumSize(1275, 863);

    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setStyleSheet("QWidget { background-color: rgb(50, 8, 85) }");  //目前设置整个主窗口的背景色为紫色

    m_videoWidget = new QVideoWidget();
    m_player = new QMediaPlayer;
    m_playlist = new QMediaPlaylist(m_player);
    //m_playlist->addMedia(QUrl::fromLocalFile("D:\\ProjectCode\\HH-Music\\music\\玄觞 - 黯然销魂.mp3" ));
    m_playlist->addMedia(QUrl::fromLocalFile("D:\\ProjectCode\\HH-Music\\music\\zj.mp4" ));
    m_player->setPlaylist(m_playlist);
    connect(m_player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    //m_player->setMedia(QUrl::fromLocalFile("D:\\ProjectCode\\HH-Music\\music\\玄觞 - 黯然销魂.mp3" ));
    //m_player->setVolume(50);


    m_bottomWidget = new BottomWidget();
    m_leftWidget = new LeftWidget();
    m_upperWidget = new UpperWidget();
    m_volumeWidget = new VolumeWidget();
    m_leftWidget->setFixedWidth(262);
    m_bottomWidget->setFixedHeight(90);
    m_upperWidget->setFixedHeight(90);

    auto centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);

    hMainLayout = new QHBoxLayout(centralWidget);

    vBoxLayout = new QVBoxLayout();
    vBoxLayout->addWidget(m_upperWidget);
    vBoxLayout->addWidget(m_videoWidget);
    vBoxLayout->addWidget(m_bottomWidget);

    hMainLayout->addWidget(m_leftWidget);
    hMainLayout->addLayout(vBoxLayout);
    hMainLayout->setMargin(0); //调整主布局的外边距
    hMainLayout->setSpacing(0);


    m_player->setVideoOutput(m_videoWidget);
    m_player->play(); //不能播放的花可能是因为没装LAVFilters，、
                      //报错DirectShowPlayerService::doRender: Unresolved error code 0x80040266

    m_player->setVolume(0);
    m_volumeWidget->m_volumeSlider->setValue(m_player->volume());


    connect(m_bottomWidget->m_playBtn.get(), SIGNAL(clicked()), this, SLOT(play()));
    connect(m_upperWidget, SIGNAL(windgetMove(QPoint)), this, SLOT(moveSlot(QPoint)));
    connect(m_upperWidget, SIGNAL(doubleClick()), this, SLOT(showMaxNormal()));
    connect(m_bottomWidget, SIGNAL(windgetMove(QPoint)), this, SLOT(moveSlot(QPoint)));
    connect(m_upperWidget->m_closeBtn, SIGNAL(clicked()), this, SLOT(close()));
    connect(m_upperWidget->m_minBtn, SIGNAL(clicked()), this, SLOT(showMinimized()));
    connect(m_upperWidget->m_maxBtn, SIGNAL(clicked()), this, SLOT(showMaxNormal()));
    connect(m_bottomWidget->m_volumeBtn.get(), SIGNAL(clicked()), m_bottomWidget, SLOT(volumeBtnSlot()));
    connect(m_bottomWidget, SIGNAL(clickPos(QPoint)), this, SLOT(showVolumeWidget(QPoint)));
    connect(m_volumeWidget->m_volumeSlider.get(), SIGNAL(valueChanged(int)), m_player, SLOT(setVolume(int)));
}

MusicMainWindow::~MusicMainWindow()
{
    delete m_player;
    delete m_playlist;
    delete m_videoWidget;
    delete m_bottomWidget;
    delete m_leftWidget;
    delete m_volumeWidget;
    delete m_upperWidget;
    delete hMainLayout;
    delete vBoxLayout;
}


void MusicMainWindow::play()
{
    if(m_play) //处于播放状态时点击展示暂停图片
    {
        m_player->play();
        m_bottomWidget->m_playBtn->setStyleSheet("QPushButton{ border-image: url(:pause.png);"
                                               "background: transparent; }" );
    }
    else      //处于暂停状态时点击展示播放图片
    {
        m_player->pause();
        m_bottomWidget->m_playBtn->setStyleSheet("QPushButton{ border-image: url(:play.png);"
                                               "background: transparent; }" );
    }


    m_play = !m_play;
}

void MusicMainWindow::moveSlot(QPoint point)
{
    move(this->pos() + point);
}

void MusicMainWindow::showMaxNormal()
{
    m_showNormal = !m_showNormal;

    if(m_showNormal)
    {
        showNormal();
    }
    else
    {
        showMaximized();
    }
}

void MusicMainWindow::showVolumeWidget(QPoint pos)
{
    //QPoint volumePos = pos + QPoint(0, m_volumeWidget->height());
    //pos.x() - m_volumeWidget->width()/4 是个目测估计值，可以再优化
    QPoint volumePos = QPoint(pos.x() - m_volumeWidget->width()/4, pos.y() - m_volumeWidget->height());

    m_showVolumeWidget = !m_showVolumeWidget;

    if(m_showVolumeWidget)
    {
        //qDebug() << "m_bottomWidget->m_volumeBtn->pos is :" <<  m_bottomWidget->m_volumeBtn->pos() << endl;
        //qDebug() << "m_bottomWidget->m_volumeBtn->pos is :" <<  mapToGlobal( m_bottomWidget->m_volumeBtn->pos() ) << endl;
        //qDebug() << "m_bottomWidget->m_volumeBtn->pos is :" <<  mapToGlobal( m_bottomWidget->mapToParent( m_bottomWidget->m_volumeBtn->pos()) ) << endl;
        //m_volumeWidget->move(QCursor::pos());  //??? how to let it above the volume button
        m_volumeWidget->move(volumePos);
        m_volumeWidget->show();
    }
    else
    {
        m_volumeWidget->hide();
    }

}


void MusicMainWindow::positionChanged(qint64 ms)
{
    //qDebug() << __FUNCTION__ << ms << endl;
    //qDebug() << __FUNCTION__ << "duration is:" <<m_player->duration() << endl;
    m_bottomWidget->m_progressSlider->setSliderPosition(static_cast<double>(ms)/m_player->duration()*100);
}
