#ifndef COMBINEDWIDGET_H
#define COMBINEDWIDGET_H

#include <QWidget>
#include <QStringList>

class CombinedWidget : public QWidget {
    Q_OBJECT

public:
    explicit CombinedWidget(QWidget *parent = nullptr);
    void setLabels(const QString &a, const QString &b, const QString &c, const QString &d, const QString &e, const QString &f);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QString labelA; // "1"
    QString labelB; // "B"
    QString labelC; // "u"
    QStringList verticalLabels; // [ ; , 2 , ; , w - ? ]
};

#endif // COMBINEDWIDGET_H
