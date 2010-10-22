#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QWidget>

namespace Ui {
    class SettingsWidget;
}


class SettingsWidget : public QWidget
{
    Q_OBJECT

    public:
        explicit SettingsWidget( QWidget *parent = 0);
        ~SettingsWidget();

    private:
        Ui::SettingsWidget *ui;
};

#endif

// vim: expandtab:tabstop=4:shiftwidth=4
// kate: space-indent on; indent-width 4
