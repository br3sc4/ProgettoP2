#ifndef BASEVIEW_H
#define BASEVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTableWidget>
#include <QHeaderView>
#include <QSizePolicy>
#include <QMenuBar>

class BaseAbstractView : public QWidget {
    Q_OBJECT

public:
    explicit BaseAbstractView(const QString& title, const QStringList& headerStrings, QWidget *parent = nullptr);
    virtual ~BaseAbstractView() = 0;

    virtual void update() = 0;

    void setTitle(const QString& title);
    QString getTitle() const;
    void setHederStrings(const QStringList& headerStrings);
    void resetTableSelection();
    void showMessage(const QString& msg);

private:
    QLabel* _title;

    void setupLayout();
    void setupLabel(const QString& title);
    virtual void setupTable(const QStringList& headerStrings);
    virtual void setupMenuBar();

protected:
    QMenuBar* _menubar;
    QTableWidget* _table;
    QVBoxLayout* _verticalLayout;
    QHBoxLayout* _horizontalLayout;

signals:
    void closeSignal();
    void showWizard();
    void rowClicked(int row);
};
#endif // BASEVIEW_H
