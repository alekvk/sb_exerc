#include "callermainwindow.h"


CallerMainWindow::CallerMainWindow(QWidget* parent):
    QMainWindow(parent)
    {}


void CallerMainWindow::ch1()
{
    channel = 1;
    outputDisplay();
}

void CallerMainWindow::ch2()
{
    channel = 2;
    outputDisplay();
}

void CallerMainWindow::ch3()
{
    channel = 3;
    outputDisplay();
}

void CallerMainWindow::ch4()
{
    channel = 4;
    outputDisplay();
}

void CallerMainWindow::ch5()
{
    channel = 5;
    outputDisplay();
}

void CallerMainWindow::ch6()
{
    channel = 6;
    outputDisplay();
}

void CallerMainWindow::ch7()
{
    channel = 7;
    outputDisplay();
}

void CallerMainWindow::ch8()
{
    channel = 8;
    outputDisplay();
}

void CallerMainWindow::ch9()
{
    channel = 9;
    outputDisplay();
}

void CallerMainWindow::ch0()
{
    channel = 0;
    outputDisplay();
}

void CallerMainWindow::volHigh()
{
    if (volume < 100)
        volume += 10;
    outputDisplay();
}

void CallerMainWindow::volLow()
{
    if (volume > 0)
        volume -= 10;
    outputDisplay();
}

void CallerMainWindow::chBack()
{
    if (channel > 0)
        --channel;
    else
        channel = 9;

    outputDisplay();
}

void CallerMainWindow::chForward()
{
    if (channel < 9)
        ++channel;
    else
        channel = 0;

    outputDisplay();
}

void CallerMainWindow:: outputDisplay()
{
    std::string ch = std::to_string(channel);
    std::string vol = std::to_string(volume);

    std::string res_str = "Channel: " + ch + " vol: " + vol;
    result->setText(QString::fromStdString(res_str));
}


