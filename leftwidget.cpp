#include "leftwidget.h"
#include <QVBoxLayout>

LeftWidget::LeftWidget(QWidget *parent) : QWidget(parent)
{
    m_scrollArea = new QScrollArea(this);
    auto scrollWidget = new QWidget();
    m_scrollArea->setBackgroundRole(QPalette::Light);
    auto vLayout = new QVBoxLayout(/*m_scrollArea*/);
    auto mainLayout = new QVBoxLayout(this);

    for(int i = 0; i < 25; ++i)
    {
        m_btnList.push_back(new QPushButton(QString("音乐馆%1").arg(i+1)));
    }

    for(auto btn: m_btnList)
    {
        btn->setMinimumSize(200, 40);
        btn->setStyleSheet("QPushButton {color: white;}");
        vLayout->addWidget(btn);
    }
    m_scrollArea->setMaximumWidth(255);
    scrollWidget->setLayout(vLayout);
    m_scrollArea->setWidget(scrollWidget);
    mainLayout->addWidget(m_scrollArea);

    m_scrollArea->setStyleSheet("QScrollBar:horizontal { "
                                "border: 2px solid grey; "
                                "background: #32CC99;    "
                                "height: 15px; "
                                "margin: 0px 20px 0 20px; "
                            "}     "
                            "QScrollBar::handle:horizontal {  "
                            "    background: white; "
                            "    min-width: 20px;    "
                            "}  "
                            "QScrollBar::add-line:horizontal { "
                            "    border: 2px solid grey;  "
                            "   background: #32CC99;   "
                            "    width: 20px;   "
                            "    subcontrol-position: right; "
                            "    subcontrol-origin: margin;   "
                            "} "

                            "QScrollBar::sub-line:horizontal { "
                            "   border: 2px solid grey;  "
                            "    background: #32CC99;   "
                            "    width: 20px; "
                            "    subcontrol-position: left; "
                            "    subcontrol-origin: margin; "
                            "}");  //不起作用，会被主窗口的样式覆盖掉
}
