#include "records_window.h"

Records_window::Records_window(QString file_name,QMainWindow*parent)
{
    setWindowTitle("Records");
    setMinimumSize(300, 300);
    setMaximumSize(300, 300);

    table = new QTableWidget(0, 2, this);
    table->move(0, 10);
    table->resize(this->width(), 300);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QStringList list {"Player", "attempts"};
    table->setHorizontalHeaderLabels(list);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    file.setFileName(file_name);
    check_records();

    QMetaObject::connectSlotsByName(this);
}

void Records_window::check_records(){
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream text_stream (&file);
    while (!text_stream.atEnd()){
        QString in_line = text_stream.readLine();
        records.push_back({in_line.split(' ').first().toInt(), in_line.split(' ').last()});
    }
    file.close();
}

void Records_window::drow_score_table(){
    if (records.size() == 0)
        check_records();
    if (table->rowCount()!= 0){
        table->clearContents();
        table->setRowCount(0);
    }
    for (int i = 0; i<records.size(); i++)
        if (i==10)
            break;
        else{
            table->insertRow(table->rowCount());

            QTableWidgetItem* cell_1 = new QTableWidgetItem;
            QTableWidgetItem* cell_2 = new QTableWidgetItem;

            cell_1->setText(records[i].second);
            cell_2->setText(QString::number(records[i].first));

            table->setItem(table->rowCount()-1, 0, cell_1);
            table->setItem(table->rowCount()-1, 1, cell_2);
        }
}

void Records_window::save_score(int score, QString name){
    int i;
    for (i = 0; i < records.size(); i++)
        if (score < records[i].first)
            break;
    records.insert(i, {score, name});
    file.open(QIODevice::WriteOnly | QIODevice::Truncate |  QIODevice::Text);
    QTextStream out_stream (&file);
    for(int k = 0; k < records.size(); k++)
        out_stream<<QString::number(records[k].first)<< ' ' <<records[k].second << '\n';
    file.close();
}


Records_window::~Records_window(){
    close();
}
