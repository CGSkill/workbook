#include "checkboxbuttonwidget.h"

CheckBoxButtonWidget::CheckBoxButtonWidget(QString str, QWidget *parent):
    QWidget(parent),
    m_Data(str)
{
    initUI();
    connected();
}

void CheckBoxButtonWidget::initUI()
{

    m_ChecKBox = new QCheckBox(this);
    m_ChecKBox->setCheckable(true);
    m_ChecKBox->setChecked(true);
    m_ChecKBox->setText(m_Data);

    m_PushButton = new QPushButton(this);
    m_PushButton->setText(QStringLiteral("预览"));
    m_PushButton->setToolTip(QStringLiteral("Clicked me"));
    m_PushButton->setCursor(QCursor(Qt::PointingHandCursor));

    m_MainLayout = new QHBoxLayout();
    m_MainLayout->setSpacing(0);

    m_MainLayout->addWidget(m_ChecKBox);
    m_MainLayout->addSpacing(3);
    m_MainLayout->addWidget(m_PushButton);
    m_MainLayout->addStretch();

    this->setLayout(m_MainLayout);
}

void CheckBoxButtonWidget::connected()
{
    connect(m_ChecKBox, &QCheckBox::stateChanged, this, &CheckBoxButtonWidget::sigCheckBoxStateChanged);
    connect(m_PushButton, &QPushButton::pressed, this, &CheckBoxButtonWidget::sigPushButtonClicked);
}
