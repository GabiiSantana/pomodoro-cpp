#include "pomodoro.h"
#include "ui_pomodoro.h"

pomodoro::pomodoro(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::pomodoro)
{
    ui->setupUi(this);

    Qt::WindowFlags flags = this->windowFlags();
    this->setWindowFlags(flags | Qt::WindowStaysOnTopHint); // Deixar o app no topo (fixado)
    isAlternateSize = false;
    timer = new QTimer(this);
    remainingTime = 50 * 60; // Defina o tempo inicial como 50 minutos (50 minutos * 60 segundos)

    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(startPomodoro()));
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimer()));
    connect(ui->adjustTimeButton, SIGNAL(clicked()), this, SLOT(adjustTimer()));
    connect(ui->pauseButton, SIGNAL(clicked()), this, SLOT(pauseTimer()));
}

pomodoro::~pomodoro()
{
    delete ui;
}

void pomodoro::startPomodoro() {
    if (!timer->isActive()) {
        timer->start(1000); // Iniciar o temporizador a cada segundo
        this->setFixedSize(360, 135);
    }
}

void pomodoro::updateTimer() {
    remainingTime--; // Decrementar o tempo restante
    int hours = remainingTime / 3600;
    int minutes = (remainingTime % 3600) / 60;
    int seconds = remainingTime % 60;

    // Exibir o tempo restante no QLabel (supondo que você tem um QLabel no seu formulário)
    QString displayTime = QString("%1:%2:%3")
                              .arg(hours, 2, 10, QChar('0'))
                              .arg(minutes, 2, 10, QChar('0'))
                              .arg(seconds, 2, 10, QChar('0'));

    ui->timerLabel->setText(displayTime);

    if (remainingTime <= 0) {
        timer->stop(); // Parar o temporizador quando o tempo acabar

        if (!isWorkingTime) {
            remainingTime = 5 * 60; // Tempo de descanso de 5 minutos
            isWorkingTime = false;
        } else {
            remainingTime = 25 * 60; // Tempo de trabalho de 25 minutos
            isWorkingTime = true;
        }

        if (!isPaused) {
            // Iniciar o temporizador novamente para o próximo intervalo
            timer->start();
        }

        // Atualizar a exibição do tempo com o novo intervalo
        int newDisplayHours = remainingTime / 3600;
        int newDisplayMinutes = (remainingTime % 3600) / 60;
        int newDisplaySeconds = remainingTime % 60;

        QString newDisplayTime = QString("%1:%2:%3")
                                     .arg(newDisplayHours, 2, 10, QChar('0'))
                                     .arg(newDisplayMinutes, 2, 10, QChar('0'))
                                     .arg(newDisplaySeconds, 2, 10, QChar('0'));

        ui->timerLabel->setText(newDisplayTime);
    }

    ui->timerLabel->setText(displayTime);
    ui->timerLabel->setAlignment(Qt::AlignCenter);
    timer->start(); // Iniciar o temporizador novamente para o próximo intervalo

}

void pomodoro::adjustTimer() {
    bool ok;
    // Diálogo para ajustar horas, minutos e segundos
    int hours, minutes, seconds;

    // Exemplo de diálogo de entrada para alterar o tempo (você pode substituir isso pelo método que preferir)
    hours = QInputDialog::getInt(this, tr("Ajustar Tempo"),
                                 tr("Digite as horas:"),
                                 0, 0, 9999, 1, &ok);
    if (!ok) return;

    minutes = QInputDialog::getInt(this, tr("Ajustar Tempo"),
                                   tr("Digite os minutos:"),
                                   0, 0, 59, 1, &ok);
    if (!ok) return;

    seconds = QInputDialog::getInt(this, tr("Ajustar Tempo"),
                                   tr("Digite os segundos:"),
                                   0, 0, 59, 1, &ok);
    if (!ok) return;

    // Converter horas, minutos e segundos para o tempo total em segundos
    int newTimeInSeconds = hours * 3600 + minutes * 60 + seconds;

    // Definir o novo tempo do temporizador
    remainingTime = newTimeInSeconds;

    // Atualizar o visor com o novo tempo
    int displayHours = remainingTime / 3600;
    int displayMinutes = (remainingTime % 3600) / 60;
    int displaySeconds = remainingTime % 60;

    QString displayTime = QString("%1:%2:%3")
                              .arg(displayHours, 2, 10, QChar('0'))
                              .arg(displayMinutes, 2, 10, QChar('0'))
                              .arg(displaySeconds, 2, 10, QChar('0'));

    ui->timerLabel->setText(displayTime);
}

void pomodoro::pauseTimer() {
    if (timer->isActive()) {
        timer->stop(); // Pausa o QTimer
        isPaused = true;

        // Alterar a cor dos números do contador para vermelho
        ui->timerLabel->setStyleSheet("color: red;");

        // Alterar o texto do botão para "Retomar"
        ui->pauseButton->setText("RETOMAR");
    } else {
        timer->start(1000); // Se estiver pausado, retoma o QTimer
        isPaused = false;

        // Restaurar a cor padrão dos números do contador
        ui->timerLabel->setStyleSheet(""); // Ou defina para a cor desejada

        // Restaurar o texto do botão para "Pausar"
        ui->pauseButton->setText("PAUSAR");
    }
}

void pomodoro::mouseDoubleClickEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        if (!isAlternateSize) {
            this->setFixedSize(360, 180); // Altere para o tamanho maior desejado
            isAlternateSize = true; // Atualize o estado para indicar tamanho alternativo
        } else {
            this->setFixedSize(360, 135); // Altere para o tamanho menor desejado
            isAlternateSize = false; // Atualize o estado para indicar tamanho normal
        }
    }
}

