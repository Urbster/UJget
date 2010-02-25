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
    ui->progressBar->setValue(0);
    ui->CurrentFile->setText("");
    ui->CurrentFolder->setText("");
    dir = new QDir("");
    ui->DirEdit->setText(dir->absolutePath());
}

UDialog::~UDialog()
{
    delete ui;
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
        ui->progressBar->setValue((done/total * 100));
    }
}
void UDialog::downloadFinished(bool error)
{
    file->close();
    if(error || file->size() < 1000)
        next = true;
    loop.quit();
}
void UDialog::onGetBtnClicked()
{
    //http://img55.onemanga.com/mangas/00000004/000100772/01.jpg;
    QString Url = ui->UrlEdit->text();
    QStringList SubFolders;
    QString Host;
    QString CurrentFile;
    QString CurrentFolder;
    QString Folder;
    QString SubUrl;
    QString WorkingDir;
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
        int FolderNumber = 0;
        int maxFolderNumber = ui->NumberEdit->text().toInt();
        for(int FolderIndex = CurrentFolder.toInt(); FolderNumber <= maxFolderNumber && !cancel; FolderIndex += 10)
        {
            Folder = QString::number(FolderNumber);
            while(Folder.length() < 3)
                    Folder = "0" + Folder;
            dir->mkdir(Folder);
            dir->cd(Folder);
            ui->CurrentFolder->setText(Folder);
            CurrentFolder = QString::number(FolderIndex);
            while(CurrentFolder.length() < folderLength)
                    CurrentFolder = "0" + CurrentFolder;

            for(int FileIndex = 1; FileIndex <= 99 && !cancel && !next; FileIndex++)
            {
                ui->progressBar->setValue(0);
                CurrentFile = QString::number(FileIndex);
                while(CurrentFile.length() < fileLength)
                    CurrentFile = "0" + CurrentFile;
                CurrentFile += ".jpg";
                ui->CurrentFile->setText(CurrentFile);
                file = new QFile((dir->absolutePath() + "/" + CurrentFile));
                if(file->exists())
                    file->remove();
                if(!file->open(QIODevice::WriteOnly))
                {
                    cancel = false;
                    return;
                }
                SubUrl = "/" + SubFolders.join("/") + "/" + CurrentFolder + "/" + CurrentFile;
                http->get(SubUrl,file);
                loop.exec();
            }
            next = false;
            if(file->exists())
                file->remove();
            FolderNumber++;
        }

    }
    cancel = false;
}
