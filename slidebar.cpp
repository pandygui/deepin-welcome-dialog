#include "slidebar.h"
#include <QPainter>

SlideBar::SlideBar(QWidget *parent)
    : QWidget(parent),
      m_layout(new QVBoxLayout(this)),
      m_buttonGroup(new QButtonGroup)
{
    m_titleList << tr("Introduction") << tr("Desktop mode")
                << tr("Icon theme")   << tr("Window effect")
                << tr("Support us")   << tr("About us");

    setStyleSheet("#NavButton {"
                  "border: none;"
                  "text-align: left;"
                  "font-size: 14px;"
                  "padding-left: 10px;"
                  "border: 1px solid transparent;"
                  "border-right: 3px solid transparent;"
                  "}"
                  "#NavButton:hover {"
                  "background-color: #EDEDEE;"
                  "}"
                  "#NavButton:checked {"
                  "color: #2CA7F8;"
                  "background-color: #D5EDFE;"
                  "border: 1px solid #C5E6FD;"
                  "border-right: 3px solid #2CA7F8;"
                  "}");

    m_layout->setSpacing(0);
    m_layout->setMargin(0);

    setFixedWidth(125);
    initButton();

    connect(m_buttonGroup, SIGNAL(buttonClicked(int)), this, SIGNAL(currentIndexChanged(int)));
}

void SlideBar::initButton()
{
    m_layout->addStretch();

    for (int i = 0; i < m_titleList.count(); ++i) {
        QPushButton *btn = new QPushButton(m_titleList.at(i));
        btn->setCheckable(true);
        btn->setObjectName("NavButton");
        btn->setFixedSize(width(), 40);
        m_layout->addWidget(btn);
        m_buttonGroup->addButton(btn, i);

        if (i == 0) {
            btn->setChecked(true);
        }
    }

    m_layout->addStretch();
}
