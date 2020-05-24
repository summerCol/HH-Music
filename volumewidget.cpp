#include "volumewidget.h"

VolumeWidget::VolumeWidget(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(90, 300);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

    m_volumeSlider = unique_ptr<QSlider>(new QSlider(Qt::Vertical));
    m_vLayout = unique_ptr<QVBoxLayout>(new QVBoxLayout(this));
    m_hLayout1 = unique_ptr<QHBoxLayout>(new QHBoxLayout());
    m_hLayout2 = unique_ptr<QHBoxLayout>(new QHBoxLayout());
    m_volumeBtn = unique_ptr<QPushButton>(new QPushButton());

    m_volumeSlider->setRange(0, 100); //because QMediaPlayer is ranging from 0 (silence) to 100 (full volume).

    m_hLayout1->addWidget(m_volumeSlider.get());
    m_hLayout2->addWidget(m_volumeBtn.get());

    m_volumeBtn->setFixedSize(60, 60);

    m_vLayout->addLayout(m_hLayout1.get());
    m_vLayout->addLayout(m_hLayout2.get());
}
