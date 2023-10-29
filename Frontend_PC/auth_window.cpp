#include "auth_window.h"

#include <QVBoxLayout>
#include <QMessageBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

AuthorizationDialog::AuthorizationDialog(QWidget *parent)
    : QDialog(parent) {
    QVBoxLayout* layout = new QVBoxLayout(this);

    usernameInput = new QLineEdit;
    passwordInput = new QLineEdit;
    loginButton = new QPushButton("Login");
    resultLabel = new QLabel;
    registerButton = new QPushButton("Register");
    usernameInput->setPlaceholderText("Username");
    passwordInput->setPlaceholderText("Password");
    usernameInput->setEchoMode(QLineEdit::Normal);
    passwordInput->setEchoMode(QLineEdit::Password);
    this->setWindowTitle("Authorization Form");
    QString styleSheet = "background-color: white; color: blue; border: 1px solid blue;";
    usernameInput->setStyleSheet(styleSheet);
    passwordInput->setStyleSheet(styleSheet);

    registerButton->setStyleSheet("background-color: blue; color: white;");
    loginButton->setStyleSheet("background-color: blue; color: white;");
    resultLabel->setStyleSheet("color: blue;");

    layout->addWidget(usernameInput);
    layout->addWidget(passwordInput);
    layout->addWidget(loginButton);
    layout->addWidget(resultLabel);
    layout->addWidget(registerButton);
    connect(loginButton, &QPushButton::clicked, this, &AuthorizationDialog::handleLoginButton);
}

void AuthorizationDialog::handleLoginButton() {
    QString username = usernameInput->text();
    QString password = passwordInput->text();

    // Replace this with your actual authentication logic
    if (username == "your_username" && password == "your_password") {
        resultLabel->setText("Login successful");
    } else {
        resultLabel->setText("Login failed. Please check your credentials.");
    }
}
