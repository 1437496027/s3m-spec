#pragma once
#include "StringHelper.h"
#include "Shell.h"
class S3MBWriter
{
public:
	S3MBWriter()
	{
		m_bChangeTexture = true;
		m_CompressType = 14;
	}
	~S3MBWriter() {}
public:
	void ProcessSaveInfo(int vertexCompressOptions = 19);
	//! \brief ȡ��PagedLOD��ʵ��
	void FillEntityPack(RenderOperationPagedLOD* pROPagedLOD);
	//! \brief ȡ��Geode��ʵ��
	void FillEntityPack(RenderOperationGeode* pROGeode);
	//! \brief ȡ��Geometry�Ĳ��ʺ�����
	void FillEntityPack(Geometry* pGeometry);
	//! \brief ȡ��Material������
	void FillEntityPack(Material*  pMaterial3D);

	bool Save(int vertexCompressOptions = 19);
	//������Ҫд���ļ���RenderOperationGroup
	void SetROGroup(RenderOperationGroup* pGroup) { this->m_pROGroup = pGroup; }
	//���õ����ļ�·��
	void SetFilePath(string filePath) {
		if (filePath.find(':') == string::npos)
		{
			this->m_strFilePath = StringHelper::GetAbsolutePath(filePath);
		}
		else
			this->m_strFilePath = filePath;
	}
	//�����Ƿ�ı�ͼƬ��ʽ
	void SetIsChangeTexture(bool bChange) { this->m_bChangeTexture = bChange; }
private:
	// ����Դ�ļ�
	std::string m_strFilePath;

	RenderOperationGroup* m_pROGroup;

	//! \brief �Ƕ����õ��ڴ�������
	MemoryStream m_streamShell;

	//! \brief �Ǽܷ��õ��ڴ�������
	MemoryStream m_streamGeometry;

	//! \brief SelectionInfo���õ��ڴ�������
	MemoryStream m_streamSelectionInfo;

	//! \brief �Ƿ���SelectionInfo
	unsigned char m_bHasSelectionInfo;

	//! \brief ������õ��ڴ�������
	MemoryStream m_streamTexture;

	//! \brief ���в��ʷ��� Json
	string m_strJsonMaterials;

	//! \brief Ŀ��ѹ����ʽ��ԭ��ѹ����ʽ��һ��ʱ���Ƿ����ת��
	bool m_bChangeTexture;

	// ѹ����������
	//CodecTypeö��
	unsigned int m_CompressType;

	//! \brief ����Ϊ HashCode ��Ϊ��������
	std::map<string, Geometry*> m_mapGeometry;
	std::map<string, Material*> m_mapMaterial;
	std::map<string, TextureDataInfo*> m_mapTexture;
};