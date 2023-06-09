#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QDialog>
#include <qmessagebox.h>


namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr);
    ~RegisterWindow();

private slots:
    void on_BackBtn_clicked();

    void on_ContinueBtn_clicked();


private:
    Ui::RegisterWindow *ui;
};

#endif // REGISTERWINDOW_H
