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

	//ディレクトリパス
	std::wstring directoryPath_;
	//ファイル名
	std::wstring fileName_;
	//ファイル拡張子
	std::wstring fileExt_;

	void SaveDDSTextureToFile();
};

