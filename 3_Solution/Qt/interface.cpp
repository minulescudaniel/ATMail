#include "interface.h"
#include "ui_interface.h"
#include "mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QByteArray>
#include <QFileDialog>
#include <QMessageBox>
#include "smtp.h"
#include <QList>
#include "QPixmap"
#include "QIcon"
#include <QButtonGroup>
#include "settingswindow.h"


using namespace std;

void Interface::openMail()
{
    ui->scrollArea->hide();
    for(QToolButton *folder :folderList)
    {
        ui->dropDown->addItem(folder->text()); //nou
    }
    ui->viewMail->show();
    ui->mailContent->setReadOnly(true);
}

void Interface::openFolder()
{
    for (int i = 0; i < 7; i++) {
        QToolButton* button = new QToolButton();

        //DE MODIFICAT
//            if (citit)
//            {
//                QIcon icon(":openedMail.png");
//            }

//            else
//            {
//                QIcon icon(":mail.png");
//            }


        QIcon icon(":mail.png");

        button->setFixedSize(775,50);
        //QPixmap pixmap = icon.pixmap(QSize(100, 100));
        //QIcon resizedIcon(pixmap);
        button->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        button->setText("Test\nSubject");
        button->setIcon(icon);
        button->setStyleSheet("QToolButton {   background-color: #40403e; border-radius: 5px; color: #fff; } QToolButton:hover { background-color: #4f4f4d} QToolButton:pressed {background-color: #373778;} ");
        connect(button, &QToolButton::clicked, this, &Interface::openMail);

        buttonList.append(button);
    }

    for(QToolButton *button :buttonList)
    {
        layout->addWidget(button);
    }

    //pt fisiere
    for (int i = 0; i < 2; ++i) {
        QToolButton* file = new QToolButton;
        file->setIcon(QIcon(":blackFile.png"));
        file->setIconSize(QSize(32, 32));
        file->setText("File.txt");
        file->setStyleSheet("text-align:center;");
        file->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        connect(file, &QToolButton::clicked, this, &Interface::downloadFile);

        filesList.append(file);
    }

    for(QToolButton *button :filesList)
    {
        filesLayout->addWidget(button);
    }
}

void Interface::downloadFile()
{

}

//functia pentru search in mail
void Interface::performSearch(const QString& searchText)
{
    for(QToolButton *button :buttonList)
    {
        if (button->text().contains(searchText, Qt::CaseInsensitive))
        {
            button->setVisible(true);
        }

        else
        {
            button->setVisible(false);
        }
    }
}

void Interface::performFolderSearch(const QString& searchText)
{
    for(QToolButton *folder :folderList)
    {
        if (folder->text().contains(searchText, Qt::CaseInsensitive))
        {
            folder->setVisible(true);
        }

        else
        {
            folder->setVisible(false);
        }
    }
}

