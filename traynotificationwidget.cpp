#include "traynotificationwidget.h"

TrayNotificationWidget::TrayNotificationWidget(QPixmap pixmapIcon, QString headerText, QString messageText) : QWidget(0)
{
    setWindowFlags(
        #ifdef Q_OS_MAC
            Qt::SubWindow | // This type flag is the second point
        #else
            Qt::Tool |
        #endif
            Qt::FramelessWindowHint |
            Qt::WindowSystemMenuHint |
            Qt::WindowStaysOnTopHint
        );
    setAttribute(Qt::WA_NoSystemBackground, true);
    // set the parent widget's background to translucent
    setAttribute(Qt::WA_TranslucentBackground, true);

    //setAttribute(Qt::WA_ShowWithoutActivating, true);

    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    // create a display widget for displaying child widgets
    QWidget* displayWidget = new QWidget;
    displayWidget->setGeometry(0, 0, this->width(), this->height());
    displayWidget->setStyleSheet(".QWidget { background-color: rgba(255, 230, 128, 40%); border-width: 1px; border-style: solid; border-radius: 10px; border-color: rgba(255, 230, 128, 40%);} .QWidget:hover { background-color: rgba(68, 68, 68, 75%); border-width: 2px; border-style: solid; border-radius: 10px; border-color: #ffffff; }");

    QLabel* icon = new QLabel;
    icon->setPixmap(pixmapIcon);
    icon->setMaximumSize(32, 32);
    QLabel* header = new QLabel;
    header->setMaximumSize(300, 50);
    header->setWordWrap(true);
    header->setText(headerText);
    header->setStyleSheet("QLabel { color: #000000; font-weight: bold; font-size: 14px; }");
    QLabel* message = new QLabel;
    message->setMaximumSize(300, 100);
    message->setWordWrap(true);
    message->setText(messageText);
    message->setStyleSheet("QLabel { color: #000000; font-size: 12px; }");
    QHBoxLayout* displayMainLayout = new QHBoxLayout;
    displayMainLayout->addWidget(icon);
    QVBoxLayout* vl = new QVBoxLayout;
    vl->addWidget(header);
    vl->addWidget(message);
    displayMainLayout->addLayout(vl);
    displayWidget->setLayout(displayMainLayout);

    QHBoxLayout* containerLayout = new QHBoxLayout;
    containerLayout->addWidget(displayWidget);
    setLayout(containerLayout);

    show();

    timeout = new QTimer(this);
    connect(timeout, SIGNAL(timeout()), this, SLOT(fadeOut()));
    timeout->start(3000);
}

void TrayNotificationWidget::fadeOut()
{
    emit deleted(this);
    this->hide();
}

