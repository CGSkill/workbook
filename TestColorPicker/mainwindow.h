#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWindow>
#include <QEvent>
#include <QMouseEvent>
#include <QScreen>
#include <QDesktopWidget>
#include <QPixmap>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//void getMousePosition(int *mouseX,int *mouseY);
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showColorValue(int x, int y);
public slots:
     void showColor();
protected:
    void mouseMoveEvent(QMouseEvent *ev) override;
    void mousePressEvent(QMouseEvent *ev) override;

private:
    Ui::MainWindow *ui;
    QTimer *time;
};
#endif // MAINWINDOW_H