Interface::Interface(QString User,QString Email,QString Password, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Interface)
{
    ui->setupUi(this);

    connect(ui->sw, &QCheckBox::stateChanged, [=](int state){
        if (state == Qt::Checked)
        {
            ui->Logo->setStyleSheet("border-image: url(:Logo_black.png);");
            ui->inbox->setStyleSheet("border-image: url(:inbox_black.png);");
            ui->star->setStyleSheet("border-image: url(:star_black.png);");
            ui->sent->setStyleSheet("border-image: url(:sent_black.png);");
            ui->trash->setStyleSheet("border-image: url(:trash_black.png);");
            ui->pushButton->setStyleSheet("QPushButton#pushButton:hover{background-color:#dbdbdb;}QPushButton#pushButton{background-color: transparent;border-radius: 20px; color: black; text-align: left; padding-left: 50px;}");
            ui->pushButton_2->setStyleSheet("QPushButton#pushButton_2:hover{background-color:#dbdbdb;}QPushButton#pushButton_2{background-color: transparent;border-radius: 20px; color: black; text-align: left; padding-left: 50px;}");
            ui->pushButton_3->setStyleSheet("QPushButton#pushButton_3:hover{background-color:#dbdbdb;}QPushButton#pushButton_3{background-color: transparent;border-radius: 20px; color: black; text-align: left; padding-left: 50px;}");
            ui->pushButton_4->setStyleSheet("QPushButton#pushButton_4:hover{background-color:#dbdbdb;}QPushButton#pushButton_4{background-color: transparent;border-radius: 20px; color: black; text-align: left; padding-left: 50px;}");
            ui->area1->setStyleSheet("background-color:#9e9e9e;");
            ui->area2->setStyleSheet("background-color:#c2c2c2;");
            ui->label->setStyleSheet("color:black;");
            ui->user->setStyleSheet("color:black");
            ui->dockWidgetContents->setStyleSheet("background-color:#9e9e9e;");
            ui->dockWidget->setStyleSheet("background-color:#dbdbdb;");
        }
        else
        {
            ui->Logo->setStyleSheet("border-image: url(:Logo.png);");
            ui->inbox->setStyleSheet("border-image: url(:inbox.png);");
            ui->star->setStyleSheet("border-image: url(:star.png);");
            ui->sent->setStyleSheet("border-image: url(:sent.png);");
            ui->trash->setStyleSheet("border-image: url(:trash.png);");
            ui->pushButton->setStyleSheet("QPushButton#pushButton:hover{background-color:#363634;}QPushButton#pushButton{background-color: transparent;border-radius: 20px; color: white; text-align: left; padding-left: 50px;}");
            ui->pushButton_2->setStyleSheet("QPushButton#pushButton_2:hover{background-color:#363634;}QPushButton#pushButton_2{background-color: transparent;border-radius: 20px; color: white; text-align: left; padding-left: 50px;}");
            ui->pushButton_3->setStyleSheet("QPushButton#pushButton_3:hover{background-color:#363634;}QPushButton#pushButton_3{background-color: transparent;border-radius: 20px; color: white; text-align: left; padding-left: 50px;}");
            ui->pushButton_4->setStyleSheet("QPushButton#pushButton_4:hover{background-color:#363634;}QPushButton#pushButton_4{background-color: transparent;border-radius: 20px; color: white; text-align: left; padding-left: 50px;}");

            ui->area1->setStyleSheet("background-color:#242423");
            ui->area2->setStyleSheet("background-color:#1c1c1b;");
            ui->label->setStyleSheet("color:white;");
            ui->user->setStyleSheet("color:white;");
            ui->dockWidgetContents->setStyleSheet("background-color:#363634;");
            ui->dockWidget->setStyleSheet("background-color:white;");
        }
    });



    this->layout = new QVBoxLayout(ui->scrollZone);
    this->layout->setAlignment(Qt::AlignTop);
    this->layout->setSpacing(10);
    this->layout->setContentsMargins(10,10,10,10);

    this->filesLayout = new QHBoxLayout(ui->filesArea);
    this->filesLayout->setAlignment(Qt::AlignTop);
    this->filesLayout->setSpacing(10);
    this->filesLayout->setContentsMargins(10,10,10,10);

    this->folderLayout = new QVBoxLayout(ui->folderZone);
    this->folderLayout->setAlignment(Qt::AlignTop);
    this->folderLayout->setSpacing(10);
    this->folderLayout->setContentsMargins(10,10,10,10);

    ui->dockWidget->hide();
    ui->dockWidget->setWindowTitle("New Message");
    ui->user->setText(User);
    this->Email=Email;
    this->Password=Password;
    ui->viewMail->hide();
    ui->createFolderWindow->hide(); // nou

    ui->search->setClearButtonEnabled(true);

    ui->dropDown->addItem(""); //nou

    QButtonGroup *buttonGroup = new QButtonGroup;
    buttonGroup->setExclusive(true);
    ui->pushButton->setCheckable(true);
    ui->pushButton_2->setCheckable(true);
    ui->pushButton_3->setCheckable(true);
    ui->pushButton_4->setCheckable(true);


    buttonGroup->addButton(ui->pushButton);
    buttonGroup->addButton(ui->pushButton_2);
    buttonGroup->addButton(ui->pushButton_3);
    buttonGroup->addButton(ui->pushButton_4);


    connect(ui->pushButton, &QPushButton::toggled, [=](bool checked) {
        if (ui->pushButton->isChecked()) {
            ui->pushButton->setStyleSheet("#pushButton {background-color: #363634; border-radius: 20px;color: #fff; text-align: left;padding-left: 50px;}");
            ui->pushButton_2->setChecked(false);
            ui->pushButton_3->setChecked(false);
            ui->pushButton_4->setChecked(false);

            this->on_pushButton_2_clicked(1);
            this->on_pushButton_3_clicked(1);
            this->on_pushButton_4_clicked(1);

            this->on_pushButton_clicked(0);
        } else {
            ui->pushButton->setStyleSheet("#pushButton {background-color: transparent; border-radius: 20px;color: #fff; text-align: left;padding-left: 50px;} #pushButton:hover{background-color: #363634;}");
        }
    });

    connect(ui->pushButton_2, &QPushButton::toggled, [=](bool checked) {
        if (ui->pushButton_2->isChecked()) {
            ui->pushButton_2->setStyleSheet("#pushButton_2 {background-color: #363634; border-radius: 20px;color: #fff; text-align: left;padding-left: 50px;}");
            ui->pushButton->setChecked(false);
            ui->pushButton_3->setChecked(false);
            ui->pushButton_4->setChecked(false);

            this->on_pushButton_clicked(1);
            this->on_pushButton_3_clicked(1);
            this->on_pushButton_4_clicked(1);

            this->on_pushButton_2_clicked(0);
        } else {
            ui->pushButton_2->setStyleSheet("#pushButton_2 {background-color: transparent; border-radius: 20px;color: #fff; text-align: left;padding-left: 50px;} #pushButton_2:hover{background-color: #363634;}");
        }
    });

    connect(ui->pushButton_3, &QPushButton::toggled, [=](bool checked) {
        if (ui->pushButton_3->isChecked()) {
            ui->pushButton_3->setStyleSheet("#pushButton_3 {background-color: #363634; border-radius: 20px;color: #fff; text-align: left;padding-left: 50px;}");
            ui->pushButton_2->setChecked(false);
            ui->pushButton->setChecked(false);
            ui->pushButton_4->setChecked(false);

            this->on_pushButton_clicked(1);
            this->on_pushButton_2_clicked(1);
            this->on_pushButton_4_clicked(1);

            this->on_pushButton_3_clicked(0);

        } else {
            ui->pushButton_3->setStyleSheet("#pushButton_3 {background-color: transparent; border-radius: 20px;color: #fff; text-align: left;padding-left: 50px;} #pushButton_3:hover{background-color: #363634;}");
        }
    });

    connect(ui->pushButton_4, &QPushButton::toggled, [=](bool checked) {
        if (ui->pushButton_4->isChecked()) {
            ui->pushButton_4->setStyleSheet("#pushButton_4 {background-color: #363634; border-radius: 20px;color: #fff; text-align: left;padding-left: 50px;}");
            ui->pushButton_2->setChecked(false);
            ui->pushButton_3->setChecked(false);
            ui->pushButton->setChecked(false);

            this->on_pushButton_clicked(1);
            this->on_pushButton_2_clicked(1);
            this->on_pushButton_3_clicked(1);

            this->on_pushButton_4_clicked(0);
        } else {
            ui->pushButton_4->setStyleSheet("#pushButton_4 {background-color: transparent; border-radius: 20px;color: #fff; text-align: left;padding-left: 50px;} #pushButton_4:hover{background-color: #363634;}");
        }
    });


    connect(ui->search,&QLineEdit::textChanged,this,&Interface::performSearch); // pentru search
    connect(ui->search_2,&QLineEdit::textChanged,this,&Interface::performFolderSearch);


}

