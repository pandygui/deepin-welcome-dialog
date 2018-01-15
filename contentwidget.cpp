#include "contentwidget.h"
#include <QLabel>

ContentWidget::ContentWidget(QWidget *parent)
    : QFrame(parent),
      m_contentArea(new QScrollArea),
      m_contentFrame(new QWidget),
      m_contentLayout(new QVBoxLayout(m_contentFrame))
{
    setContentsMargins(0, 0, 0, 0);

    auto layout = new QVBoxLayout(this);

    m_contentArea->setContentsMargins(0, 0, 0, 0);
    m_contentArea->setWidgetResizable(true);
    m_contentArea->setWidget(m_contentFrame);
    
    layout->addWidget(m_contentArea);

    for (int i = 0; i < 100; ++i) {
        m_contentLayout->addWidget(new QLabel(QString::number(i)));
    }
}
