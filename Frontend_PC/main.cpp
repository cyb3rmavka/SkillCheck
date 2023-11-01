#include <QtWidgets>
#include <QApplication>
#include <QDialog>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>




class TrainingTestForm : public QWidget {
    Q_OBJECT

public:
    TrainingTestForm(QWidget *parent = nullptr) : QWidget(parent) {
        QVBoxLayout *layout = new QVBoxLayout;
        QLabel *questionLabel = new QLabel("Question:");
        QTextEdit *questionTextEdit = new QTextEdit;

        QLabel *answersLabel = new QLabel("Answers:");
        QLineEdit *answer1 = new QLineEdit;
        QLineEdit *answer2 = new QLineEdit;
        QLineEdit *answer3 = new QLineEdit;
        QLineEdit *answer4 = new QLineEdit;

        QPushButton *addMediaButton = new QPushButton("Add Media");

        layout->addWidget(questionLabel);
        layout->addWidget(questionTextEdit);
        layout->addWidget(answersLabel);
        layout->addWidget(answer1);
        layout->addWidget(answer2);
        layout->addWidget(answer3);
        layout->addWidget(answer4);
        layout->addWidget(addMediaButton);

        connect(addMediaButton, &QPushButton::clicked, this, &TrainingTestForm::addMedia);

        setLayout(layout);
    }

private slots:
    void addMedia() {
        QString filePath = QFileDialog::getOpenFileName(this, "Select Media File", QDir::homePath(), "Images (*.png *.jpg *.jpeg);;Videos (*.mp4 *.avi)");
        // Store the media file path for later use.
        // You can handle this data as needed.
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    TrainingTestForm window;
    window.show();
    return app.exec();
}

#include "main.moc"
