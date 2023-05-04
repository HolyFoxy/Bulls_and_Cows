#include "bulls_and_cows.h"


Bulls_and_Cows::Bulls_and_Cows(QWidget *parent) //400*500
    : QMainWindow(parent)
{

    setMinimumSize(width_, height_);
    setMaximumSize(width_, height_);

    //------------------------------------------------------------------------------
    //Создание кнопок
    start_b = new QPushButton("Start", this);
    start_b->setGeometry(0, 0, 75, 25);
    start_b->setObjectName("Start_b");

    check_b = new QPushButton("Check", this);
    check_b->setGeometry(325, 25, 75, 25);
    check_b->setObjectName("Check_b");
    check_b->setEnabled(false);

    records_b = new QPushButton("Records", this);
    records_b->setGeometry(80, 0, 75, 25);
    records_b->setObjectName("Records_b");

    //------------------------------------------------------------------------------
    //Создание текстового описания на окне игры
    text_on_window = new QLabel(this);
    text_on_window->setGeometry(160, 0, 200, 25);
    text_on_window->setText("Press start button...");

    text_for_p = new QLabel(this);
    text_for_p->setGeometry(250, 0, 200, 25);
    text_for_p->setText("");

    //------------------------------------------------------------------------------
    //Создание таблицы результатов
    table = new QTableWidget(0, 2, this);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QStringList list {"Number" , "Bulls and Cows"};
    table->setHorizontalHeaderLabels(list);
    table->setGeometry(0, 55, width_, height_);
    table->setEnabled(false);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //------------------------------------------------------------------------------
    //Создание поля ввода числа
    input_line = new QLineEdit(this);
    input_line->setValidator(new QIntValidator(this));
    input_line->setGeometry(0, 25, 320, 25);
    input_line->setObjectName("Input_line");
    input_line->setMaxLength(4);
    input_line->setEnabled(false);

    //------------------------------------------------------------------------------
    //Создание связей между компанентами программы
    QMetaObject::connectSlotsByName(this);
    r_window = new Records_window;
    connect(this, &Bulls_and_Cows::s_game_winned, this, &Bulls_and_Cows::game_winned);
    connect(this, &Bulls_and_Cows::s_save_score, r_window, &Records_window::save_score);
    connect(this, &Bulls_and_Cows::s_open_records_window, r_window, &Records_window::drow_score_table);
}

void Bulls_and_Cows::on_Start_b_clicked()
{
    int sec_num = 1000 + rand()%9000;
    secret = QString::number(sec_num);

    if (input_line->isEnabled() == false)
    {
        text_on_window->setText("Game is going...");
        text_for_p->setText("Input your num");
        input_line->setEnabled(true);
        check_b->setEnabled(true);
        table->setEnabled(true);
    }
    table->clearContents();
    table->setRowCount(0);
}

void Bulls_and_Cows::on_Check_b_clicked()
{
    if (input_line->text().size()==secret.size())
    {
        table->insertRow(table->rowCount());

        QTableWidgetItem* cell_1 = new QTableWidgetItem;
        QTableWidgetItem* cell_2 = new QTableWidgetItem;

        cell_1->setText(input_line->text());
        table->setItem(table->rowCount()-1, 0, cell_1);

        cell_2->setText(Check_num());
        table->setItem(table->rowCount()-1, 1, cell_2);
        if (input_line->text() == secret)
            emit s_game_winned();
        input_line->clear();
    }
    else
    {
        input_line->setText("");
        text_for_p->setText("Invalid num...");
        repaint();
        QThread::msleep(1500);
        text_for_p->setText("Input your num");
    }
}

void Bulls_and_Cows::on_Records_b_clicked()
{
    r_window->setWindowModality(Qt::ApplicationModal);
    emit s_open_records_window();
    r_window->show();
}

void Bulls_and_Cows::catch_name(QString name){
    text_on_window->setText("Press start button...");
    int score = table->rowCount();
    table->clearContents();    
    table->setRowCount(0);
    table->setEnabled(false);
    emit s_save_score(score, name);
}

void Bulls_and_Cows::game_winned()
{
    check_b->setEnabled(false);
    input_line->setEnabled(false);
    text_on_window->setText("You win");
    text_for_p->setText("Our congratulations!!!");

    //создать окно для ввода имени для рекорда
    i_window = new input_window;
    connect(i_window, &input_window::s_name_catched, this, &Bulls_and_Cows::catch_name);
    i_window->show();
}

QString Bulls_and_Cows::Check_num()
{
    QString answer;
    QString num;
    QString clone;

    int bulls = 0;
    int cows = 0;

    num = input_line->text();
    clone = secret;

    for (int i = 0; i < secret.size(); i++)
        if (clone[i] == num[i]) { bulls++; clone[i] = 'c'; }

    for (int i = 0; i < secret.size(); i++)
        for (int j = 0; j < secret.size(); j++)
            if (clone[j] == num[i]) { cows++; clone[j] = 'c'; break; }

    answer = "bulls: ";
    answer += QString::number(bulls);
    answer += ", cows: ";
    answer += QString::number(cows);
    return answer;
}

Bulls_and_Cows::~Bulls_and_Cows()
{
    delete(r_window);
    close();
}


