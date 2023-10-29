#include "register_form.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QPushButton>

RegistrationDialog::RegistrationDialog(QWidget *parent)
    : QDialog(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    nameLabel = new QLabel("Full Name:");
    nameInput = new QLineEdit;

    userTypeLabel = new QLabel("User Type:");
    studentRadio = new QRadioButton("Student");
    teacherRadio = new QRadioButton("Teacher");

    registerButton = new QPushButton("Register");

    layout->addWidget(nameLabel);
    layout->addWidget(nameInput);
    layout->addWidget(userTypeLabel);
    layout->addWidget(studentRadio);
    layout->addWidget(teacherRadio);
    layout->addWidget(registerButton);

    connect(registerButton, &QPushButton::clicked, this, &RegistrationDialog::registerUser);
}

void RegistrationDialog::registerUser()
{
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

    // You can process the registration data here, e.g., save it to a database
    // Replace this with your actual registration logic

    QMessageBox::information(this, "Registration Successful", "Registration complete. User type: " + userType);
}
