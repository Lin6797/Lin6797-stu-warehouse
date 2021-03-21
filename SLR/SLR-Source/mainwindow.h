#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Sure_clicked();

    void on_getFButton_clicked();

    void on_ifExtend_clicked();

    void on_getLRButton_clicked();


    void on_beginInput_clicked();

    void on_ifSLR_clicked();

    void on_getSLR_clicked();

    void on_openButton_clicked();

    void on_Save_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
