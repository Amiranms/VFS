#include "TestTask.cpp"
using namespace TestTask;

int main()
{ 
    
    IVFS fs{ "./directory" };
    File * f = fs.Create("/file1");
    File* f1 = fs.Create("/dir1/file1");
    File* f2= fs.Create("/dir2/dir3/file1");
    File* f3 = fs.Create("/dri1/file2");

  //  std::cout << (int)f->m_isOpened;
    char a[] = "Very imprtant conten";
    char b[] = "Is london the capital of GB?";
    fs.Write(f, a, 14);
    fs.Write(f1, b, 44);
    fs.Write(f2, a, 4);
    fs.Write(f3, b, 1);

   // Dir * d = fs.m_root.findDir("/dir1/dir2/dir8/dir12");
   // std::cout << (d!=nullptr?d->m_FullName:"its' null");

   /* Дря проверка восстановления виртуальных файлов раскоментировать нижнюю строчку а все что сверху закомментировать
    IVFS fs{ "./directory" };
    */
    
}