#ifndef CONTENTWIDGET_H
#define CONTENTWIDGET_H

#include <QFrame>
#include <QScrollArea>
#include <QVBoxLayout>

class ContentWidget : public QFrame
{
    Q_OBJECT

public:
    explicit ContentWidget(QWidget *parent = 0);

private:
    QScrollArea *m_contentArea;
    QWidget *m_contentFrame;
    QVBoxLayout *m_contentLayout;
};

#endif
