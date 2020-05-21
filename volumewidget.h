#ifndef VOLUMEWIDGET_H
#define VOLUMEWIDGET_H

#include <QObject>
#include <QWidget>
#include <QSlider>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <memory>

using namespace std;

class VolumeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit VolumeWidget(QWidget *parent = nullptr);

signals:

public:
    unique_ptr<QSlider> m_volumeSlider;
    unique_ptr<QVBoxLayout> m_vLayout;
    unique_ptr<QHBoxLayout> m_hLayout1;
    unique_ptr<QHBoxLayout> m_hLayout2;
    unique_ptr<QPushButton> m_volumeBtn;
};

#endif // VOLUMEWIDGET_H
