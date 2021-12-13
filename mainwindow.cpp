#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    client = new VK("token");
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(updateMessages()));

    movie = new QMovie(QCoreApplication::applicationDirPath() + "/" + "loading.gif");
    movie->setScaledSize(QSize(32, 32));
    ui->label->setMovie(movie);
    movie->start();
    ui->label->hide();
}

void MainWindow::updateMessages()
{
    ui->label->show();

    QVector<Message> msges = client->getVectorMessages("unread");
    ui->listWidget->clear();
    for(qint32 i = 0; i < msges.size(); i++) {
        QListWidgetItem* listItem = new QListWidgetItem("User: " + msges[i].from_user.first_name + " " + msges[i].from_user.last_name + "\nMessage: " +msges[i].text);
        ui->listWidget->addItem(listItem);
    }

    ui->label->hide();
    qDebug() << "updateMessages";
}

MainWindow::~MainWindow()
{
    delete ui;
}

