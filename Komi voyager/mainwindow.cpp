#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"
#include <QTableWidget>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   ui->setupUi(this);
    }

MainWindow::~MainWindow()
{
    // Подчищаем

    delete ui;
}
void MainWindow::on_pushButton_2_clicked()//Создание таблицы смежности
{
    if(((ui->textEdit->toPlainText()).toInt()<8)||(ui->textEdit->toPlainText()).toInt()>1)
    col=(ui->textEdit->toPlainText()).toInt();
    else
        col=2;

    ui->tableWidget_2->setRowCount(col);
    ui->tableWidget_2->setColumnCount(col);

    first=1;
    last=col;

    ui->textEdit_2->setText("1");
    ui->textEdit_3->setText(ui->textEdit->toPlainText());

    for(int i=0;i< ui->tableWidget_2->rowCount();i++)
        for(int j=0;j<ui->tableWidget_2->columnCount();j++)
        {QTableWidgetItem*item=ui->tableWidget_2->item(i,j);
            if(i==j){
            ui->tableWidget_2->setItem(i,j,new QTableWidgetItem("1000"));
            ui->tableWidget_2->item(i,j)->setBackground(QColor(170, 170, 255));

            }
            else{
                if(item==NULL){
                 ui->tableWidget_2->setItem(i,j,new QTableWidgetItem("100"));
                }
            }
        }
    }
