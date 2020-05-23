#pragma once
//!  \brief ���ζ������
class S3mbElement
{
public:
	//! \brief element����
	//! \remarks 0-10000Ϊ�ڲ�Ԥ����10000����Ϊ�û���չ��
	enum Type
	{
		//! \brief ��
		ElemNull = 0,
		//! \brief ��
		ElemPoint = 1,
		//! \brief ���
		ElemMultiPoint = 2,
		//! \brief ��
		ElemLine = 3,
		//! \brief ��
		ElemRegion = 5,
		//! \brief �ı�
		ElemText = 7,
		//! \brief ���Σ�֧����б
		ElemRect = 12,
		//! \brief Բ�Ǿ��Σ�֧����б
		ElemRectRound = 13,
		//! \brief Բ
		ElemCircle = 15,
		//! \brief ��Բ��֧����б
		ElemEllipse = 20,
		//! \brief ��Բ������
		ElemPie = 21,
		//! \brief ��Բ������
		ElemChord = 23,
		//! \brief Բ��
		ElemArc = 24,
		//! \brief ��Բ��
		ElemEllipticArc = 25,
		//! \brief Cardinal����,��֤����һ��ͨ�����Ƶ�
		ElemCardinal = 27,
		//! \brief DGN curve������
		ElemCurve = 28,
		//! \brief ���ξ���B��������
		ElemBSpline = 29,
		//! \brief �̶��ߣ�����������ϵ���ߣ�
		ElemLineM = 35,
		//! \brief ��ά��
		ElemPoint3D = 101,
		//! \brief ��ά���
		ElemMultiPoint3D = 102,
		//! \brief ��ά��
		ElemLine3D = 103,
		//! \brief ��ά��
		ElemRegion3D = 105,
		//! \brief ���϶���
		ElemCompound = 1000,
		//! \brief �û��������
		ElemUser = 1001,
	};

public:
	//!  \brief ���ζ������Ĭ�Ϲ��캯��
	S3mbElement();
	//!  \brief ���ζ������Ĭ����������
	virtual ~S3mbElement();

public:
	//! \brief  �õ�Element���͡�
	virtual int GetType() const = 0;

	//! \brief  �õ�������ά���������0ά����1ά����2ά���ı�-1ά��
	virtual int GetStyleDimension() const = 0;

	//! \brief  �õ������������
	virtual S3mbRect2D GetBounds();

public:
	//! \brief 	���ζ���ID����ȡ������ʱҪ��֤Ψһ��
	int m_nID;
	//! \brief  0ά��1ά��2ά��-1ά���ζ���ķ��ά����
	S3mbStyle* m_pStyle;
	//! \brief	�����������
	S3mbRect2D m_rcBounds;

};
