#ifndef BOTTOMWIDGET_H
#define BOTTOMWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QToolButton>

class BottomWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BottomWidget(QWidget *parent = nullptr);

signals:

private:
    QPushButton* m_playBtn;
    QPushButton* m_preBtn;
    QPushButton* m_nextBtn;
    QToolButton* m_volumeBtn;
    QToolButton* m_recycleBtn;

};

#endif // BOTTOMWIDGET_H
