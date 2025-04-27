#include "sound_button.h"


SoundButton::SoundButton(QWidget* parent)
{
    QString projectName = "38_1_cmake";
    QString pathMedia = "..\\" + projectName + "\\media\\";
    setParent(parent);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mButtonUp = QPixmap(pathMedia + "redBtnUp.png");
    mButtonDown = QPixmap(pathMedia + "redBtnDown.png");
    filePathSound = pathMedia + "click.mp3";
    mCurrentButton = mButtonUp;
    setGeometry(mCurrentButton.rect());
    player = new QMediaPlayer();
    player->setVolume(1000);
    player->setMedia(QUrl::fromLocalFile(filePathSound));
    QObject::connect (this, &QPushButton::clicked, this, &SoundButton::setDown);
}

void SoundButton::paintEvent(QPaintEvent* e)
{
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrentButton);
}

QSize SoundButton::sizeHint() const
{
    return QSize(100, 100);
}

QSize SoundButton::minimumSizeHint() const
{
    return sizeHint();
}

void SoundButton::setDown()
{
    player->stop();
    mCurrentButton = mButtonDown;
    player->play();
    update();
    QTimer::singleShot(200, this, &SoundButton::setUp);
}

void SoundButton::setUp()
{
    mCurrentButton = mButtonUp;
    update();
}
