#include "mainwindow.h"
#include "ui_mainwindow.h"

double number_1;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_plusminus,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_percent,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_functions()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(math_functions()));
    connect(ui->pushButton_multiply,SIGNAL(clicked()),this,SLOT(math_functions()));
    connect(ui->pushButton_share,SIGNAL(clicked()),this,SLOT(math_functions()));

    ui->pushButton_plus->setChecked(true);
    ui->pushButton_minus->setChecked(true);
    ui->pushButton_multiply->setChecked(true);
    ui->pushButton_share->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_point_clicked()
{
    if(!(ui->label->text().contains('.')))
        ui->label->setText(ui->label->text() + ".");
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();

    double numbers;
    QString new_label;
    numbers = (ui->label->text()+button->text()).toDouble();
    new_label = QString::number(numbers, 'g', 15);

    ui->label->setText(new_label);
}

void MainWindow::operations()
{
    QPushButton *button = (QPushButton *)sender();

    double numbers;
    QString new_label;

    if(button->text() == "+/-")
    {
        numbers = (ui->label->text()).toDouble();
        numbers = numbers*(-1);
        new_label = QString::number(numbers, 'g', 15);
    }
    else if(button->text() == "%")
    {
        numbers = (ui->label->text()).toDouble();
        numbers = numbers*0.01;
        new_label = QString::number(numbers, 'g', 15);
    }

    ui->label->setText(new_label);
}

void MainWindow::on_pushButton_delete_clicked()
{

}

void MainWindow::on_pushButton_equally_clicked()
{
    double label_Number, number_2;
    QString new_label;

    number_2 = ui->label->text().toDouble();

    if(ui->pushButton_plus->isChecked())
    {
        label_Number = number_1 + number_2;
        new_label = QString::number(label_Number, 'g', 15);
        ui->label->setText(new_label);
        ui->pushButton_minus->setChecked(false);
    }
    else if(ui->pushButton_minus->isChecked())
    {
        label_Number = number_1 - number_2;
        new_label = QString::number(label_Number, 'g', 15);
        ui->label->setText(new_label);
        ui->pushButton_minus->setChecked(false);
    }
    else if(ui->pushButton_share->isChecked())
    {
        if(number_2 == 0)
        {
            ui->label->setText("ERROR");
        }
        else
        {
        label_Number = number_1 / number_2;
        new_label = QString::number(label_Number, 'g', 15);
        ui->label->setText(new_label);
        }
        ui->pushButton_share->setChecked(false);
    }
    else if(ui->pushButton_multiply->isChecked())
    {
        label_Number = number_1 * number_2;
        new_label = QString::number(label_Number, 'g', 15);
        ui->label->setText(new_label);
        ui->pushButton_multiply->setChecked(false);
    }
}

void MainWindow::math_functions()
{
    QPushButton *button = (QPushButton *)sender();

    number_1 = ui->label->text().toDouble();
    ui->label->setText("");
    button->setChecked(true);
}
