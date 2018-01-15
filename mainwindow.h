#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <DMainWindow>
#include <QVBoxLayout>
#include "slidebar.h"
#include "contentwidget.h"

DWIDGET_USE_NAMESPACE

class MainWindow : public DMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QWidget *m_mainWidget;
    QVBoxLayout *m_mainLayout;
    QHBoxLayout *m_contentLayout;
    SlideBar *m_slideBar;
    ContentWidget *m_contentWidget;
};

#endif // MAINWINDOW_H
