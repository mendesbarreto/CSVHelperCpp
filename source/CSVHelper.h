#ifndef __CVS__HELPER__H 
#define __CVS__HELPER__H

#define READ "rb"
#define WRITE "wb"

#include <exception>
#include <string>
#include <iostream>
#include <sstream>
#include "s3e.h"


class CSVRow
{
private:
	std::string m_data;
	std::stringstream m_dataStream;

public:
	CSVRow();
	~CSVRow();

	inline std::string ReadItem()
	{
		std::string L_item;
		std::getline(m_dataStream, L_item, ',');
		return L_item;
	}

	inline std::string GetData(){ return m_data; }
	inline void SetData(std::string str)
	{ 
		m_data.clear();
		m_data.append(str.c_str());
		m_dataStream.str(m_data);
	}
};


class CSVReader
{
private:
	s3eFile* m_pFile;
	std::istringstream m_fileStream;
	int32 m_fileSize;
	int32 m_rowNumber;
	char* m_pContent;

public:	
	CSVReader( char* fileName );
	CSVReader( std::string fileName );

	bool ReadRow(CSVRow& row);

	int32 GetFileSize()
	{
		return m_fileSize;
	}

	~CSVReader();
};

// class CSVFileNotFound : exception
// {
// 	virtual const char* what() const throw()
// 	{
// 		return "The current file could not be found";
// 	}
// };
// 
// class CSVFileCouldNotBeRead : exception
// {
// 	virtual const char* what() const throw()
// 	{
// 		return "The current file could not be read";
// 	}
// };


#endif // __CVS__HELPER__H





