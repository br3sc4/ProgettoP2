#ifndef BASEVIEW_H
#define BASEVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTableWidget>
#include <QHeaderView>
#include <QSizePolicy>

class BaseAbstractView : public QWidget {
    Q_OBJECT

public:
    explicit BaseAbstractView(const QString& title, const QStringList& headerStrings, QWidget *parent = nullptr);
    virtual ~BaseAbstractView() = 0;
    void setTitle(const QString& title);
    void setHederStrings(const QStringList& headerStrings);
    void resetTableSelection();
    void setData(const QStringList& headerStrings);

private:
    QLabel* _title;

    void setupLayout();
    void setupLabel(const QString& title);
    virtual void setupTable(const QStringList& headerStrings);

protected:
    QTableWidget* _table;
    QVBoxLayout* _verticalLayout;
    QHBoxLayout* _horizontalLayout;

signals:
    void rowDoubleClicked(QTableWidgetItem* rowClicked);
};
#endif // BASEVIEW_H