#ifndef BASEVIEW_H
#define BASEVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTableWidget>
#include <QHeaderView>
#include <QSizePolicy>

class BaseView : public QWidget {
    Q_OBJECT

public:
    explicit BaseView(const QString& title = "Elenco città", QWidget *parent = nullptr);
    virtual ~BaseView();
    void setTitle(const QString& title);
    void resetTable();

private:
    QVBoxLayout* _verticalLayout;
    QLabel* _title;

    void setupLayout();
    void setupLabel(const QString& title);
    virtual void setupTable();

protected:
    QTableWidget* _table;
    QHBoxLayout* _horizontalLayout;

private slots:
    void selectRow(QTableWidgetItem* itemClicked);

signals:
    void selectedCity(QTableWidgetItem* itemClicked);
};
#endif // BASEVIEW_H
