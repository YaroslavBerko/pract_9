#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private: // variables
    int rows;
    int player_now;
    int number_of_moves;
    std::vector<std::vector<int>> player_choose;

private: // function
    char change_of_player(); // зміна гравців
    int test(int pos_x, int pos_y, int direction_x, int direction_y); // pos_x, pos_y - координати задіяного поля, клітинки
                                                                      // direction_x, direction_y - напрямок зміщення
    void disablePushbutton();

private slots:
    void clicked_1();
    void clicked_2();
    void clicked_3();
    void clicked_4();
    void clicked_5();
    void clicked_6();
    void clicked_7();
    void clicked_8();
    void clicked_9();

    void test_on_winner(int pos_x, int pos_y);

    void clear();
signals:
    void the_move_is_done(int pos_x, int pos_y);
};

#endif // MAINWINDOW_H
