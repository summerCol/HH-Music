#include "bottomwidget.h"
#include <QHBoxLayout>
#include <QPalette>
#include <QColor>

BottomWidget::BottomWidget(QWidget *parent) : QWidget(parent)
{
    auto hLayout = new QHBoxLayout(this);

    m_recycleBtn = unique_ptr<QToolButton>(new QToolButton());
    m_preBtn  = unique_ptr<QPushButton>(new QPushButton());
    m_playBtn = unique_ptr<QPushButton>(new QPushButton());
    m_nextBtn  = unique_ptr<QPushButton>(new QPushButton());
    m_volumeBtn  = unique_ptr<QToolButton>(new QToolButton());

    hLayout->addStretch(10); //这一行没注释掉中间几个按钮会偏右边（但是没添加左边Widget的时候不会，刚好是居中的）
    //hLayout->addSpacing(1);
    hLayout->addWidget(m_recycleBtn.get());
    hLayout->addWidget(m_preBtn.get());
    hLayout->addWidget(m_playBtn.get());
    hLayout->addWidget(m_nextBtn.get());
    hLayout->addWidget(m_volumeBtn.get());
    hLayout->addStretch(25);

//    QPalette palette(QColor(50, 8, 85));
//    this->setPalette(palette);
    this->setObjectName("bottomwidget");
    this->setStyleSheet("QWidget#bottomwidget { background-color: rgb(50, 8, 85) }"); //这里不知道为什么添加到主窗口中背景色样式就不见了


    m_playBtn->setFixedSize(48,48);
    m_playBtn->setStyleSheet("QPushButton{ border-image: url(:play.png);"
                                           "background: transparent; }" );
    m_preBtn->setFixedSize(40,40);
    m_preBtn->setStyleSheet("QPushButton{ border-image: url(:pre.png);"
                                           "background: transparent; }" );

    m_nextBtn->setFixedSize(40,40);
    m_nextBtn->setStyleSheet("QPushButton{ border-image: url(:next.png);"
                                           "background: transparent; }" );

    m_recycleBtn->setFixedSize(40,30);
    m_recycleBtn->setStyleSheet("QToolButton{ border-image: url(:recycleMode.png);"
                                           "background: transparent; }" );

    m_volumeBtn->setFixedSize(40,30);
    m_volumeBtn->setStyleSheet("QToolButton{ border-image: url(:volume.png);"
                                           "background: transparent; }" );
}

void BottomWidget::mousePressEvent(QMouseEvent *event)
{
    m_isPress = true;
    m_pressPoint = event->pos();
}

void BottomWidget::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    m_isPress = false;
}

void BottomWidget::mouseMoveEvent(QMouseEvent *event)
{
    //qDebug() << "EVENT POS IS:"<< event->pos() << endl;
    //qDebug() << "this POS IS:"<< this->pos() << endl;
    //this->pos() 返回的是窗体在系统屏幕坐标系的位置坐标
    //event->pos() 返回的是在本窗体坐标系中的位置坐标
    //event->pos() - m_pressPoint 返回点击作用点与当前移动到的点相对本窗体坐标的一个偏移向量，如果点击作用点在原点则便宜向量为（0， 0）
    QPoint tmp = event->pos() - m_pressPoint;
    if(m_isPress)
    {
        //move(this->pos() + tmp);
        emit windgetMove(tmp);
    }
}
