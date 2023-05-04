#ifndef RECORDS_WINDOW_H
#define RECORDS_WINDOW_H

#include <QtWidgets>

class Records_window : public QWidget
{
    Q_OBJECT
public:
    Records_window(QString file_name = "C:/Users/Home/Documents/QT_projects/Bulls_and_Cows/Records.txt",
                   QMainWindow*parent = nullptr);
    ~Records_window();

public slots:
    //------------------------------------------------------------------------------
    //Функции отображения таблицы рекордов
    //------------------------------------------------------------------------------
    /**
     * @brief Функция отрисовки таблицы
     */
    void drow_score_table();

    /**
     * @brief Функция сохранения рекорда
     * @param int - число попыток, QString - имя игрока
     */
    void save_score(int score, QString name);

private slots:
    /**
     * @brief Функция загрузки рекордов из файла в вектор
     */
    void check_records();

signals:
    //------------------------------------------------------------------------------
    //Сигналы обработки рекорда
    //------------------------------------------------------------------------------
    /**
     * @brief Сигнал открытия окна
     */
    void s_open_records_window();

    /**
     * @brief Сигнал сохранения рекорда
     * @param int - число попыток, QString - имя игрока
     */
    void s_save_score(int, QString);

    /**
     * @brief Сигнал закрытия окна
     */
    void s_window_closing();

private:
    //------------------------------------------------------------------------------
    //Элементы окна и программы
    //------------------------------------------------------------------------------
    /**
     * @brief Таблица первых 10 рекордов
     */
    QTableWidget* table;

    /**
     * @brief Вектор-список всех рекордов игры
     */
    QVector<QPair<int, QString>> records;

    /**
     * @brief Файл для записи рекордов
     */
    QFile file;
};

#endif // RECORDS_WINDOW_H
