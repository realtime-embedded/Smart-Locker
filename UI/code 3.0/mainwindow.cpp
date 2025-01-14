#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "FaceRecognition.h"
#include "FeatureGroup.h"

#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include "dlgfaceinput.h"
#include <iostream>


#include <QInputDialog>

extern QImage MatToQImage(const cv::Mat& mat);

FaceRecognition fr;

FeatureGroup fg("feature.index", &fr);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_trainFaces_clicked()
{
    std::vector<string> filenames;
    QString  imagePath = "./images/";

    QDir dir(imagePath);

    QStringList imageFilter;

    imageFilter << "*.bmp" << "*.jpg" << "*.png";//向字符串列表添加图片类型

    dir.setNameFilters(imageFilter);//获得文件夹下图片的名字

    int cnt = dir.count();//获得dir里名字的个数，也表示文件夹下图片的个数

    /************获得图片名，对dir进行下标访问即可************/

    for (int i=0;i < cnt;i++)
    {
        QString imageName  = dir[i];
        QString  temp="./images/";
        qDebug() << imageName;//输出图片名
        filenames.push_back(temp.append(imageName).toStdString());

    }


    for(int i=0;i<filenames.size();i++)
    {
        std::cout <<filenames[i] << std::endl;
    }

    float **feat;

    FaceRecognition fr;
    FeatureGroup fg(fr.GetFeatureDims(), &fr);

    feat = new float*[10];

    for (int i = 0; i < 10; i++)
    {
        feat[i] = new float[fr.face_recognizer->feature_size()];
    }

    for (int i = 0; i < filenames.size(); i++)
    {
        if (fr.GetFeature(filenames[i], feat))
        {
            fg.AddFeature(feat[0], filenames[i]);
        }
    }

    fg.SaveModel("feature.index");

    QMessageBox::information(this, "提示", "人脸数据录入完成,请重启系统");
}


void MainWindow::on_pushButton_clicked()
{
    //    cv::Mat img;
    //    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"),".",tr("Image File(*.png *.jpg *.jpeg *.bmp)"));
    //    //img = cv::imread(fileName.toLatin1().data());
    //    img = cv::imread(std::string((const char *)fileName.toLocal8Bit()));
    cv::Mat imgDetect=img;
    QString name;
    if(!imgDetect.data)
    {
        QMessageBox msgBox;
        msgBox.setText(tr("image data is null"));
        msgBox.exec();
    }

    float **feat;

    feat = new float*[100];

    for (int i = 0; i < 100; i++)
    {
        feat[i] = new float[fr.face_recognizer->feature_size()];
    }

    std::vector<Feature> result;

    if (!fr.GetFeature(imgDetect, feat))
    {
        return;
    }

    cv::Rect face_rect;
    int32_t num_face = static_cast<int32_t>(fr.faces.size());


    for (int32_t i = 0; i < num_face; i++)
    {
        fg.FindTopK(1, feat[i], result);

        face_rect.x = fr.faces[i].bbox.x;
        face_rect.y = fr.faces[i].bbox.y;
        face_rect.width = fr.faces[i].bbox.width;
        face_rect.height = fr.faces[i].bbox.height;

        cv::rectangle(imgDetect, face_rect, CV_RGB(0, 0, 255), 4, 4, 0);

        if (result[0].similarity_with_goal > 0.6)
        {
            size_t len = result[0].filename.length();
            name=QString::fromStdString(result[0].filename.substr(9, len - 13));
            cv::putText(imgDetect, result[0].filename.substr(9, len - 13), cv::Point2d(face_rect.x - 5, face_rect.y - 5), CV_FONT_HERSHEY_COMPLEX, 0.4, cv::Scalar(0, 0, 255));
        }
        else
        {
            name="Unknown";
            cv::putText(imgDetect, "Unknown", cv::Point2d(face_rect.x - 5, face_rect.y - 5), CV_FONT_HERSHEY_COMPLEX, 0.5, cv::Scalar(255, 255, 0));
        }
        result.clear();
    }

    ui->lineEdit_name->setText(name);
    QImage qimg = MatToQImage(imgDetect);
    ui->label_image->setPixmap(QPixmap::fromImage(qimg));
    //cv::imshow("DetectImage", img);
}


void MainWindow::on_pushButton_faceInput_clicked()
{
    dlgFaceInput w;
    w.exec();
}


void MainWindow::on_pushButton_cameraOpen_clicked()
{
    cv::VideoCapture cap(0);

    if (!cap.isOpened())
    {
        return;
    }


    while (true)
    {
        cap >> img;

        cv::imshow("faceInput", img);
        if (27 == cv::waitKey(30))
        {
            QImage qimg = MatToQImage(img);
            ui->label_image->setPixmap(QPixmap::fromImage(qimg));

            break;
        }
    }

    cv::destroyAllWindows();
}


void MainWindow::on_pushButton_2_clicked()
{
    bool isOK;
    QString name = QInputDialog::getText(NULL, "输入",
                                         "请输入要注销的人脸姓名",
                                         QLineEdit::Normal,
                                         "",
                                         &isOK);


    QString  imagePath = "./images/";
    QFile::remove(imagePath.append(name).append(".jpg"));

    if(isOK)
    {
        QMessageBox::information(NULL, "提示",
                                 "要注销的人脸姓名是: <b>" + name + "</b>",
                                 QMessageBox::Yes | QMessageBox::No,
                                 QMessageBox::Yes);
    }
}
