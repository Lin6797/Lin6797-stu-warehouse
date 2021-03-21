#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "vector"
#include <QMainWindow>

using namespace std;

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
    void on_gettree_button_clicked();

    void on_showtree_button_clicked();

    void on_getfile_button_clicked();

    void on_save_button_clicked();

private:
    Ui::MainWindow *ui;
    vector<string> ERROR_MSG;
    string Tree;
};

#endif // MAINWINDOW_H
