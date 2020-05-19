#ifndef UPPERWIDGET_H
#define UPPERWIDGET_H

#include <QObject>
#include <QWidget>
#include <QMouseEvent>
#include <QPushButton>
#include <QHBoxLayout>

class UpperWidget : public QWidget
{
    Q_OBJECT
public:
    explicit UpperWidget(QWidget *parent = nullptr);
    ~UpperWidget();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

signals:
    void windgetMove(QPoint);

public:
    QPushButton* m_preBtn;
    QPushButton* m_nextBtn;
    QPushButton* m_minBtn;
    QPushButton* m_maxBtn;
    QPushButton* m_closeBtn;
    QHBoxLayout* m_hLayout;
    QHBoxLayout* m_hLayout1;
    QHBoxLayout* m_mainLayout;

private:
    bool m_isPress;
    QPoint m_pressPoint;
};

#endif // UPPERWIDGET_H
