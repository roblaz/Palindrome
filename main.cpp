#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>

//#define WORKPATH "C:\Users\Robert\Desktop\Cplusplus\Palinndrome"

int main()
{
    QString strTemp;
    QFile writef("SaveResult.txt");
    QFile readf("Palindrome.txt");
    QString strWorkPath = "C:\\Users\\Robert\\Desktop\\Cplusplus\\Palinndrome";

    if (!QDir(strWorkPath).exists()) {
        qDebug() << (strWorkPath + " not exist") << endl;
        return 1;
    }

    QDir::setCurrent(strWorkPath);
    //qDebug() << QDir::current().path();

    QString strFullPath = QDir::current().path() + "/" + readf.fileName();

    if (readf.open(QFile::ReadOnly)) {
        if (!readf.exists()) {
            qDebug() << strFullPath + "Input file can't open";
            return 1;
        }
    } else {
        qDebug() << strFullPath + " Input file not exist";
        return 1;
    }

    strFullPath = QDir::current().path() + "/" + writef.fileName();

    if (writef.open(QFile::WriteOnly | QFile::Truncate)) {
        if (!writef.exists()) {
            qDebug() << strFullPath + "Output file can't create";
            return 1;
        }
    } else {
        qDebug() << strFullPath + " Output file can't create";
        return 1;
    }

    QTextStream out(&writef);
    QTextStream in(&readf);

    //qDebug() << endl;

    bool bResult;
    int iStart, iEnd; //iStart - first position, iEnd - end position in line

    while (!in.atEnd()) {
        strTemp = in.readLine();
        //qDebug() << strTemp;

        // prepare initial values by variables
        bResult = true;
        iStart = 0;
        iEnd = strTemp.length() - 1;

        for(; iEnd - iStart > 1; iEnd--, iStart++) {

            if (strTemp[iStart] != strTemp[iEnd]) {
                bResult = false;
                break;
            }
        }

        if (bResult) {
            out << "yes, it is a palindrome: ";
        } else {
            out << "this is not a palindrome: ";
        }
        //qDebug() <<  bResult << endl;
        out << strTemp << endl;
    }


    writef.close();
    readf.close();
    return 0;// a.exec();
}
