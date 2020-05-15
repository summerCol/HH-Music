#ifndef BOTTOMWIDGET_H
#define BOTTOMWIDGET_H

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QToolButton>
#include <QMouseEvent>
#include <memory>

using namespace std;

class BottomWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BottomWidget(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

signals:
    void windgetMove(QPoint point);
public:
    unique_ptr<QHBoxLayout> m_hLayout;
    unique_ptr<QPushButton> m_playBtn;
    unique_ptr<QPushButton> m_preBtn;
    unique_ptr<QPushButton> m_nextBtn;
    unique_ptr<QToolButton> m_volumeBtn;
    unique_ptr<QToolButton> m_recycleBtn;
    bool m_isPress;
    QPoint m_pressPoint;

};

#endif // BOTTOMWIDGET_H
