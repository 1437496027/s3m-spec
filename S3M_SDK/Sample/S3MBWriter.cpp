#include <setjmp.h>
#include <assert.h>
#include "S3MBWriter.h"
#include "AltizureToS3MB.h"
#include "CacheBuilder3D/UGS3MBSCP.h"

S3MBWriter::S3MBWriter()
{
}

S3MBWriter::~S3MBWriter()
{
}

void S3MBWriter::SetJsonFileName(const UGString & jsonFileName)
{
	m_jsonFileName = jsonFileName;
}
void S3MBWriter::SetOutPutFolder(const UGString & outPutFolder)
{
	m_outputFolder = outPutFolder;
}

UGbool S3MBWriter::AltizureTOS3MB()
{
	//ʹ�� UGJsonUtils��ȡjson��Ϣ
	UGJsonUtils objJsonUtils;
	objJsonUtils.SetFileName(m_jsonFileName);
	objJsonUtils.ParseJson();
	UGint lodNum = objJsonUtils.GetLodNum();
	UGint tileLength = objJsonUtils.GetTileLength();
	UGPoint3D postion = objJsonUtils.GetPostion();
	EmPrjCoordSysType priCoordSysType = objJsonUtils.GetProjection();
	//ͨ��AltizureToS3MB���� S3MB�����ļ�
	AltizureToS3MB altizureToS3MB;
	altizureToS3MB.SetFileName(m_jsonFileName);

	altizureToS3MB.SetOutputFilePath(m_outputFolder);
	altizureToS3MB.SetLodNum(lodNum);
	altizureToS3MB.SetTileLength(tileLength);
	altizureToS3MB.SetPostion(postion);
	altizureToS3MB.SetProjection(priCoordSysType);

	altizureToS3MB.GenerateS3MB();
	altizureToS3MB.GenerateScp();

	return TRUE;
}