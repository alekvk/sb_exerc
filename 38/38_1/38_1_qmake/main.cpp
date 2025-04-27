#include <iostream>
#include "sound_button.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SoundButton redButton(nullptr);

    redButton.setFixedSize(200, 200);
    redButton.move(1000, 400);

    redButton.show();

    return a.exec();
}
