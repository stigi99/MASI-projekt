#ifndef SAVE_H
#define SAVE_H

#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>

class save : public QDialog {
    Q_OBJECT

public:
    explicit save(QWidget *parent = nullptr);
    QString getName() const;
    QString getDescription() const;

private:
    QLineEdit *nameEdit;
    QTextEdit *descriptionEdit;
    QPushButton *saveButton;
    QPushButton *cancelButton;
};

#endif // SAVE_H
