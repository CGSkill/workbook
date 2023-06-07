#include "mainwindow.h"
#include "ui_mainwindow.h"

#define WHO

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

#ifdef WHO
    // 方式一
    QQuickView *pView = new QQuickView();
    QWidget *pWidget = QWidget::createWindowContainer(pView, this);
    pView->setResizeMode(QQuickView::SizeRootObjectToView);
    pView->setSource(QUrl("qrc:/MyQML.qml"));
#else
    // 方式二
    QQuickWidget *pWidget = new QQuickWidget();
    pWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    pWidget->setSource(QUrl("qrc:/MyQML.qml"));

#endif

    m_pButton = new QPushButton(this);
    m_pButton->setText("Qt Widgets...");

    QVBoxLayout *pLayout = new QVBoxLayout();
    pLayout->addWidget(pWidget);
    pLayout->addWidget(m_pButton);
    pLayout->setSpacing(10);
    pLayout->setContentsMargins(10, 10, 10, 10);
    this->ui->widget->setLayout(pLayout);
    pLayout->setMargin(0);

    // QML 与 Qt Widgets 通信
#ifdef WHO
     QObject *pRoot = (QObject*)pView->rootObject();
#else
    QObject *pRoot = (QObject*)pWidget->rootObject();
#endif
    if (pRoot != NULL) {
        connect(pRoot, SIGNAL(qmlSignal()), this, SLOT(receiveFromQml()));
        connect(m_pButton, SIGNAL(clicked(bool)), pRoot, SIGNAL(cSignal()));
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receiveFromQml()
{
    static int i = 0;
    i ++;
    m_pButton->setText(QString("Call Slot %1 times").arg(i));
}

