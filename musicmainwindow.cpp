#include "musicmainwindow.h"
#include <QDebug>
#include <QSpacerItem>

MusicMainWindow::MusicMainWindow(QWidget *parent) : QMainWindow(parent),
                                                    m_play(false), m_isPress(false),
                                                    m_showNormal(true), m_pressPoint(QPoint(0, 0))
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
    //connect(m_player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    //m_player->setMedia(QUrl::fromLocalFile("D:\\ProjectCode\\HH-Music\\music\\玄觞 - 黯然销魂.mp3" ));
    //m_widgetContainVideo->setMinimumSize(500,400);
    //m_player->setVolume(50);


    m_bottomWidget = new BottomWidget();
    m_leftWidget = new LeftWidget();
    m_upperWidget = new UpperWidget();
    m_leftWidget->setMinimumWidth(260);
    //m_bottomWidget->setFixedWidth(this->width() - m_leftWidget->width());
    //m_upperWidget->setFixedWidth(this->width() - m_leftWidget->width());

    auto centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);

    hMainLayout = new QHBoxLayout(centralWidget);

    vBoxLayout = new QVBoxLayout();
    //auto spacerItem = new QSpacerItem(650, 30);
    vBoxLayout->addWidget(m_upperWidget);
    //vBoxLayout->addStretch(150);
    //m_widgetContainVideo->setLayout(vBoxLayout);
    vBoxLayout->addWidget(m_videoWidget);
    //vBoxLayout->addSpacerItem(spacerItem);
    vBoxLayout->addWidget(m_bottomWidget);

    hMainLayout->addWidget(m_leftWidget);
    hMainLayout->addLayout(vBoxLayout);
    hMainLayout->setMargin(0); //调整主布局的外边距
    hMainLayout->setSpacing(0);


    //m_videoWidget->setMinimumSize(500,400);
    m_player->setVideoOutput(m_videoWidget);
    //m_playlist->setCurrentIndex(0);
    //m_videoWidget->show();
    m_player->play(); //不能播放的花可能是因为没装LAVFilters，、
                      //报错DirectShowPlayerService::doRender: Unresolved error code 0x80040266


    connect(m_bottomWidget->m_playBtn.get(), SIGNAL(clicked()), this, SLOT(play()));
    connect(m_upperWidget, SIGNAL(windgetMove(QPoint)), this, SLOT(moveSlot(QPoint)));
    connect(m_bottomWidget, SIGNAL(windgetMove(QPoint)), this, SLOT(moveSlot(QPoint)));
    connect(m_upperWidget->m_closeBtn, SIGNAL(clicked()), this, SLOT(close()));
    connect(m_upperWidget->m_minBtn, SIGNAL(clicked()), this, SLOT(showMinimized()));
    connect(m_upperWidget->m_maxBtn, SIGNAL(clicked()), this, SLOT(showMaxNormal()) );
}

MusicMainWindow::~MusicMainWindow()
{
    delete m_player;
    delete m_playlist;
    delete m_videoWidget;
    delete m_bottomWidget;
    delete m_leftWidget;
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

/*
void MusicMainWindow::mousePressEvent(QMouseEvent *event)
{
    m_isPress = true;
    m_pressPoint = event->pos();
}

void MusicMainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    m_isPress = false;
}

void MusicMainWindow::mouseMoveEvent(QMouseEvent *event)
{
    //qDebug() << "EVENT POS IS:"<< event->pos() << endl;
    //qDebug() << "this POS IS:"<< this->pos() << endl;
    //this->pos() 返回的是窗体在系统屏幕坐标系的位置坐标
    //event->pos() 返回的是在本窗体坐标系中的位置坐标
    //event->pos() - m_pressPoint 返回点击作用点与当前移动到的点相对本窗体坐标的一个偏移向量，如果点击作用点在原点则便宜向量为（0， 0）
    if(m_isPress)
    {
        move(this->pos() + (event->pos() - m_pressPoint));
    }
}
*/
