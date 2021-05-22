#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPainter>
#include <QGridLayout>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {class MainWindow;
}
QT_END_NAMESPACE
class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    int col=0;
    int x=400;
    int y=200;
    bool ris=false;
    int mat[512][512];
    int first;
    int last;
    int rast=150;
    int h=360;
    QBrush front;
    QBrush back;
    QFont glFont;
    QPen textPen;
    ~MainWindow();
private:
    Ui::MainWindow *ui;
 protected:
    void paintEvent(QPaintEvent*) override;
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
};
#endif//
