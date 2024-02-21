#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QFont>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    void uiComponents();
    void sendFunction();
    void removeFunction();
private:
    QLabel* m_title;
    QLineEdit* m_inputLine;
    QPushButton* m_sendButton;
    QListWidget* m_generalWidget;
    QPushButton* m_resicleButtton;
    QPushButton* currentRemoveButton;
    int trashStart;
    int trashEnd;
    int index = 0;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
