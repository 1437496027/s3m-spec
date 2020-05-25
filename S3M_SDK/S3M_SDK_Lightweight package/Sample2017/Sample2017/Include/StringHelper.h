#pragma once
#include <string>
//#include <stringapiset.h>
#include <stdarg.h>
#include <algorithm>
#include <sstream>
#include <vector>
//#include <winnls.h>
using namespace std;

namespace S3MB
{
	class StringHelper
	{
	public:
		//���ַ�����Сд�ַ�ת��Ϊ��д�ַ�
		static string StrToUpper(string str);

		//�ж��ַ����Ƿ���ͬ
		static bool CompareNoCase(const string& strA, const string& strB);

		//�и��ַ���
		static void Split(const string& s, vector<string>arrStr, const char flag = ' ');

		//ȥ�����ָ���ַ���
		static string TrimLeft(string& str, char* pStr = NULL);

		//ȥ���ұ�ָ���ַ���
		static string TrimRight(string& str, char* pStr = NULL);
		static string TrimRight(string& str, char ch);

		//ansi����ת��Ϊutf8����
		static std::string ANSI_to_UTF8(const string& str);

		//utf8����ת��Ϊansi����
		static std::string UTF8_to_ANSI(const string& str);

		//��ȡ�ַ�������
		static int GetStrLength(const char* pStr);

		// ��ʽ���ַ���
		static std::string Format(const char* pStr, ...);

		//! \brief ȡ���ַ����������ұߵ�ָ�����ȵ����ַ���
		//! \param nCount �ֽڸ���
		//! \return �����ұ�ָ�����ȵ����ַ���
		//! \include str_right.cpp
		static string Right(const string& str, int nCount);

		//! \brief ȡ���ַ�����������ߵ�ָ�����ȵ����ַ���
		//! \param nCount �ֽڸ���
		//! \return �������ָ�����ȵ����ַ���
		//! \include str_right.cpp
		static string Left(const string& str, int nCount);
		static string From(long lVal, unsigned int base = 10);
		static string From(unsigned long lVal, unsigned int base = 10);

		//��ȡ�ļ������ļ���
		static string GetDir(string filePath);

		//��ȡ�ļ�����·��
		static string GetAbsolutePath(string strSrcPath, string path);
		static string GetAbsolutePath(string relatPath);

		//�ı��ļ���׺
		static string ChangeExt(string path, string ext);
		//��ȡ�ļ���׺
		static string GetExt(string filePath);
		//�ж��ļ��Ƿ����
		static bool IsFileExist(string path);

	};

	class FileType
	{
	public:
		enum EmType
		{
			//! \brief δ֪���ݸ�ʽ��
			none = 0,
			//! \brief Tiff/BigTIFF/GeoTIFF�ļ���
			GTiff = 103,
			//! \brief bitmap�ļ���
			BMP = 121,
			//! \brief jpg�ļ���
			JPG = 122,
			//! \brief portal network graphic(PNG)��
			PNG = 123,
			//! \brief gif�ļ���
			GIF = 124,
			//! \brief tga�ļ���
			TGA = 125,
		};
		//! \brief ���ݺ�׺���õ��ļ����͡�
		//! \param strExtName [in] ��.�ĺ�׺����
		//! \return �ļ���ʽ���͡�
		static EmType ExtNameToFileType(const string& strExtName);

		//! \brief �����ļ����͵õ���׺����
		//! \param eFileType [in] �ļ���ʽ���͡�
		//! \return ��.�ĺ�׺����
		static string FileTypeToExtName(EmType eFileType);
	};
}
