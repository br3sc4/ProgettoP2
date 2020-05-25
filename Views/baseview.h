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
    explicit BaseView(const QString& title = "Elenco città", QWidget *parent = nullptr);
    virtual ~BaseView();
    virtual void setTitle(const QString& title);

private:
    QVBoxLayout* _verticalLayout;
    QLabel* _title;
    QTableWidget* _table;

    void setupLayout();
    void setupLabel(const QString& title);
    void setupTable();
protected:
    QHBoxLayout* _horizontalLayout;
};
#endif // BASEVIEW_H
