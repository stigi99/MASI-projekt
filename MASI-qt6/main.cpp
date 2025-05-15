#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>
#include <QInputDialog>
#include <QWidget>
#include <QFrame>
#include <QMessageBox>
#include "verticalwidget.h"
#include "horizontalwidget.h"
#include "combinedwidget.h"
#include "globals.h"

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
    horizontalDrawing->setFixedSize(400,120);
    canvasLayout->addWidget(horizontalDrawing, 0, Qt::AlignCenter);
    horizontalDrawing->hide();


    auto *verticalDrawing = new VerticalWidget();
    verticalDrawing->setStyleSheet("background-color: white;"); // tło widgetu na biało
    verticalDrawing->setFixedSize(300, 300);
    canvasLayout->addWidget(verticalDrawing, 0, Qt::AlignLeft);
    verticalDrawing->hide();
   // canvasLayout->setContentsMargins(10, 10, 10, 10);0

    auto *combinedDrawing = new CombinedWidget();
    combinedDrawing->hide();

    auto *buttonvertical = new QPushButton("Wprowadź dane pionowo");
    auto *buttonhorizontal = new QPushButton("Wprowadź dane poziomo");
    auto *buttonswap = new QPushButton("Zamień");
    auto *buttonsave = new QPushButton("Zapisz");

    layout->addWidget(canvasFrame, 1);  // ramka z rysunkiem zajmuje większość miejsca
    layout->addWidget(buttonhorizontal);
    layout->addWidget(buttonvertical);
    layout->addWidget(buttonswap);
    layout->addWidget(buttonsave);


    QObject::connect(buttonvertical, &QPushButton::clicked, [&]() {
        verticalDrawing->show();
        combinedDrawing->hide();
        val1 = QInputDialog::getText(&window, "Dane", "Wprowadź wartość 1:");
        val2 = QInputDialog::getText(&window, "Dane", "Wprowadź wartość 2:");
        valW = QInputDialog::getText(&window, "Dane", "Wprowadź wartość w - ?:");

        if (!val1.isEmpty() && !val2.isEmpty() && !valW.isEmpty()) {
            verticalDrawing->setLabels(val1, val2, valW);
        }
    });

    QObject::connect(buttonhorizontal, &QPushButton::clicked, [&]() {
        horizontalDrawing->show();
        combinedDrawing->hide();
        valA = QInputDialog::getText(&window, "Dane", "Wprowadź wartość A:");
        valB = QInputDialog::getText(&window, "Dane", "Wprowadź wartość B:");
        valU = QInputDialog::getText(&window, "Dane", "Wprowadź wartość u - ?:");

        if (!valA.isEmpty() && !valB.isEmpty() && !valU.isEmpty()) {
            horizontalDrawing->setLabels(valA, valB, valU);
        }
    });

    QObject::connect(buttonswap, &QPushButton::clicked, [&]() {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Zmiana unitermu poziomej operacji eliminowania unitermów na pionową operację eliminowania unitermów.");
        msgBox.setText("Czy chcesz zamienić?");

        // Dodaj własne przyciski
        QPushButton *buttonswapforb = msgBox.addButton("Zamień za B", QMessageBox::ActionRole);
        QPushButton *buttonswapfora = msgBox.addButton("Zamień za A", QMessageBox::ActionRole);

        QPushButton *buttoncancel = msgBox.addButton("Anuluj", QMessageBox::ActionRole);
        // Wyświetl okno dialogowe
        msgBox.exec();
        horizontalDrawing->hide();
        verticalDrawing->hide();

        // Sprawdź, który przycisk został kliknięty
        if (msgBox.clickedButton() == buttonswapfora) {
            combinedDrawing->show();
            combinedDrawing->setMinimumSize(300, 300);
            combinedDrawing->setStyleSheet("background-color: white;");
            if (!val1.isEmpty() && !val2.isEmpty() && !valW.isEmpty() && !valA.isEmpty() && !valB.isEmpty() && !valU.isEmpty()) {
                combinedDrawing->setLabels(val1,val2,valW,valA,valB, valU);
            }

            canvasLayout->addWidget(combinedDrawing);
            // Zapisz dane
        } else if (msgBox.clickedButton() == buttonswapforb) {
            // Nie zapisuj
        } else if (msgBox.clickedButton() == buttoncancel) {
            horizontalDrawing->show();
            verticalDrawing->show();
            // Anuluj operację
        }
    });



    window.resize(800, 600);
    window.show();
    return app.exec();
}
