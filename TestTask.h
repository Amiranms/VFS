#include <iostream> 
#include <vector>
#include <unordered_map> 
#include <string>
#include <filesystem>
#include <fstream>
#include <queue>

constexpr int MAX_FILES = 10000;//one physical file capacity
constexpr int MAX_CHAR = 500;//one virtual file capacity



namespace TestTask{

    std::string extractingName(const std::string name );//should search from end of the string 


    std::string extractingDirPath(const std::string name);


    //this structure using to demonstrate in which mode file opened and also what access it have 
   enum class Access {
    CLOSED=0, //for FILE::m_isOpened variable by default
    READ,
    WRITE,
    RaW //read and write, for all files by default 

    //also there should be execute access, but it's unnecessary in our case
  };

    struct File {
        std::string m_Fullname;//just like /dir1/dir2/dir3/file.extension
        std::string m_Name;//only file.extension.
        std::string m_fcontent;//for virtual file content
        time_t m_TimeAccess;//looks like it really useless within the scope of the task 
        time_t m_TimeMod;
        Access m_isOpened; //btw...should be more professional approach to control openning 
        Access m_Access;

        File(std::string FullName,std::string content);

    };

    struct Dir {
        std::string m_FullName;
        std::string m_Name;
        time_t m_TimeAccess;
        time_t m_TimeMod;
        std::vector<File> m_files;//files into directory
        std::vector<Dir> m_dirs;//children directories 

    //  Dir * parent;//nullptr if it mainfolder 
        Dir();

        Dir(std::string  FullName);

        int ifDirExists(std::string name);

        //creates directory and returns last dir pointer
        Dir* addDir(std::string fullPath);

        //returns last directory in the path pointer, creates ones if it necesary 
        Dir* addAllDirs(std::string fullPath);

        //function findFile could be recursive, but it's not, so it search for file into current directory
        File* findFile(const char* name);

        File* addFile(std::string fileName, std::string content);

    
        Dir* findDir(std::string  name);



    };



    struct IVFS
    {

        Dir m_root;//should be initialized at the start of the work
        std::string mountDirPath;//folder there all physic files will be stored
        long long numberOfFiles;

        File* Open(const char* name);
        // Открыть файл в readonly режиме. Если нет такого файла или же он открыт во writeonly режиме - вернуть nullptr
        
        File* Create(const char* name);
        
        size_t Read(File* f, char* buff, size_t len);// Прочитать данные из файла. Возвращаемое значение - сколько реально байт удалось прочитать
        
        size_t Write(File* f, char* buff, size_t len); // Записать данные в файл. Возвращаемое значение - сколько реально байт удалось записать
         
        void Close(File* f) ;// Закрыть файл	
      
        IVFS(const char* folder_path);//folder_path it is a path to a physical folder where will be all our virtual files stored 
        


        ~IVFS();

    };

}

