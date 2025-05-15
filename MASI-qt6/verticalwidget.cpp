#include "verticalwidget.h"
#include <QPainter>
#include <QFont>

VerticalWidget::VerticalWidget(QWidget *parent) : QWidget(parent) {
    // Domyślne etykiety
    labels = { "1", ";", "2", ";", "w - ?" };
}

void VerticalWidget::setLabels(const QString &a, const QString &b, const QString &c) {
    labels = { a, ";", b, ";", c + " - ?" };
    update(); // odświeżenie widoku
}

void VerticalWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int margin = 30;
    int x = width() / 2;

    painter.drawLine(x, margin, x, height() - margin);
    painter.drawLine(x - 20, margin, x + 20, margin);
    painter.drawLine(x - 20, height() - margin, x + 20, height() - margin);

    QFont font = painter.font();
    font.setPointSize(40);
    painter.setFont(font);

    int baseY = height() / 2 - 60;
    int spacing = 40;

    for (int i = 0; i < labels.size(); ++i) {
        int y = baseY + i * spacing;
        painter.drawText(x + 25, y, labels[i]);
    }
}
