#ifndef AUTH_H
#define AUTH_H
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

class AuthenticationWidget : public QWidget {
    Q_OBJECT

public:
    AuthenticationWidget(QWidget *parent = nullptr);
    ~AuthenticationWidget();

private slots:
    //void handleLoginButton();

private:
    QGridLayout *gridLayout;
    QHBoxLayout* buttonLayout;

    QLineEdit *usernameInput;
    QLineEdit *passwordInput;
    QPushButton *loginButton;
    QPushButton *registerButton;
    QLabel *usernameLabel;
    QLabel *passwordLabel;
    QLabel *resultLabel;
};

#endif
