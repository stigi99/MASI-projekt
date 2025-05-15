#include "horizontalwidget.h"
#include <QPainter>
#include <QFont>

HorizontalWidget::HorizontalWidget(QWidget *parent) : QWidget(parent) {
    labels = { "A", ";", "B", ";", "u - ?" };
}

void HorizontalWidget::setLabels(const QString &a, const QString &b, const QString &c) {
    labels = { a, ";", b, ";", c + " - ?" };
    update();
}

void HorizontalWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int margin = 30;
    int y = height() / 2;

    painter.drawLine(margin, y, width() - margin, y);
    painter.drawLine(margin, y - 20, margin, y + 20);
    painter.drawLine(width() - margin, y - 20, width() - margin, y + 20);

    QFont font = painter.font();
    font.setPointSize(30);
    painter.setFont(font);

    int baseX = width() / 2 - 160;
    int spacing = 60;

    for (int i = 0; i < labels.size(); ++i) {
        int x = baseX + i * spacing;
        painter.drawText(x, y+ 50, labels[i]);
    }
}
