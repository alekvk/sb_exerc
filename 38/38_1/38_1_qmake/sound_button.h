#ifndef SOUND_BUTTON_H
#define SOUND_BUTTON_H

#include <QPushButton>
#include <QPaintEvent>
#include <QApplication>
#include <QPixmap>
#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QMediaPlayer>
#include <QMediaContent>


class SoundButton : public QPushButton
{
    Q_OBJECT
public:
    SoundButton() = default;
    SoundButton (QWidget* parent);

    ~SoundButton();

    void paintEvent(QPaintEvent* e) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;


public slots:
    void setUp();
    void setDown();

private:
    QPixmap mCurrentButton;
    QPixmap mButtonDown;
    QPixmap mButtonUp;
    QMediaPlayer* player;
    QString filePathSound;
};

#endif // SOUND_BUTTON_H
