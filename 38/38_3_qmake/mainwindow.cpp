#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QImage MainWindow::blurImage(QImage imageSource, int blurRadius)
{
    if(imageSource.isNull()) return QImage();
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(imageSource));
    auto* blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(blurRadius);
    item.setGraphicsEffect(blur);
    scene.addItem(&item);
    QImage result (imageSource.size(), QImage::Format_ARGB32);
    result.fill(Qt::transparent);
    QPainter painter(&result);
    scene.render(&painter, QRectF(),
    QRectF(0, 0, imageSource.width(), imageSource.height()));
    return result;
}

void MainWindow::openFile()
{
    sourceFile = QFileDialog::getOpenFileName (nullptr,
                               "Select file to open",
                                "",
                               "image files (*.jpg *.png)" //"Images (*.png *.xpm *.jpg)");
                                );
    setImage(sourceFile, ui->horizontalSlider->sliderPosition());
}

void MainWindow::blurImage()
{
    if(sourceFile.isEmpty())
        ui->label->setText("The image is not selected");
    else
        setImage(sourceFile, ui->horizontalSlider->sliderPosition());
}

void MainWindow::setImage(QString sourceFile, int blurRadius)
{
    ui->label->setPixmap(QPixmap::fromImage(blurImage(QImage(sourceFile), blurRadius).scaled(
    ui->label->width(),
    ui->label->height(),
    Qt::KeepAspectRatio)));
}
