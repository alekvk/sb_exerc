#include "callermainwindow.h"

void CallerMainWindow::add()
{
    if (checkIsNums(number_1, number_2))
        result->display(number_1 + number_2);
    else result->display("ERROR");
};

void CallerMainWindow::substract()
{
    if (checkIsNums(number_1, number_2))
        result->display(number_1 - number_2);
    else result->display("ERROR");

};

void CallerMainWindow::multiply()
{
    if (checkIsNums(number_1, number_2))
        result->display(number_1 * number_2);
    else result->display("ERROR");

};

void CallerMainWindow::divide()
{
    if (checkIsNums(number_1, number_2) && number_2 != 0)
        result->display(number_1 / number_2);
    else result->display("ERROR");
};


bool CallerMainWindow::checkIsNums(double& n1, double& n2)
{
    bool result;
    bool* noErr_1 = new bool (true);
    bool* noErr_2 = new bool (true);

    n1 = num_1->text().toDouble(noErr_1);
    n2 = num_2->text().toDouble(noErr_2);
    result = *noErr_1 && *noErr_2;

    delete noErr_1;
    noErr_1 = nullptr;
    delete noErr_2;
    noErr_2 = nullptr;

    return result;
}