Interface::~Interface()
{
    delete ui;
}

void Interface::on_pushButton_8_clicked()
{
    QMessageBox::StandardButton reply;
     reply = QMessageBox::question(this, "Sunteti sigur?", "Doriti sa va intoarceti?",
                                   QMessageBox::Yes|QMessageBox::No);
     if (reply == QMessageBox::Yes) {
         this->hide();
         MainWindow *mainWindow=new MainWindow;
         mainWindow->setStyleSheet("background-image:url(:bg.jpg);color:white;");
         mainWindow->setWindowIcon(QIcon(":Logo.png"));
         mainWindow->setWindowTitle("ATMail");
         mainWindow->show();
     }
     else{}
}




void Interface::on_attachment_clicked()
{
    //QString file_name=QFileDialog::getOpenFileName(this,"Select a file","C://");
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->attachLine->setText( fileListString );
}


void Interface::on_send_clicked()
{
    Smtp* smtp = new Smtp(this->Email, this->Password, "smtp.gmail.com", 465);
       connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

       if( !files.isEmpty() )
           smtp->sendMail(this->Email, ui->ToLine->text() , ui->SubjectLine->text(),ui->textEdit->toPlainText(), files );
       else
           smtp->sendMail(this->Email, ui->ToLine->text() , ui->SubjectLine->text(),ui->textEdit->toPlainText());
}

