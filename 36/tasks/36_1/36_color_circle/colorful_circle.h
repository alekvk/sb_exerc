#pragma once

#include <QPixmap>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>


class ColorfulCircle : public QWidget
{
    Q_OBJECT

public:
    ColorfulCircle() = default;
    ColorfulCircle(QWidget* parent);

    void paintEvent(QPaintEvent* e) override;
    QSize minimumSizeHint() const override;
    void setGreen();
    void setYellow();
    void setRed();

private:
    QPixmap mGreenCircle;
    QPixmap mYellowCircle;
    QPixmap mRedCircle;
    QPixmap  mCurrentCircle;
};
