#ifndef BOTTOMWIDGET_H
#define BOTTOMWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QToolButton>
#include <QMouseEvent>

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
    QPushButton* m_playBtn;
    QPushButton* m_preBtn;
    QPushButton* m_nextBtn;
    QToolButton* m_volumeBtn;
    QToolButton* m_recycleBtn;
    bool m_isPress;
    QPoint m_pressPoint;

};

#endif // BOTTOMWIDGET_H