void MainWindow::on_pushButton_3_clicked()//Прием первого элемента
{
    if((((ui->textEdit_2->toPlainText()).toInt()<=col)&&(ui->textEdit_2->toPlainText()).toInt()>1)){
        first=(ui->textEdit_2->toPlainText()).toInt();

    }
    else
        first=1;
    QString he;

    ui->textEdit_2->setText(he.setNum(first));

}
void MainWindow::on_pushButton_4_clicked()//Прием последнего элемента графа
{

    if((((ui->textEdit_3->toPlainText()).toInt()<col)&&(ui->textEdit_3->toPlainText()).toInt()>=1)){
        last=(ui->textEdit_3->toPlainText()).toInt();
    }
    else
        last=col;
    QString he;

    ui->textEdit_3->setText(he.setNum(last));
}
void MainWindow::on_pushButton_clicked()//Функция нахождения кратчайшего маршрута и его пути
{
    if((((ui->textEdit_3->toPlainText()).toInt()<col)&&(ui->textEdit_3->toPlainText()).toInt()>=1)){
        last=(ui->textEdit_3->toPlainText()).toInt();
    }
    else
        last=col;

    if((((ui->textEdit_2->toPlainText()).toInt()<=col)&&(ui->textEdit_2->toPlainText()).toInt()>1)){
        first=(ui->textEdit_2->toPlainText()).toInt();
    }
    else
        first=1;
    if(last==first){
        last=col;
        first=1;
        QString sq = QString::number(last);
        ui->textEdit_2->setText("1");
        ui->textEdit_3->setText(sq);
    }
    int way[120];
       long int var = 0;
       long int min = 10000;
       long int min_way;

    for(int i=0;i< ui->tableWidget_2->rowCount();i++)
        for(int j=0;j<ui->tableWidget_2->columnCount();j++){
            int h=(ui->tableWidget_2->item(i,j)->text()).toInt();
            if((h<=0)||(h>=1000)){
                mat[i][j]=1000;
            }
            if((h>0)||(h<1000)){
                mat[i][j]=h;
            }
        }

               first--;
               last--;
               switch (col) {
               case 3:

                       for (int i2 = 0; i2 < col; i2++) {


                           if ((first != i2) && (first != last) &&
                               (i2 != last)
                               ) {
                               way[var] = ((first + 1) * 10 + (i2 + 1)) * 10 + last + 1;
                               //cout << way[var] << endl;

                               if (mat[first][i2] + mat[i2][last] < min) {
                                   min = mat[first][i2] + mat[i2][last] ;
                                   min_way = way[var];
                               }
                               var++;
                           }
                       }

               case 4:
                   for (int i2 = 0; i2 <col; i2++) {
                       for (int i3 = 0; i3 <col; i3++) {

                           if ((first != i2) && (first != i3) && (first != last) &&
                               (i2 != i3) && (i2 != last) &
                               (i3 != last)) {
                               way[var] = ((((first + 1) * 10 + (i2 + 1)) * 10 + (i3 + 1)) * 10) + last + 1;
                               //cout << way[var] << endl;

                               if (mat[first][i2] + mat[i2][i3] + mat[i3][last] < min) {
                                   min = mat[first][i2] + mat[i2][i3] + mat[i3][last];
                                   min_way = way[var];
                               }
                               var++;
                           }
                       }
                   }
                  // cout << "Min way= " << min_way << "  Milles: " << min;
               case 5:
                   for (int i2 = 0; i2 < col; i2++) {
                       for (int i3 = 0; i3 < col; i3++) {
                           for (int i4 = 0; i4 < col; i4++) {
                               if ((first != i2) && (first != i3) && (first != i4) && (first != last) &&
                                   (i2 != i4) && (i2 != i3) && (i2 != last) &&
                                   (i3 != i4) && (i3 != last) &&
                                   (i4 != last)) {
                                   way[var] = (((((first + 1) * 10 + (i2 + 1)) * 10 + (i3 + 1)) * 10) + (i4 + 1)) * 10 + last + 1;
                                   //cout << way[var] << endl;

                                   if (mat[first][i2] + mat[i2][i3] + mat[i3][i4] + mat[i4][last] < min) {
                                       min = mat[first][i2] + mat[i2][i3] + mat[i3][i4] + mat[i4][last];
                                       min_way = way[var];
                                   }
                                   var++;
                               }
                           }
                       }
                   }
                 //  cout << "Min way= " << min_way << "  Milles: " << min;


               case 6:
                   for (int i2 = 0; i2 < col; i2++) {
                       for (int i3 = 0; i3 <col; i3++) {
                           for (int i4 = 0; i4 < col; i4++) {
                               for (int i5 = 0; i5 < col; i5++) {
                                   if ((first != i2) && (first != i3) && (first != i4) && (first != i5) && (first != last) &&
                                       (i2 != i4) && (i2 != i3) && (i2 != i5) && (i2 != last) &&
                                       (i3 != i4) && (i3 != last) && (i3 != i5) &&
                                       (i4 != last) && (i4 != i5)
                                       && (i5 != last)) {
                                       way[var] = ((((((first + 1) * 10 + (i2 + 1)) * 10 + (i3 + 1)) * 10) + (i4 + 1)) * 10 + (i5 + 1)) * 10 + last + 1;
                                       //cout << way[var] << endl;

                                       if (mat[first][i2] + mat[i2][i3] + mat[i3][i4] + mat[i4][i5] + mat[i5][last] < min) {
                                           min = mat[first][i2] + mat[i2][i3] + mat[i3][i4] + mat[i4][i5] + mat[i5][last];
                                           min_way = way[var];
                                       }
                                       var++;
                                   }
                               }
                           }
                       }
                   }
                   //cout << "Min way= " << min_way << "  Milles: " << min;
               case 7:
                   for (int i2 = 0; i2 < col; i2++) {
                       for (int i3 = 0; i3 < col; i3++) {
                           for (int i4 = 0; i4 < col; i4++) {
                               for (int i5 = 0; i5 < col; i5++) {
                                   for (int i6 = 0; i6 < col; i6++) {
                                       if ((first != i2) && (first != i3) && (first != i4) && (first != i5) && (first != last) && (first != i6) &&
                                           (i2 != i4) && (i2 != i3) && (i2 != i5) && (i2 != last) && (i2 != i6) &&
                                           (i3 != i4) && (i3 != last) && (i3 != i5) && (i3 != i6) &&
                                           (i4 != last) && (i4 != i5) && (i4 != i6)
                                           && (i5 != last) && (i5 != i6)
                                           && (i6 != last)) {
                                           way[var] = (((((((first + 1) * 10 + (i2 + 1)) * 10 + (i3 + 1)) * 10) + (i4 + 1)) * 10 + (i5 + 1)) * 10 + (i6 + 1)) * 10 + last + 1;
                                           //cout << way[var] << endl;

                                           if (mat[first][i2] + mat[i2][i3] + mat[i3][i4] + mat[i4][i5] + mat[i5][i6] + mat[i6][last] < min) {
                                               min = mat[first][i2] + mat[i2][i3] + mat[i3][i4] + mat[i4][i5] + mat[i6][last] + mat[i5][i6];
                                               min_way = way[var];
                                           }
                                           var++;
                                       }
                                   }
                               }
                           }
                       }
                   }


                   }


    QString s = QString::number(min_way);
     QString st = QString::number(min);

    ui->label->setText(s);
    ui->label_2->setText(st);

    ris=true;


}



