#include "upperwidget.h"
#include <QHBoxLayout>

UpperWidget::UpperWidget(QWidget *parent) : QWidget(parent)
{
    m_preBtn   = new QPushButton;
    m_nextBtn  = new QPushButton;
    m_minBtn   = new QPushButton;
    m_maxBtn   = new QPushButton;
    m_closeBtn = new QPushButton ;

    m_preBtn->setStyleSheet("QPushButton{ border-image: url(:upPre1.png);"
                                           "background: transparent; }" );
    m_nextBtn->setStyleSheet("QPushButton{ border-image: url(:upNext1.png);"
                                           "background: transparent; }" );
    m_minBtn->setStyleSheet("QPushButton{ border-image: url(:minimum.png);"
                                           "background: transparent; }" );
    m_maxBtn->setStyleSheet("QPushButton{ border-image: url(:maximum.png);"
                                           "background: transparent; }" );
    m_closeBtn->setStyleSheet("QPushButton{ border-image: url(:close.png);"
                                           "background: transparent; }" );
    auto hLayout = new QHBoxLayout;
    hLayout->addWidget(m_preBtn);
    hLayout->addWidget(m_nextBtn);

    auto hLayout1 = new QHBoxLayout;
    hLayout1->addWidget(m_minBtn);
    hLayout1->addWidget(m_maxBtn);
    hLayout1->addWidget(m_closeBtn);

    m_preBtn->setFixedSize(30,30);
    m_nextBtn->setFixedSize(30,30);
    m_minBtn->setFixedSize(30,30);
    m_maxBtn->setFixedSize(30,30);
    m_closeBtn->setFixedSize(30,30);

    auto mainLayout = new QHBoxLayout(this);
    mainLayout->addLayout(hLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(hLayout1);

}
