#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>
#include <QInputDialog>
#include <QWidget>
#include <QFrame>
#include "verticalwidget.h"
#include "horizontalwidget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Rysunek z edycją danych");

    auto *layout = new QVBoxLayout(&window);

    // Tworzymy ramkę jako obszar "canvasowy"
    auto *canvasFrame = new QFrame();
    canvasFrame->setFrameShape(QFrame::Box);
    canvasFrame->setLineWidth(2);
    canvasFrame->setMinimumSize(160, 250);
     canvasFrame->setStyleSheet("background-color: white;"); // tło ramki na biało

    auto *canvasLayout = new QVBoxLayout(canvasFrame);

    auto *horizontalDrawing = new HorizontalWidget();
    horizontalDrawing->setStyleSheet("background-color: white;");
    horizontalDrawing->setFixedSize(300,300);
    canvasLayout->addWidget(horizontalDrawing, 0, Qt::AlignLeft);
    auto *verticalDrawing = new VerticalWidget();
    verticalDrawing->setStyleSheet("background-color: white;"); // tło widgetu na biało
    verticalDrawing->setFixedSize(300, 300);
    canvasLayout->addWidget(verticalDrawing, 0, Qt::AlignLeft);
   // canvasLayout->setContentsMargins(10, 10, 10, 10);

    auto *buttonvertical = new QPushButton("Wprowadź dane pionowo");
    auto *buttonhorizontal = new QPushButton("Wprowadź dane poziomo");

    layout->addWidget(canvasFrame, 1);  // ramka z rysunkiem zajmuje większość miejsca
    layout->addWidget(buttonhorizontal);
    layout->addWidget(buttonvertical);


    QObject::connect(buttonvertical, &QPushButton::clicked, [&]() {
        QString val1 = QInputDialog::getText(&window, "Dane", "Wprowadź wartość 1:");
        QString val2 = QInputDialog::getText(&window, "Dane", "Wprowadź wartość 2:");
        QString val3 = QInputDialog::getText(&window, "Dane", "Wprowadź wartość w - ?:");

        if (!val1.isEmpty() && !val2.isEmpty() && !val3.isEmpty()) {
            verticalDrawing->setLabels(val1, val2, val3);
        }
    });

    QObject::connect(buttonhorizontal, &QPushButton::clicked, [&]() {
        QString valA = QInputDialog::getText(&window, "Dane", "Wprowadź wartość A:");
        QString valB = QInputDialog::getText(&window, "Dane", "Wprowadź wartość B:");
        QString valU = QInputDialog::getText(&window, "Dane", "Wprowadź wartość u - ?:");

        if (!valA.isEmpty() && !valB.isEmpty() && !valU.isEmpty()) {
            verticalDrawing->setLabels(valA, valB, valU);
        }
    });

    window.resize(800, 600);
    window.show();
    return app.exec();
}
