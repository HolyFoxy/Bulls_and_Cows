#ifndef INPUT_WINDOW_H
#define INPUT_WINDOW_H

#include <QtWidgets>

class input_window : public QWidget
{
    Q_OBJECT
public:
    input_window(QMainWindow *parent = nullptr);
    ~input_window();


private slots:
    /**
     * @brief Функция нажатия на клавишу принятия введенного имени.
     * Закрывает окно ввода имени и отправляет сигнал
     */
    void on_Apply_b_clicked();

signals:
    /**
     * @brief Сигнал полученного имени
     * @param QString - имя игрока
     */
    void s_name_catched(QString);

private:
    //------------------------------------------------------------------------------
    //Элементы окна и программы
    //------------------------------------------------------------------------------
    /**
     * @brief Кнопка принятия имени
     */
    QPushButton* apply_b;

    /**
     * @brief Строка для ввода имени
     */
    QLineEdit* input_line;

    /**
     * @brief Информация для игрока
     */
    QLabel* text_on_window;

};

#endif // INPUT_WINDOW_H
