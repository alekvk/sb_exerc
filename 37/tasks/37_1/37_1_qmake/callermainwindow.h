#ifndef CALLERMAINWINDOW_H
#define CALLERMAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLineEdit>


class CallerMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CallerMainWindow(QWidget* parent = nullptr):
         QMainWindow(parent)
    {}

   QLCDNumber* result = nullptr;
   QLineEdit* num_1 = nullptr;
   QLineEdit* num_2 = nullptr;

public slots:
    void add();
    void substract();
    void multiply();
    void divide();

private:
    double number_1 = 0;
    double number_2 = 0;
    bool checkIsNums(double& n1, double& n2);

};

#endif // CALLERMAINWINDOW_H*/

