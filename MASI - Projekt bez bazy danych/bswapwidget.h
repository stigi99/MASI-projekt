#ifndef BSWAPWIDGET_H
#define BSWAPWIDGET_H

#include <QWidget>
#include <QStringList>

class BSwapWidget : public QWidget {
    Q_OBJECT

public:
    explicit BSwapWidget(QWidget *parent = nullptr);
    void setLabels(const QString &a, const QString &b, const QString &c, const QString &d, const QString &e, const QString &f);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QString labelA; // "1"
    QString labelB; // "B"
    QString labelC; // "u"
    QStringList verticalLabels; // [ ; , 2 , ; , w - ? ]
};

#endif // BSWAPWIDGET_H
