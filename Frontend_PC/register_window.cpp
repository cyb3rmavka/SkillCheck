#include "register_window.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QPushButton>

RegistrationDialog::RegistrationDialog(QWidget *parent)
    : QDialog(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    nameLabel = new QLabel("ПІБ");
    nameInput = new QLineEdit;

    userTypeLabel = new QLabel("Тип користувача:");
    studentRadio = new QRadioButton("Студент");
    teacherRadio = new QRadioButton("Викладач");

    registerButton = new QPushButton("Реєстрація");

    layout->addWidget(nameLabel);
    layout->addWidget(nameInput);
    layout->addWidget(userTypeLabel);
    layout->addWidget(studentRadio);
    layout->addWidget(teacherRadio);
    layout->addWidget(registerButton);

    connect(registerButton, &QPushButton::clicked, this, &RegistrationDialog::registerUser);
}

void RegistrationDialog::registerUser() {
    QString fullName = nameInput->text();
    QString userType;

    if (studentRadio->isChecked()) {
        userType = "Student";
    } else if (teacherRadio->isChecked()) {
        userType = "Teacher";
    } else {
        QMessageBox::critical(this, "Error", "Please select a user type.");
        return;
    }

    QMessageBox::information(this, "Registration Successful", "Registration complete. User type: " + userType);
}
