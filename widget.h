#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSound>

#include <QPaintEvent>
#include <QTimerEvent>
#include <QKeyEvent>
#include <QMouseEvent>

#include <QStringList>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    int screen_w;
    int screen_h;

    int timerID;
    int msec;

    int score;
    int lives;
    int delay;
    int gotIt;

    int sideState;
    int canState;
    int chiefState;
    int dendyState;

    int buttonState;

    bool sound;
    int soundDelay;

    int dendyDelay;

    int keysDelay;
    bool keysAvailable;

    bool sfxDirAndFilesAvailable;
    bool gfxDirAndFilesAvailable;

    QString dirName;

    QChar keys[4];
    QString strPause;
    QString strPressKey;
    QString strGameOver;
    QString strWindowTitle;

    QStringList gfxFiles;
    QStringList sfxFiles;

    enum gameState { // 0 - Main Screen, 1 - Game, 2 - Won, 3 - Game Over, 4 - Pause
        MainScreen,
        TheGame,
        TheWon,
        GameOver,
        Pause
    };

    int currentGameState;

    QSound *s_got;
    QSound *s_move;
    QSound *s_start;
    QSound *s_miss;
    QSound *s_gameOver;
    QSound *s_Win;

    QPixmap *pixSurface;

    QPixmap pixBackground;
    QPixmap pixChair;
    QPixmap pixWonScreen;

    QPixmap pixCans[8]; // 0-3 - leftside, 4-7 - rightside
    QPixmap pixChiefs[4];
    QPixmap pixBroken[2];
    QPixmap pixDigits[10];
    QPixmap pixDendy[2];
    QPixmap pixButtons[7];

    QPoint chiefCoords[4];
    QPoint chairCoords[3];
    QPoint cansCoords[4][4];
    QPoint hintsCoords[7];
    QPoint brokenCoords[2];
    QPoint digitCoords[4];
    QPoint dendyCoords[2];
    QPoint buttonCoords[7];

    QRect mouseCoords[7];

    int levels[7];

private:
    bool checkAllGfxRes();
    QStringList getAllGfxFiles() const;
    QStringList updateGfxListFiles(const QString &dirName);
    void loadAllGfx();

    bool checkAllSfxRes();
    QStringList getAllSfxFiles() const;
    void loadAllSfx();

    void initAll();

    void initCansCoords();
    void initChairCoords();
    void initChiefCoords();
    void initBrokenCoords();
    void initDigitCoords();
    void initDendyCoords();
    void initButtonsCoords();

    void initMouseCoords();
    void updateMouserCoords();
    int getScaleLevel() const;

    void initLevels();

    void initHintsCoords();

    void initStrings();

    void refreshDelay();
    void resetAllVariables();

    void drawGameFrame();
    void drawChairBar(QPainter &painter);

    void drawAll(QPainter &painter);
    void drawKeyHints(QPainter &painter);
    void drawGameText(const QString &aStr, QPainter &painter);
    void drawButtons(QPainter &painter);

#ifdef _DEBUG
    void drawRectangles(QPainter &painter);
#endif

    void drawDigitPairs(int number, int pair, QPainter &painter);

    void pauseGame(bool aPause);

    void stopAllSfx();

    QPixmap getCanPixmap() const;
    QPoint getCanCoords() const;

signals:
    void disableSound();

protected slots:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

protected slots:
    void slotEnableSound(bool aSound);
    void slotStartNewGame();
    void slotReset();
    void slotSetPixmapSize(int w, int h);
};

#endif // WIDGET_H
