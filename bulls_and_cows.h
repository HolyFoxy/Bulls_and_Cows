#ifndef BULLS_AND_COWS_H
#define BULLS_AND_COWS_H

#include <QMainWindow>
#include <QtWidgets>
#include "input_window.h"
#include "records_window.h"

class Bulls_and_Cows : public QMainWindow
{
    Q_OBJECT

public:
    Bulls_and_Cows(QWidget *parent = nullptr);
    ~Bulls_and_Cows();

private slots:
    //------------------------------------------------------------------------------
    // Методы кнопок
    //------------------------------------------------------------------------------
    /**
     * @brief Функция нажатия на клавишу новой игры.
     * Запускает игру или начинает ее по новой
     */
    void on_Start_b_clicked();

    /**
     * @brief Функция нажатия на клавишу проверки числа.
     * Вызывает функцию проверки числа на совпадение с загаданным.
     * В случае победы вызывает функцию, обрабатывающую победу
     */
    void on_Check_b_clicked();

    /**
     * @brief Функция нажатия на клавишу рекордов.
     * Вызывает окно рекордов
     */
    void on_Records_b_clicked();

    /**
     * @brief Функция проверки числа на совпадение с загаданным
     */
    QString Check_num();

    //------------------------------------------------------------------------------
    // Функции обработки сигналов
    //------------------------------------------------------------------------------
    /**
     * @brief Функция обработки победы
     */
    void game_winned();

    /**
     * @brief Функция обработки полученного имени
     */
    void catch_name(QString);

signals:
    /**
     * @brief Сигнал победы
     */
    void s_game_winned();

    /**
     * @brief Сигнал полученного имени
     * @param QString - имя игрока
     */
    void s_name_catched(QString);

    /**
     * @brief Сигнал сохранения рекорда
     * @param int - число попыток, QString - имя игрока
     */
    void s_save_score(int, QString);

    /**
     * @brief Сигнал открытия окна рекордов
     */
    void s_open_records_window();

private:
    //------------------------------------------------------------------------------
    //Вторичные окна
    //------------------------------------------------------------------------------
    /**
     * @brief Окно рекордов
     */
    Records_window* r_window;

    /**
     * @brief Окно получения имени
     */
    input_window* i_window;

    //------------------------------------------------------------------------------
    //Элементы окна и программы
    //------------------------------------------------------------------------------
    /**
     * @brief Таблица игры
     */
    QTableWidget *table;

    /**
     * @brief Клавиша начала игры
     */
    QPushButton *start_b;

    /**
     * @brief Клавиша вызова окна рекордов
     */
    QPushButton *records_b;

    /**
     * @brief Клавиша проверки числа
     */
    QPushButton *check_b;

    /**
     * @brief Строка для ввода числа
     */
    QLineEdit *input_line;

    /**
     * @brief Загаданное игрой число
     */
    QString secret;

    /**
     * @brief Текст состояния игры
     */
    QLabel* text_on_window;

    /**
     * @brief Текст подсказки игроку
     */
    QLabel* text_for_p;

    //------------------------------------------------------------------------------
    int width_ = 400;
    int height_ = 500;

};
#endif // BULLS_AND_COWS_H
