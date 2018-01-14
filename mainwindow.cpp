#include "mainwindow.h"
#include "dtitlebar.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : DMainWindow(parent),
      m_mainWidget(new QWidget),
      m_mainLayout(new QVBoxLayout(m_mainWidget)),
      m_contentLayout(new QHBoxLayout),
      m_slideBar(new SlideBar)
{
    if (titlebar()) {
        titlebar()->setWindowFlags(Qt::WindowCloseButtonHint);
    }

    m_contentLayout->addWidget(m_slideBar);
    m_contentLayout->addStretch();
    m_mainLayout->setMargin(0);
    m_mainLayout->addLayout(m_contentLayout);

    setFixedSize(700, 450);
    setCentralWidget(m_mainWidget);

    connect(m_slideBar, &SlideBar::currentIndexChanged, this, [=](const int &index) {
        qDebug() << index;
    });
}

MainWindow::~MainWindow()
{

}
