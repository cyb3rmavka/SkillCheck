#ifndef AUTH_H
#define AUTH_H
#include <QDialog>

class QLineEdit;
class QPushButton;
class QLabel;

class AuthorizationDialog : public QDialog
{
    Q_OBJECT

public:
    AuthorizationDialog(QWidget *parent = nullptr);

private slots:
    void handleLoginButton();

private:
    QLineEdit* usernameInput;
    QLineEdit* passwordInput;
    QPushButton* loginButton;
    QLabel* resultLabel;
};

#endif
