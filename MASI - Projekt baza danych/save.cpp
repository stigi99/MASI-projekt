#include "save.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

save::save(QWidget *parent) : QDialog(parent) {
    setWindowTitle("Zapisz dane");

    auto *layout = new QVBoxLayout(this);

    // Pole: Nazwa
    auto *nameLabel = new QLabel("Nazwa:");
    nameEdit = new QLineEdit();
    layout->addWidget(nameLabel);
    layout->addWidget(nameEdit);

    // Pole: Opis
    auto *descLabel = new QLabel("Opis:");
    descriptionEdit = new QTextEdit();
    layout->addWidget(descLabel);
    layout->addWidget(descriptionEdit);

    // Przyciski
    saveButton = new QPushButton("Zapisz");
    cancelButton = new QPushButton("Anuluj");

    auto *buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();
    buttonLayout->addWidget(saveButton);
    buttonLayout->addWidget(cancelButton);

    layout->addLayout(buttonLayout);

    connect(saveButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
}

QString save::getName() const {
    return nameEdit->text();
}

QString save::getDescription() const {
    return descriptionEdit->toPlainText();
}
