#ifndef CHECKBOXBUTTONWIDGET_H
#define CHECKBOXBUTTONWIDGET_H

#include <QObject>
#include <QWidget>
#include <QListWidgetItem>
#include <QCheckBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QString>

class CheckBoxButtonWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CheckBoxButtonWidget(QString str, QWidget *parent = nullptr);

private:
    void initUI();

    void connected();

signals:
    void sigCheckBoxStateChanged(int state);
    void sigPushButtonClicked();

public slots:

private:
    QCheckBox * m_ChecKBox = nullptr;
    QPushButton *m_PushButton = nullptr;

    QHBoxLayout *m_MainLayout = nullptr;

    QString m_Data;
};

#endif // CHECKBOXBUTTONWIDGET_H
