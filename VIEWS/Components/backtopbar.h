#ifndef BACKTOPBAR_H
#define BACKTOPBAR_H

#include "basetopbar.h"
#include <QPushButton>

class BackTopBar : public BaseTopBar {
    Q_OBJECT

public:
    explicit BackTopBar(const QString& title, QWidget* parent = nullptr);
    virtual ~BackTopBar();

private:
    QPushButton* _backButton;

    void setupBackButton();

signals:
    void backButtonClicked();
};

#endif // BACKTOPBAR_H
