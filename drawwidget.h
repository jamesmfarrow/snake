#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QWidget>

class DrawWidget: QWidget
{
public:
    DrawWidget();

    void paintEvent(QPaintEvent *event);
};

#endif // DRAWWIDGET_H
