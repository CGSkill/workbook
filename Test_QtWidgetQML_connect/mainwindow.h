#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QQuickWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QQuickView>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public  slots:
    void receiveFromQml();
private:
    Ui::MainWindow *ui;
    QPushButton *m_pButton;
};
#endif // MAINWINDOW_H
