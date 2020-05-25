#pragma once
#include "Shell.h"
using namespace std;
using namespace S3MB;
class ROGroupLite
{
public:
	struct MeshParamInfo
	{
		string strID;
		int LodID;
		std::vector<float> verts;
		std::vector<unsigned int> indexs;
		std::vector<float> normals;
		std::vector<float> texCoords;
		std::vector<float> colors;
	};
	static RenderOperationGroup* CreateROGroupLite(int lodId, string texturePath);

	//! \brief ����һ��ģ�͹Ǽ�����
	static MeshParamInfo CreateMeshData(int lodId);

	//! \brief ���ݶ�ȡ�Ķ�����Ϣ����geometry����
	static Geometry* CreateGeometry(MeshParamInfo& meshInfo);

	//! \brief ��������
	static TextureData* CreateTextureData(string texturePath);

	//! \brief ��������
	static Material* CreateMaterial(string textureDataName);
};
