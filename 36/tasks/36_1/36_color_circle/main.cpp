#include <QApplication>
#include <QSlider>
#include <QVBoxLayout>

#include "colorful_circle.h"


int main(int argc, char *argv[])
{
     QApplication app(argc, argv);
     auto* qvBox = new QVBoxLayout(nullptr);

     auto* sliderCircle = new QWidget();
     sliderCircle->setFixedSize(250, 300);

     auto* circle = new ColorfulCircle(sliderCircle);
     circle->setFixedSize(200, 200);
     circle->move(20, 10);

     auto* slider = new QSlider(Qt::Horizontal);
     slider->setMinimum(0);
     slider->setMaximum(100);
     slider->resize(200, 50);
     slider->move(20, 230);
     slider->setParent(sliderCircle);

     qvBox->addWidget(sliderCircle);

     sliderCircle->show();

     QObject::connect(slider, &QSlider::valueChanged, [&circle](int newValue)
     {
         if (newValue <= 33)
             circle->setGreen();
         else if (newValue > 33 && newValue <= 66)
             circle->setYellow();
         else
             circle->setRed();
     });

     return app.exec();
}

