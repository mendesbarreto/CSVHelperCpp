#include <string>
#include <iostream>
#include <assert.h>
#include <sstream>
#include "IwDebug.h"

#include "CSVHelper.h"


CSVReader::CSVReader( char* fileName )
{
	IwTrace(CSV_READER, ( ("The follow file will be load: %s" , fileName) ));
	m_pFile = s3eFileOpen(fileName, READ);
	assert(m_pFile != NULL);

// 	if (m_pFile == NULL)
// 	{
// 		
// 		//throw CSVFileNotFound();
// 	}

	m_fileSize = s3eFileGetSize(m_pFile);
	m_pContent = (char*)s3eMallocBase(m_fileSize+1);
	memset(m_pContent, 0, m_fileSize+1);

	m_rowNumber = 0;

	if (s3eFileRead(m_pContent, m_fileSize, 1, m_pFile))
	{
		std::string content = m_pContent;
		m_fileStream.str(content);
	}
	else
	{
		//throw CSVFileCouldNotBeRead();
	}

}

CSVReader::~CSVReader()
{
	if (m_pFile != 0)
		s3eFileClose(m_pFile);
}

bool CSVReader::ReadRow(CSVRow& row)
{
	std::string line;
	//std::getline(m_fileStream, line, '\n');
	//getline(stringStream, line, m_rowNumber);
	//if (line == "0")
	if (std::getline(m_fileStream, line, '\n'))
	{
		row.SetData(line);
		return true;
	}
		
	return false;
}

CSVRow::CSVRow()
{

}

CSVRow::~CSVRow()
{

}
