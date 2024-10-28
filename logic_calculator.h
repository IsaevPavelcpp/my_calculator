//
// Created by Павел on 02.07.2024.
//

#ifndef LOGIC_CALCULATOR_H
#define LOGIC_CALCULATOR_H
#include <QMainWindow>
#include <QtWidgets/QLineEdit>
#include <string>
#include <vector>;
class Decision;
class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    QLineEdit* lineEdit = nullptr;
   explicit  Calculator(QWidget* parent = nullptr) : QMainWindow(parent){}
public slots:
    void add0(){lineEdit->setText(lineEdit->text()+"0");};
    void add1(){lineEdit->setText(lineEdit->text()+"1");};
    void add2(){lineEdit->setText(lineEdit->text()+"2");};
    void add3(){lineEdit->setText(lineEdit->text()+"3");};
    void add4(){lineEdit->setText(lineEdit->text()+"4");};
    void add5(){lineEdit->setText(lineEdit->text()+"5");};
    void add6(){lineEdit->setText(lineEdit->text()+"6");};
    void add7(){lineEdit->setText(lineEdit->text()+"7");};
    void add8(){lineEdit->setText(lineEdit->text()+"8");};
    void add9(){lineEdit->setText(lineEdit->text()+"9");};
    void addC()
    {
        sign = false;
        fract = false;
        x = 0;
        y = 0;
        lineEdit->setText("");
    }
    void addperc()
    {
        x = lineEdit->text().toDouble();
        lineEdit->setText(lineEdit->text().number(x/100));
    };
    void addplus()
    {
        move = "+";
        x = lineEdit->text().toDouble();
        lineEdit->setText("");
        fract = false;
        sign = false;
    };
    void addmin()
    {
        move = "-";
        x = lineEdit->text().toDouble();
        lineEdit->setText("");
        fract = false;
        sign = false;
    };
    void addshare()
    {
        move = "/";
        x = lineEdit->text().toDouble();
        lineEdit->setText("");
        fract = false;
        sign = false;
    };
    void addmultiply()
    {
        move = "*";
        x = lineEdit->text().toDouble();
        lineEdit->setText("");
        fract = false;
    };
    void addsign()
    {
        if(lineEdit->text() != "")
        {
            x = lineEdit->text().toDouble();
            x *= -1;
            lineEdit->setText(lineEdit->text().number(x));
        }
        else
        {
            lineEdit->setText("-");
        }

        if(!sign)
        {
            sign = true;
        }else
        {
            sign = false;
        }

    };
    void addcomma()
    {
        if(!fract)
        {
            lineEdit->setText(lineEdit->text()+".");
            fract =  true;
        }
        else
        {
            QString buf = lineEdit->text();
            buf.chop(1);
            lineEdit->setText(buf);
            fract = false;
        }
    } ;
    void addequally()
    {
        y = lineEdit->text().toDouble();
        if(move == "+")
        {
            x += y;
        }
        else if(move == "-")
        {
            x-= y;
        }
        else if(move == "/")
        {
            x /= y;
        }
        else if(move == "*")
        {
            x *= y;
        }
        lineEdit->setText("");
        lineEdit->setText(lineEdit->text().number(x));
    };
private:
double x = 0;
double y = 0;
std::string move = "uncnown";
bool sign = false;
bool fract = false;
};



#endif //LOGIC_CALCULATOR_H
