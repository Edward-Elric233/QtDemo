#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QCheckBox>
#include <QRadioButton>
#include <QPushButton>
#include <QPlainTextEdit>

class Dialog : public QDialog
{
    Q_OBJECT
private:
    QCheckBox *checkBoxUnderLine, *checkBoxItalic, *checkBoxBold;
    QRadioButton *radioButtonBlack, *radioButtonBlue, *radioButtonRed;
    QPlainTextEdit *plainTextEdit;

    QPushButton *pushButtonOk, *pushButtonCancle, *pushButtonClose;

    void initLayout();
    void initEvent();

private slots:
    void on_checkBoxUnderLine(bool checked);
    void on_checkBoxItalic(bool checked);
    void on_checkBoxBold(bool checked);
    void on_radioButton(bool clicked);

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
};
#endif // DIALOG_H
