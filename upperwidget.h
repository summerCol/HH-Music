#ifndef UPPERWIDGET_H
#define UPPERWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPushButton>

class UpperWidget : public QWidget
{
    Q_OBJECT
public:
    explicit UpperWidget(QWidget *parent = nullptr);

signals:

private:
    QPushButton* m_preBtn;
    QPushButton* m_nextBtn;
    QPushButton* m_minBtn;
    QPushButton* m_maxBtn;
    QPushButton* m_closeBtn;

};

#endif // UPPERWIDGET_H
