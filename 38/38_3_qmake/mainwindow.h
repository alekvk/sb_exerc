#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsBlurEffect>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString sourceFile;
    QImage blurImage(QImage source, int blurRadius);


public slots:
    void openFile();
    void blurImage();

private:
    void setImage(QString sourceFile, int blurValue);
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
