#ifndef __CVS__HELPER__H 
#define __CVS__HELPER__H

#include <exception>
#include <string>
#include <iostream>
#include <sstream>

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
protected:
	std::istringstream m_fileStream;
	int32 m_fileSize;
	int32 m_rowNumber;
	char* m_pContent;
	

public:
	CSVReader(void);
	void SetContent(std::string &contentFile);
	bool ReadRow(CSVRow& row);

	int32 GetFileSize()
	{
		return m_fileSize;
	}

	~CSVReader();
};


#ifdef IW_SDK

#include "s3e.h"

#define READ "rb"
#define WRITE "wb"

class CSVReaderS3e : public CSVReader
{
private:
	s3eFile* m_pFile;

public:
	CSVReaderS3e(char* fileName);
	~CSVReaderS3e();
};
#endif // IW_SDK

#endif // __CVS__HELPER__H





