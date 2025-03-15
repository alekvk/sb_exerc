#include "colorful_circle.h"


ColorfulCircle::ColorfulCircle(QWidget* parent)
{
    setParent(parent);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mGreenCircle = QPixmap("..\\colors\\green.png");
    mYellowCircle = QPixmap("..\\colors\\yellow.png");
    mRedCircle = QPixmap("..\\colors\\red.png");
    mCurrentCircle = mGreenCircle;
    setGeometry(mCurrentCircle.rect());
}

void ColorfulCircle::paintEvent(QPaintEvent* e)
{
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrentCircle);
}

QSize ColorfulCircle::minimumSizeHint() const
{
    return QSize(100, 100);
}

void ColorfulCircle::setGreen()
{
   mCurrentCircle = mGreenCircle;
   update();
}

void ColorfulCircle::setYellow()
{
   mCurrentCircle = mYellowCircle;
   update();
}

void ColorfulCircle::setRed()
{
   mCurrentCircle = mRedCircle;
   update();
}
