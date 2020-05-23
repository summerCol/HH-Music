#include "bottomwidget.h"
#include <QPalette>
#include <QColor>
#include <QDebug>

BottomWidget::BottomWidget(QWidget *parent) : QWidget(parent)
{
    m_hLayout = unique_ptr<QHBoxLayout>(new QHBoxLayout());
    m_vLayout = unique_ptr<QVBoxLayout>(new QVBoxLayout(this));

    m_recycleBtn = unique_ptr<QToolButton>(new QToolButton());
    m_preBtn  = unique_ptr<QPushButton>(new QPushButton());
    m_playBtn = unique_ptr<QPushButton>(new QPushButton());
    m_nextBtn  = unique_ptr<QPushButton>(new QPushButton());
    m_volumeBtn  = unique_ptr<QToolButton>(new QToolButton());
    m_progressSlider = unique_ptr<QSlider>(new QSlider(Qt::Horizontal));

    m_progressSlider->setRange(1,100);

    m_hLayout->addStretch(10); //这一行没注释掉中间几个按钮会偏右边（但是没添加左边Widget的时候不会，刚好是居中的）
    //hLayout->addSpacing(1);
    m_hLayout->addWidget(m_recycleBtn.get());
    m_hLayout->addWidget(m_preBtn.get());
    m_hLayout->addWidget(m_playBtn.get());
    m_hLayout->addWidget(m_nextBtn.get());
    m_hLayout->addWidget(m_volumeBtn.get());
    m_hLayout->addStretch(10);  //bottomwidget layout will be compact to middle(if set 25 will compact to left)


    m_vLayout->addWidget(m_progressSlider.get());
    m_vLayout->addLayout(m_hLayout.get());

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

    m_progressSlider->setStyleSheet("  QSlider::groove:horizontal { "
                                  "border: 1px solid #999999; "
                                  "height: 1px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */ "
                                  "background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4); "
                                  "margin: 1px 0; "
                              "} "

                              "QSlider::handle:horizontal { "
                                  "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #b4b4b4, stop:1 #8f8f8f); "
                                  "border: 2px solid rgb(167, 120, 254); "
                                  "width: 12px; "
                                  "margin: -2px 0; /* handle is placed by default on the contents rect of the groove. Expand outside the groove */ "
                                  "border-radius: 3px; "
                              "}"
                              "QSlider::add-page:horizontal { "
                                  "background: rgb(93, 61, 117); "
                              "} "

                              "QSlider::sub-page:horizontal { "
                                  "background: rgb(167, 120, 254);"
                              "}");

    connect(m_volumeBtn.get(), SIGNAL(click()), this, SLOT(volumeBtnSlot()));
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

void BottomWidget::volumeBtnSlot()
{
    QPoint point;

    point = mapToGlobal(m_volumeBtn->pos());

    emit clickPos(point);
}
