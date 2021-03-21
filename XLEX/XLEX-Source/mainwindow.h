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
    void on_file_Button_clicked();

    void on_sure_Button_clicked();

    void on_toNFA_Button_clicked();

    void on_toDFA_Button_clicked();

    void on_miniDFA_button_clicked();

    void on_toText_Button_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