void Interface::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}


void Interface::on_exitBtn_clicked()
{
    ui->viewMail->hide();
    ui->scrollArea->show();
}


void Interface::on_pushButton_clicked(int check)
{

    if (check==0)
    {
        //creare mail-uri (pana la cate vor fi)
        for (int i = 0; i < 7; i++) {
            QToolButton* button = new QToolButton();

            //DE MODIFICAT
//            if (citit)
//            {
//                QIcon icon(":openedMail.png");
//            }

//            else
//            {
//                QIcon icon(":mail.png");
//            }


            QIcon icon(":mail.png");

            button->setFixedSize(775,50);
            //QPixmap pixmap = icon.pixmap(QSize(100, 100));
            //QIcon resizedIcon(pixmap);
            button->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
            button->setText("Test\nSubject");
            button->setIcon(icon);
            button->setStyleSheet("QToolButton {   background-color: #40403e; border-radius: 5px; color: #fff; } QToolButton:hover { background-color: #4f4f4d} QToolButton:pressed {background-color: #373778;} ");
            connect(button, &QToolButton::clicked, this, &Interface::openMail);

            buttonList.append(button);
        }

        for(QToolButton *button :buttonList)
        {
            layout->addWidget(button);
        }

        //pt fisiere
        for (int i = 0; i < 2; ++i) {
            QToolButton* file = new QToolButton;
            file->setIcon(QIcon(":blackFile.png"));
            file->setIconSize(QSize(32, 32));
            file->setText("File.txt");
            file->setStyleSheet("text-align:center;");
            file->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
            connect(file, &QToolButton::clicked, this, &Interface::downloadFile);

            filesList.append(file);
        }

        for(QToolButton *button :filesList)
        {
            filesLayout->addWidget(button);
        }

    }

    if (check==1)
    {
        if (layout==nullptr)
        {
            return;
        }

        else
        {
            for(QToolButton *button :buttonList)
            {
                layout->removeWidget(button);
                delete button;
            }

            for(QToolButton *button :filesList)
            {
                filesLayout->removeWidget(button);
                delete button;
            }

        }

        buttonList.clear();
        filesList.clear();
    }
}


void Interface::on_pushButton_2_clicked(int check)
{

    if (check==0)
    {
        for (int i = 0; i < 3 ; i++) {
            QToolButton* button = new QToolButton();
            QIcon icon(":mail.png");

            button->setFixedSize(775,50);
            //QPixmap pixmap = icon.pixmap(QSize(100, 100));
            //QIcon resizedIcon(pixmap);
            button->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
            button->setText("Test\nSubject");
            button->setIcon(icon);
            button->setStyleSheet("QToolButton {   background-color: #40403e; border-radius: 5px; color: #fff; } QToolButton:hover { background-color: #4f4f4d} QToolButton:pressed {background-color: #373778;} ");
            connect(button, &QToolButton::clicked, this, &Interface::openMail);

            buttonList.append(button);
        }

        for(QToolButton *button :buttonList)
        {
            layout->addWidget(button);
        }


    }

    if (check==1)
    {
        if (layout==nullptr)
        {
            return;
        }

        else
        {
            for(QToolButton *button :buttonList)
            {
                layout->removeWidget(button);
                delete button;
            }


        }
        buttonList.clear();
    }
}


