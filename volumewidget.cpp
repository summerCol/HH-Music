#include "volumewidget.h"

VolumeWidget::VolumeWidget(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(90, 300);
    this->setWindowFlag(Qt::FramelessWindowHint);

    m_volumeSlider = unique_ptr<QSlider>(new QSlider(Qt::Vertical));
    m_vLayout = unique_ptr<QVBoxLayout>(new QVBoxLayout(this));
    m_hLayout1 = unique_ptr<QHBoxLayout>(new QHBoxLayout());
    m_hLayout2 = unique_ptr<QHBoxLayout>(new QHBoxLayout());
    m_volumeBtn = unique_ptr<QPushButton>(new QPushButton());

    m_hLayout1->addWidget(m_volumeSlider.get());
    m_hLayout2->addWidget(m_volumeBtn.get());

    m_volumeBtn->setFixedSize(60, 60);

    m_vLayout->addLayout(m_hLayout1.get());
    m_vLayout->addLayout(m_hLayout2.get());
}
