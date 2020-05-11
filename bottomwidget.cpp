#include "bottomwidget.h"
#include <QHBoxLayout>
#include <QPalette>
#include <QColor>

BottomWidget::BottomWidget(QWidget *parent) : QWidget(parent)
{
    auto hLayout = new QHBoxLayout(this);

    m_recycleBtn = new QToolButton();
    m_preBtn  = new QPushButton();
    m_playBtn = new QPushButton();
    m_nextBtn  = new QPushButton();
    m_volumeBtn  = new QToolButton();

    //hLayout->addStretch(1); //这一行没注释掉中间几个按钮会偏右边（但是没添加左边Widget的时候不会，刚好是居中的）
    hLayout->addWidget(m_recycleBtn);
    hLayout->addWidget(m_preBtn);
    hLayout->addWidget(m_playBtn);
    hLayout->addWidget(m_nextBtn);
    hLayout->addWidget(m_volumeBtn);
    hLayout->addStretch(1);

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
