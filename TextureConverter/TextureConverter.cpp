#include "TextureConverter.h"
#include <Windows.h>
#include <cassert>

using namespace DirectX;

TextureConverter::TextureConverter()
{

}

TextureConverter::~TextureConverter()
{

}

void TextureConverter::ConvertTextureWICToDDS(const std::string& filePath)
{
	//テクスチャファイルを読み込む
	LoadWICTextureFromFile(filePath);


}

void TextureConverter::LoadWICTextureFromFile(const std::string& filePath)
{
	//ファイルパスをワイド文字列に変換する
	std::wstring wfilePath = ConverterMulteByStringToWideString(filePath);

	HRESULT result = LoadFromWICFile(wfilePath.c_str(), WIC_FLAGS_NONE,&metadata_,scratchImage_);

	/*result = LoadFromWICFile(wfilePath.c_str(), WIC_FLAGS_NONE, &metadata_, scratchImage_);*/
	assert(SUCCEEDED(result));

	SeparateFilePath(wfilePath);
}

std::wstring TextureConverter::ConverterMulteByStringToWideString(const std::string& mString)
{
	//ワイド文字列に変換した際の文字列を計算
	int filePathBufferSize = MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, nullptr, 0);

	//ワイド文字列
	std::wstring wString;
	wString.resize(filePathBufferSize);

	//ワイド文字列に変換
	MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, &wString[0], filePathBufferSize);


	return std::wstring();
}

void TextureConverter::SeparateFilePath(const std::wstring& filePath)
{
	size_t pos1;
	std::wstring exceptExt;

	pos1 = filePath.rfind('.');

	if (pos1 != std::wstring::npos) {
		fileExt_ = filePath.substr(pos1 + 1, filePath.size() - pos1 - 1);

		exceptExt = filePath.substr(0, pos1);
	}
	else {
		fileExt_ = L"";
		exceptExt = filePath;
	}
	pos1 = exceptExt.rfind('\\');
		if (pos1 != std::wstring::npos) {
			directoryPath_ = exceptExt.substr(pos1 + 1, exceptExt.max_size() - pos1 - 1);
			return;
		}
		pos1 = exceptExt.rfind('/');
		if (pos1 != std::wstring::npos) {

		}
		directoryPath_ = L"";
		fileName_ = exceptExt;
}

void TextureConverter::SaveDDSTextureToFile()
{
	metadata_.format = MakeSRGB(metadata_.format);

	HRESULT result;

	std::wstring filePath = directoryPath_ + fileName_ + L".dds";

	result = SaveToDDSFile(scratchImage_.GetImage(), scratchImage_.GetImageCount(), metadata_,
		DDS_FLAGS, NONE, filePath.c_str());
	assert(SUCCEEDED(result))
}

