#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_title(new QLabel("To Do List"))
    , m_inputLine(new QLineEdit("Text..."))
    , m_generalWidget(new QListWidget(this))
{
    ui->setupUi(this);
    m_sendButton = new QPushButton(this);
    m_resicleButtton = new QPushButton(this);
    uiComponents();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::uiComponents()
{
    QWidget *centralWidget = new QWidget(this); // Create a central widget
    this->setCentralWidget(centralWidget); // Set it as the central widget of the main window

    // Create a vertical layout for the central widget
    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);

    this->setWindowTitle("To Do List");
    this->setFixedSize(600, 600);

    // Create and configure the title label
    m_title->setGeometry(250, 10, 100, 17);
    m_title->setStyleSheet("QLabel {"
                           "color: grey;"
                           "background-color: white;"
                           "font-size: 18px;"
                           "font-weight: bold;"
                           "border: 2px solid black;"
                           "}");

    m_inputLine->setGeometry(0, 30, 470, 25);
    m_inputLine->setStyleSheet("QLineEdit {"
                               "color: grey;"
                               "background-color: white;"
                               "font-size: 18px;"
                               "font-weight: bold;"
                               "border: 2px solid black;"
                               "}"
                               );

    m_sendButton->setGeometry(475, 30, 100, 25);
    m_sendButton->setStyleSheet("QPushButton {"
                                "color: grey;"
                                "background-color: white;"
                                "font-size: 18px;"
                                "font-weight: bold;"
                                "border: 2px solid black;"
                                "}");
    m_sendButton->setText("Send");

    m_generalWidget->setGeometry(0, 55, 575, 470);
    m_generalWidget->setStyleSheet("QListWidget {"
                                   "color: grey;"
                                   "background-color: white;"
                                   "font-size: 18px;"
                                   "font-weight: bold;"
                                   "border: 2px solid black;"
                                   "}");

    m_resicleButtton->setText("Remove");
    m_resicleButtton->setGeometry(475, 540, 100, 25);
    m_resicleButtton->setStyleSheet("QPushButton {"
                                    "color: grey;"
                                    "background-color: white;"
                                    "font-size: 18px;"
                                    "font-weight: bold;"
                                    "border: 2px solid black;"
                                    "}");

    // Add widgets to the layout
    mainLayout->addWidget(m_title);
    mainLayout->addWidget(m_inputLine);
    mainLayout->addWidget(m_sendButton);
    mainLayout->addWidget(m_generalWidget);
    mainLayout->addWidget(m_resicleButtton);

    // Set the layout for the central widget
    centralWidget->setLayout(mainLayout);

    connect(m_sendButton, &QPushButton::clicked, this, &MainWindow::sendFunction);
    connect(m_resicleButtton, &QPushButton::clicked, this, &MainWindow::removeFunction);
}

void MainWindow::sendFunction()
{
    QString item = ". " + m_inputLine->text();
    QListWidgetItem* newItem = new QListWidgetItem(item, m_generalWidget);
    m_generalWidget->addItem(newItem);
    newItem -> setFlags(newItem->flags() | Qt::ItemIsEditable);
    m_inputLine -> setText("Text...");

}

void MainWindow::removeFunction()
{
    QListWidgetItem* item = m_generalWidget->takeItem(m_generalWidget->currentRow());
    delete item;
}
