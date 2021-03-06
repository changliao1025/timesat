#include "system.h"
//=============================================================================================
//file and path operation functions
//=============================================================================================

//=============================================================================================
//test the existance of a file
//not the most efficient, but easy to understand for now
//=============================================================================================
int file_test(std::string sFilename)
{
  std::ifstream ifs(sFilename.c_str());
  if (ifs.good())
    {
      return 1;
    }
  else
    {
      return 0;
    }
}


//=============================================================================================
//recursive mkdir when it does not exist
//=============================================================================================
int make_directory(std::string sDirectory)
{
  //the maximum length for current setting
  int dir_err;
  char tmp[250];
  char *p = NULL;
  size_t len;
  ///=================================================
  ///convert char * to cstring
  ///=================================================
  snprintf(tmp, sizeof(tmp), "%s", sDirectory.c_str());
  ///=================================================
  len = strlen(tmp);
  ///===================================================
  ///remove the last slash
  ///==================================================
  if (tmp[len - 1] == slash)
    {
      tmp[len - 1] = 0;
    }
  ///=================================================
  for (p = tmp + 1; *p; p++)
    {
      if (*p == slash)
        {
          ///=================================
          /// Temporarily truncate
          ///=================================
          *p = 0;

          std::string temp(tmp);
          if (path_test(temp) == false)
            {
#if defined(__linux__)
              mkdir(tmp, S_IRWXU);
#else
              dir_err = _mkdir(tmp);
#endif
            }
          ///===================================
          ///recover the slash
          ///===================================
          *p = slash;

        }
    }
  ///=================================================
  ///final step
  ///=================================================
#if defined(__linux__)
  dir_err = mkdir(tmp, S_IRWXU);
#else
  dir_err = _mkdir(tmp);
#endif
  if (-1 == dir_err)
    {
      cout << "Error creating directory!" << tmp << endl;
      return 0;
    }
  else
    {
      return 1;
    }
}



//=============================================================================================
//test the existance of a path
//use the stat header file
///=================================================
int path_test(std::string sPath)
{
#if defined(__linux__)
  struct stat sb;
  if (stat(sPath.c_str(), &sb) == 0 && S_ISDIR(sb.st_mode))
    {
      return 1;
    }
  else
    {
      return 0;
    }
#else
  DWORD attribs = GetFileAttributesA( sPath.c_str()  );
  if (attribs == INVALID_FILE_ATTRIBUTES)
    {
      return 0;
    }
  else
    {
      return 1;
    }

  /*std::wstring stemp = std::wstring(sPath.begin(), sPath.end());
    LPCTSTR  sw = (LPCTSTR)(stemp.c_str());
    if (0xffffffff == GetFileAttributes(sw))
    {
    return 0;
    }
    else
    {
    return 1;
    }*/

#endif
}


///==============================================================
/*!
  <long-description>

  \param sCommand
  \return <ReturnValue>
*/
///==============================================================

int run_command(std::string sCommand)
{
  int error_code = 1;
  FILE *pFile;
  char buffer[512];
#if defined(__linux__)
  if( !( pFile = popen( sCommand.c_str(),"r" )) )
    {
      error_code = 0; ///<failed to submit job
    }
  else
    {
      ///get the output
      while( fgets(buffer, sizeof(buffer), pFile) != NULL )
        {
          ///prpFilet the output
          std::cout<<buffer<<std::endl;
        }
      ///close the output
      pclose( pFile );
    }
#else

	  #endif
  return error_code;
}

///============================================================== 
/*!
  <long-description>

  \param sFilename      
  \return <ReturnValue>
*/
///============================================================== 

long get_file_size(std::string sFilename)
{
  std::ifstream ifs;
  ifs.open(sFilename, std::ifstream::ate | std::ifstream::binary);
  if (ifs.good())
    {
      return ifs.tellg();
    }
  else
    {
      return -1;
    }
}
