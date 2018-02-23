#include "mainwindow.h"
#include "dtitlebar.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : DMainWindow(parent),
      m_mainWidget(new QWidget),
      m_mainLayout(new QVBoxLayout(m_mainWidget)),
      m_bottomLayout(new QHBoxLayout),
      m_contentLayout(new QHBoxLayout),
      m_slideBar(new SlideBar),
      m_contentFrame(new ContentFrame)
{
    if (titlebar()) {
        titlebar()->setWindowFlags(Qt::WindowCloseButtonHint);
    }

    m_contentLayout->setMargin(0);
    m_contentLayout->addWidget(m_slideBar);
    m_contentLayout->addSpacing(10);
    m_contentLayout->addWidget(m_contentFrame);

    m_mainLayout->setMargin(0);
    m_mainLayout->addLayout(m_contentLayout);
    m_mainLayout->addLayout(m_bottomLayout);
    m_mainLayout->addSpacing(15);

    m_bottomLayout->addStretch();
    m_bottomLayout->addWidget(new DLinkButton("用户社区"));
    m_bottomLayout->addSpacing(10);
    m_bottomLayout->addWidget(new DLinkButton("报告问题"));
    m_bottomLayout->addSpacing(10);
    m_bottomLayout->addWidget(new DLinkButton("帮助手册"));
    m_bottomLayout->addSpacing(10);
    m_bottomLayout->addWidget(new DLinkButton("致谢"));
    m_bottomLayout->addStretch();

    setFixedSize(700, 450);
    setCentralWidget(m_mainWidget);

    connect(m_slideBar, &SlideBar::currentIndexChanged, this,
            [=] (const int &index) {
                qDebug() << index;
            });
}

MainWindow::~MainWindow()
{

}
