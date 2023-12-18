# Pomodoro C++ (QT CREATOR)

### Instruções:
- Clique em "pomodoro.exe" para abrir o programa.
- O app fica acima de todos os outros, caso não queira, no pomodoro.cpp tire esse código: `this->setWindowFlags(flags | Qt::WindowStaysOnTopHint);`.
- Clique duas vezes no app para reajustar o tamanho da tela.
- O modo "descanso" virá automaticamente e não tem como ajustar, somente no código `if (!isWorkingTime) { remainingTime = 5 * 60; // Tempo de descanso de 5 minutos }`.
