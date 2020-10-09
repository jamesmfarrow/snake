#include "drawwidget.h"

#include <QPainter>

DrawWidget::DrawWidget()
{
    setGeometry(0, 0, 300, 300);
    show();
}

void DrawWidget::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
    QPainter painter(this);

    painter.setPen(QPen(Qt::red));
    painter.setBrush(QBrush(Qt::green));
    painter.drawRect(10, 10, 50, 75);
    painter.drawText(20, 30, "hello world!");
}
