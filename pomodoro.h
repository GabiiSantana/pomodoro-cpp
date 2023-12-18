#ifndef POMODORO_H
#define POMODORO_H

#include <QMainWindow>
#include <QTimer>
#include <QInputDialog>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class pomodoro; }
QT_END_NAMESPACE

class pomodoro : public QMainWindow
{
    Q_OBJECT

public:
    pomodoro(QWidget *parent = nullptr);
    ~pomodoro();

private slots:
    void startPomodoro();
    void updateTimer();
    void adjustTimer();
    void pauseTimer();

protected:
    void mouseDoubleClickEvent(QMouseEvent *event) override;

private:
    Ui::pomodoro *ui;
    QTimer *timer;
    int remainingTime;
    bool isWorkingTime;
    bool isPaused;
    bool isAlternateSize;
};
#endif // POMODORO_H
