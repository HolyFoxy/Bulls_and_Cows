#include "input_window.h"

input_window::input_window(QMainWindow *parent) : QWidget(parent)
{
    setWindowTitle("Congratulations!");
    setMinimumSize(300, 75);
    setMaximumSize(300, 75);
    QGridLayout* layout = new QGridLayout(this);
    //------------------------------------------------------
    apply_b = new QPushButton("Apply", this);
    layout->addWidget(apply_b, 1, 3, 1, 1);
    apply_b->setObjectName("Apply_b");

    //------------------------------------------------------
    input_line = new QLineEdit(this);
    layout->addWidget(input_line, 1, 0, 1, 3);
    input_line->setObjectName("Input_line");
    input_line->setText("");

    //------------------------------------------------------
    text_on_window = new QLabel(this);
    text_on_window->setText("Input your name. Your results will be saved");
    layout->addWidget(text_on_window, 0, 0, 1, 4);

    //------------------------------------------------------
    setWindowModality(Qt::ApplicationModal);
    setAttribute(Qt::WA_DeleteOnClose, true);
    QMetaObject::connectSlotsByName(this);
}

void input_window::on_Apply_b_clicked(){
    QString name;
    name = input_line->text();
    if((name!= "") && (name!= " ")){
        if (name[1].isLetterOrNumber()){
            emit s_name_catched(name);
            close();
        }
    }
    input_line->setText("");
}

input_window::~input_window()
{
    close();
}
