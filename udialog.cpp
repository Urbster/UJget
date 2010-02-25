#include "udialog.h"
#include "ui_udialog.h"

UDialog::UDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::UDialogClass)
{
    ui->setupUi(this);
    http = new QHttp(this);
    connect(ui->GetBtn,SIGNAL(clicked()),this,SLOT(onGetBtnClicked()));
    connect(http,SIGNAL(done(bool)),this,SLOT(downloadFinished(bool)));
    connect(http,SIGNAL(dataReadProgress(int,int)), this, SLOT(downloadProgress(int,int)));
    connect(ui->CancelBtn,SIGNAL(clicked()),this,SLOT(onCancelBtnClicked()));
    connect(ui->FindBtn,SIGNAL(clicked()),this,SLOT(onFindBtnClicked()));
    cancel = false;
    next = false;
    //ui->progressBar->setValue(0);
    //ui->CurrentFile->setText("");
    //ui->CurrentFolder->setText("");
    ui->LoadPics->setText("");
    ui->LoadMangas->setText("");
    dir = new QDir("");
    ui->tableWidget->insertColumn(0);
    ui->tableWidget->insertColumn(1);
    ui->tableWidget->insertColumn(2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"MNumber"<<"Page"<<"Progress");
    ui->DirEdit->setText(dir->absolutePath());
}

UDialog::~UDialog()
{
    delete ui;
}

void UDialog::UpdateList(QString File, QString Folder)
{

}

void UDialog::onFindBtnClicked()
{
    dialog = new QFileDialog(this);
    dialog->setFileMode(QFileDialog::Directory);
    dialog->setDirectory(*dir);
    dialog->exec();
    *dir = dialog->directory();
    ui->DirEdit->setText(dir->absolutePath());
}
void UDialog::onCancelBtnClicked()
{
    cancel = true;
}
void UDialog::downloadProgress(int done,int total)
{
    if(total > 0)
    {
       // ui->progressBar->setValue((done/total * 100));
    }
}
void UDialog::downloadFinished(bool error)
{
    file->close();
    if(error || file->size() < 1000)
    {
        next = true;
    }
    loop.quit();
}
void UDialog::onGetBtnClicked()
{
    QString Url = ui->UrlEdit->text();
    QStringList SubFolders;
    QString Host;
    QString CurrentFile;
    QString CurrentFolder;
    QString Folder;
    QString SubUrl;
    QString WorkingDir;
    QString Page1;
    QString Page2;
    int PageCount = 1;
    int MangaCount = 1;
    QTableWidgetItem *Item;
    for(int row = (ui->tableWidget->rowCount()-1); row >= 0;row--)
        ui->tableWidget->removeRow(row);
    if(!Url.isEmpty())
    {
        Url = Url.remove("http://");
        Host = Url.section("/",0,0);
        SubFolders = Url.split("/");//.section("/",1,-1,QString::SectionIncludeLeadingSep);
        if(SubFolders.count() < 3)
            return;

        SubFolders.removeFirst();
        CurrentFile = SubFolders.last().section(".",0,0);
        SubFolders.removeLast();
        CurrentFolder = SubFolders.last();
        SubFolders.removeLast();
        http->setHost(Host);
        WorkingDir = ui->DirEdit->text();
        dir->cd(WorkingDir);
        Folder = ui->MangaEdit->text();
        if(!Folder.isEmpty())
        {
            dir->mkdir(Folder);
            dir->cd(Folder);
        }
        int fileLength = CurrentFile.length();
        int folderLength = CurrentFolder.length();
        int FolderNumber = ui->StartEdit->text().toInt();
        int maxFolderNumber = ui->NumberEdit->text().toInt() + FolderNumber;
        for(int FolderIndex = CurrentFolder.toInt(); FolderNumber <= maxFolderNumber && !cancel; FolderIndex += 10)
        {
            Folder = QString::number(FolderNumber);
            while(Folder.length() < 3)
                    Folder = "0" + Folder;
            dir->mkdir(Folder);
            dir->cd(Folder);


            CurrentFolder = QString::number(FolderIndex);
            while(CurrentFolder.length() < folderLength)
                    CurrentFolder = "0" + CurrentFolder;
            next = false;
            for(int FileIndex = 1; FileIndex <= 99 && !cancel && !next; FileIndex++)
            {
                //ui->progressBar->setValue(0);                
                CurrentFile = QString::number(FileIndex);
                while(CurrentFile.length() < fileLength)
                    CurrentFile = "0" + CurrentFile;
                CurrentFile += ".jpg";
               // ui->CurrentFile->setText(CurrentFile);
                file = new QFile((dir->absolutePath() + "/" + CurrentFile));
                Item = new QTableWidgetItem(Folder);
                ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                ui->tableWidget->setRowHeight(ui->tableWidget->rowCount()-1,20);
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,Item);
                Item = new QTableWidgetItem(CurrentFile);
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,Item);
                Item = new QTableWidgetItem("Start Downloading");
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,Item);
                if(file->exists())
                {
                    file->remove();
                }
                if(!file->open(QIODevice::WriteOnly))
                {
                    cancel = false;
                    return;
                }
                SubUrl = "/" + SubFolders.join("/") + "/" + CurrentFolder + "/" + CurrentFile;

                http->get(SubUrl,file);
                loop.exec();

                if(next)
                {
                    next = false;
                    file->remove();
                    Item = new QTableWidgetItem("invalid-removed");
                    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,Item);
                    Page1 = QString::number(FileIndex);
                    Page2 = QString::number(FileIndex+1);                    
                    FileIndex++;
                    while(Page1.length() < fileLength)
                        Page1 = "0" + Page1;
                    while(Page2.length() < fileLength)
                        Page2 = "0" + Page2;
                    CurrentFile = Page1 + '-' +Page2 +".jpg";
                    ui->LoadPics->setText(CurrentFile);
                    Item = new QTableWidgetItem(Folder);
                    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                    ui->tableWidget->setRowHeight(ui->tableWidget->rowCount()-1,20);
                    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,Item);
                    Item = new QTableWidgetItem(CurrentFile);
                    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,Item);
                    Item = new QTableWidgetItem("Start Downloading");
                    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,Item);
                    file = new QFile((dir->absolutePath() + "/" + CurrentFile));
                    if(file->exists())
                        file->remove();
                    if(!file->open(QIODevice::WriteOnly))
                    {
                        ui->LoadPics->setText("error");
                        cancel = false;
                        return;
                    }
                    SubUrl = "/" + SubFolders.join("/") + "/" + CurrentFolder + "/" + CurrentFile;
                    http->get(SubUrl,file);
                    loop.exec();
                    if(!next)
                    {
                        Item = new QTableWidgetItem("downloaded");
                        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,Item);
                        ui->LoadPics->setText(QString::number(PageCount));
                        PageCount++;
                    }
                    else
                    {
                        break;
                    }

                }
                else
                {
                    Item = new QTableWidgetItem("downloaded");
                    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,Item);
                    ui->LoadPics->setText(QString::number(PageCount));
                    PageCount++;
                }

            }
            if(!next)
            {
                Item = new QTableWidgetItem("downloaded");
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,Item);
            }
            else
            {
                Item = new QTableWidgetItem("invalid");
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,Item);

            }
            ui->LoadMangas->setText(QString::number(MangaCount));
            MangaCount++;
            if(file->exists())
                file->remove();
            FolderNumber++;
            dir->cd("..");
        }

    }
    cancel = false;
}
