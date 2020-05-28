#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void digits_numbers();
    void on_pushButton_point_clicked();
    void operations();
    void on_pushButton_delete_clicked();
    void on_pushButton_equally_clicked();
    void math_functions();
};
#endif // MAINWINDOW_H
