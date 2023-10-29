#ifndef REGISTER_FORM_H
#define REGISTER_FORM_H

#include <QDialog>

#include <QRadioButton>
#include <QLabel>
#include <QLineEdit>

class RegistrationDialog : public QDialog
{
    Q_OBJECT

public:
    RegistrationDialog(QWidget *parent = nullptr);

private slots:
    void registerUser();

private:
    QLabel *nameLabel;
    QLineEdit *nameInput;
    QLabel *userTypeLabel;
    QRadioButton *studentRadio;
    QRadioButton *teacherRadio;
    QPushButton *registerButton;
};

#endif // REGISTER_FORM_H
