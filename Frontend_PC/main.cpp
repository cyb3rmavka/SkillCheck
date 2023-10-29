#include <QApplication>
#include <QDialog>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>

#include "auth_window.h"
#include "register_window.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    AuthorizationDialog dialog;
    //RegistrationDialog dialog;

    //dialog.setWindowTitle("User Registration Form");
    dialog.show();

    return app.exec();
}
