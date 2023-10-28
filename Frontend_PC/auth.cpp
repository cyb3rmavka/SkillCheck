#include "auth_window.h"

#include <QVBoxLayout>
#include <QMessageBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

AuthorizationDialog::AuthorizationDialog(QWidget *parent)
    : QDialog(parent)
{
    QVBoxLayout layout(this);

    usernameInput = new QLineEdit;
    passwordInput = new QLineEdit;
    loginButton = new QPushButton("Login");
    resultLabel = new QLabel;

    usernameInput->setPlaceholderText("Username");
    passwordInput->setPlaceholderText("Password");
    usernameInput->setEchoMode(QLineEdit::Normal);
    passwordInput->setEchoMode(QLineEdit::Password);

    QString styleSheet = "background-color: white; color: blue; border: 1px solid blue;";
    usernameInput->setStyleSheet(styleSheet);
    passwordInput->setStyleSheet(styleSheet);

    loginButton->setStyleSheet("background-color: blue; color: white;");
    resultLabel->setStyleSheet("color: blue;");

    layout.addWidget(usernameInput);
    layout.addWidget(passwordInput);
    layout.addWidget(loginButton);
    layout.addWidget(resultLabel);

    connect(loginButton, &QPushButton::clicked, this, &AuthorizationDialog::handleLoginButton);
}

void AuthorizationDialog::handleLoginButton()
{
    QString username = usernameInput->text();
    QString password = passwordInput->text();

    // Replace this with your actual authentication logic
    if (username == "your_username" && password == "your_password") {
        resultLabel->setText("Login successful");
    } else {
        resultLabel->setText("Login failed. Please check your credentials.");
    }
}
