#ifndef BASEVIEW_H
#define BASEVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTableWidget>

class BaseView : public QWidget {
    Q_OBJECT

public:
    BaseView(const QString& title, QWidget *parent = nullptr);
    virtual ~BaseView();

private:
    QLabel* _title;
    QTableWidget* _table;
    QVBoxLayout* _verticalLayout;

    void setupLayout();
    void setupLabel(const QString& title);
    void setupTable();
protected:
    QHBoxLayout* _horizontalLayout;
};
#endif // BASEVIEW_H