void Interface::on_pushButton_3_clicked(int check)
{
    //hardcodat

    if (check==0)
    {
        QToolButton* button = new QToolButton();
        QIcon icon(":mail.png");

        button->setFixedSize(775,50);
        //QPixmap pixmap = icon.pixmap(QSize(100, 100));
        //QIcon resizedIcon(pixmap);
        button->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        button->setText("Sergiu\nATM");
        button->setIcon(icon);
        button->setStyleSheet("QToolButton {   background-color: #40403e; border-radius: 5px; color: #fff; } QToolButton:hover { background-color: #4f4f4d} QToolButton:pressed {background-color: #373778;} ");
        connect(button, &QToolButton::clicked, this, &Interface::openMail);

        buttonList.append(button);

        //////////////////////////
        QToolButton* button2 = new QToolButton();
        //QIcon icon(":mail.png");

        button2->setFixedSize(775,50);
        //QPixmap pixmap = icon.pixmap(QSize(100, 100));
        //QIcon resizedIcon(pixmap);
        button2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        button2->setText("Dani\nCe faci?");
        button2->setIcon(icon);
        button2->setStyleSheet("QToolButton {   background-color: #40403e; border-radius: 5px; color: #fff; } QToolButton:hover { background-color: #4f4f4d} QToolButton:pressed {background-color: #373778;} ");
        connect(button2, &QToolButton::clicked, this, &Interface::openMail);
        buttonList.append(button2);
        ////////////////////////////////
        QToolButton* button3 = new QToolButton();
        //QIcon icon(":mail.png");

        button3->setFixedSize(775,50);
        //QPixmap pixmap = icon.pixmap(QSize(100, 100));
        //QIcon resizedIcon(pixmap);
        button3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        button3->setText("Sergiu\nFac bine");
        button3->setIcon(icon);
        button3->setStyleSheet("QToolButton {   background-color: #40403e; border-radius: 5px; color: #fff; } QToolButton:hover { background-color: #4f4f4d} QToolButton:pressed {background-color: #373778;} ");
        connect(button3, &QToolButton::clicked, this, &Interface::openMail);



        buttonList.append(button3);

        for(QToolButton *button :buttonList)
        {
            layout->addWidget(button);
        }


    }

    if (check==1)
    {
        if (layout==nullptr)
        {
            return;
        }

        else
        {
            for(QToolButton *button :buttonList)
            {
                layout->removeWidget(button);
                delete button;
            }


        }
        buttonList.clear();
    }

}


void Interface::on_pushButton_4_clicked(int check)
{
    if (check==0)
    {
        for (int i = 0; i < 1 ; i++) {
            QToolButton* button = new QToolButton();
            QIcon icon(":mail.png");

            button->setFixedSize(775,50);
            //QPixmap pixmap = icon.pixmap(QSize(100, 100));
            //QIcon resizedIcon(pixmap);
            button->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
            button->setText("Test\nSubject");
            button->setIcon(icon);
            button->setStyleSheet("QToolButton {   background-color: #40403e; border-radius: 5px; color: #fff; } QToolButton:hover { background-color: #4f4f4d} QToolButton:pressed {background-color: #373778;} ");
            connect(button, &QToolButton::clicked, this, &Interface::openMail);

            buttonList.append(button);
        }

        for(QToolButton *button :buttonList)
        {
            layout->addWidget(button);
        }


    }

    if (check==1)
    {
        if (layout==nullptr)
        {
            return;
        }

        else
        {
            for(QToolButton *button :buttonList)
            {
                layout->removeWidget(button);
                delete button;
            }


        }
        buttonList.clear();
    }

}




void Interface::on_forwardBtn_clicked()
{
    ui->dockWidget->show();
}


void Interface::on_replyBtn_clicked()
{
    ui->dockWidget->show();
}


void Interface::on_trashBtn_clicked()
{

}

//nou
void Interface::on_favorite_clicked()
{
    ui->favorite->setStyleSheet("#favorite {background-color: transparent; border-image: url(:favorite_yellow.png); background: none; border: none; background-repeat: none;}");
}

//nou
void Interface::on_settings_clicked()
{
   SettingsWindow* settingswindow= new SettingsWindow;
   settingswindow->show();
}


void Interface::on_addFolder_clicked()
{
    ui->createFolderWindow->show();
}


void Interface::on_addBtn_clicked()
{

    ui->createFolderWindow->hide();
    QToolButton* folder= new QToolButton;
    QIcon icon(":folder_yellow.png");
    folder->setFixedSize(290,35);
    folder->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    folder->setText(ui->editName->text());
    ui->editName->clear();
    folder->setIcon(icon);
    folder->setStyleSheet("QToolButton {   background-color: #40403e; border-radius: 5px; color: #fff; } QToolButton:hover { background-color: #4f4f4d} QToolButton:pressed {background-color: #373778;} ");
    connect(folder, &QToolButton::clicked, this, &Interface::openFolder);
    folderLayout->addWidget(folder);
    folderList.append(folder);

}


void Interface::on_exitBtn_2_clicked()
{
    ui->createFolderWindow->hide();
    ui->editName->clear();
}



void Interface::on_dropDown_currentTextChanged(const QString &arg1)
{
    for(QToolButton *folder :folderList)
    {
        if (folder->text()==arg1)
        {
            //TODO: se adauga intr-o lista gen list.append(...)

        }
    }
}

