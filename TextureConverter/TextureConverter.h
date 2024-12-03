#pragma once
#include <string>
#include "External/DirectXTex/DirectXTex.h"

class TextureConverter
{
	public:
		void ConvertTextureWICToDDS(const std::string& filePath);

private:
	void LoadWICTextureFromFile(const std::string& filePath);

	static std:: wstring ConverterMulteByStringToWideString(const std::string& mString);

	DirectX::TexMetadata metadata_;
	DirectX::ScratchImage scratchImage;

	void SeparateFilePath(const std::wstring& filePath);

	//�f�B���N�g���p�X
	std::wstring directoryPath_;
	//�t�@�C����
	std::wstring fileName_;
	//�t�@�C���g���q
	std::wstring fileExt_;

	void SaveDDSTextureToFile();
};

