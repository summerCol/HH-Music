#ifndef LEFTWIDGET_H
#define LEFTWIDGET_H

#include <QObject>
#include <QWidget>
#include <QScrollArea>
#include <QPushButton>

class LeftWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LeftWidget(QWidget *parent = nullptr);

signals:

private:
    QScrollArea* m_scrollArea;
    QList<QPushButton*> m_btnList;

};

#endif // LEFTWIDGET_H
