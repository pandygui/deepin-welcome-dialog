#ifndef SLIDEBAR_H
#define SLIDEBAR_H

#include <QWidget>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QPushButton>

class SlideBar : public QWidget
{
    Q_OBJECT

public:
    explicit SlideBar(QWidget *parent = nullptr);

signals:
    void currentIndexChanged(int);

private:
    void initButton();

private:
    QVBoxLayout *m_layout;
    QButtonGroup *m_buttonGroup;
    QStringList m_titleList;
};

#endif // SLIDEBAR_H
