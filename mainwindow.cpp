#include "mainwindow.h"
#include "ui_mainwindow.h"

sudoku::matrix matx;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_table_cellClicked(int row, int column)
{
    Row = row;
    Column = column;
    QString str = "";
    str += '0' + row;
    str += ',';
    str += '0' + column;
    const QString cstr = str;
    ui->label->setText(cstr);
}

void MainWindow::on_pb00_1_clicked()
{
    //extern sudoku::matrix mat;
    QTableWidgetItem* Cell = ui->table->item(Row, Column);
    matx.write(Row, Column, 1);
    Cell->setText("1");
}

void MainWindow::on_pb00_2_clicked()
{
    //extern sudoku::matrix mat;
    QTableWidgetItem* Cell = ui->table->item(Row, Column);
    matx.write(Row, Column, 2);
    Cell->setText("2");
}

void MainWindow::on_pb00_3_clicked()
{
    //extern sudoku::matrix mat;
    QTableWidgetItem* Cell = ui->table->item(Row, Column);
    matx.write(Row, Column, 3);
    Cell->setText("3");
}

void MainWindow::on_pb00_4_clicked()
{
    //extern sudoku::matrix mat;
    QTableWidgetItem* Cell = ui->table->item(Row, Column);
    matx.write(Row, Column, 4);
    Cell->setText("4");
}

void MainWindow::on_pb00_5_clicked()
{
    //extern sudoku::matrix mat;
    QTableWidgetItem* Cell = ui->table->item(Row, Column);
    matx.write(Row, Column, 5);
    Cell->setText("5");
}

void MainWindow::on_pb00_6_clicked()
{
    //extern sudoku::matrix mat;
    QTableWidgetItem* Cell = ui->table->item(Row, Column);
    matx.write(Row, Column, 6);
    Cell->setText("6");
}

void MainWindow::on_pb00_7_clicked()
{
    //extern sudoku::matrix mat;
    QTableWidgetItem* Cell = ui->table->item(Row, Column);
    matx.write(Row, Column, 7);
    Cell->setText("7");
}

void MainWindow::on_pb00_8_clicked()
{
    //extern sudoku::matrix mat;
    QTableWidgetItem* Cell = ui->table->item(Row, Column);
    matx.write(Row, Column, 8);
    Cell->setText("8");
}

void MainWindow::on_pb00_9_clicked()
{
    //extern sudoku::matrix mat;
    QTableWidgetItem* Cell = ui->table->item(Row, Column);
    matx.write(Row, Column, 9);
    Cell->setText("9");
}

void MainWindow::on_solve_clicked()
{
    matx.solve();
    for (int i = 0; i < 9; ++i)
	{
        for (int j = 0; j < 9; ++j)
		{
			QTableWidgetItem* Cell = ui->table->item(i, j);
			QString str = "";
            str += '0' + matx.read(i,j);
			const QString cstr = str;
			Cell->setText(cstr);
		}
	}
}

void MainWindow::on_actionNew_game_triggered()
{
    matx.empty();
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            QTableWidgetItem* Cell = ui->table->item(i, j);
            Cell->setText("0");
        }
    }
}
