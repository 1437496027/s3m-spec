#pragma once
#include "Toolkit/UGMarkup.h"
#include "Base3D/UGBoundingBox.h"
#include "Base3D/UGBoundingSphere.h"
#include "Projection/UGPrjCoordSys.h"

namespace UGC{

class CACHEBUILDER3D_API UGSCPFile
{
public:
	UGSCPFile(void);
	~UGSCPFile(void);
public:
	//! \brief strSCPFile���ļ�·��
	UGbool LoadFromFile(const UGString strSCPFile);
	//! \brief strSCPXML xml���ݣ�����·��
	UGbool Load(const UGString strSCPXML);
	UGbool Save(UGString& strSCPXML);

	UGbool SaveToFile(const UGString& strSCPPath);
	
	//! \brief �汾��
	UGdouble GetVersion();

	//! \brief �ļ�����
	UGString GetFileType();
	void SetFileType(const UGString &strFileType);

	//! \brief RenderMode
	UGString GetRenderMode();
	
	//! \brief �ռ��ʷַ�ʽ
	UGString GetTileSplitType();
	void SetTileSplitType(const UGString &strTileSplitType);

	//! \brief �����зַ�ʽ���Ĳ������˲���
	UGString GetPyramidSplitType();
	void SetPyramidSplitType(const UGString &strPyramidType);

	std::map<UGdouble, UGString> GetScales();

	//! \brief �����
	UGPoint3D GetPosition();
	void SetPosition(const UGPoint3D & pnt);

	//! \brief �����ģ��BBOX
	UGBoundingBox GetBBox();
	void SetBBox(UGBoundingBox &bbox);

	//! \brief ����ĵ���Χ
	UGRect2D GetGeoBounds();
	void SetGeoBounds(UGRect2D &rcBounds);

	//! \brief ����ϵ��Ϣ
	UGbool GetPrjCoords(UGPrjCoordSys& prjCoordj);
	void SetPrjCoords(UGPrjCoordSys& prjCoordj);

	//��ȡ���ڵ�����
	std::vector<UGString> GetRootNames();
	void SetRootNames(const std::vector<UGString> &vecRootNames);
	//��ȡ���ڵ��Χ��
	std::vector<UGBoundingSphere> GetBoundingSpheres();
	void SetBoundingSpheres(const std::vector<UGBoundingSphere>& vecBSpheres);

private:
	UGdouble m_dbVersion;
	UGString m_strFileType;
	UGString m_strPyramidSplitType;
	UGString m_strRenderMode;
	UGString m_strTileSplitType;

	std::map<UGdouble, UGString> m_mapScaleCaption;

	//! \brief �����
	UGPoint3D m_pntPosition;
	
	//! \brief ���������ģ�Ͱ�Χ��
	UGBoundingBox m_bbox;

	//! \brief ��������ĵ���Χ
	UGRect2D m_rcGeoBounds;

	//! \brief TileInfo(s)
	std::vector<UGString> m_vecRootNames;
	std::vector<UGBoundingSphere> m_vecBSpheres;	//x y z radius

	UGPrjCoordSys m_prjCoord;

	UGbool m_bHasPrj;
};

}