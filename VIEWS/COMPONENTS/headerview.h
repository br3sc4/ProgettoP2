#ifndef HEADERVIEW_H
#define HEADERVIEW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVector>
#include <QString>
#include <QLabel>

class HeaderView : public QWidget {
    Q_OBJECT
public:
    explicit HeaderView(const QVector<QString>& headerStrings, QWidget *parent = nullptr);
    ~HeaderView();

private:
    QHBoxLayout* _layout;
    QVector<QString> _headerStrings;
    QVector<QLabel*>* _headerLabels;

    void setupLayout();
    void setupLabels();
};

#endif // HEADERVIEW_H
