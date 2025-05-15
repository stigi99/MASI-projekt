#ifndef HORIZONTALWIDGET_H
#define HORIZONTALWIDGET_H

#include <QWidget>
#include <QStringList>

class HorizontalWidget : public QWidget {
    Q_OBJECT

public:
    explicit HorizontalWidget(QWidget *parent = nullptr);
    void setLabels(const QString &a, const QString &b, const QString &c);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QStringList labels;
};

#endif // HORIZONTALWIDGET_H
