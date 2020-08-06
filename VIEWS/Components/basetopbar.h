#ifndef BASETOPBAR_H
#define BASETOPBAR_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMenuBar>

class BaseTopBar: public QWidget {
    Q_OBJECT

public:
    explicit BaseTopBar(const QString& title, QWidget* parent = nullptr);
    virtual ~BaseTopBar();

    QString title() const;
    void setTitle(const QString& title);

private:
    QMenuBar* _menubar;
    QLabel* _title;

    void setupLayout();
    void setupMenuBar();
    void setupLabel(const QString& title);

protected:
    QVBoxLayout* _verticalLayout;
    QHBoxLayout* _horizontalLayout;

signals:
    void closeSignal();
    void showAddCityWizard();
    void showAddVehicleWizard();
};

#endif // BASETOPBAR_H
