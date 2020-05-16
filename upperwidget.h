#ifndef UPPERWIDGET_H
#define UPPERWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

class UpperWidget : public QWidget
{
    Q_OBJECT
public:
    explicit UpperWidget(QWidget *parent = nullptr);
    ~UpperWidget();

signals:

public:
    QPushButton* m_preBtn;
    QPushButton* m_nextBtn;
    QPushButton* m_minBtn;
    QPushButton* m_maxBtn;
    QPushButton* m_closeBtn;
    QHBoxLayout* m_hLayout;
    QHBoxLayout* m_hLayout1;
    QHBoxLayout* m_mainLayout;
};

#endif // UPPERWIDGET_H
