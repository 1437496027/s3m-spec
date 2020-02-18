// �ڴ�ͼ������,����һЩ���õ�ͼ����
// ��������з�����Ϊ��̬����
// ����:��ï
// ����:2010-12-15
// �汾:1.0.0

#ifndef  MEMIMAGE_H
#define MEMIMAGE_H

#ifdef WIN32
	#ifdef MEMIMAGE_EXPORTS
		#define MEMIMAGE_API __declspec(dllexport)
	#else
		#define MEMIMAGE_API __declspec(dllimport)
	#endif
#else
	#define MEMIMAGE_API 
#endif

class MEMIMAGE_API MemImage
{
public:
	// format ԭͼ������ظ�ʽ
	// width,height ԭͼ��Ŀ�Ⱥ͸߶�
	// in ԭͼ�������
	// comtype ͼ��ѹ������
	// out  ѹ��������,�ⲿ��������㹻�Ŀռ�
	// return ����ѹ����ͼ�����ݵĴ�С
	static unsigned int Encode( const unsigned int pixsize, unsigned int width, unsigned int height,const unsigned char* in,unsigned char *out );

	// ��ѹ��dxtn
	static void Decode( const unsigned int pixsize, unsigned int width, unsigned int height,unsigned char* out,const unsigned char *in );

	// ����ָ���Ĵ�С����ͼƬ
	static void Scale(const unsigned int components, unsigned int widthin, unsigned int heightin,unsigned char *in,
					        unsigned int widthout, unsigned int heightout, unsigned char *out);

	// RGB,RGBA �� BGR,BRGA֮���໥ת��,ֱ�Ӹı�ԭʼ����
	// RGBʱcomponents = 3,RGBA components = 4
	static void ImageSwapRB(const unsigned int components, unsigned int widthin, unsigned int heightin,unsigned char *in);
};
#endif
