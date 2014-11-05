#include <string>
#include <iostream>
#include <assert.h>
#include <sstream>
#include "CSVHelper.h"

void CSVReader::SetContent(std::string &contentFile)
{
	m_fileStream.str(contentFile);
}

CSVReader::~CSVReader()
{
	delete m_pContent;
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

CSVReader::CSVReader(void)
{

}

CSVRow::CSVRow()
{

}

CSVRow::~CSVRow()
{

}

#ifdef IW_SDK

#include "IwDebug.h"


CSVReaderS3e::~CSVReaderS3e()
{
	if (m_pFile != 0)
		s3eFileClose(m_pFile);
}

CSVReaderS3e::CSVReaderS3e(char* fileName)
{
	IwTrace(CSV_READER, (("The follow file will be load: %s", fileName)));
	m_pFile = s3eFileOpen(fileName, READ);

	assert(m_pFile != NULL);

	m_fileSize = s3eFileGetSize(m_pFile);
	m_pContent = (char*)s3eMallocBase(m_fileSize + 1);

	memset(m_pContent, 0, m_fileSize + 1);

	m_rowNumber = 0;

	if (s3eFileRead(m_pContent, m_fileSize, 1, m_pFile))
	{
		std::string content = m_pContent;
		SetContent(content);
	}
}


#endif // IW_SDK