void MainWindow::paintEvent(QPaintEvent*)//Визуализация графа
{
    if(ris==true){
        QPainter painter;
            painter.begin(this);
        int len=col;        //кол-во узлов в графе
        int R=300;        //радиус графа
        int r=40;         //радиус узла
        double pi=3.1415;
        int HeightText=30;
        int xa=1000;       //отступ от вертикали
        int ya=600;       //отступ от горизонтали
        //ouble angle=pi/8;//угол раствора стрелки
        //int ls=30;        //длина кончика стрелки
        int disp=60;      //разброс подписей ребер
       front=QBrush(QColor(127,255,212));
       back=QBrush(QColor(200,200,200));
        textPen=QPen(QColor(33,33,33));
        //painter.fillRect(event->rect(),back);
        painter.setBrush(front);
        painter.setPen(textPen);
        painter.setFont(glFont);
        textPen.setWidth(4);

        for (int i=0;i<col;i++)
        {
            double a=pi*3/2+pi*2/col*i; //угол в полярных координатах (узел)
            int xc=cos(a)*R+xa;         //декартовы координата узла
            int yc=sin(a)*R+ya;
            int c1=xc-20;               //координаты текста
            int c2=yc-HeightText/2;
            int c3=40;
            int c4=HeightText;
           int  mat1[256][256];
            QString text; text.setNum(i+1);
            painter.drawEllipse(QRectF(xc-r,yc-r,2*r,2*r));
            painter.drawText(QRect(c1,c2,c3,c4),Qt::AlignCenter,text);
            for (int k=0;k<col;k++)
            {
                if(i!=k){
                    mat1[i][k]=mat[i][k];
                    if(mat1[i][k]!=mat1[k][i]){
                    //линия
                    double a2=pi*3/2+pi*2/col*k;
                    double xc2=cos(a2)*R+xa;
                    double yc2=sin(a2)*R+ya;
                    double l=sqrt((xc2-xc)*(xc2-xc)+(yc2-yc)*(yc2-yc));
                    int xl1=(xc2-xc)/l*r+xc;
                    int yl1=(yc2-yc)/l*r+yc;
                    int xl2=xc2-(xc2-xc)/l*r;
                    int yl2=yc2-(yc2-yc)/l*r;
                    painter.drawLine(xl1,yl1,xl2,yl2);
                    //текст
                    c1=(xl2+xl1)/2-20+qrand()%disp-disp/2;
                    c2=(yl2+yl1)/2-HeightText/2+qrand()%disp-disp/2;
                    c3=40;
                    c4=HeightText;
                    text.setNum(mat[i][k]);
                    painter.drawText(QRect(c1,c2,c3,c4),Qt::AlignCenter,text);
                    }
                }
            }
        }
    }
 }










