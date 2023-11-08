#ifndef AUTH_H
#define AUTH_H
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class AuthenticationWidget : public QWidget {
    Q_OBJECT

public:
    AuthenticationWidget(QWidget *parent = nullptr);

private slots:
    void handleLoginButton();

private:
    QLineEdit* usernameInput;
    QLineEdit* passwordInput;
    QPushButton* loginButton;
    QPushButton* registerButton;
    QLabel* resultLabel;
};

#endif
