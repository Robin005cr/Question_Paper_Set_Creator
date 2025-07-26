#include <QApplication>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class QuestionPaperSetCreator : public QWidget {
    Q_OBJECT
public:
    QuestionPaperSetCreator(QWidget *parent = nullptr) : QWidget(parent) {
        // Heading
        QLabel *heading = new QLabel("Question Paper Set Creator");
        QFont font = heading->font();
        font.setPointSize(16);
        font.setBold(true);
        heading->setFont(font);
        heading->setAlignment(Qt::AlignCenter);

        // Input path widgets
        QLineEdit *inputEdit = new QLineEdit(this);
        QPushButton *inputBrowse = new QPushButton("Browse...", this);
        connect(inputBrowse, &QPushButton::clicked, [this, inputEdit]() {
            QString file = QFileDialog::getOpenFileName(this, "Select setofquestions.txt", QString(), "Text Files (*.txt);;All Files (*)");
            if (!file.isEmpty())
                inputEdit->setText(file);
        });

        QHBoxLayout *inputLayout = new QHBoxLayout;
        inputLayout->addWidget(new QLabel("Input File Path (setofquestions.txt):"));
        inputLayout->addWidget(inputEdit);
        inputLayout->addWidget(inputBrowse);

        // Output path widgets
        QLineEdit *outputEdit = new QLineEdit(this);
        QPushButton *outputBrowse = new QPushButton("Browse...", this);
        connect(outputBrowse, &QPushButton::clicked, [this, outputEdit]() {
            QString file = QFileDialog::getSaveFileName(this, "Select output file", QString(), "Text Files (*.txt);;All Files (*)");
            if (!file.isEmpty())
                outputEdit->setText(file);
        });

        QHBoxLayout *outputLayout = new QHBoxLayout;
        outputLayout->addWidget(new QLabel("Output File Path:"));
        outputLayout->addWidget(outputEdit);
        outputLayout->addWidget(outputBrowse);

        // Generate button
        QPushButton *generateBtn = new QPushButton("Generate", this);
        generateBtn->setMinimumHeight(32);
        QFont genFont = generateBtn->font();
        genFont.setBold(true);
        generateBtn->setFont(genFont);
        connect(generateBtn, &QPushButton::clicked, [inputEdit, outputEdit]() {
            // Insert your processing logic here
            qDebug("Input: %s", qPrintable(inputEdit->text()));
            qDebug("Output: %s", qPrintable(outputEdit->text()));
        });

        // Layout
        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        mainLayout->addWidget(heading);
        mainLayout->addLayout(inputLayout);
        mainLayout->addLayout(outputLayout);
        mainLayout->addWidget(generateBtn, 0, Qt::AlignHCenter);

        setLayout(mainLayout);
        setWindowTitle("Question Paper Set Creator");
        setMinimumSize(500, 200);
        resize(600, 220);
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QuestionPaperSetCreator window;
    window.show();
    return app.exec();
}

#include "main.moc"
