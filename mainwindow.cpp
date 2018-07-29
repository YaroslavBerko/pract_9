#include "mainwindow.h"
#include "ui_mainwindow.h"

/*
 *  При створенні масиву player_choose заповнюється нулями.
 *  При виборі хрестика вводиться '1', а при виборі новика '-1'.
 */

void MainWindow::clear()
{
    number_of_moves = 0;
    for (int i=0; i < rows; ++i)
        player_choose[i].resize(rows);
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < rows; j++)
            player_choose[i][j] = 0;
    }
    ui->pushButton_1->setText(tr(""));
    ui->pushButton_2->setText(tr(""));
    ui->pushButton_3->setText(tr(""));
    ui->pushButton_4->setText(tr(""));
    ui->pushButton_5->setText(tr(""));
    ui->pushButton_6->setText(tr(""));
    ui->pushButton_7->setText(tr(""));
    ui->pushButton_8->setText(tr(""));
    ui->pushButton_9->setText(tr(""));
    ui->pushButton_1->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_7->setEnabled(true);
    ui->pushButton_8->setEnabled(true);
    ui->pushButton_9->setEnabled(true);

    ui->actionButton->setText(tr("Clear"));
}

void MainWindow::disablePushbutton()
{
    ui->pushButton_1->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);
    ui->pushButton_9->setEnabled(false);
}

char MainWindow::change_of_player()
{
    player_now *= (-1);
    if (player_now == 1){
        ui->player->setText(tr("Second player"));
        return 'X';
    }
    else{
        ui->player->setText(tr("First player"));
        return 'O';
    }
}

void MainWindow::clicked_1()
{
    ui->pushButton_1->setText(QString(change_of_player()));
    player_choose[1][1] = player_now;
    ui->pushButton_1->setEnabled(false);
    emit the_move_is_done(1, 1);
}

void MainWindow::clicked_2()
{
    ui->pushButton_2->setText(QString(change_of_player()));
    player_choose[1][2] = player_now;
    emit the_move_is_done(1, 2);
    ui->pushButton_2->setEnabled(false);
}

void MainWindow::clicked_3()
{
    ui->pushButton_3->setText(QString(change_of_player()));
    player_choose[1][3] = player_now;
    emit the_move_is_done(1, 3);
    ui->pushButton_3->setEnabled(false);
}

void MainWindow::clicked_4()
{
    ui->pushButton_4->setText(QString(change_of_player()));
    player_choose[2][1] = player_now;
    emit the_move_is_done(2, 1);
    ui->pushButton_4->setEnabled(false);
}

void MainWindow::clicked_5()
{
    ui->pushButton_5->setText(QString(change_of_player()));
    player_choose[2][2] = player_now;
    emit the_move_is_done(2, 2);
    ui->pushButton_5->setEnabled(false);
}

void MainWindow::clicked_6()
{
    ui->pushButton_6->setText(QString(change_of_player()));
    player_choose[2][3] = player_now;
    emit the_move_is_done(2, 3);
    ui->pushButton_6->setEnabled(false);
}

void MainWindow::clicked_7()
{
    ui->pushButton_7->setText(QString(change_of_player()));
    player_choose[3][1] = player_now;
    emit the_move_is_done(3, 1);
    ui->pushButton_7->setEnabled(false);
}

void MainWindow::clicked_8()
{
    ui->pushButton_8->setText(QString(change_of_player()));
    player_choose[3][2] = player_now;
    emit the_move_is_done(3, 2);
    ui->pushButton_8->setEnabled(false);
}

void MainWindow::clicked_9()
{
    ui->pushButton_9->setText(QString(change_of_player()));
    player_choose[3][3] = player_now;
    emit the_move_is_done(3, 3);
    ui->pushButton_9->setEnabled(false);
}

int MainWindow::test(int pos_x, int pos_y, int direction_x, int direction_y)
{
    if (player_choose[pos_x][pos_y] == player_choose[pos_x + direction_x][pos_y + direction_y])
        return (1 + test(pos_x + direction_x, pos_y + direction_y, direction_x, direction_y));
}

void MainWindow::test_on_winner(int pos_x, int pos_y)
{
    number_of_moves +=1;
    if (number_of_moves == 9){
        QMessageBox::information(this, tr(""), tr("Draw."));
        ui->actionButton->setText(tr("New game"));
    }
    int x_ = 1,
        y_ = 0,
        z = 0,
        direction_x = 0,
        direction_y = 0,
        x = pos_x - 1,
        y = pos_y - 1;
    for (int j=0; j<2; j++){
        z = x_;
        x_ = y_;
        y_ = z;
        for (int k=0; k<2; k++){
            x += x_;
            y += y_;
            direction_x = x - pos_x;
            direction_y = y - pos_y;
            if (test(pos_x, pos_y, direction_x, direction_y) +
                    test(pos_x, pos_y, direction_x * (-1), direction_y * (-1)) == 2){
                disablePushbutton();
                ui->actionButton->setText(tr("New game"));
                if (player_now == 1)
                    QMessageBox::information(this, tr(""), tr("First player win!!!"));
                else
                    QMessageBox::information(this, tr(""), tr("Second player win!!!"));
                }
        }
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->pushButton_1, SIGNAL(clicked(bool)), this, SLOT(clicked_1()));
    QObject::connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(clicked_2()));
    QObject::connect(ui->pushButton_3, SIGNAL(clicked(bool)), this, SLOT(clicked_3()));
    QObject::connect(ui->pushButton_4, SIGNAL(clicked(bool)), this, SLOT(clicked_4()));
    QObject::connect(ui->pushButton_5, SIGNAL(clicked(bool)), this, SLOT(clicked_5()));
    QObject::connect(ui->pushButton_6, SIGNAL(clicked(bool)), this, SLOT(clicked_6()));
    QObject::connect(ui->pushButton_7, SIGNAL(clicked(bool)), this, SLOT(clicked_7()));
    QObject::connect(ui->pushButton_8, SIGNAL(clicked(bool)), this, SLOT(clicked_8()));
    QObject::connect(ui->pushButton_9, SIGNAL(clicked(bool)), this, SLOT(clicked_9()));

    QObject::connect(this, SIGNAL(the_move_is_done(int, int)), this, SLOT(test_on_winner(int, int)));

    QObject::connect(ui->actionButton, SIGNAL(clicked(bool)), this, SLOT(clear()));

    rows = 5;
    player_now = -1;
    number_of_moves = 0;
    player_choose.resize(rows);
    for (int i=0; i < rows; ++i)
        player_choose[i].resize(rows);
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < rows; j++)
            player_choose[i][j] = 0;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
