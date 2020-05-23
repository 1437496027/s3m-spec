#include <iostream>
#include <codecvt>
#include <fstream>
#include <string>

#include "S3MBReader.h"
#include "S3MBWriter.h"
#include "ROGroupLite.h"
#include <iosfwd>

using namespace std;
int main(int argc, char* argv[])
{

	///************************************************************************/
	//*          1.����һ�����������ݲ�д��S3MB�ļ�
    ///************************************************************************/	

	RenderOperationGroup* pGroup = ROGroupLite::CreateROGroupLite();

	S3MBWriter m_S3MBWriter;
	m_S3MBWriter.SetROGroup(pGroup);
	m_S3MBWriter.SetIsChangeTexture(true);
	string strS3mbFile = "./������.s3mb";
	m_S3MBWriter.SetFilePath(strS3mbFile);
	m_S3MBWriter.Save(0);

	///************************************************************************/
    //*        2:ͨ��ָ����s3mb�ļ�����ȡ����Ro��Ϣ�����������                                                                     */
   ///************************************************************************/


	S3MBReader m_S3MBReaderRo;

	string strS3MBFileSrc = "./������.s3mb";
	//cout << "��������Ҫ��ʾ��S3mb·����" << endl;
	//string strS3MBFileSrc;
	//cin >> strS3MBFileSrc;
	m_S3MBReaderRo.SetFilePath(strS3MBFileSrc);
	m_S3MBReaderRo.ReadS3MBAsROGroup();

	///************************************************************************/
    //*       3:ͨ��ָ����s3mb�����ļ��У�������ȡs3md�����                                                                */
   ///************************************************************************/


	//S3MBReader m_S3MBReaderAtt;

	//string strS3MBFolderSrc = "..\\SampleData\\CBD_part";
	//m_S3MBReaderAtt.SetFilePath(strS3MBFolderSrc);
	//m_S3MBReaderAtt.ReadS3MBAttribute();
}