#include "upperwidget.h"

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
    m_hLayout = new QHBoxLayout;
    m_hLayout->addWidget(m_preBtn);
    m_hLayout->addWidget(m_nextBtn);

    m_hLayout1 = new QHBoxLayout;
    m_hLayout1->addWidget(m_minBtn);
    m_hLayout1->addWidget(m_maxBtn);
    m_hLayout1->addWidget(m_closeBtn);

    m_preBtn->setFixedSize(30,30);
    m_nextBtn->setFixedSize(30,30);
    m_minBtn->setFixedSize(30,30);
    m_maxBtn->setFixedSize(30,30);
    m_closeBtn->setFixedSize(30,30);

    m_mainLayout = new QHBoxLayout(this);
    m_mainLayout->addLayout(m_hLayout);
    m_mainLayout->addStretch();
    m_mainLayout->addLayout(m_hLayout1);
}

UpperWidget::~UpperWidget()
{
    delete m_preBtn;
    delete m_nextBtn;
    delete m_minBtn;
    delete m_maxBtn;
    delete m_closeBtn;
    delete m_hLayout;
    delete m_hLayout1;
    delete m_mainLayout;
}
