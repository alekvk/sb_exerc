#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->lineEdit, &QLineEdit::textEdited, [this](QString currentText)
    {
        if (currentText.size()== 12) {
            QRegularExpression exp("(\\+)\\d{11}");
            if(exp.match(currentText).hasMatch())
                setOkLabel();
            else
                setNonOkLabel();
        } else if (currentText.size()== 0) {
            setHintLabel();
        } else
            setNonOkLabel();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Enter the phone number in the format +XXXXXXXXXX

void MainWindow::setHintLabel()
{
    ui->label->setText("Enter the phone number in the format +XXXXXXXXXX");
    ui->label->setStyleSheet("QLabel {color : green;}");

}

void MainWindow::setOkLabel()
{
    ui->label->setText("Ok");
    ui->label->setStyleSheet("QLabel {color : green;}");

}

void MainWindow::setNonOkLabel()
{
    ui->label->setText("Not Ok");
    ui->label->setStyleSheet("QLabel {color : red;}");
}
