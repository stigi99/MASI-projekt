#ifndef VERTICALWIDGET_H
#define VERTICALWIDGET_H

#include <QWidget>
#include <QStringList>

class VerticalWidget : public QWidget {
    Q_OBJECT

public:
    explicit VerticalWidget(QWidget *parent = nullptr);

    void setLabels(const QString &a, const QString &b, const QString &c);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QStringList labels;
};

#endif // VERTICALWIDGET_H
