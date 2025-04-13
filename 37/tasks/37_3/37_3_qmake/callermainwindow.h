#ifndef CALLERMAINWINDOW_H
#define CALLERMAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QLineEdit>


QT_BEGIN_NAMESPACE
namespace Ui { class TVControlPanel; }
QT_END_NAMESPACE


class CallerMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CallerMainWindow(QWidget* parent = nullptr);
    QLineEdit* result = nullptr;
    int volume = 10;
    int channel = 0;

public slots:
    void ch1();
    void ch2();
    void ch3();
    void ch4();
    void ch5();
    void ch6();
    void ch7();
    void ch8();
    void ch9();
    void ch0();
    void volLow();
    void volHigh();
    void chBack();
    void chForward();

private:
    Ui::TVControlPanel *ui;
    void outputDisplay();
};

#endif // CALLERMAINWINDOW_H
