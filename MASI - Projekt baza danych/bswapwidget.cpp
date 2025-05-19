#include "bswapwidget.h"
#include <QPainter>
#include <QFont>
#include "globals.h"

BSwapWidget::BSwapWidget(QWidget *parent) : QWidget(parent) {
    // domyślne wartości
    labelA = "A";
    labelB = "1";
    labelC = "u";
    verticalLabels = { ";", "2", ";", "w - ?" };
}

void BSwapWidget::setLabels(const QString &a, const QString &b, const QString &c, const QString &d, const QString &e, const QString &f ){
    labelA = d;
    labelB = a;
    labelC = f;
    verticalLabels = { ";", b, ";", c + " - ?" };
    update();
}

void BSwapWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QFont font = painter.font();
    font.setPointSize(16);
    painter.setFont(font);

    int margin = 30;
    int widthMid = width() / 2;
    int heightMid = height() / 2;

    // ---- Rysuj poziomą linię u góry ----
    int topY = margin;
    painter.drawLine(margin, topY, width() - margin, topY);  // pozioma linia
    painter.drawLine(margin, topY - 10, margin, topY + 10);  // lewy znacznik
    painter.drawLine(width() - margin, topY - 10, width() - margin, topY + 10);  // prawy znacznik

    // Rysuj teksty poziome
    int baseX = widthMid - 100;
    int spacingX = 40;
    painter.drawText(baseX + 0 * spacingX , topY + 20, labelA);          // "A"
    painter.drawText(baseX + 1 * spacingX, topY + 20, ";");
    painter.drawText(baseX + 2 * spacingX, topY + 20, labelB);          // "1"
    painter.drawText(baseX + 3 * spacingX, topY + 20, ";");
    painter.drawText(baseX + 4 * spacingX, topY + 20, labelC + " - ?"); // "u - ?"

    // ---- Rysuj pionową linię pod "1" ----
    int verticalX = baseX + 50;  // linia pionowa pod "1"
    int verticalTop = topY + 5;
    int verticalBottom = height() - margin;

    painter.drawLine(verticalX, verticalTop, verticalX, verticalBottom);
    painter.drawLine(verticalX - 10, verticalTop, verticalX + 10, verticalTop);
    painter.drawLine(verticalX - 10, verticalBottom, verticalX + 10, verticalBottom);

    // Rysuj teksty pionowe
    int baseY = verticalTop + 30;
    int spacingY = 35;

    for (int i = 0; i < verticalLabels.size(); ++i) {
        int y = baseY + i * spacingY;
        painter.drawText(verticalX + 15, y, verticalLabels[i]);
    }
}
