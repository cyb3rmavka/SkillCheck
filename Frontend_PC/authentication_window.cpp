#include "authentication_window.h"

#include <QVBoxLayout>
#include <QMessageBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

AuthenticationWidget::AuthenticationWidget(QWidget *parent): QWidget(parent){
    gridLayout = new QGridLayout(this);
    usernameInput = new QLineEdit();
    passwordInput = new QLineEdit();
    usernameLabel = new QLabel("Логін:");
    passwordLabel = new QLabel("Пароль");
    loginButton = new QPushButton("Увійти");
    registerButton = new QPushButton("Реєстрація");

    gridLayout->addWidget(usernameLabel, 0, 0);
    gridLayout->addWidget(usernameInput, 0, 1);
    gridLayout->addWidget(passwordLabel, 1, 0);
    gridLayout->addWidget(passwordInput, 1, 1);

    buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(loginButton, 1, Qt::AlignCenter);
    buttonLayout->addWidget(registerButton, 1, Qt::AlignCenter);

    //gridLayout->addWidget(buttonRegister, 2, 1);
    gridLayout->addLayout(buttonLayout, 2, 0, 1, 2);
    gridLayout->setSpacing(10);
}

AuthenticationWidget::~AuthenticationWidget(){}
